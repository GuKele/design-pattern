#include "Shape.h"

#include <iostream>

int main(){
  ColoredShape redCircle(TransparentShape(Circle(3.4), 23), "red");
  
  std::cout << redCircle.str() << std::endl;
  return 0;
}