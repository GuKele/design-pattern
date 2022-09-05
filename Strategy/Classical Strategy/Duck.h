#ifndef _DUCK_H_
#define _DUCK_H_

#include "FlyBehavior.h"

#include <memory>

//接口类，但是如果定义为纯虚函数则不太方便
class Duck{
 public:
  Duck(FlyBehavior* flyBehavior) : flyBehavior_(flyBehavior)
  { };

  bool setFlyBeHavior(FlyBehavior* newflyBehavior) {
    flyBehavior_.reset(newflyBehavior);
  }

  bool performFly() {
    flyBehavior_->fly();
  }

  std::unique_ptr<FlyBehavior> flyBehavior_;
};

class WoodDuck : public Duck{
 public:
  WoodDuck(FlyBehavior* flyBehavior) : Duck(flyBehavior) { };
};

class RealDuck : public Duck{
 public:
  RealDuck(FlyBehavior* flyBehavior) : Duck(flyBehavior) { };
};
#endif