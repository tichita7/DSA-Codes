#include<iostream>
using namespace std;

class Human{
    public:
    int age;
    string name;

    void walk(){
        cout << "I walk!" << endl;
        cout << this->age << " " << this->name << endl;
    }
};

class person1: public Human{
void get(int age, string name){
this->age = age;
this->name = name;
}
};
int main(){
  person1 p1;
  p1.age;
  p1.name;
}