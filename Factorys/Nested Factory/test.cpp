#include "NestedFactory.h"

int main(){
  auto p1 = Point::factory_.newCartesian(4, 5);
  auto p2 = Point::factory_.newPolar(sqrt(2), M_PI_4);
  p1.show();
  p2.show();
}
