class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode* i = head;
       ListNode* j = head;
       while(j && j->next ){
            i = i->next;
            j= j->next->next;
            if(i==j){
                i=head;
                while(i!=j){
                    i=i->next;
                    j=j->next;
                }
                return i;
            }
        }
        return NULL;
        
       } 

};