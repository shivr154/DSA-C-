#include<iostream>
#include<limits.h>
#include<vector>
#include<stack>
using namespace std;

// Ques--> 4
vector<int> prevSmaller(vector<int>& input){
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    // left to right 
    for(int i=0; i<input.size();i++){
        int curr = input[i];
            // answer stack mai se lao
           while(s.top() >= curr){
                     s.pop();
           }

           // chhota element mil gya
             ans[i] = s.top();

             // push kardo curr element ko
             s.push(curr);
    }
    return ans; 
}
// Ques--> 3
vector<int> nextSmaller(vector<int>& input){
       
     stack<int> s;
     s.push(-1);
     vector<int> ans(input.size());

     for(int i= input.size()-1; i>=0;i--){ // loop for moving right to left
           int curr = input[i];
            // answer stack mai se lao
           while(s.top() >= curr){
                     s.pop();
           }

           // chhota element mil gya
             ans[i] = s.top();

             // push kardo curr element ko
             s.push(curr);
     }
     return ans;
}
  
  // Ques --> 5 for rectangular area of histogram

vector<int> prevSmaller1(vector<int>& input){
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    // left to right 
    for(int i=0; i<input.size();i++){
        int curr = input[i];
            // answer stack mai se lao
           while(s.top() != -1 && input[s.top()] >= curr){
                     s.pop();
           }

           // chhota element mil gya
             ans[i] = s.top();

             // push kardo curr element ko
             s.push(i);
    }
    return ans; 
}

vector<int> nextSmaller1(vector<int>& input){
       
     stack<int> s;
     s.push(-1);
     vector<int> ans(input.size());

     for(int i= input.size()-1; i>=0;i--){ // loop for moving right to left
           int curr = input[i];
            // answer stack mai se lao
           while(s.top() != -1 && input[s.top()] >= curr){
                     s.pop();
           }

           // chhota element mil gya
             ans[i] = s.top();

             // push kardo curr element ko
             s.push(i);
     }
     return ans;
}
 

int getrectangularAreaHistogram(vector<int>& height){
     
      // STEP 1  : prev smaller output
      vector<int> prev= prevSmaller1(height);

      // step 2: next smaller ouput
      vector<int> next= nextSmaller1(height);

      int maxArea = INT_MIN;
      int size = height.size();

      for(int i=0; i<height.size();i++){
          int length = height[i];

           if(next[i] == -1){
            next[i] = size;
           }

          int width = next[i] - prev[i] - 1;

          int area = length * width;
          maxArea = max(maxArea, area);
      }
      return maxArea;
}

int main(){
    // Ques--> 3 and 4 next smaller and previous smaller element
  /*   vector<int> input;
     input.push_back(2);
     input.push_back(1);
     input.push_back(4);
     input.push_back(3);
     
     vector<int> ans1 = nextSmaller(input);
     cout<<"printing ans1 "<<endl; 
      for(int i=0; i<input.size();i++){
        cout<<ans1[i]<<" ";
      }
      cout<<endl;

      vector<int> ans2= prevSmaller(input);
      cout<<"printing ans2 "<<endl;
      for(int i=0; i<input.size();i++){
        cout<<ans2[i]<<" ";
      }
      cout<<endl;

*/

     // Ques--> 5 largest rectangular area in histogram (Leetcode --> 84)

     vector<int> v;
     v.push_back(2);
     v.push_back(1);
     v.push_back(5);
     v.push_back(6);
     v.push_back(2);
     v.push_back(3);

     cout<<" Ans is: " << getrectangularAreaHistogram(v)<<endl;

    return 0;
}