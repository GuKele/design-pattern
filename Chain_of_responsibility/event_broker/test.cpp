#include <crea.h>

#include <iostream>

int main(){
  Creature goblin("Strong Goblin", 2, 4);
  std::cout << goblin.getAttack() << std::endl;
  {
    DoubleAttackModifier buff(goblin);
    std::cout << goblin.getAttack() << std::endl;
  }
  std::cout << goblin.getAttack() << std::endl;
  return 0;
}