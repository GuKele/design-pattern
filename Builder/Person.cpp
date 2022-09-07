#include "Person.h"


PersonBuilder Person::create() { return PersonBuilder(); }

PersonAddressBuilder PersonBuilderBase::live() const {
  return PersonAddressBuilder(person_);
}

PersonJobBuilder PersonBuilderBase::work() const {
  return PersonJobBuilder(person_);
}