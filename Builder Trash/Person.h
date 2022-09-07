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

#endif