#include "Ducks.h"
void fastFly(int space) {
  std::cout << "用" << space << "速度来飞" << std::endl;
}

int main(){
  DirDuck duck1; //使用默认的default fly
  DirDuck duck2([]() -> void { std::cout << "非常快的飞" << std::endl; }); //使用lambda
  DirDuck duck3(std::bind(&fastFly, 5)); //使用std::bind

  duck1.performFly();
  duck2.performFly();
  duck3.performFly();
}