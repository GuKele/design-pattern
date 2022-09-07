#ifndef _PERSON_JOB_BUILDER_H_
#define _PERSON_JOB_BUILDER_H_

#include "PersonBuilder.h"

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