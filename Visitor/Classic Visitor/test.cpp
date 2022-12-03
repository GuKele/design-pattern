#include <iostream>

#include "Expression.h"
#include "ExpressionPrintor.h"
#include "ExpressionEvaluator.h"

int main(int argc, char const *argv[])
{
  auto e = new AdditionExpression {
    new DoubleExpression{1},
    new AdditionExpression{
      new DoubleExpression{2},
      new DoubleExpression{3}
    }
  };

  auto printor = ExpressionPrintor{};
  
  auto evaluator = ExpressionEvaluator{};

  string str = printor.visit(e).str();
  double result = evaluator.visit(e).getResult();

  cout << str << "\n" << result;

  return 0;
} 
