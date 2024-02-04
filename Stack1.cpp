#include<iostream>
#include<stack> // stl command for stack implementaion
#include<string.h>
using namespace std;

class Stack{ // creating stack by using array
     public:

     int* arr;
     int top;
     int size;

     Stack(int size){
        arr = new int[size];
        this->size=size;
        top=-1;
     }

     // functions

     void push(int data){
            if(size -top >1){
                // space available
                // insert
                top++;
                arr[top] = data;
            }
            else{
                // space not available
                cout<<"stack overflow "<<endl; 
            }
     }

     void pop(){
        if(top == -1){
            // stack is empty
            cout<<"stack is underflow , can't delete element "<<endl;
        }
        else{
               // stack is not empty
               top--;
        }

     }

     int getTop(){
        if(top == -1){
            cout<<"There is no elemnet in stack "<<endl;
        }
        else{
            return arr[top];
        }

     }
         // returns number of valid element present in stack
     int getSize(){ 
              return top+1;

     }

     bool isEmpty(){ 
        if(top == -1){
            return true;
        }
        else{
            return false;
        }

     }

};

class Stack1{ // creating 2 stack by using only 1 array
          public:
          int* arr;
          int size;
          int top1;
          int top2;

          Stack1(int size){
            arr= new int[size];
            this->size = size;
            top1=-1;
            top2=size;
          }
          // function
          void push1(int data){
                 if(top2 - top1 == 1){
                    // space not avaliable
                    cout<<"OVERFLOW in stack 1 "<<endl;
                 }
                 else{
                    // space available
                    top1++;
                    arr[top1] = data;
                 }
          }

          void pop1(){
                if(top1 == -1){
                    // stack empty
                    cout<<"UNDERFLOW in stack 1"<<endl;
                }
                else{
                    // stack not empty
                    top1--;
                }
          }

          void push2(int data){
                  if(top2 - top1 == 1){
                    cout<<"OVERFLOW in stack 2"<<endl;
                  }
                  else{
                    top2--;
                    arr[top2] = data;
                  }
          }

          void pop2(){
            if(top2 == size){
                // stack 2 is empty
                cout<<"UNDERFLOW in stack 2"<<endl;
            }
            else{
                // stack 2 is not empty
                top2++;
            }

          } 

          void print(){
            cout<<endl;
            cout<<"top1: "<< top1 <<endl;
            cout<<"top2: "<< top2 <<endl;
            for(int i=0; i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
          }
};

void printMiddle(stack<int> &s, int &totalSize){
  if(s.size() == 0){
         cout<<"There is no element in stack ";
         return;
  }
   // base case
    if(s.size() == totalSize/2 + 1){
      cout<<"Middle elemnet is: "<< s.top()<<endl;
      return;
    }

    int temp=s.top();
    s.pop();

    // recursive call
    printMiddle(s, totalSize);

    // backtrack
    s.push(temp);

}

int main(){
       /*   // creation
          stack<int> st;

          // insertion
          st.push(10);
          st.push(20);
          st.push(30);
          st.push(40);

          // remove
          st.pop();

          // check element on top
          cout<<"element on top is : "<< st.top() <<endl;

          // size
          cout<<"size of stack is : "<< st.size()<<endl;

          if(st.empty())
          cout<<"stack is empty "<<endl;
          else{
            cout<<"stack is not empty "<<endl;
          }
*/

       /*  stack<int>s;
         s.push(10);
         s.push(20);
         s.push(30);
         s.push(40);

         // printing stack
            while(!s.empty()){//jab tak stack empty na hojaye
                  cout<<s.top()<<" ";
                  s.pop();
            }
      */
      
      // creating Stack by using array 
/*
     Stack s(10); // stack of size 10
     // insertion
     s.push(10);
     s.push(20);
     s.push(30);
     s.push(40);

       while(!s.isEmpty()){
        cout<< s.getTop()<<" ";
        s.pop();
       }
       cout<<endl;  

       cout<<"size of stack "<< s.getSize()<<endl;
 */
      /*  Stack1 s(10);
         
         s.push1(10);
         s.print();
         s.push1(20);
         s.print();
         s.push1(30);
         s.print();

         s.push2(100);
         s.print();
         s.push2(110);
         s.print();
         s.push2(120);
         s.print();
        */

       //reverse String Using Stack
    /*   string str="babbar";

       stack<char> s;
       for(int i=0; i<str.length(); i++){
        s.push(str[i]);
       }

       while(!s.empty()){
               cout << s.top()<<" ";
               s.pop();
       }
       cout<<endl;
*/

  // Ques--> Find Middle element in the stack without changing the stack
          
          stack<int> s;
          s.push(10);
          s.push(20);
          s.push(30);
          s.push(40);
          s.push(50);
          s.push(60);
          s.push(70);
          
          int totalSize= s.size();
          printMiddle(s, totalSize);

    return 0;
}