#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Q--> 1 First non repeaing character in a stream
    string str="aabc";
    int freq[26] = {0};
    queue<char> q;
    
    string ans="";

    for(int i=0; i<str.length();i++){
        char ch = str[i];

        // increment frequency
          freq[ch - 'a']++;
          // q.push
          q.push(ch);

          while(!q.empty()){
             if(freq[q.front() - 'a'] > 1){
                   q.pop();
              }
              else{
                   ans.push_back(q.front());
                   break;
              }
          }
          if(q.empty()){
                ans.push_back('#');
          }     
        }

        cout<<"Final Ans is: "<< ans<<endl;


     // Ques --> 2 gas station (Leetcode-->134)
     // Ques --> 3 Sliding Window Maximum(Leetcode--> 239)
     

    return 0;
}