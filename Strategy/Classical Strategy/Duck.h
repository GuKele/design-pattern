#ifndef _FLY_BEHAVIOR_
#define _FLY_BEHAVIOR_

#include "FlyBehavior.h"

#include <memory>

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