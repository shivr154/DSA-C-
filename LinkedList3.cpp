#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next= NULL;
    }

};

void print(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" " ;
        temp=temp->next;
    }
}

Node* getMiddle(Node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return head;
    }
    if(head -> next == NULL){
        // only 1 node
        return head;
    }
    // LL have greater than 1 node
    Node* slow= head;
    Node* fast= head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;
}

int getLength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node* &head, int k){
    if(head==NULL){
        cout<<"LL is empty "<<endl;
        return NULL;
    }
    int len=getLength(head);
    if(k > len){
        //cout<<"enter valid value for k"<<endl;
        return head;
    }
     // it means no of nodes in LL is greater than k
     // Step A : reverse first K node of LL
     Node* prev=NULL;
     Node* curr=head;
     Node* forward= curr->next;
     int count=0;

     while(count < k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
     }
     // Step B: attach other node with this
     if(forward!=NULL){
        // we still have nodes left to reverse
        head->next = reverseKNodes(forward,k);
     }
     // step C: return head of modified LL
     return prev;

}

bool checkForLoop(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return false;
    }

    Node* slow= head;
    Node* fast=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow == fast){
            // loop present
            return true;
        }
    }
    // fast NULL hogya
     return false;
}

Node* StartingPointLoop(Node* &head){
    
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    Node* slow= head;
    Node* fast=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next; 
            slow=slow->next;
        }
        if(slow == fast){
            // loop present
            slow = head;
            break;
        }
    }
    while(slow != fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;

    
}

Node* RemoveLoop(Node* &head){
    
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    Node* slow= head;
    Node* fast=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next; 
            slow=slow->next;
        }
        if(slow == fast){
            // loop present
            slow = head;
            break;
        }
    }

    Node* prev=fast;
    while(slow != fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;
    return slow;

}

int main(){
     Node* head= new Node(10);
     Node* second= new Node(20);
     Node* third= new Node(30);
     Node* fourth= new Node(40);
     Node* fifth= new Node(50);
     Node* sixth= new Node(60);
     Node* seventh= new Node(70);
     Node* eigth= new Node(80);
     Node* ninth= new Node(90);

     head->next=second;
     second->next=third;
     third->next=fourth;
     fourth->next=fifth;
     fifth->next=sixth;
     sixth->next=seventh;
     seventh->next=eigth;
     eigth->next=ninth;
     ninth->next= fourth;

   //  print(head);
     // cout<<endl;

     // cout<<"middle node is "<< getMiddle(head) -> data <<endl;

    //head = reverseKNodes(head,3  );
     //print(head);

     cout<<"LOOP is present or not " << checkForLoop(head);
     cout<<endl;
     cout<<" starting point of loop is "<< StartingPointLoop(head)->data;
     RemoveLoop(head);
     cout<<endl;
     print(head);
     cout<<endl;
     cout<<"LOOP is present or not " << checkForLoop(head);


    return 0;
}

