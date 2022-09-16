#ifndef _PERSON_H_
#define _PERSON_H_

#include <memory>
#include <string>
using std::string;

class Person
{
 private:
  class PersonImpl;
  /*当使用unique_ptr的时候，Person自己生成的析构函数会调用unique_ptr的默认删除器，
  **其中会使用delete，而delete前会检查PersonImpl是不是完整类型,
  **所以我们将Person析构函数的定义放在PersonImpl定义后*/
  std::unique_ptr<PersonImpl> impl_;
 public:
  Person(const string& name);
  ~Person();
  void greet();
};


#endif