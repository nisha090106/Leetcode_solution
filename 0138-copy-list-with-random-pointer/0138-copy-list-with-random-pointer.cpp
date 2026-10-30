class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node* , Node*>mp;
        Node* curr = head;
        while(curr!=NULL){
           mp[curr]=new Node(curr->val);
           curr= curr->next; 
        }
        curr=head;
        while(curr!=NULL){
        mp[curr]->next = (curr->next!= NULL) ? mp[curr->next]:NULL;
        mp[curr]->random = (curr->random!= NULL) ? mp[curr->random]:NULL;
        curr= curr->next;
        }
        return mp[head];
    }
};