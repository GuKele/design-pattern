#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>

#include "Observer.h"
#include "WeatherData.h"

class  CurrentDisplay : public Observer
{
 private:
  double humidity_, temperature_;

 public:
  
  CurrentDisplay(WeatherData* weatherData) : Observer(weatherData) { }; 

  virtual bool update(Observable* observable) override final {
    if(observable_ && observable_.get() == observable){
      //要想通过基类指针访问派生类独有的成员，必须使用dynamic_cast
      WeatherData* weatherData = dynamic_cast<WeatherData*>(observable_.get());
      humidity_ = weatherData->getHumidity();
      temperature_ = weatherData->getTemperature();
      std::cout << "current display :" << std::endl 
                << "current humidity = " << humidity_ 
                << "current temperature = " << temperature_ << std::endl;
    } 
  }
};

class StatisticsDisplay : public Observer
{
 private:
  double humidity_, temperature_;

 public:

  StatisticsDisplay(WeatherData* weatherData) : Observer(weatherData){};

  virtual bool update(Observable* observable) override final{
    if (observable_ && observable_.get() == observable) {
      //要想通过基类指针访问派生类独有的成员，必须使用dynamic_cast
      WeatherData* weatherData = dynamic_cast<WeatherData*>(observable_.get());
      humidity_ = weatherData->getHumidity();
      temperature_ = weatherData->getTemperature();
      std::cout << "statistics display :" << std::endl
                << "statistics humidity = " << humidity_
                << "statistics temperature = " << temperature_ << std::endl;
    }
  }
};

#endif