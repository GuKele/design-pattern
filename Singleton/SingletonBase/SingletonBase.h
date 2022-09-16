#ifndef _SINGLETON_BASE_H_
#define _SINGLETON_BASE_H_

#include <map>
#include <string>

/*我们并不会直接使用SingletonBase::get()，而是给单例对象提供接口，
**而是在函数调用中传参或者在类中存储一个Base*,
**这样更灵活，我们的代码不止局限于只能使用单例对象
*/

class Base
{
 public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonBase : public Base
{
private:
  std::map<std::string, int> capitals_;
  SingletonBase(){ capitals_["beijing"] = 362; }
public:
  virtual int get_population(const std::string& name) override {
    return capitals_[name];
  }
 
  static SingletonBase& get(){
    static SingletonBase* sb = new SingletonBase();
    return *sb;
  }
};


#endif
