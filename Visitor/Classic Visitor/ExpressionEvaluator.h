#ifndef _EXPRESSION_EVALUATOR_H_
#define _EXPRESSION_EVALUATOR_H_

#include "ExpressionVisitor.h"
#include "Expressions.h"

//使用visitor设计模式的好处就是，使用了双重分派，我们只需要通过层次结构实现一次accept成员，再也不用碰层级中的成员了。
class ExpressionEvaluator : public ExpressionVisitor {
 public:
  double result_;
  double getResult() const override { return result_; }
  ExpressionVisitor& visit(DoubleExpression* de) override {
    result_ = de->value_;
    return *this;
  }
  ExpressionVisitor& visit(AdditionExpression* ae) override {
    ae->left_->accept(this);
    double temp = result_;
    ae->right_->accept(this);
    result_ += temp;
    return *this;
  }

 private:
  string str() const override {} //隐藏起来，这个类不需要这个接口
};

#endif // _EXPRESSIONEVALUATOR_H_