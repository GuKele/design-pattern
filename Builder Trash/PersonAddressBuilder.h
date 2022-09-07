#ifndef _PERSON_ADDRESS_BUILDER_H_
#define _PERSON_ADDRESS_BUILDER_H_


#include "PersonBuilder.h"

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

#endif