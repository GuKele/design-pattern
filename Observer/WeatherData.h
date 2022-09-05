#ifndef _WEATHERDATA_H_
#define _WEATHERDATA_H_

#include "Observable.h"

class  WeatherData : public Observable
{
 private:

  double temperature_, humidity_, pressure_;
 
 public:
  
  double getTemperature() const { return temperature_; }

  double getHumidity() const { return humidity_; }

  double getPressure() const { return pressure_; }

  bool setter(double t, double h, double p){
    temperature_ = t;
    humidity_ = h;
    pressure_ = p;
    notifyAll();
    //setChanged();
  }

};



#endif