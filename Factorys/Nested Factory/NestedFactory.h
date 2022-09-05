#ifndef _NESTED_FACTORY_H_
#define _NESTED_FACTORY_H_

#include <cmath>
#include <iostream>

//我们将所有工厂方法提取出来放置的到一个单独的类中，这个类就叫做工厂
//工厂可以是friend，也可以是内嵌类,这里我们使用内嵌工厂
class Point
{
 private:
  double x_, y_;
  Point(const double x, const double y) : x_(x), y_(y) {}
  
  class NestedFactory {
   public:
    static Point newCartesian(const double x, const double y) { return {x, y}; }
    static Point newPolar(const double r, const double theta) { return {r * cos(theta), r * sin(theta)}; }
  };

 public:
  void show() { std::cout << x_ << " " << y_ << std::endl; }
  static NestedFactory factory_;


};

Point::NestedFactory Point::factory_ = NestedFactory();

#endif