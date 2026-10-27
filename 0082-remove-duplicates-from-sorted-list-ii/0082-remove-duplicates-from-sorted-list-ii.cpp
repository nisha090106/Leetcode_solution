class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* curr = dummy;

        while(curr->next!=NULL){
            if(curr->next->next!=NULL && curr->next->val == curr->next->next->val){
                int val = curr->next->val;

                while(curr->next!= NULL && curr->next->val == val){
                    curr->next = curr->next->next;
                }
            }else{
                curr= curr->next;
            }
        }
        return dummy->next;
    }
};