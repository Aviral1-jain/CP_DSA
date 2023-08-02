#include<bits/stdc++.h>
using namespace std;

// #include "Hero.cpp"
// class Hero {
//     public:
//     int health;
//     char level;
//     void print(){
//         cout<<level<<endl;
//     }
    
    
// };
class Hero {
    private:
    int health;

    public:
    char level;
    void print(){
        cout<<level<<endl;
    }
      int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
    
    
};
// class Hero {
//     public:
//     int health;
//     private:
//     char level;

//     void print(){
//         cout<<level<<endl;
//     }

    
// };

int main(){
    Hero h1;
    cout<<"size: "<<sizeof(h1)<<endl; //4 //after including Hero.cpp it 108
    // if class is empty gives 1 as it is required to keep a track of it
    //gives default value
    // cout<<"health: "<<h1.health<<endl;
    // cout<<"level: "<<h1.level<<endl;



    // set the attributes

    // h1.health=70;
    // h1.level='A';

    // cout<<"health: "<<h1.health<<endl;
    // cout<<"level: "<<h1.level<<endl;



    //private health
//setter
   h1.setHealth(70);
   h1.level='A';
//getter
    cout<<"health: "<<h1.getHealth()<<endl;
    cout<<"level: "<<h1.level<<endl;




    return 0;

}
