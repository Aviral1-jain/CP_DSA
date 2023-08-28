class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
    int n=asteroids.size();

    for(int i=0;i<n;i++){
        if(asteroids[i]>0){
            st.push(asteroids[i]);
        }
        else if(asteroids[i]<0){
            
            //    int aval=abs(asteroids[i]);
                bool flag=true;
            while(!st.empty()){
                if(st.top()<0){
                    break;
                }
                else if(st.top()==abs(asteroids[i])){
                    flag=false;
                    st.pop();
                    break;
                }
                else if(st.top()>abs(asteroids[i])){
                    flag=false;
                    break;
                }
                else{
                    st.pop();
                }
                

            }
            if(flag)st.push(asteroids[i]);
            
        }
    }
   // int t=st.size();
    vector<int> ans;
     while(!st.empty()){
           ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;


    }
};