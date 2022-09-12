#include "Person.h"

#include <string>
// Person.h头文件中只需要声明所需头文件，不需要包含实现，将iostream头文件放在.cpp而非.h文件,可以更少的头文件传递性
#include <iostream>  

using std::string;
using std::cout;
using std::endl;


class Person::PersonImpl
{
 private:
  string name_;
 public:
  void greet(){
    cout << "你好" << name_ << endl;
  }
  PersonImpl(const string& name) : name_(name) {}
};


Person::Person(const string& name) : impl_(new PersonImpl(name)) {}
Person::~Person() { delete impl_; }

//将更多的细节隐藏在PersonImpl中，并且减少编译时间。修改PersonImpl数据成员不会影响二进制兼容性
void Person::greet(){ 
  impl_->greet();
}