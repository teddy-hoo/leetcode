/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, int> hash;
        map<RandomListNode *, int>::iterator iter;
        vector<RandomListNode *> copy;
        
        RandomListNode *p = head;
        RandomListNode *newHead = new RandomListNode(0);
        RandomListNode *pn = newHead;
        
        for(int i = 0; p != NULL; i++, p = p->next){
            hash[p] = i;
            RandomListNode *newNode = new RandomListNode(p->label);
            pn->next = newNode;
            pn = pn->next;
            copy.push_back(newNode);
        }
        
        p = head;
        for(int i = 0; p != NULL; i++, p = p->next){
            iter = hash.find(p->random);
            if(iter != hash.end()){
                copy[i]->random = copy[iter->second];
            }
        }
        
        return newHead->next;
    }
};
