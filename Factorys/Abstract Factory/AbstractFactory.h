#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include <memory>
#include <map>
#include <string>
#include <functional>

using namespace std;

class AbstractDrink
{
  
};

class Coffee : public AbstractDrink 
{

};

class Tea : public AbstractDrink 
{

};

class AbstractFactory
{ 
 public:
  virtual std::unique_ptr<AbstractDrink> make() = 0;
};

class CoffeFactory : public AbstractFactory
{
 public:
  virtual std::unique_ptr<AbstractDrink> make() override { return std::make_unique<Coffee>(); }
};

class TeaFactory : public AbstractFactory
{
 public:
  virtual std::unique_ptr<AbstractDrink> make() override { return std::make_unique<Tea>(); }
};

class DrinksFactory
{
 public:
  //也可以map<string, function<>>  
  //其中function可以直接用lambda实现函数工厂，而不用创建AbstractFactory、CoffeFactory等工厂类了
  std::map<string, unique_ptr<AbstractFactory>> factories_;
  DrinksFactory(){
    factories_["coffe"] = make_unique<CoffeFactory>();
    factories_["tea"] = make_unique<TeaFactory>();
  } 
  unique_ptr<AbstractDrink> make(const string& name) { return factories_[name]->make(); }
};

#endif