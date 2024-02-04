#include<iostream>
#include<algorithm>
using namespace std;


int expandAroundIndex( string s, int i, int j){
    int count=0;
    while(i >= 0 && j < s.length() && s[i]==s[j]){
        count++;
        i--;
        j++;
    }
    return count;


   bool cmp(char first, char second){
         
         return first < second;
   }

}

int main(){
 /*string s;
  int countSubstring(string s);
  int count=0;

  int n=s.length();
   
  for(int i=0;i<n;i++){
     // odd
     int oddkaAns= expandAroundIndex(s ,i,i);
     count=count+oddkaAns;


     // even
     int evenkaAns= expandAroundIndex(s,i,i+1);
     count=count+evenkaAns;
  }
   

   return count;*/



   string s="babbar";

   sort(s.begin(), s.end());
   cout<< s <<endl;
 


}