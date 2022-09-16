#include <iostream>

#include "User.h"

int main(){
  User xiaoming("huang", "xiaoming");
  User daming("huang", "daming");
  std::cout << std::boolalpha << (&xiaoming.firstName_.get() == &daming.firstName_.get()) << std::endl;
  return 0;
}