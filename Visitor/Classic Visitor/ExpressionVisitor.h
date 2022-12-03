#ifndef _EXPRESSION_VISITOR_H_
#define _EXPRESSION_VISITOR_H_


class DoubleExpression;
class AdditionExpression;

class ExpressionVisitor {
 public:
  virtual ExpressionVisitor& visit(DoubleExpression* de) = 0;
  virtual ExpressionVisitor& visit(AdditionExpression* ae) = 0;
  //为了链式访问，其实这里不太适合，因为你每添加一个新的visitor，就得重新改这个基类
  virtual string str() const{}; //不能定义成纯虚函数了，因为纯虚必须重载，而有的派生类不需要真正的这个函数
  virtual double getResult() const{};
};


#endif // _EXPRESSIONVISITOR_H_