#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

class ExpressionVisitor;

class Expression {
 public:
  //分派，这样各种表达式中，他们重载accept中会调用visitor的visit函数，传入this，this是有明确的类型
  virtual void accept(ExpressionVisitor* visitor)=0;

};

#endif // _EXPRESSION_H_