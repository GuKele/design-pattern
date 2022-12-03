#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_

#include "Expression.h"

class DoubleExpression : public Expression {
 public:
  explicit DoubleExpression(const double& value) : value_(value) {}
  void accept(ExpressionVisitor* visitor) override { visitor->visit(this); }

  double value_;

};

class AdditionExpression : public Expression {
 public:  
  AdditionExpression(Expression* const left, Expression* const right) 
    : left_(left),
      right_(right) {
  }
  // 比如在这里，这个AdditionExpression对象可能是存储在另外一个AdditionExpression对象中的left_，这个left_的类型是Expression*
  // 如果是将left_传给一个funtion，那么这个function必须在内部使用dynamic_cast来区分它真正的类型
  // if(auto ae = dynamic_cast<AdditionExpression*>(e))
  // 每添加一个功能都需要重写Expression及派生类，并且还要用dynamic_cast区分，很麻烦
  // 而在visitor设计模式中，新添加功能都是一个visitor，并且我们使用重载和this指针天然的可以实现分派
  void accept(ExpressionVisitor* visitor) override { visitor->visit(this); }

  Expression *left_, *right_; 

};

#endif // _EXPRESSIONS_H_