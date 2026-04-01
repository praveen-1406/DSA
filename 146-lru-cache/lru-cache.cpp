class LRUCache {
    class Node{
    public:
        int key;
        int val;
        Node*prev;
        Node*next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>m;
public:
    LRUCache(int capacity) {
        this->cap=capacity;
        head->next=tail;
        tail->next=head;
    }
    
    void addNode(Node*newNode){
        Node*temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
        head->next=newNode;
    }

    void deleteNode(Node*delNode){
        Node*pNode=delNode->prev;
        Node*nNode=delNode->next;
        pNode->next=nNode;
        nNode->prev=pNode;
        delete delNode;
    }

    int get(int key) {
        if(m.find(key)==m.end())    return -1;
        Node*node=m[key];
        int val=node->val;
        m.erase(key);
        deleteNode(node);
        Node* newNode=new Node(key,val);
        addNode(newNode);
        m.insert({key,newNode});
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node*node=m[key];
            m.erase(key);
            deleteNode(node);
            Node* newNode=new Node(key,value);
            m.insert({key,newNode});
            addNode(newNode);
            
        }else{
            Node*node=new Node(key,value);
            m.insert({key,node});
            addNode(node);
            if(m.size()>cap){
                Node*delNode=tail->prev;
                m.erase(delNode->key);
                deleteNode(delNode);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */