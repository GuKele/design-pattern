#ifndef _FLYBEHAVIOR_H_
#define _FLYBEHAVIOR_H_

#include <iostream>

class FlyBehavior{
 public:
  //飞接口
  virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior{
 public:
  virtual void fly() final{
    //用翅膀飞
    std::cout << "用翅膀飞"  << std::endl;
  }
};

class FlyNoWay : public FlyBehavior{
 public:
  virtual void fly() final{
    //不会飞
    std::cout << "我不会飞啊" << std::endl; 
  }
};


#endif
