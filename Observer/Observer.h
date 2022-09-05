#ifndef _OB_H_
#define _OB_H_

#include <memory>

//#include "Observable.h"

class Observable;

//接口类
class Observer{
 public:

  Observer(Observable* observable) : observable_(observable){ observable_->registerOb(this); };

  virtual bool update(Observable*) = 0;
  
 protected:
  std::shared_ptr<Observable> observable_;

};

#endif