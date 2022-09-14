#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <sstream>
#include <string>
using std::string;
//装饰器模式就是遵循开闭原则（不修改原始类型）或导致派生类数量激增的情况下增加现有类的功能
//动态装饰器就是每个类都继承接口基类，使用组合包含基类的引用。
//提供动态（运行时）可组合型，但是不能访问底层对象自己的成员
class Shape
{
 public:
  virtual string str() const = 0; 
};

class Circle : public Shape
{
 public:
  explicit Circle(const double& radius) : radius_(radius) {}

  virtual std::string str() const override {
    std::ostringstream oss;
    oss << "A circle of radius " << radius_ << " ";
    return oss.str();
  }
 private:
  double radius_;

};

class ColoredShape : public Shape
{ 
 public:
  ColoredShape(const Shape& shape, const std::string& color) : shape_(shape), color_(color) {}
  virtual string str() const override {
    std::ostringstream oss;
    oss << shape_.str() << "has the color " << color_ << " ";
    return oss.str();
  }
 private:
  const Shape& shape_;
  string color_;
};

class TransparentShape : public Shape
{
 public:
  TransparentShape(const Shape& shape, const int& transparency)
      : shape_(shape), transparency_(transparency) {}
  virtual string str() const override {
    std::ostringstream oss;
    oss << shape_.str() << "has " 
        << transparency_ / 100.0
        << "% transparency ";
    return oss.str();
  }

 private:
  const Shape& shape_;
  int transparency_;
};

#endif