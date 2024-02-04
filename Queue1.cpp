#include<iostream>
#include<queue>
#include<deque> // Doubly ended Queue
using namespace std;

class Queue{
      public:
       int *arr; 
       int size;
       int front;
       int rear;

       Queue(int size){
               this -> size = size;
               arr = new int[size];
               front = 0;
               rear = 0;
       }

        void push(int data){
            if(rear == size){
                cout<<"Q is full " << endl;
            }
            else{
                  arr[rear] = data;
                  rear++;
            }
        }

        void pop(){
            if(front == rear){
                cout << "Q is empty "<<endl;
            }
            else{
                arr[front] = -1;
                front++;
                if(front == rear){
                    front =0;
                    rear =0;
                }
            }
        }

        int getFront(){
            if(front == rear){
                cout<<"Q is empty"<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else{
                return false;
            }
        }

        int getSize(){
            return rear - front;
        }


};

class CQueue{
          public:
           int size;
           int *arr;
           int front;
           int rear;

           CQueue(int size){
                 this-> size = size;
                 arr= new int[size];
                 front = -1;
                 rear = -1;
           }

           void push(int data){
               
                    // Queue full
                   if((front == 0 && rear == size - 1 )){
                       cout<< "Q is full , cannot insert" << endl;
                   }
                   else if(front == -1){  // single element case
                        front = rear = 0;
                        arr[rear] = data;
                   }
                   else if(rear == size - 1 && front != 0 ){      // circular nature
                         rear = 0;
                         arr[rear] = data;
                   }
                   else{                   // normal flow
                        rear++;
                        arr[rear] = data;
                   }
           }

           void pop(){
                   
                   // empty check
                   if(front == -1){
                    cout<<"Q is empty cant pop"<<endl;
                   }
                   else if(front == rear){   // single element
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                   }
                   else if(front == size-1){   // circular nature
                          front = 0;
                   }
                   else{    // normal flow
                        front++;
                   }
           }

};

  class DoublyEndedQueue{
           public:

           int* arr;
           int size;
           int front;
           int rear;

           DoublyEndedQueue(int size){
                  this->size = size;
                  arr = new int[size];
                  front = -1;
                  rear = -1;
           }

           void pushRear(int data){
                   // Queue full
                   if((front == 0 && rear == size - 1 )){
                       cout<< "Q is full , cannot insert" << endl;
                       return;
                   }
                   else if(front == -1){  // single element case
                        front = rear = 0;
                        arr[rear] = data;
                   }
                   else if(rear == size - 1 && front != 0 ){     // circular nature
                         rear = 0;
                         arr[rear] = data;
                   }
                   else{                   // normal flow
                        rear++;
                        arr[rear] = data;
                   }
           }

           void pushFront(int data){
                   // Queue full
                   if((front == 0 && rear == size - 1 )){
                       cout<< "Q is full , cannot insert" << endl;
                       return;
                   }
                   else if(front == -1){  // single element case
                        front = rear = 0;
                        arr[front] = data;
                   }
                   else if(front == 0 && rear != size-1 ){     // circular nature
                         front = size-1;
                         arr[front] = data;
                   }
                   else{                   // normal flow
                        front --;
                        arr[front] = data;
                   }
           }

           void popFront(){
                    // empty check
                   if(front == -1){
                    cout<<"Q is empty cant pop"<<endl;
                   }
                   else if(front == rear){   // single element
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                   }
                   else if(front == size-1){   // circular nature
                          front = 0;
                   }
                   else{    // normal flow
                        front++;
                   }
           }


           void popRear(){
                     // empty check
                   if(front == -1){
                    cout<<"Q is empty cant pop"<<endl;
                   }
                   else if(front == rear){   // single element
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                   }
                   else if(rear == 0){   // circular nature
                          rear = size - 1;
                   }
                   else{    // normal flow
                        rear-- ;
                   }
           }

  };

int main(){

     /*  // creation of Queue
       queue<int> q;

      // insertion in Queue is from the rear end 
       q.push(5);
       q.push(15);
       q.push(25);

       // size
       cout<<"size of queue is: "<< q.size()<<endl;

       q.pop();  // pop will be from front of the queue
       cout<<"size of queue is: "<< q.size()<<endl;

       if(q.empty()){
              cout<<"Q is empty" <<endl;
       }
       else{
        cout<<"Q is not empty"<<endl;
       }

      // front element
      cout<<"front element is: "<< q.front()<<endl;
*/

     /* Queue q(10);

      q.push(5);
      q.push(15);
      q.push(55);
*/

    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);
     
    cout<<"size "<< dq.size() << endl;
    dq.pop_front();

    cout<<"size "<< dq.size() << endl;
    dq.pop_back();

    cout<<"size "<< dq.size() << endl;
    cout<<"Front : " << dq.front() <<endl;
    cout<<"back : "<< dq.back() <<endl;

    if(dq.empty()){
        cout<<"DQ is empty "<<endl;
    }
    else{
        cout<< " DQ is not empty"<<endl;
    }
    

    return 0;
}