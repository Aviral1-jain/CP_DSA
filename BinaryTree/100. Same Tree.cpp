 #include <bits/stdc++.h> 
using namespace std;

 bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)return true;
        if(r1==NULL || r2==NULL || r1->data!=r2->data)return false;
        bool first=isIdentical(r1->left,r2->left);
        bool second=isIdentical(r1->right,r2->right);
        return first && second;
    }