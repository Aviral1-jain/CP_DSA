 
 #include <bits/stdc++.h> 
using namespace std;
 void mirror(Node* node) {
        // code here
        if(node==NULL)return;
        if(node->left==NULL && node->right==NULL)return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
        return;
        
    }