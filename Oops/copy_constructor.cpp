#include<bits/stdc++.h>
using namespace std;

class Hero {

    //properties
    private:
    int health;

    public:
    char *name;
    char level;
   

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //Paramerterised Constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
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

    void setName(char name[]) {
        strcpy(this->name, name);
    }

  

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

};

int main(){
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('A');
    char name[7]="Ramesh";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor

    Hero hero2(hero1);
    hero2.print();
   // default constructor
    hero1.name[0]='S';
     hero1.print(); //Samesh
    hero2.print(); // Samesh 
    // due to shallow copy

    // now deep copy
    // own copy constructor
    hero1.name[0]='S';
     hero1.print(); //Samesh
    hero2.print(); // Ramesh 



}