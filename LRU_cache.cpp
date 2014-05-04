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
    Node* tmp;
    map<int, Node*> cache;
    map<int, Node*>::iterator iter;
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
        tmp = iter->second;
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
        pushtohead(tmp);
        return iter->second->value;
    }
    
    void set(int key, int value) {
        iter = cache.find(key);
        if(iter != cache.end()){
            iter->second->value = value;
            tmp = iter->second;
            tmp->pre->next = tmp->next;
            tmp->next->pre = tmp->pre;
            pushtohead(tmp);
        }
        else if(count < capac){
            tmp = new Node(key, value);
            cache.insert(pair<int, Node*>(key, tmp));
            pushtohead(tmp);
            count++;
        }
        else{
            tmp = new Node(key, value);
            pushtohead(tmp);
            cache.insert(pair<int, Node*>(key, tmp));
            tmp = tail->pre;
            tmp->pre->next = tail;
            tail->pre = tmp->pre;
            cache.erase(cache.find(tmp->key));
            delete(tmp);
            count++;
        }
    }
private:
    void pushtohead(Node* target){
        target->next = head->next;
        head->next = target;
        target->pre = head;
        target->next->pre = target;
    }
};
