#include<iostream>
#include<vector>
using namespace std;


 // code for check array is sorted or not by recursion`
  bool checkSorted(vector<int>& arr, int& n, int i){
    // base case
    if(i == n-1)
    return true;

    // 1 case solve kardo
    if(arr[i+1] < arr[i]){
        return false;
    }
    // baaki recursion sambhal lega
    return checkSorted(arr,n,i+1);
  }

  // code for binary search by recursion
   int binarySearch(vector<int> arr, int s, int e , int key){
    // base case
    //case 1-> key not found

    // invalid array
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;

    // case 2-> key found
    if(arr[mid] == key){
        return mid;
    }
    // arr[mid]<key --> right search
        if(arr[mid] < key){
            return binarySearch(arr,mid+1,e,key);
        }
    // arr[mid]>key --> left search
    else{
        return binarySearch(arr,s,mid-1,key);
    }
   }

  // print subsequences of a string

  void printSubsequences(string str, string output, int i, vector<string>& v){
    //  base case
    if(i >= str.length() ){
       //  cout<< output <<endl;
       // store
       v.push_back(output);
        return;
    }

    //exclude
    printSubsequences(str,output,i+1,v);

    // include
    output.push_back(str[i]);
    printSubsequences(str,output,i+1,v);

  }



int main(){

    // array is sorted or not by recursion
 /*   vector<int> v{10,20,20,40};
    int n=v.size();
    int i=0;
    bool isSorted=checkSorted(v,n,i);

    if(isSorted){
        cout<<"array is sorted "<<endl;

    }
    else{
        cout<<"array is not sorted "<<endl;
    }
*/
   
   // binary search code by recursion
 /*   vector<int> v{10,20,40,60,70,90,99};
    int target=99;
    int n=v.size();
    int s=0;
    int e=n-1;
    int ans=binarySearch(v,s,e,target);

    cout<<"ans is : "<<ans<<endl;
  */
    
    // subsequences of a string
    
    string str="abc";
    string output= " ";
    vector<string> v;

    int i=0;
    printSubsequences(str,output,i,v);

    cout<<"printing all subsequences "<< endl;
    
    for(auto val: v){
        cout<< val << " ";  
    }    
    cout<<endl<<"size of vector is : "<< v.size() <<endl;

    


    return 0;
}
