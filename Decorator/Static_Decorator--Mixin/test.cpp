#include "Shape.h"

#include <iostream>

int main() {
  TransparentShpae<ColoredShpae<Circle>> coloredTransShape(45, "red", 4.2);
  std::cout << coloredTransShape.str() << std::endl;
  return 0;
}