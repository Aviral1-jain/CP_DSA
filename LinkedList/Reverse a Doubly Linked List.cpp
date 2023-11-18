//https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
 Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* nxt;
        Node* prv=NULL;
        while(head!=NULL){
            nxt=head->next;
            head->next=prv;
            head->prev=nxt;
            prv=head;
            
            
            
            
            head=nxt;
            
            
            
        }
        return prv;
    }
