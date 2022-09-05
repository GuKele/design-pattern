#ifndef _DUCKS_H_
#define _DUCKS_H_

#include <functional>
#include <iostream>  

void defaultFly(){
  std::cout << "default fly" << std::endl;
}

class BaseDuck{
 public:
  using Fly = std::function<void()>;

  BaseDuck(Fly fly = defaultFly) : fly_(fly) { };

  bool setFly(Fly newfly){
    fly_ = newfly;
  }

  bool performFly(){
    fly_(); 
  }

 private:
  Fly fly_;
};

class DirDuck : public BaseDuck{
 public:
  DirDuck(Fly fly = defaultFly) : BaseDuck(fly) { }; 
};

#endif