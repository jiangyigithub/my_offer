#include <memory>
#include <iostream>
using namespace std;

class Dog {
    string m_name;
  public:
      void bark() { cout << "Dog " << m_name << " rules!" << endl; }
      Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
      Dog() { cout << "Nameless dog created." << endl; m_name = "nameless"; }
     ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
	  //void enter(DogHouse* h) { h->setDog(shared_from_this()); }  // Dont's call shared_from_this() in constructor
};

// dangling pointer
void foo1(){
    Dog* p=new Dog("Gunner");
    //...
    delete p;
    //...
    p->bark();//p is a dangling pointer - undefined behavior
}

// memory leak
void foo2(){
    Dog* p=new Dog("Gunner");
    //...
    //...
    p->bark();
}// Memory leak

void foo3(){
    shared_ptr<Dog> p(new Dog("Gunner"));
    {
        shared_ptr<Dog> p2=p;//count = 2
        p2->bark();
    }
    p->bark();
}

int main(){
    foo3();
    return 0;
}