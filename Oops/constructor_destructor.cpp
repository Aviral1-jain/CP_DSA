#include<bits/stdc++.h>
using namespace std;


class Hero {
    

    public:
    int health;
    char level;

        Hero(){
            cout<<"Constructor Called"<<endl;
        }
        //Paramerterised Constructor
        Hero(int health) {
            cout<<"this-> "<<this<<endl;
            this -> health = health;
        }
        Hero(int health,char level) {
            
            this -> health = health;
            this -> level = level;
        }

        
 //copy constructor
    Hero(Hero& temp) {

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    
    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
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

int main(){
    cout<<"Hi"<<endl;
    //statically
    // Hero h1;
    // cout<<"Hello"<<endl;
    // Hero *h=new Hero ();
    // cout<<"Helloos"<<endl;



     //object created statically
    Hero ramesh(10);
    cout << "Address of ramesh " << &ramesh << endl;
    

    Hero *h=new Hero(11);

    Hero temp(22,'B');





    return 0;

}
