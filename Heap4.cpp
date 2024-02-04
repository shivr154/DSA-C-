#include<iostream>
#include<queue>
using namespace std;

int signum(int a, int b){
    if(a == b)
            return 0;
    if(a > b)
            return 1;
    if(a < b)
            return -1;
}


void callMedian(int &median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap, int element){

         switch(signum(minHeap.size(), maxHeap.size())){
              case 0:  if(element > median){
                         minHeap.push(element);
                         median = minHeap.top();
                         }
                        else{
                           maxHeap.push(element);
                           median = maxHeap.top(); 
                         }
                       break;
              
              case 1:  if(element > median){
                          int minTop = minHeap.top();
                           minHeap.pop();
                           maxHeap.push(minTop);
                           minHeap.push(element);
                           median = (minHeap.top() + maxHeap.top())/2;
                         }
                        else{
                           maxHeap.push(element);
                           median = (minHeap.top() + maxHeap.top())/2;
                            }
                        break;
              
              case -1:    if(element > median){
                           minHeap.push(element);
                           median = (minHeap.top() + maxHeap.top())/2;
                        }
                        else{
                           int maxTop = maxHeap.top();
                           maxHeap.pop();
                           minHeap.push(maxTop);
                           maxHeap.push(element);
                           median = (minHeap.top() + maxHeap.top())/2;
                        }
                        break;

         }

}

int main(){
    // Ques-->1 Removing stones to minimize the total(Leetcode--> 1962)
    // Ques-->2 Reorganize string (Leetcode--> 767)
    // Ques-->3 Longest Happy String (Leetcode--> 1405)
    // Ques-->4 Median in a Stream

    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int>, greater<int> > minHeap;
    for(int i=0; i<n; i++){
          int element = arr[i];
         callMedian(median, maxHeap, minHeap, element);
          cout<<"arr[i]->median " << median;
           cout<<endl;
    }
    cout<<endl;


    return 0;
}