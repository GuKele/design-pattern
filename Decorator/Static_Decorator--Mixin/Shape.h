#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <sstream>
#include <string>
#include <utility>
#include <type_traits>

using std::string;
//装饰器模式就是遵循开闭原则（不修改原始类型）或导致派生类数量激增的情况下增加现有类的功能
//静态装饰器就是使用Mixin手法(模板类继承其模板类型参数)。
//不可以重新组合对象，但是允许访问底层对象的成员，这些对象也可以通过构造函数转发完成初始化
class Shape {
 public:
  virtual string str() const = 0;
};

class Circle : public Shape {
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

template <typename T>
class ColoredShpae : public T { 
 private:
  //static_assert可以在类体中作为成员声明，false时，字符串（字面值）消息会出现在编译失败的诊断信息中
  static_assert(std::is_base_of<Shape, T>::value, "Template argument must be a Shape");
  string color_;
 public:
  string str() {
    std::ostringstream oss;
    oss << T::str() << "has the color " << color_ << " ";
    return oss.str();
  }

  template <typename... Args>
  ColoredShpae(const string& color, Args&&... args) 
    : color_(color), 
      T(std::forward<Args>(args)...) {
    //  
  }
};

template <typename T>
class TransparentShpae : public T {
 private:
  // static_assert可以在类体中作为成员声明，false时，字符串（字面值）消息会出现在编译失败的诊断信息中
  static_assert(std::is_base_of<Shape, T>::value,
                "Template argument must be a Shape");
  int transparent_;

 public:
  string str() {
    std::ostringstream oss;
    oss << T::str() << "has " << transparent_ << "% transparent ";
    return oss.str();
  }

  template <typename... Args>
  TransparentShpae(const int& transparent, Args&&... args)
      : transparent_(transparent), 
        T(std::forward<Args>(args)...) {
    //
  }
};


#endif