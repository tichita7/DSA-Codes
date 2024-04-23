#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this-> next =  NULL;
        this-> prev= NULL;
    }

    ~Node(){
        int val =  this-> data;
        while(this->next != NULL){
            this->next = NULL;
            delete this->next;
        }
        cout << "The value deleted is: " << val << endl;

    }

};
void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp =  new Node(d);
        head  = temp;
    }
    else{
    Node* temp =  new Node(d);
    temp->next = head;
    head->prev = temp;
    head =  temp;

    }
   
}

 void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail == NULL){
         Node* temp  = new Node(d);
         tail =  temp;

    }
    else{
    Node* temp  = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail =  temp;

    }

}

void insertAtMiddle(Node* &head, Node* &tail, int position, int d){
     Node* anynode =  head;
    int cnt = 1;

    if( position == 1 ){
        insertAtHead(head, tail, d);
        return;
    }

    while(cnt < position-1){
        anynode =  anynode->next;
        cnt++;
    }
    
    if(anynode-> next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = anynode->next;
    newNode->next->prev = newNode;
    newNode->prev = anynode;
    anynode->next =  newNode;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

void deleteNode(int position, Node* &head, Node* &tail){
    //delete 1st position
    if(position == 1){
        Node* temp  = head;
        temp->next->prev = NULL;
        head  = temp->next;
        temp->next = NULL;
    }
    else{
        Node* curr = head;
        Node* prev  = NULL;
        int cnt = 1;
        while(cnt < position){
             prev  =  curr;
            curr =  curr->next;
            cnt++;
        }
    
           curr->prev = NULL;
           prev->next = curr->next;
           curr->next  = NULL;
           delete curr;
    }
        
    }

int main(){
    Node* node1 = new Node(10);
    Node* head =  node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, tail, 12);
    print(head);

    insertAtTail(tail,head,  20);
    print(head);

    insertAtMiddle(head, tail, 1, 22);
    print(head);

    deleteNode(4, head, tail);
    print(head);

    return 0;
}