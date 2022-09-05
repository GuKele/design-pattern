#include "Display.h"


int main(){
  WeatherData weatherData;
  CurrentDisplay cd(&weatherData);
  StatisticsDisplay sd(&weatherData);
  weatherData.setter(25, 0.4, 7);
}