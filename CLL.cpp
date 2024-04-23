#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data =  d;
        this->next =  NULL;
    }

    ~Node(){
        int val =  this->data;
        while(this->next != NULL){
            this->next= NULL;
            delete this-> next;
        }
    }
};

void insertNode(Node* &tail, int el, int d){
    //empty list
    if(tail== NULL){
        Node* temp = new Node(d);
        tail =  temp;
        temp->next = temp;
    }
    else{
        //non-empty linked List
        Node* curr = tail;

        //until element not found
        while(curr-> data != el){
            curr = curr->next;
        }

        //element found
        Node* temp =  new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int d){
    //empty
    if(tail == NULL){
        cout << "list is empty" << endl;
    }
    else{
        //non-empty
        Node* prev  = tail;
        Node* curr = prev->next;

        //Until the data is found
        while(curr->data != d){
            prev = curr;
            curr = curr->next;
        }

        prev->next  = curr->next;
        curr->next = NULL;
        delete curr;
    }

}

void print(Node* tail){
    Node* temp =  tail;
    do{
        cout << tail->data << " ";
        tail = tail->next;
    }
    while(tail != temp);
    cout << endl;
}

bool isCLL(Node* &head){
    if(head==NULL){
        return true;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    
    if(temp==head){
        return true;
    }
    return false;


}

//To detect the cycle
bool isCycle(Node* head){
    if(head==NULL){
        return false;
    }

    Node* temp= head;
    map<Node*, bool> visited;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }

    return false;
}

//floyd loop
Node* floydLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(fast==slow){
            cout<< slow->data << endl;
            return slow;
        }
    }
    return NULL;
}




int main(){
    Node* tail =  NULL;
    insertNode(tail, 5, 3);
    // print(tail);

    insertNode(tail, 3, 4);
    // print(tail);

    insertNode(tail, 4, 10);
    // print(tail);

    deleteNode(tail,10);
    // print(tail);
    tail->next= tail->next->next;
    
    if(isCLL(tail)){
        cout << "Circular List" << endl;
    }
    else{
        cout << "Not circular" << endl;
    }

    if(floydLoop(tail)!= NULL){
        cout << "Cycle is present" << endl;
    }
    else{
        cout << "Cycle not present" << endl;
    }


    
    return 0;
}
