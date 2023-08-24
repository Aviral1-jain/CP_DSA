#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

  string preToInfix(string exp) {
        // Write your code here
        stack<string> st;
        string ans="";
        int n=exp.length();
        for(int i=n-1;i>=0;i--){
            if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
                string p="";
                p+=exp[i];
                st.push(p);
            }
            else if(exp[i]=='+'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'+'+temp1+')';
                st.push('('+temp1+'+'+temp2+')');
            }
            else if(exp[i]=='-'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'-'+temp1+')';
                st.push('('+temp1+'-'+temp2+')');
            }
            else if(exp[i]=='*'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'*'+temp1+')';
                st.push('('+temp1+'*'+temp2+')');
            }
            else if(exp[i]=='/'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'/'+temp1+')';
                st.push('('+temp1+'/'+temp2+')');
            }
            
        }
        return st.top();
    }