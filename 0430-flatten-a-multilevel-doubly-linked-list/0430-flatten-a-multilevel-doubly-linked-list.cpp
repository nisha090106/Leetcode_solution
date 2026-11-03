class Solution {
public:
    Node* flattenDFS(Node* head) {
        Node* curr = head;
        Node* tail = head;
        while(curr!=NULL){
            Node* next = curr->next;
            if(curr->child!=NULL){
                Node* CH = curr->child;
                Node* CT = flattenDFS(CH);

                curr->next = CH;
                CH->prev=curr;
                curr->child=NULL;

                if(next!=NULL){
                    CT->next=next;
                    next->prev = CT;  
                }
                tail = CT;
            }
            else{
                tail=curr;
            }
            curr=next;
        }
        return tail;
    }
         Node* flatten(Node* head) {

        if (head == nullptr) {
            return nullptr;
        }

        flattenDFS(head);

        return head;
         }
    
};