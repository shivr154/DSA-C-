#include<iostream>
using namespace std;

// for encapsulation
/*
class Animal{
         private:// this was full encapsulation we use private for full encapsulation
         int age;
         int weight;

          public:
         void eat(){
            cout<<"eating"<<endl;
         }

         int getage(){
            return this->age;
         }
         void setage(int age){
            this->age=age;
         }

};
*/

// for inheritance
// single level
   /* class Animal{
       public:
       int age;
       int weight;

       void eat(){
        cout<< "eating"<<endl;
       }
    };

    class Dog: private Animal{  // inheritance
        public:
        void print(){
         cout<< this->age<<endl;
        }
    };
  */
 // multilevel
    
   /* class Fruit{
      public:
      string name;
    };

    class Mango:public Fruit{
              public:
              int weight;
    };

    class Alphanso:public Mango{
                public:
                int sugarLevel;
    };
*/

// multiple
/*
  class A{
        public:
        int physics;
        int chemistry;

        A(){
         chemistry=100;
        }

  };

  class B{
      public:
      int chemistry;

      B(){
         chemistry=200;
      }

  };

  class C: public A , public B{
        public:
        int maths;
  }; 
  */

 // Heirarchieral
/*
 class car{
      public:
      int age;
      int weight;
      string name;

      void speedUp(){
             cout<< "speeding up "<< endl;
      }  
 };

 class Scorpio: public car{
    
 };

 class fortuner: public car{
 
 };
  */

 // POLYMORPHISM
/*
  class Maths{
         public:
    // function overloading
         int sum(int a, int b){
            cout<<"I am first signature "<<endl;
            return a+b;
         }

         int sum(int a, int b, int c){
            cout<<"I am Second signature "<<endl;
            return a+b+c;
         }

         int sum(int a ,float b){
            cout<<"I am third signature "<<endl;
            return a+b+10;
         }
  };
*/

  // operator Overloading

  class Param{
          public:
          int val;

          void operator+(Param& obj2){
              int value1=this->val;
              int value2=obj2.val;
              cout<<(value2-value1) <<endl;

          }

  };

int main(){
    
    // inheritance
    // single level

    /*Dog d1;
    d1.print();
   
   // multi-level

   Alphanso a;
   cout << a.name <<" "<< a.weight << " "<< a.sugarLevel <<endl; 
    */
   
   // multiple
/*
   C obj;
   cout<<obj.physics<<" "<< obj.A::chemistry <<" "<< obj.maths<< " " << obj.B::chemistry<< endl;
*/

   // Heirarchiral
 /*
   Scorpio S11;
   S11.speedUp();

   fortuner f11;
   f11.speedUp();
*/

  // POLYMORPHISM

// function overloading
  /*Maths obj;
  cout<< obj.sum(2,5.12f);
*/

// operator overloading

Param obj1, obj2;

obj1.val=7;
obj2.val=2; 

// this should print the diff b/w them
obj1 + obj2;




    return 0; 
}