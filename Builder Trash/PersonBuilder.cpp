#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder PersonBuilderBase::live() const {
  return PersonAddressBuilder(person_);
}

PersonJobBuilder PersonBuilderBase::work() const {
  return PersonJobBuilder(person_);
}