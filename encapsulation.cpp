#include<iostream>
using namespace std;
class Animal{
    private:
    int height;
    string color;

    public:
    int getheight(){
        return height;
    }
    string getcolor(){
        return color;
    }
      void setheight(int height){
        this->height= height;
      }

      void setcolor(string color){
        this->color = color;
      }
    
};
int main(){
    Animal a;
    a.setheight(10);
    cout << a.getheight() << endl;
    a.setcolor("Red");
    cout << a.getcolor();


}