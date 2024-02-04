#include<iostream>
#include<vector>
#include<queue> 
using namespace std;

class info{
        public:
        int data; // kis int ke bare mai baat hori hai
        int row;  // kis array ke bare mai baat hori hai
        int col;  // array ke konse index ke bare mai baat hori hai

        info(int val ,int r, int c){
            data= val;
            row = r;
            col = c;
        }
};

class compare{
    public:
    bool operator()(info* a,info* b){
         return a->data > b->data;
    }

};

vector<int> mergeSortedArrays(int arr[][4], int k, int n){
      priority_queue<info*, vector<info*>, compare> minHeap;

     // hr array ka first element insert karo
     for(int i=0; i<k; i++){
        info* temp = new info(arr[i][0], i, 0);
        minHeap.push(temp);
     }

     vector<int> ans;

     while(!minHeap.empty()){
          info* temp = minHeap.top();
          int topElement = temp->data;
          int topRow = temp->row;
          int topCol = temp->col;
          minHeap.pop(); 

          ans.push_back(topElement);
          if(topCol+1 < n){
             info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
             minHeap.push(newInfo);
          }
     }
     return ans;

}


int main(){
      int arr[][4] = {{2,4,6,8},{1,3,5,7},{0,9,10,11}};
      int k =3;
      int n = 4;

      vector<int> ans = mergeSortedArrays(arr, k ,n);
      for(auto i:ans){
            cout<< i <<" ";
      }
      cout<<endl;
      

  return 0;
}

// QUes --> Leetcode(632)
// class node{
//      public:
//      int data;
//      int row;
//      int col;

//      node(int d, int r , int c){
//          data = d;
//          row = r;
//          col = c;
//      }

// };

// class compare{
//     public:
//     bool operator()(node*a, node*b){
//         return a->data > b->data;
//     }   
// };

// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int mini = INT_MAX;
//         int maxi = INT_MIN;

//         priority_queue<node*, vector<node*>, compare> minHeap;
//         int k = nums.size();

//         for(int i=0; i<k; i++){
//             int element = nums[i][0];
//             maxi = max(maxi , element);
//             mini = min(mini, element);
//             minHeap.push(new node(element, i ,0));
//         }

//         int ansStart = mini;
//         int ansEnd = maxi;

//         while(!minHeap.empty()){
//             node* top = minHeap.top();
//             int topElement = top->data;
//             int topRow = top->row;
//             int topCol = top->col;
//             minHeap.pop();
//             // mini update
//             mini = topElement;

//             // check for ans
//             int currRange = maxi - mini;
//             int ansRange = ansEnd - ansStart;
//             if(currRange < ansRange){
//                  ansStart= mini;
//                  ansEnd = maxi;
//             }

//             // check for new element in the same list
//             if(topCol +1 < nums[topRow].size()){
//                 maxi = max(maxi, nums[topRow][topCol+1]);
//                 node* newNode = new node(nums[topRow][topCol+1], topRow, topCol+1);
//                 minHeap.push(newNode);
//             }
//             else{
//                 // there is no element in the same array or list
//                 break;
//             }  
//         }
//           vector<int> ans;
//           ans.push_back(ansStart);
//           ans.push_back(ansEnd);
//           return ans;

//     }
// };