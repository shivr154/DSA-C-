#include<iostream>
using namespace std;


void solve(int arr[]){
     cout<<"size inside solve function = "<< sizeof(arr)<<endl;
     
     cout<<"arr : "<< arr <<endl;
     cout<<"&arr : " << &arr <<endl;


     arr[0]=50;
 }


 
int main(){
   // int arr[4]={12,24,16,28};

    /*cout<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;

   int* p=arr;
   cout<< p <<endl;
   cout<< &p <<endl;*/

   /*cout<< *arr <<endl;
   cout<< arr[0] <<endl;
   cout<< *arr + 1 <<endl;
   cout<< *(arr) + 1 <<endl;
   cout<< *(arr + 1) <<endl;
    cout<< arr[1] <<endl;
   cout<< *(arr + 2) <<endl;
    cout<< arr[2] <<endl;
   cout<< *(arr + 3) <<endl;
  cout<< arr[3] <<endl;
*/

  /* int i=0;
   cout<<arr[i]<<endl;
   cout<<i[arr]<<endl;
   cout<< *(arr+i) <<endl;
   cout<< *(i+arr)<<endl;

   //arr=arr+2;

   int* p= arr;
   p=p+2;*/
    
   /*int arr[10];
   cout<< sizeof(arr)<<endl;

   int* p=arr;
   cout<<sizeof(p)<<endl;
   cout<<sizeof(*p)<<endl;
*/


  /*char ch[10]="Babbar";
  char* c=ch;

  
  cout<< ch <<endl;
  cout<< ch[0] <<endl;
  cout<< &ch <<endl;
  
  cout<<endl;

  cout<< &c <<endl;
  cout<< *c <<endl;
  cout<< c <<endl;*/

/*  char name[9]="SherBano";
  char* c=&name[0];

  cout<< name <<endl;
  cout<< &name <<endl;
  cout<< *(name+3) <<endl;  
  cout<< c <<endl;
  cout<< &c <<endl;
  cout<< *(c+3) <<endl;
  cout<< c+2 <<endl;
  cout<< *c <<endl;
   cout<< c+8 <<endl;*/

   /*char ch='k';
   char* cptr=&ch;

   cout<< cptr <<endl;*/

   int arr[10]={1,2,4,5};
   cout<<"size inside main function = "<< sizeof(arr);
   cout<<endl;
   
   cout<<arr<<endl;
   cout<<&arr<<endl;

  // printing array inside main
  for(int i=0;i<10;i++){
    cout<< arr[i] << " ";
  }
  cout<<endl;
  cout<<"now calling solve function "<<endl;
 cout<<endl;
   solve(arr);
   // wapas main function me agya

 for(int i=0;i<10;i++){
    cout<< arr[i] << " ";
  }
  cout<<endl;

    return 0;
}