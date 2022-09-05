#include "FunctionFactory.h"

int main(){

  DrinksFactory factory;
  auto coffee = factory.make("coffee");
  auto tea = factory.make("tea");

}