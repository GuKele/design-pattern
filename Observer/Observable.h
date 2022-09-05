#ifndef _OBSERVABLE_H_
#define _OBSERVABLE_H_

#include <unordered_set>
#include <memory>

#include "Observer.h"

//接口类
class  Observable
{
 protected:
  std::unordered_set<Observer*> observers_;
  bool changed_;

 public:
  virtual bool registerOb(Observer* observer) { observers_.insert(observer); }

  virtual bool removeOb(Observer* observer) { return static_cast<bool>(observers_.erase(observer)); }

  //setChanged函数让更新的时候更有弹性，可以设置各种条件才set changed
  //virtual bool setChanged() { changed_ = true; }

  virtual bool notifyAll();

};

#endif