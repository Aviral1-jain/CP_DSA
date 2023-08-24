#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


  int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<S.length();i++){
            if((S[i]>='0' && S[i]<='9')){
                st.push((S[i]-'0'));
            }
            else if(S[i]=='+'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                int res=temp2+temp1;
                st.push(res);
            }
            else if(S[i]=='-'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                int res=temp2-temp1;
                st.push(res);
            }
            else if(S[i]=='*'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                int res=temp2*temp1;
                st.push(res);
            }
            else if(S[i]=='/'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                int res=temp2/temp1;
                st.push(res);
            }
        }
        return st.top();
    }