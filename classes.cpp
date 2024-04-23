#include<iostream>
using namespace std;
class game {
    public:
    int level;
    int health;
    char *name = new char[100];
    // game(int level, int health, char name){
    //    this->level = level;
    //    this->health = health;  // 'this->' represents the current object's properties i.e the ones we declared above in the public section
    //   name = new char[100];
    // }
    static int time;
    
    void setlevel(int level){
        this->level = level;
    }
    int getlevel(){
        return level;
    }
    char getname(){
        return *name;
    }
    // char setname(char name[]){
    //    strcpy(this->name = name);
    // }
    void print(){
        cout << health << " " << level << endl;
    }
    
};
int game::time = 10;

int main(){
  
//    game g(2,3) ;
//    cout << "g wala: " << endl;
//     g.print();
//    game h(g);
//    cout << "h wala copied: " << endl;
//    h.print();

//    g.setlevel(22);
//    g.print();

//    h.print();


cout << game::time << endl;  



    // game g;
    // g.health=10;
    // g.level= 3;
    // cout << g.health << endl;
    // cout << g.level << endl;
    //  g.setname('t');
    // cout << g.getname();
    // game g;
    // game *a = new game;
    // a->health;
    // a->setname('t');
    // cout << a->getname() << endl;

   
}