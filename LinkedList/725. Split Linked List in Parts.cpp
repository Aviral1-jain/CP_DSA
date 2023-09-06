#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int leng(ListNode* head){
        int cnt=0;
        while(head){
            cnt++,head=head->next;
        }
        return cnt;

    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=leng(head);
        int leneachbl=len/k;
        int extras=len%k;
    //    cout<<len<<endl;
    vector<ListNode*> ans(k,NULL);
    ListNode* curr=head;
    ListNode *prev=NULL;
    for(int i=0;i<k;i++){
        ans[i]=curr;

    for(int i=1;i<=leneachbl;i++){
            
            prev=curr;
            curr=curr->next;

        }
        if(extras>0){
            prev=curr;
            curr=curr->next;
            extras--;

        }
        if(prev!=NULL)
        prev->next=NULL;

    }
       
   return ans;
    }
};