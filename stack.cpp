#include<iostream>
#include<stack>
using namespace std;
class Stack{
   //properties
   public:
   int top;
   int *arr;
   int size;

   //constructor
   Stack(int size){
    this->size = size;
    arr = new int[size];
    top = -1;
   }

   //behaviours
    void push(int element){
        //to push an element, space should be available (Atleast one space). For that-->
        if( size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack is overflowed." << endl;
        }

    }

    void pop(){
        //To pop, there should eb atleast one element present
        if(top >= 0){
            top--;
        }
        else{
            cout << "Stack is underflowed." << endl;
        }

    }

    int peek(){
    //For this too, stack should not be empty
    if( top >= 0 ){
        return arr[top] ;
    }
    else{
        cout << "Stack is empty." <<endl;
    }

    }

    bool isEmpty(){
        if( top = -1){
            return 1;
        }
        else{
            return -1;
        }

    }
};

int main(){
    Stack st(4);
    
    st.push(21);
    st.push(45);
    st.push(55);

    cout << st.peek() <<endl;
    st.pop();
     cout << st.peek() <<endl;

    st.pop();
     cout << st.peek() <<endl;

    st.pop();
     cout << st.peek() <<endl;

     if(st.isEmpty()){
        cout << "Stack is empty dear!" <<endl;
     }
     else{
        cout << "Stack is not empty dear!" << endl;
     }

   





/*
//creation
stack<int> s;

//insert element
s.push(1);
s.push(2);
cout << s.top() <<endl;
//delete
s.pop();
cout << s.top() << endl;

//check if empty
if(s.empty()){
    cout << "empty" << endl;
}
else{
    cout << "Not empty" <<endl;
}

cout << "sIze --> " << s.size();
*/


}