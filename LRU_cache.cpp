struct Node{
    Node* pre;
    Node* next;
    int key;
    int value;
    Node(int k, int v):pre(NULL), next(NULL), key(k), value(v){};
};

class LRUCache{
private:
    int count;
    int capac;
    Node* head;
    Node* tail;
    map<int, Node*> cache;
    map<int, Node*>::iterator iter;
private:
    void pushtohead(Node* target){
        target->next = head->next;
        head->next = target;
        target->pre = head;
        target->next->pre = target;
    }
    void withdraw(Node *cur){
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
    }
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        capac = capacity;
        count = 0;
    }
    
    int get(int key) {
        iter = cache.find(key);
        if(iter == cache.end())
            return -1;
        withdraw(iter->second);
        pushtohead(iter->second);
        return iter->second->value;
    }
    
    void set(int key, int value) {
        iter = cache.find(key);
        if(iter != cache.end()){
            iter->second->value = value;
            withdraw(iter->second);
            pushtohead(iter->second);
        }
        else if(count < capac){
            Node *tmp = new Node(key, value);
            cache.insert(pair<int, Node*>(key, tmp));
            pushtohead(tmp);
            count++;
        }
        else{
            Node *tmp = new Node(key, value);
            pushtohead(tmp);
            cache.insert(pair<int, Node*>(key, tmp));
            Node *removed = tail->pre;
            withdraw(removed);
            cache.erase(cache.find(removed->key));
            delete(removed);
        }
    }
};
