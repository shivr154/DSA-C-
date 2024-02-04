#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target){
    // base case
    if(s.empty()){  // agar stack empty hai to target push kardo
        s.push(target);
        return;
    }
    // A step
    int topElement= s.top();
    // B step
    s.pop();
    // recursive call
    insertAtBottom(s, target);
    // backtrack
    s.push(topElement);
}

void reverseStack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);
    // insert AT Bottom target ko
    insertAtBottom(s, target);
}

void insertSorted(stack<int>& s, int target){
       // base case
        if(s.empty()){  // if stack is empty then insert element kyuki vo sorted hi mana jayega
             s.push(target);
             return;
        }
         
         if(s.top() >= target){  
            s.push(target);
            return;
         }

         int topElement = s.top();
         s.pop();
         // Recursive call
         insertSorted(s,target);
         // BT
         s.push(topElement); 
}

void sortStack(stack<int> &s){
     // base case
     if(s.empty()){
        return;
     }

     int topElement= s.top();
     s.pop();

     sortStack(s);

     insertSorted(s,topElement);
}

int main(){
    // Ques-->1 insert at Bottom
  /*  stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    if(s.empty()){
        cout<<"stack is empty, cant insert at bottom "<<endl;
        return 0;
    }
    int target = s.top();
    s.pop();

    insertAtBottom(s,target);
    
    cout<<"Printing"<<endl;
    while(!s.empty()){
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
*/
    // Ques-->2 reverse a stack
    /* 
     stack<int> s;
     s.push(10);
     s.push(20);
     s.push(30);
     s.push(40);
     s.push(50);

    reverseStack(s);

    cout<<"Printing reverse stack"<<endl;
    while(!s.empty()){
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
*/
  // Ques-> 3 Valid Parenthesis (Leetcode --> 20)
  
  // Ques --> 4 Sort a Stack

     stack<int> s;
     
     s.push(7);
     s.push(11);
     s.push(3);
     s.push(5);
     s.push(9);

     sortStack(s);

     cout<<"Printing  stack"<<endl;
    while(!s.empty()){
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
     
    
  



  return 0;
}