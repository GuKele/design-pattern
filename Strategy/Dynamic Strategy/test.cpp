#include <iostream>
#include "DTextProcessor.h"


int main() {
  vector<string> items = {"nihao", "i am fn"};
  DTextProcessor temp{};
  temp.setOutputFormat(DTextProcessor::html);
  temp.appendList(items);
  temp.setOutputFormat(DTextProcessor::markdown);
  temp.appendList(items);
  std::cout << temp.str() << std::endl;
}
