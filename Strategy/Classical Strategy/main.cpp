#include "Duck.h"

int main() {
  FlyWithWings flyWithWings;
  FlyNoWay flyNoWay;
  WoodDuck woodDuck(new FlyNoWay());
  RealDuck realDuck(new FlyWithWings());
  woodDuck.performFly();
  realDuck.performFly();
}
