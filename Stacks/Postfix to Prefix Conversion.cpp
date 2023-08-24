#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

   string postToPre(string exp) {
        // Write your code here
          stack<string> st;
        string ans="";
        int n=exp.length();
        for(int i=0;i<n;i++){
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
                st.push('+'+temp2+temp1);
            }
            else if(exp[i]=='-'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'-'+temp1+')';
                st.push('-'+temp2+temp1);
            }
            else if(exp[i]=='*'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'*'+temp1+')';
                st.push('*'+temp2+temp1);
            }
            else if(exp[i]=='/'){
                string temp1=st.top();
                st.pop();
                string temp2=st.top();
                st.pop();
            //    string res='('+temp2+'/'+temp1+')';
                st.push('/'+temp2+temp1);
            }
            
        }
        return st.top();
    }
