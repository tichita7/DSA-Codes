#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

    ~Node(){
        int val = this-> data;
        while(this->next != NULL){
            delete next;         // to handle tail deletion case
            this-> next =  NULL;
        }
    }
};
 void insertAtHead(Node* &head, int d){
        Node* newNode = new Node(d);
        newNode-> next = head;
        head  = newNode;
        
    }

    void insertAtTail(Node* &tail, int d){
        Node* newNode = new Node(d);
        tail-> next =  newNode;
        tail = newNode;
    }

void insertAtMiddle(Node* &head, Node* &tail, int position, int d){
    Node* anynode =  head;
    int cnt = 1;

    if( position == 1 ){
        insertAtHead(head, d);
        return;
    }

    while(cnt < position-1){
        anynode =  anynode->next;
        cnt++;
    }
    
    if(anynode-> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode-> next =  anynode-> next;
    anynode-> next = newNode;
}

   

void print(Node* &head){
    Node* counter = head;
    while(counter != NULL){
        cout << counter-> data << " " ;
        counter = counter-> next;
    }
    cout << endl;
}

void deleteNode(int position, Node* &head, Node* &tail){
    //delete 1st position
    if(position == 1){
        Node* temp  = head;
        head =  head->next;
        temp-> next = NULL;
        delete temp;
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
        while(curr->next == NULL){
        tail  = prev;
    }
            prev->next = curr->next;
            curr-> next =  NULL;
            delete curr;
        
    }
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
            
            return slow;
        }
    }
    return NULL;
}

Node* getStartingLoop(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection  =floydLoop(head);
    Node* slow= head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }

    Node* startingLoop = getStartingLoop(head);
    Node* temp = startingLoop;
    while(temp->next != startingLoop){
        temp = temp-> next;
    }
    temp->next = NULL;
}


int main(){
    Node* node =  new Node(10);
    // cout << node->next << endl;
    // cout << node->data << endl;

    Node* head = node;
    Node* tail =  node;
    insertAtHead(head, 02);
    // print(head);

    // cout << "After tail" << endl;

     insertAtTail(tail, 12);
    //  print(head);

    insertAtTail(tail, 20);
    // print(head);

    insertAtMiddle(head, tail, 4, 30);
    // print(head);

     insertAtMiddle(head, tail, 1, 30);
    print(head);

    // deleteNode(5, head, tail);
    // print(head);

    tail->next = head->next;


    //  if(isCLL(head)){
    //     cout << "Circular List" << endl;
    // }
    // else{
    //     cout << "Not circular" << endl;
    // }

     if(floydLoop(head)!=NULL){
        cout << "Cycle present" <<endl;
    }
    else{
        cout << "Not present";
    }

    cout << "Starting Loop at " << getStartingLoop(head)->data << endl;

    removeLoop(head);
    print(head);
    return 0;
}