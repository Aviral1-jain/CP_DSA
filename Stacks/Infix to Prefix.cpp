
#include <bits/stdc++.h>
using namespace std;

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
        int  n=s.length();
        
        for(int i=n-1;i>=0;i--){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='1' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]==')'){
                st.push(s[i]);
            }
            else if(s[i]=='('){
                while(st.top()!=')'){
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
        reverse(ans.begin(),ans.end());
     //   cout<<ans;
        return ans;
    }