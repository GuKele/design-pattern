#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
using std::string;

class Person
{
 private:
  class PersonImpl;
  PersonImpl* impl_; //或者干脆直接unique_ptr，会复杂一些，看Effective Modern C++
 public:
  Person(const string& name);
  ~Person();
  void greet();
};


#endif