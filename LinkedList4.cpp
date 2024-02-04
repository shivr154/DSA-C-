#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next= curr->next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool checkPalindrome(Node* &head){
       if(head==NULL){
        cout<<"LL is empty"<<endl;
        return true;
       }
       if(head->next==NULL){
        // only 1 node
        return true;
       }
         // for greater than 1 node
        // step A: find the middle node
        Node* slow=head;
        Node* fast=head->next;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        // slow pointer is pointing to middle node

        // step B: reverse LL after middle/slow node
        Node* reverseLLKaHead = reverse(slow->next);

        // step C: slow ke age reverse LL ka head lga do
        slow->next=reverseLLKaHead;
        // step D: start comparision
        Node* temp1= head;
        Node* temp2= reverseLLKaHead;

        while(temp2!=NULL){
            if(temp1->data != temp2->data){
                // not a palindrome
                return false;
            }
            else{
                // if data is equal
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return true;
}

void removeDuplicate(Node* &head){
    if(head==NULL){
        cout<<"LL is empty "<<endl;
        return;
    }
    if(head->next==NULL){
        cout<<"single node in LL"<<endl;
        return;
    }
    // greater than 1 node
    Node* curr=head;

    while(curr!=NULL){
        if((curr->next != NULL) && (curr->data == curr -> next -> data)){
                 // equal
                 Node* temp= curr->next;
                 curr->next = curr->next->next; 
                 // delete node
                 temp->next= NULL;
                 delete temp;  
        }
        else{
            // not equal
            curr=curr->next;
        }
    }
}

void sortZeroOneTwo(Node* &head){
    // step 1 find count of 0,1 and 2s
     int zero= 0;
     int one= 0;
     int two= 0;

     Node* temp=head;
     while(temp != NULL){
        if(temp->data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else if(temp->data == 2)
             two++;
        temp=temp->next;
     }

     // step 2: fill 0, 1 and 2s in the original LL
           temp=head;
        // fill zeroes
         while(zero--){
            temp->data =0;
            temp= temp->next;
         }

        // fill ones
        while(one--){
            temp->data=1;
            temp= temp->next;
        }
        // fill twos
         while(two--){
            temp->data=2;
            temp= temp->next;
         }
}

Node* sort2(Node* &head){

    // creating Dummy Nodes   
       Node* zerohead= new Node(-1);
       Node* zerotail= zerohead;

       Node* onehead= new Node(-1);
       Node* onetail= onehead;

       Node* twohead= new Node(-1);
       Node* twotail= twohead;

       // traverse the original LL
       Node* curr=head;

       while(curr!=NULL){
        if(curr->data == 0){
            // take out the zero wali node
             Node* temp=curr;
             curr=curr->next;
             temp->next=NULL;
             // append the Zero wali node in zero  head LL
             zerotail->next=temp;
             zerotail = temp;

        }
        else if(curr->data == 1){
           // take out the one wali node
             Node* temp=curr;
             curr=curr->next;
             temp->next=NULL;
             // append the one wali node in one head LL
             onetail->next=temp;
             onetail = temp;

        }
        else if(curr->data == 2){
            // take out the two wali node
             Node* temp=curr;
             curr=curr->next;
             temp->next=NULL;
             // append the two wali node in two head LL
             twotail->next=temp;
             twotail = temp;

        }
       }
       // ab yaha par zero , one , two , teeno LL ready hai

       // modify one wali list
       Node* temp=onehead;
       onehead= onehead->next;
       temp->next=NULL;
       delete temp;

       // modify two wali list
       temp=twohead;
       twohead=twohead->next;
       temp->next=NULL;
       delete temp;

       // join list
       if(onehead != NULL){
        // one wali list is non empty
        zerotail->next = onehead;
        if(twohead != NULL)
              onetail->next = twohead;
       }
       else{
             // one wali list is empty
             if(twohead != NULL)
                  zerotail->next =twohead;
       }
         
         // remove zerohead dummy node
         temp= zerohead;
         zerohead= zerohead->next;
         temp->next =NULL;
         delete temp;

       // return head of the Modified LL
          return zerohead;
}

  Node* Solve(Node* &head1, Node* &head2){
         // step 1: reverse both Linked List
          head1=reverse(head1);
          head2=reverse(head2);

         // step 2: add both LL
         Node* anshead=NULL;
         Node* anstail=NULL;
         int carry= 0;

         while(head1 != NULL && head2 != NULL){
            // calculate sum
            int sum = carry + head1 ->data + head2 ->data;
            // find digit to create node
            int digit= sum % 10;
            // calculate carry
            carry= sum/10;

          // create a new Node for the digit
            Node* newNode= new Node(digit); 
            // attach the new node into the ans LL 
            if(anshead == NULL){
                // first node insert kar rhe hoo
                anshead= newNode;
                anstail=newNode;
            }
            else{
                anstail->next=newNode;
                anstail=newNode;
            }
            head1=head1->next;
            head2=head2->next;

         }

       // jab head1 list ki length head2 list se jada hoo
         while(head1 != NULL){
            int sum= carry + head1->data;
            int digit = sum % 10;
            int carry= sum / 10;
            Node* newNode= new Node(digit);
            anstail->next = newNode;
            anstail=newNode;
            head1=head1->next;
         }
         // jab head2 list ki length head2 se jada hoo
          while(head2 != NULL){
            int sum= carry + head2->data;
            int digit = sum % 10;
            int carry= sum / 10;
            Node* newNode= new Node(digit);
            anstail->next = newNode;
            anstail=newNode;
            head2=head2->next;
         }

         // handle carry
         while(carry != 0){
               int sum=carry;
               int digit=sum % 10;
               carry = sum / 10;
               Node* newNode= new Node(digit);
               anstail->next = newNode;
               anstail=newNode;

         }

         // step 3: reverse the ans LL
         anshead= reverse(anshead);
             return anshead;

  }

int main(){

     // use thsi input only for QUES--> 1,2 and 3
  /*   Node* head= new Node(1);
     Node* second= new Node(2);
     Node* third= new Node(1);
     Node* fourth= new Node(0);
     Node* fifth= new Node(2);
     Node* sixth= new Node(0);
      
     head->next=second;
     second->next=third;
     third->next=fourth;
     fourth->next=fifth;
     fifth->next=sixth;
*/
// QUES--> 1  check if given LL is palindrome or not
/*
     bool isPalindrome = checkPalindrome(head);

     if(isPalindrome){
        cout<<"LL is valid Palindrome " << endl;
     }
     else{
        cout<<"LL is not a Palindrome "<< endl;
     }
*/
    
    // QUES--> 2 Remove Duplicate from a Sorted LL

    /*  cout<<"Input LL Is: "<<endl;
      print(head);
      
      removeDuplicate(head);
      cout<<"output LL: ";
      print(head);
*/

    // QUES--> 3  Sort 0, 1 and 2s

    // method 1 with data replacement / counting
     /*  cout<<"input LL: ";
       print(head);
        
       sortZeroOneTwo(head);
       print(head);
*/
       // Method :2 sorting without data replacement
  /*   cout<<"previous list ";
     print(head);
     head=sort2(head);
     cout<<"sorted list ";
     print(head);
     cout<<endl;
    */

    // QUES-->4  ADD 2 numbers represented by LL

    Node* head1=new Node(2);
    Node* second1= new Node(4);
    head1->next = second1;

    Node* head2= new Node(2);
    Node* second2= new Node(3);
    Node* third2= new Node(4);
    head2->next=second2;
    second2->next=third2;

   Node* ans= Solve(head1, head2);
    print(ans);

    return 0;
}
