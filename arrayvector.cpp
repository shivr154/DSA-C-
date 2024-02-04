#include<iostream>
#include<vector>

using namespace std;

int findUnique(vector<int> arr){
  int ans =0;

  for(int i=0;i<arr.size();i++){
    ans =ans ^ arr[i]; //using xor operator to elimate duplite nos
  }
  return ans;
}

int main(){
// create vector
  /*  vector<int> arr;

    int ans=(sizeof(arr)/sizeof(int));
    cout<<ans<<endl;

    cout<<arr.size()<<endl;
    cout<<arr.capacity()<<endl;
// insert

  arr.push_back(5);
  arr.push_back(6);

  //Print

  for(int i=0; i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  arr.pop_back();
  for(int i=0; i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
*/
 /* int n;
  cout<<"enter the value of n"<<endl;
  cin>>n;

  vector<int> brr(n,-101);
  cout<<"size of brr "<<brr.size()<<endl;
  cout<<"capacity of brr "<<brr.capacity()<<endl;

  for(int i=0;i<brr.size();i++){
    cout<<brr[i]<<" ";
  }
 cout<<endl;*/
 /*
  cout<<"printing crr ";
 vector<int> crr{10,20,40,50};
 for(int i=0; i<crr.size();i++){
 cout<<crr[i]<<" ";
 }
 cout<<endl;

 cout<<"vector crr is empty or not "<< crr.empty()<<endl;

 vector<int> drr;
 cout<<"vector drr is empty or not "<< drr.empty()<<endl;
*/
/*
//unique element

int n; 
cout<<"enter the size of array ";
cin>>n;

vector<int> arr(n);
cout<<"enter the elements"<<endl;
for(int i=0;i<arr.size();i++){
  cin>>arr[i];
}
int uniqueElement = findUnique(arr);

cout<<"unique element is "<< uniqueElement <<endl;
*/
/*
//UNION

int arr[]={1,3,5,7,9};
int sizea=5;
int brr[]={2,4,6,8};
int sizeb=4;

vector<int> ans;

//push all elment of vector arr
for(int i=0;i<sizea;i++){
ans.push_back(arr[i]);
}

//push all elment of vector brr
for(int i=0;i<sizeb;i++){
ans.push_back(brr[i]);
}
//print ans
cout<<"printing ans array"<<endl;
for(int i=0;i<ans.size();i++){
  cout<<ans[i]<<" ";
}
*/
/*
// intersection


vector<int> arr{1,2,3,3,4,6,8};
vector<int> brr{3,3,4,9,10};
vector<int> ans;

//outer loop on arr vector
for(int i=0; i<arr.size();i++){
  int element=arr[i];
  //for every element run loop on brr
  for(int j=0;j<brr.size();j++){
    if(element==brr[j]){
      //mark
      brr[j]=-1;
      ans.push_back(element);
    }
  }
}
//print ans
for(auto value: ans){
  cout<< value <<" ";
}
*/
/*
// pair sum
vector<int> arr{10,20,40,60,70};
int sum=80;

//print all pairs
//outer loop will traverse for each element
for(int i=0;i<arr.size();i++){
  int element=arr[i];
  //for every element, will traverse on age wale element
  for(int j=i+1;j<arr.size();j++){
    cout<<"("<< element << ","<<arr[j]<<")" <<endl;
    if(element + arr[j]==sum){
      cout<<"pair found "<<element<< ","<<arr[j]<<endl;
    }
  }
}
*/

/*
vector<int> arr{10,20,30,40,50};
int sum=80;
for(int i=0;i<arr.size();i++){
  int element1=arr[i];

  for(int j=i+1;j<arr.size();j++){
    int element2=arr[j];

    for(int k=j+1;k<arr.size();k++){
      int element3=arr[k];

      if(element1+element2+element3==sum){
        cout<<element1<<","<<element2<<","<<element3<<endl;
      }
    }
  }
}
*/

//sort 0 and 1s

vector<int> arr{0,1,0,1,1,0,1,0,1,1};
int start=0;
int end=arr.size()-1;
int i=0;

while(i!=end){
  if(arr[i]==0){
    //swap from left
    swap(arr[start],arr[i]);
    i++;
    start++;
  }
  else{
    //swap from right
    swap(arr[i],arr[end]);
    end--;
    
  }
}
//print
for(auto value : arr){
  cout<<value<< " ";
}

    return 0;
}