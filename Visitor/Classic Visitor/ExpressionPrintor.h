#ifndef _EXPRESSION_PRINTOR_H_
#define _EXPRESSION_PRINTOR_H_

#include <sstream>
#include <string>
using namespace std;

#include "ExpressionVisitor.h"
#include "Expressions.h"

class ExpressionPrintor : public ExpressionVisitor {
 public:
  string str() const override { return oss_.str(); }
  ExpressionVisitor& visit(DoubleExpression* de) override { oss_ << de->value_; return *this; }
  ExpressionVisitor& visit(AdditionExpression* ae) override {
    oss_ << "(";
    ae->left_->accept(this);  
    oss_ << "+";
    ae->right_->accept(this);
    oss_ << ")";
    return *this;
  }

 private:
  ostringstream oss_;
  double getResult() const override {}  //隐藏起来，这个类不需要这个接口
};

#endif // _EXPRESSIONPRINTOR_H_