void removeMiddle(LinkedList *node){
    if(node == 0){
        return;
    }
    
    //create a new head
    LinkedList *tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
    delete(tmp);
    
}
