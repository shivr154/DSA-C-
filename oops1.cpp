#include<iostream>
using namespace std;

class Animal{   
  // state Or properties
  private:
  int weight;

  public:  // all members are marked public

  int age;
  string type;

  // default constructor

  Animal(){
    this->weight=0;
    this->age=0;
    this->type="";

     cout<<"constructor called "<<endl; // constructor called automatically
  }

  // parameterised constructor
  Animal(int age){
    this->age=age;
    cout<<"parameterised constructor called "<<endl;
  }

 Animal(int age, int weight){
    this->age=age;
    this->weight=weight;
    cout<<"parameterised constructor 2 called "<<endl;
  }

  // copy constructor
  Animal(Animal &obj){
    this->age=obj.age;
     this->weight=obj.weight;
     this->type=obj.type;
     cout<<"i am inside copy constructor"<<endl;
  }



  // behaviour / function
  void eat(){
       cout<<"eating"<<endl;
  }

  void sleep(){
         cout<<"sleeping"<<endl;
  } 

  int getWeight() {
    return weight;
  }

  void setWeight(int weight) {
    this->weight=weight;
  }

  void print(){
    cout<< this->age << " "<< this->weight << " "<< this->type <<endl;
  }

  ~Animal(){
    cout<<"I am inside destructor"<<endl;
  }



};


int main(){
   
   // Object creation

   // static memory
 /*  Animal ramesh; // animal ka naam ramesh hai
   ramesh.age=12;  // how u access in class
   ramesh.type="lion";
   cout<<"age of ramesh is : "<< ramesh.age << endl;
   cout<<"name of ramesh is: "<< ramesh.name <<endl;
  

  ramesh.eat();

  ramesh.sleep(); 

// TO private member
  ramesh.setWeight(101);
  cout<<"weight "<< ramesh.getWeight() <<endl;
*/

   // Dynamic memory
 /* 
  Animal* suresh= new Animal;   
  
  (*suresh).age=15; // suresh to sirf address store karega par *suresh object pe point karega
  (*suresh).type="billi";

  // alternate -> dynamic
  suresh->age=17;
  suresh->type="kutta";
  
  suresh->eat();
  suresh->sleep();*/
/*
  Animal a(10);
  Animal* b=new Animal(100,23);

  // objcet copy
  Animal c =a;
  Animal animal1(c);
  */

  Animal a;
  a.age=20;
  a.setWeight(101);
  a.type="Babbar";

  /*Animal b=a;
  cout<<" a-> ";
  a.print();
  cout<<" b-> ";
  b.print();

  a.type[0]='G';
  cout<<" a-> ";
  a.print();
  */

   Animal* b=new Animal();
   b->age=12;
   // manually destructor call
   delete b;
    return 0;
}