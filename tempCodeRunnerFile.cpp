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

};
void insertAtHead(Node* &head, int d){
    Node* temp =  new Node(d);
    temp->next = head;
    head->prev = temp;
    head =  temp;
}

 void insertAtTail(Node* &tail, int d){
    Node* temp  = new Node(d);
    tail->next = temp;