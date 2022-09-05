#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>
#include <iostream>
//把构造函数放入保护字段，然后暴露一些静态方法用于创建新的坐标点，函数参数名称清晰的表明了构造意图
//这些静态函数被称作工厂方法
class Point
{
 private:
  float x_, y_;
 protected:
  Point(const float x, const float y) : x_(x), y_(y) {}

 public:
  //笛卡尔坐标系
  static Point newCartesian(const float x, const float y) {
    return Point(x, y);
  }
  //极坐标系
  static Point newPloar(const float r, const float theta) {
    return Point(r * cos(theta), r * sin(theta));
  }

  void show(){ std::cout << this->x_ << " " << this->y_ << std::endl; }
};

#endif