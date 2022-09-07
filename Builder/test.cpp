#include <iostream>

#include "Person.h"

int main() {
  auto person = Person::create()
                    .live()
                    .at("健康东路５号")
                    .withPostCode("520250")
                    .in("厦门市")
                    .work()
                    .at("厦门大学")
                    .as_a("学生")
                    .earning(600);
  std::cout << "finished" << std::endl;
}