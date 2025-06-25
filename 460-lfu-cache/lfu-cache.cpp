class LFUCache {
private:
    class Node{
    public:
        int key;
        int val;
        int cnt;
        Node*prev;
        Node*next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->cnt=1;
        }
    };

    class List{
    public:
        int size;
        Node*head;
        Node*tail;
        List(){
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addFront(Node*node){
            node->next=head->next;
            node->next->prev=node;
            head->next=node;
            node->prev=head;
            size++;
        }
        void deleteNode(Node*node){
            node->prev->next=node->next;
            node->next->prev=node->prev;
            size--;
        }
    };

    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqListMap;
    int maxSize,minFreq,curSize;

public:
    LFUCache(int capacity) {
        this->maxSize=capacity;
        minFreq=0;
        curSize=0;
    }
    
    void updateFreqListMap(Node*node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHigherList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherList=freqListMap[node->cnt+1];
        }
        node->cnt++;
        nextHigherList->addFront(node);
        freqListMap[node->cnt]=nextHigherList;
        keyNode[node->key]=node;
    }

    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node*node=keyNode[key];
            int val=node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0)  return;
        if(keyNode.find(key)!=keyNode.end()){
            Node*node=keyNode[key];
            node->val=value;
            updateFreqListMap(node);
        }else{
            if(curSize==maxSize){
                List*list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List*listFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            Node*node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */