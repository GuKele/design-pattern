#include "AbstractFactory.h"


int main(){
  
  DrinksFactory factory;
  auto tea = factory.make("tea");
  auto coffe = factory.make("coffe");

}

