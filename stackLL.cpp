#include<iostream>
#include<stack>
using namespace std;

class node{
    //properties: next ptr, size and value
    public:
    node* next;
    int size;
    int val;

    node(int val){
        this->val = val;
        next = NULL;
        
    }

};

class Stack{
    //properties: top and size
    public:
    node* head; //head = top in stack
    int size;

    Stack(){
        head = NULL;
        size = 0;
    }

    //behaviours
    void push(int el){
        node* curr = new node(el);
        curr->next = head;
        head = curr;
        cout << "Node pushed " << curr->val << endl;
        size++;
    }

    int pop(){
        if( head == NULL ){
            return -1;
        }
        else{
            node* curr = head;
            int currData = curr->val; //to be returned at the end
            curr = curr->next;
            delete curr;
            size--;
            return currData;
            
        }
    }

    int peek(){
      if( head == NULL){
        return -1;
      }
      else{
        return head->val;
      }
    }

    int ssize(){
        return size;
    }

    bool isEmpty(){
        return head==NULL;
    }

    void print(){
        node* curr = head;
        while(curr != NULL){
            cout << "curr->val" << curr->val << endl;
             curr = curr->next;
        }
    }
};

int main(){

    Stack st;
    st.push(21);
    st.push(34);
    st.push(44);

    cout << st.pop() << endl;

    cout << st.isEmpty() << endl;
    cout << st.peek() << endl;

    cout << st.ssize() << endl;


    return  0;
}