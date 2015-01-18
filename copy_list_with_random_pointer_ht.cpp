/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<RandomListNode*, RandomListNode*> genMap(RandomListNode *head){
        unordered_map<RandomListNode*, RandomListNode*> originToNew;
        while(head != NULL){
            RandomListNode *newNode = new RandomListNode(head->label);
            originToNew[head] = newNode;
            head = head->next;
        }
        
        return originToNew;
    }
    void setPointer(unordered_map<RandomListNode*, RandomListNode*> originToNew,
        RandomListNode* head){
        while(head != NULL){
            if(head->next != NULL){
                originToNew[head]->next = originToNew[head->next];
            }
            if(head->random != NULL){
                originToNew[head]->random = originToNew[head->random];
            }
            head = head->next;
        }
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return NULL;
        }
        
        unordered_map<RandomListNode*, RandomListNode*> originToNew;
        originToNew = genMap(head);
        
        setPointer(originToNew, head);
        
        return originToNew[head];
    }
};