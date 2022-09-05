#ifndef _POINT_FACTORY_H_
#define _POINT_FACTORY_H_

#include <cmath>
#include <iostream>

class Point
{
 public:
  double x_, y_;
  friend class PointFactory;
  void show() { std::cout << x_ << " " << y_ << std::endl; }
 private:
  Point(const double x, const double y) : x_(x), y_(y) {}
};

//我们将所有工厂方法提取出来放置的到一个单独的类中，这个类就叫做工厂
//工厂可以是friend，也可以是内嵌类
class PointFactory
{
 public:
  static Point newCartesian(const double x, const double y) { return {x, y}; }
  static Point newPolar(const double r, const double theta) { return {r*cos(theta), r*sin(theta)}; }
};

#endif