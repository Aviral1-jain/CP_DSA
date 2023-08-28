#include <bits/stdc++.h>
using namespace std;


class MyQueue {
public:
stack<int> s1,s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        
    }
    
    int pop() {
          while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
      //  s2.push(s1.top());
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;

        
    }
    
    int peek() {
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        s2.push(s1.top());
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
        
    }
};