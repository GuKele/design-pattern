#include "Observable.h"


bool Observable::notifyAll() {
  // if(changed_){
  for (auto& observer : observers_) {
    observer->update(this);
  }
  //}
  // changed_ = false;
}