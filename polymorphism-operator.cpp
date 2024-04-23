#include<iostream>
using namespace std;
class oo{
    public:
    int a, b;
    string s,t;

    // int add(int a, int b) {
    //     return (a + b);
    // }

    oo operator + (oo &obj){
        int val1 = this->a;
        int val2 = obj.b;
        cout << "Your '+' operator has been overloaded!" << endl;
    }

    int operator *(oo &subj){
        int val1 = this->a;
        int val2 = subj.b;
        return val1+val2;
    }

    string operator -(oo &chit){
        string str1 =  this->s;
        string str2 =  chit.t;
        return str1 + " " + str2;

    }



};
int main(){
    oo obj1, obj2;
    obj1.a = 12;
    obj2.b = 10;
    obj1 + obj2;

    oo subj1, subj2;
    subj1.a = 2;
    subj2.b = 2;
    cout << subj1 * subj2 <<endl;

    oo chit1, chit2;
    chit1.s = "Hello";
    chit2.t = "Tichi";
    cout << chit1-chit2;

}