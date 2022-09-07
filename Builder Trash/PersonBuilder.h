#ifndef _PERSON_BUILDER_H_
#define _PERSON_BUILDER_H_

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
 protected:
  Person& person_;

 public:
  explicit PersonBuilderBase(Person& person) : person_(person) {}
  //用到前置声明类（不完全类型）的成员函数了，所以定义放在cpp中
  PersonAddressBuilder live() const;
  PersonJobBuilder work() const;
};

class PersonBuilder : public PersonBuilderBase {
 private:
  Person person_;

 public:
  PersonBuilder() : PersonBuilderBase(person_){};
};

#endif