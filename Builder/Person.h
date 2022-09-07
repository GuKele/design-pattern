#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

using namespace std;

class PersonBuilder;

class Person {
 public:
  friend class PersonBuilder;
  friend class PersonBuilderBase;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
  static PersonBuilder create();

 private:
  string streetAddress_, postCode_, city_;
  string companyName_, position_;
  int annualIncome_ = 0;
  Person() {}
};

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

class PersonAddressBuilder : public PersonBuilderBase {
 public:
  PersonAddressBuilder(Person& person) : PersonBuilderBase(person) {}
  PersonAddressBuilder& at(const string& streetAddress) {
    person_.streetAddress_ = streetAddress;
    //流畅接口，返回建造者本身的引用，可以对建造者进行链式调用
    return *this;
  }
  PersonAddressBuilder& withPostCode(const string& postCode) {
    person_.postCode_ = postCode;
    return *this;
  }
  PersonAddressBuilder& in(const string& city) {
    person_.city_ = city;
    return *this;
  }
};

class PersonJobBuilder : public PersonBuilderBase {
 public:
  PersonJobBuilder(Person& person) : PersonBuilderBase(person) {}
  PersonJobBuilder& at(const string& companyName) {
    person_.companyName_ = companyName;
    return *this;
  }
  PersonJobBuilder& as_a(const string& position) {
    person_.position_ = position;
    return *this;
  }
  PersonJobBuilder& earning(const int& annualIncome) {
    person_.annualIncome_ = annualIncome;
    return *this;
  }
};

#endif