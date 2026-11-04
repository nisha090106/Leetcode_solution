class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode lessHead(0),greatHead(0); 
      ListNode* lessTail = &lessHead;
      ListNode* greatTail = &greatHead;

      ListNode* curr= head;
      while(curr != NULL){
        if(curr->val < x){
            lessTail->next = curr;
            lessTail = curr;
        }else{
            greatTail->next = curr;
            greatTail = curr;
        }
        curr= curr->next;

        lessTail->next = greatHead.next;
        greatTail->next = NULL; 
      }
      return lessHead.next;
    }
};