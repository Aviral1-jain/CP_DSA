#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

int precedence(char c){
        if(c=='^'){
            return 3;
            
        }
        else if(c=='*' || c=='/')return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='1' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                
            }
            else{
                while(!st.empty() && (precedence(st.top())>=precedence(s[i]))){
                    
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
                
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }