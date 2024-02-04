#include<iostream>
using namespace std;

class Animal{
    public:

   virtual void speak(){
        cout<<"speaking"<<endl;
    }
};

class Dog:public Animal{
       
       public:
       // overrdide

       void speak(){
        cout<<"barking"<<endl;
       }
};


int main(){

 /* Animal a;
  a.speak();

  Dog b;
    b.speak();
*/

//Animal* a= new Animal();
//a->speak();

 //Dog* a=new Dog();
 //a->speak();

/*
 // Upcasting
 Animal* a=new Dog();
 a->speak();

 // Downcasting
 Dog* b= (Dog* )new Animal();
 b->speak();
*/

// Creating 2D array by Dynamic Memmory Allocation
   /*   
      int row=5;
      int col=3;
      int** arr=new int*[5];
      
      for(int i=0; i<row; i++){
        arr[i]= new int[col];
      }

       // printing
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
       }
*/
       // de-allocate
      
       for(int i=0;i<n;i++){
        delete []arr[i];
       }
       delete []arr;

    return 0;
}