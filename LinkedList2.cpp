#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        cout<<"node with this value "<< this->data << " deleted "<<endl;
    }
    
};

  void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
  }

  int getLength(Node* head){
        int len=0;
        Node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
  }

  void insertATHead(Node* &head, Node* &tail, int data){
    if(head==NULL){
        // LL is empty
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
       // LL is not empty
       // step :1 create a node
       Node* newNode=new Node(data);
       // step: 2 
       newNode->next=head;
       // step: 3
       head->prev=newNode;
       // step: 4
       head=newNode; 
  }

  void insertAtTail(Node* &head, Node* &tail, int data){
          if(head==NULL){
            // LL is empty
            Node* newNode= new Node(data);
            head=newNode;
            tail=newNode;
            return;
          }
          // LL is non empty
          // step1
          Node* newNode= new Node(data);
          // step 2;
           newNode->prev=tail;
          // step 3;
           tail->next=newNode;
          // step4;
          tail=newNode;
  }

   void insertAtPosition(Node* &head, Node* &tail,int data, int position){
    // LL is empty
    if(head==NULL){
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    // LL is non empty
    if(position==1){
        insertATHead(head,tail,data);
        return;
    }
    int len = getLength(head);
    if(position>len){
        insertAtTail(head,tail,data);
        return;
    }
    // insert at Middle
    // step 1: find prev and curr
     int i=1;
     Node* prevNode=head;
     while(i<position-1){
        prevNode=prevNode->next;
        i++;
     }
     Node* curr= prevNode->next;
     // step 2
     Node* newNode= new Node(data);
     // step 3
     prevNode->next=newNode;
     // step 4
     newNode->prev=prevNode;
     // step 5
     curr->prev=newNode;
     // step 6
     newNode->next=curr;

   }

   void deleteFromPos(Node* &head, Node* &tail, int position){
    if(head==NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    if(head->next==NULL){
        // single node
           Node* temp=head;
           head=NULL;
           tail=NULL;
           delete temp;
           return;
    }
    if(position==1){
        // want to delete the first node
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    int len=getLength(head);
     if(position > len){
        cout<<"please enter a valid position "<<endl;
        return;
     }

    if(position==len){
        //delete last node
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
    }

    // delete from middle of linked list

    // step 1: find left, curr, right
     int i=1;
     Node* left=head;
     while(i<position-1){
        left=left->next;
        i++;
     }
     Node* curr= left->next;
     Node* right= curr->next;

     // step 2
     left->next=right;
     // step 3
     right->prev=left;
     // step 4
     curr->prev=NULL;
     // step 5
     curr->next=NULL;
     // step 6 
     delete curr;
   }

int main(){
      
      Node* first=new Node(10);
      Node* second=new Node(20);
      Node* third=new Node(30);
      Node* head=first;
      Node* tail=third;

      first->next=second;
      second->prev=first;

      second->next=third;
      third->prev=second;

     // print(first);
      //cout<<endl;

      insertATHead(head,tail,101);
      //cout<<endl;
      //print(head);

      insertAtTail(head,tail,200);
      //cout<<endl;
      //print(head);

      insertAtPosition(head,tail,300,3);
      cout<<endl;
      print(head);
      cout<<endl;

      deleteFromPos(head,tail,4);
      cout<<endl;
      print(head);

      return 0;
}