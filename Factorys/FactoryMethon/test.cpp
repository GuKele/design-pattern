#include "Point.h"


int main(){
  auto p1 = Point::newCartesian(4, 3);
  auto p2 = Point::newPloar(sqrt(2), M_PI_4);
  p1.show();
  p2.show();
}

