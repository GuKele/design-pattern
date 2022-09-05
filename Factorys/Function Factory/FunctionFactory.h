#ifndef _FUNCTION_FACTORY_H_
#define _FUNCTION_FACTORY_H_

#include <functional>
#include <map>
#include <memory>
#include <string>

using namespace std;

class AbstractDrink {};

class Coffee : public AbstractDrink {};

class Tea : public AbstractDrink {};

class DrinksFactory {
 public:
  //也可以map<string, function<>>
  //其中function可以直接用lambda实现函数工厂，而不用创建AbstractFactory、CoffeFactory等工厂类了
  std::map<string, function<unique_ptr<AbstractDrink>()>> factories_;
  DrinksFactory() {
    factories_["coffee"] = [] { return make_unique<Coffee>(); };
    factories_["tea"] = [] { return make_unique<Tea>(); };
  }
  unique_ptr<AbstractDrink> make(const string& name) {
    return factories_[name]();
  }
};


#endif