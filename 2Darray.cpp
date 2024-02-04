#include <iostream>
#include<limits.h>
using namespace std;

bool findKey(int arr[][3], int row, int column, int key){
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(arr[i][j]==key){
        return true;
      }
      //value is not present
    }
  }
 return false;
  
}

void printRowWiseSum(int arr[][3], int row, int column){
  cout<<"printing row wise sum"<<endl;
  //row sum--> row wise travesrsal
  for(int i=0;i<row;i++){
    int sum=0;
    for(int j=0;j<column;j++){
      sum=sum+ arr[i][j];
    }
cout<<sum<< endl;
  }
}

void printcolumnWiseSum(int arr[][3], int row, int column){
  cout<<"printing column wise sum"<<endl;
  //column sum--> col wise travesrsal
  for(int i=0;i<row;i++){
    int sum=0;
    for(int j=0;j<column;j++){
      sum=sum+ arr[j][i];
    }
cout<<sum<< endl;
  }
}

int getMax(int arr[][3],int row,int column){
  int maxi=INT_MIN;
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(arr[i][j] > maxi){
        maxi = arr[i][j];
      }
    }
  }
  return maxi;
}

int getMin(int arr[][3],int row,int column){
  int mini=INT_MAX;
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(arr[i][j] < mini){
        mini = arr[i][j];
      }
    }
  }
  return mini;
}

void transpose(int arr[][3], int r , int c, int transposeArr[][3]){
  for(int i=0;i<r;i++){
    for (int j=0;j<c;j++){
      //swap(arr[i][j],arr[j][i]);
      transposeArr[j][i]=arr[i][j];
    }
  }
}

void printArray(int arr[][3],int r, int c){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main() {
  // declare 2D array
 /* int arr[3][3];
  // initialization
  int brr[3][3]={
  {1,2,3},
  {4,5,6},
  {2,4,7}
  };
  
  // row wise printing
  // outer loop
  cout<<"printing row wise"<<endl;
  for(int i=0;i<3;i++){
    //for every row we need to print value in each column 
    for(int j=0;j<3;j++){
      cout<<brr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  //column wise printing
  cout<<"printing column wise"<<endl;
  for(int i=0;i<3;i++){
    //for every row we need to print value in each column 
    for(int j=0;j<3;j++){
      cout<<brr[j][i]<<" ";// just replace i and j to print column wise
    }
    cout<<endl;
  }
*/



  int arr[3][3];
  int row=3;
  int column=3;

  /*
  //input

  // row wise input
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cin>>arr[i][j];
    }
  }
  //printing row wise
  cout<<"printing row wise"<<endl;
   for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  */

  
 /* // printing column wise
  // input column wise
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cin>>arr[j][i];
    }
  }
  //printing column wise
  cout<<"printing column wise"<<endl;
   for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cout<<arr[j][i]<<" ";
    }
    cout<<endl;
  }*/


 /*
 printRowWiseSum(arr,row,column);
 printcolumnWiseSum(arr,row,column);

int key=7;
if(findKey(arr,3,3,key)){
  cout<<"true"<<endl;
}
else{
  cout<<"false"<<endl;
}
*/

/*
cout<<"maximum no: "<<getMax(arr,row ,column);
cout<<endl;
cout<<"minimum no: "<<getMin(arr,row ,column);
cout<<endl;
*/


cout<<"printing array"<<endl;
 printArray(arr,row,column);
 cout<<"starting transpose"<<endl;
int transposeArr[3][3];
transpose(arr,row,column,transposeArr);
 cout<<"printing array"<<endl;
 printArray(transposeArr ,row ,column);



  return 0;
}