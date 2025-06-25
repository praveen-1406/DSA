

class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node*next;
        Node*prev;
        Node(int key_,int val_){
            key=key_;
            val=val_;
        }
    };

    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);

    void deleteNode(Node*node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insertAfterHead(Node*node){
        node->next=head->next;
        node->next->prev=node;
        head->next=node;
        node->prev=head;
    }

    
    int capacity;
    unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
        mpp.clear();
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())   return -1;
        Node*node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*node=mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            node->val=value;
        }else{
            if(mpp.size()<capacity){
                Node*node=new Node(key,value);
                mpp.insert({key,node});
                insertAfterHead(node);
            }
            else{
                Node*lruNode=tail->prev;
                deleteNode(lruNode);
                mpp.erase(lruNode->key);
                delete lruNode;

                Node*node=new Node(key,value);
                mpp.insert({key,node});
                insertAfterHead(node);
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