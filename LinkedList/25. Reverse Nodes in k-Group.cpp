public:
int len(ListNode* head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(len(head)>=k){
       ListNode *curr=head;
        ListNode *nxt;
        ListNode *prev=NULL;
        int cnt=0;

         while(curr!=NULL && cnt<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt++;
        }
        if(nxt!=NULL){
            head->next=reverseKGroup(nxt,k);
        }
        return prev;
        }
        else{

        return head; 
        }
    }