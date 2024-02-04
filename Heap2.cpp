#include<iostream>
#include<queue>
using namespace std;


int getkthSmallestElement(int arr[], int n, int k){
      // create max heap
      priority_queue<int> pq;
      // insert initial k elements of array
      for(int i=0; i<k;i++){
          pq.push(arr[i]);
      }
      // for remaining elements push only if they are less than top
      for(int i=k; i<n;i++){
            int element = arr[i];
            if(element < pq.top()){
                pq.pop();
                pq.push(element);
            }
      }
      int ans =pq.top();
      return ans;

}

int getkthGreatestElement(int arr[], int n, int k){
       
      // create min heap
      priority_queue<int,vector<int>, greater<int> > pq;
      // insert initial k elements of array
      for(int i=0; i<k;i++){
          pq.push(arr[i]);
      }
      // for remaining elements push only if they are greater than top
      for(int i=k; i<n;i++){
            int element = arr[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
      }
      int ans =pq.top();
      return ans;
}

// check if complete Binary Tree is Max heap or not
// pair<bool ,int> solve(Node* root){
//     // base case
//     if(root==NULL){
//         pair<bool, int> p = make_pair(true, INT_MIN);
//         return p;
//     }
//     if(root->left == NULL && root->right == NULL){
//         // leaf Node
//         pair<bool,int>p = make_pair(true, root->data);  
//         return p;
//     }

//     pair<bool, int> leftAns = solve(root->left);
//     pair<bool, int> rightAns = solve(root->right);

//     if(leftAns.first == true && rightAns.first == true && root->data > leftAns.second && root->data > rightAns){
//         pair<bool ,int> p = make_pair(true, root->data);
//         return p;
//     }
//     else{
//         pair<bool,int> p = make_pair(false, root->data);
//         return p;
//     }
// }


int main(){
     // max-heap
    //  priority_queue<int> pq;
    //  pq.push(3);
    //  pq.push(6);
    //  pq.push(9);
    //  pq.push(4);
    //  pq.push(8);

    //  cout<<"top element "<< pq.top()<< endl;
    //  pq.pop();
    //  cout<<"top element "<< pq.top()<< endl;
    //  pq.pop();
    //  cout<<"top element "<< pq.top()<< endl;
    //  cout<<"size is "<< pq.size()<< endl;
    //  if(pq.empty()){
    //     cout<<"max heap is empty "<<endl;
    //  }
    //  else{
    //     cout<<"max heap is not empty"<<endl;
    //  }

    // min-heap
    // priority_queue<int,vector<int>, greater<int>> pq;
    //  pq.push(3);
    //  pq.push(6);
    //  pq.push(9);
    //  pq.push(4);
    //  pq.push(8);
     
    //  cout<<"top element: "<< pq.top()<<endl;
    //  pq.pop();
    //  cout<<"top element: "<< pq.top()<<endl;
    //  cout<<"size "<< pq.size()<< endl;
    //  if(pq.empty()){
    //     cout<<"min heap is empty "<<endl;
    //   }
    //  else{
    //     cout<<"min heap is not empty"<<endl;
    //   }

    // Ques-->1 kth smallest element
       int arr[]= {10,5,20,4,15};
       int n=5;
       int k=2;
       int ans = getkthSmallestElement(arr,n,k);
       cout<<"smallest no is: "<< ans<<endl;
       int ans1 = getkthGreatestElement(arr,n,k);
       cout<<"greatest no is "<< ans1<<endl;
    
    // Ques-->2 Merge 2 heap
    // Ques-->3 check if complete binary tree if max heap or not
    

    return 0;
}