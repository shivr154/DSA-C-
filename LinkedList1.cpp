#include<iostream>
using namespace std;

class Node{
       public:
       int data;
       Node* next;

       Node(){
        this->data=0;
        this->next=NULL;
       }

       Node(int data){
        this->data=data;
        this->next=NULL;
       }

       ~Node(){
            cout<<"Node with value: "<< this->data << " deleted" << endl;
       }

};

void print(Node* head){
     
     Node* temp=head;
     while(temp != NULL){
        cout << temp->data <<" ";
        temp=temp->next;
     }

}

int findLength(Node* &head){
    int len=0;
    Node* temp= head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

// I want to insert a node right at the head of linked list
void insertAtHead(Node* &head,Node* &tail, int data){
    // check for empty linked list
      if(head==NULL){
            Node* newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;
       }
    // step 1: create a node
    Node* newNode= new Node(data);
    // step 2: new node ke next ko head pe point kardo
    newNode -> next= head;
    // step 3: head ko new node pe lga doo
    head= newNode;
}

// I want to insert a node right at the end of linked list
void insertAtTail(Node* &head, Node* &tail, int data){
      // check for empty linked list
      if(head==NULL){
            Node* newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;
       }
      // step 1: create a node
      Node* newNode= new Node(data); 
      // step 2: connect with tail node
      tail->next=newNode;
      // step 3: update tail
      tail=newNode;
       
}

void insertAtPosition(int data,int position, Node* &head, Node* &tail) {
    // check for empty LL
    if(head==NULL){
        Node* newNode= new Node(data);
        head= newNode;
        tail= newNode;
        return;
    }

    // handling the edge cases of inserting at head and tail
    if(position==0){
        insertAtHead(head,tail,data);
        return;
    }
    int len= findLength(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return; 
    }
    // step 1: find the position : prev & curr;
        int i=1;
        Node* prev= head;

        while(i < position){
            prev= prev->next;
            i++;
        }
        Node* curr= prev->next; 

        // step 2: create a node
            Node* newNode= new Node(data);

       // step 3: 
       newNode ->next= curr;

       // step 4:
       prev->next=newNode;

}


void deleteNode(int position, Node* &head, Node* &tail){
    if(head==NULL){
        cout<<"cannot delete, LL is empty";
        return;
    }
    // deleting first node

    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    int len=findLength(head);
     
// deleting last node
    if(position==len){
       int i=1;
       Node* prev=head;
       while(i<position-1){
        prev=prev->next;
        i++;
       }

        prev->next=NULL;
        Node*temp=tail;
        tail=prev;
        delete temp;
        return;
    }

    // deleting middle node
     
     // step 1: find prev and curr
     int i=1;
     Node* prev=head;
     while(i<position-1){
        prev=prev->next;
        i++;
     }
     Node* curr= prev->next;

      // step 2:
      prev->next= curr->next;

      // step3:
      curr->next=NULL;
      // step4;
      delete curr;
}

   Node* reverseUsingRecursion(Node* &prev, Node* &curr){
            // base case
            if(curr==NULL){
                // LL reverse ho chuki hai
                return prev;
            }
            // 1 case solve 
            Node* forward= curr->next;
            curr->next = prev;

            reverseUsingRecursion(curr,forward);
   }

   Node* reverseUsingLoop(Node* head){
                 Node* prev=NULL;
                 Node* curr=head;

                 while(curr!=NULL){
                       Node* temp= curr->next;
                       curr->next=prev;
                       prev=curr;
                       curr=temp;
                 }
                 return prev;
   }


int main(){
   /*     
        Node* first= new Node(10);     
        Node* second= new Node(20);     
        Node* third= new Node(30);     
        Node* fourth= new Node(40);
        Node* fifth= new Node(50);
       
        first->next=second;
        second->next=third;
        third->next=fourth;
        fourth->next=fifth;


     cout<<"printing the LL" <<endl;
     print(first);

*/
     Node* head=NULL;
     Node* tail =NULL;

     insertAtHead(head,tail,20);
     insertAtHead(head,tail,50);
     insertAtHead(head,tail,60);
     insertAtHead(head,tail,90);
     insertAtTail(tail,tail,77);

     print(head);
     cout<<endl;
     
   /*  cout<<"head : "<< head->data<<endl;
     cout<<"tail : "<< tail->data<<endl;

     insertAtPosition(101, 6,head, tail);

     print(head);
     cout<<endl;
     cout<<"head : "<< head->data<<endl;
     cout<<"tail : "<< tail->data<<endl;
*/

    // deleteNode(3 ,head,tail);
    // print(head);
    cout<<endl;

  // LECTURE 2 QUES --> Reverse linked list
    Node* prev= NULL;
    Node* curr=head;
    head= reverseUsingRecursion(prev,curr);   
    print(head);
    cout<<endl;
   
    
    
     

    return 0;
}