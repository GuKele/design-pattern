#include "PointFactory.h"

int main(){
  auto p1 = PointFactory::newCartesian(4, 5);
  auto p2 = PointFactory::newPolar(sqrt(2), M_PI_4);
  p1.show();
  p2.show();
}
