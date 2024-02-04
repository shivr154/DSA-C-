#include<iostream>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

void reverseQueue(queue<int>& q){
       stack<int> s;
       // step 1: put all element of q in stack
       while(!q.empty()){
           int element = q.front();
           q.pop();

           s.push(element);
       }

       // step 2: put all element from stack into q

       while(!s.empty()){
              int element = s.top();
              s.pop();

              q.push(element);
       }
}

void reverseQueueRecursion(queue<int>& q){
    // base case
        if (q.empty()) return;
    // 1 case sol
        int element = q.front();
        q.pop();

        reverseQueueRecursion(q);
        q.push(element);

}

 void reverseK(queue<int> &q , int k){
     // Step 1: Queue-->k element --> stack
     int n = q.size();
     stack<int> s;
     int count = 0;
     if(k == 0 || k > n) return; 

     while(!q.empty()){
           int temp = q.front();
           q.pop();
           s.push(temp);
           count++;
           if(count == k){
                 break;
           }
     }
       // step 2: q me vapas daaldo
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            q.push(temp);
        }

        // step 3: push N-K element from q front to back
         count =0;
         while(!q.empty() && n-k != 0){
              int temp = q.front();
              q.pop();
              q.push(temp);
              count++;
              if(count == n-k){
                break;
              }
         }
 }

  void interLeaveQueue(queue<int>& q){
    // step 1:  Separate both halves
    int n= q.size();
    if(q.empty()) return;
    int k= n/2;
    int count =0;
    queue<int> q2;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;
        if(count == k) break;
    }

    // Step 2: interleaving start kardo
    while(!q.empty() && !q2.empty()){
             int first = q2.front();
             q2.pop();
             
             q.push(first);
              
             int second = q.front();
             q.pop();

             q.push(second);
    }
        // odd wala case
        if(n&1){
            int element = q.front();
            q.pop();
            q.push(element);
        }
  }
  
  // sliding window
   void solve(int arr[], int n, int k){
         deque<int> q;

         // process first window of size k
         for(int i=0; i<k; i++){
            if(arr[i] < 0){
                q.push_back(i);
            }
         }

         // remaining window ko process karo
         for(int i=k; i<n; i++){
            // answer dedo purani window ka
            if(q.empty()){
                 cout<<0<<" ";
            }
            else{
                cout<<arr[q.front()] << " ";
            }

            // out of window element ko remove kardo
            while((!q.empty())&&(i - q.front() >= k)){
                q.pop_front();
            }

            // check curr element for insertion
            if(arr[i] < 0){
                q.push_back(i);
            }
         }
         // answer print kardo for last window
          if(q.empty()){
                 cout<<0<<" ";
            }
            else{
                cout<<arr[q.front()] << " ";
            }
   }


int main(){
    // Ques --> 1 Reverse Queue
    /*
  queue<int> q;
  q.push(3);
  q.push(6);
  q.push(9);
  q.push(2);
  q.push(8);
 
  reverseQueueRecursion(q);

  cout<<"Printing Queue After Reversal "<<endl;
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
*/
   // Ques--> 2 Reverse first K element of Queue
 /*    queue<int> q;
     q.push(3);
     q.push(6);
     q.push(9);
     q.push(2);
     q.push(8);

     reverseK(q,3);

  cout<<"Printing Queue "<<endl;
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
*/

 // Ques--> 3  InterLeave First and Second Half of Queue
 /*  queue<int> q;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
     q.push(6);
     q.push(7);
     q.push(8);
     q.push(9);

   interLeaveQueue(q);

   cout<<"Printing Queue "<<endl;
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
*/
   
   // Ques -->4 First -ve no in every window of size k (Sliding Window);
      int arr[] = {12,-1,-7,8,-15,30,16,28};
      int size= 8;
      int k= 3;

      solve(arr,size,k);


  return 0;
}