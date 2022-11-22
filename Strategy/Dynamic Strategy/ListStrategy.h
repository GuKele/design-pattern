#ifndef _LIST_STRATEGY_H_
#define _LIST_STRATEGY_H_

#include <sstream>
using namespace std;

//策略虚基类，由一组策略虚函数构成
class ListStrategy {
 public:
  virtual void start(ostringstream& oss){};
  virtual void end(ostringstream& oss){};
  virtual void addListItem(ostringstream& oss, const string& item){};
};

class HtmlListStrategy : public ListStrategy {
 public:
  void start(ostringstream& oss) override { oss << "<ul>\n"; }
  void end(ostringstream& oss) override { oss << "</ul>\n"; }
  void addListItem(ostringstream& oss, const string& item) override {
    oss << "<li>" << item << "</li>\n";
  }
};

class MarkDownListStrategy : public ListStrategy {
 public:
  void start(ostringstream& oss) override {}
  void end(ostringstream& oss) override {}
  void addListItem(ostringstream& oss, const string& item) override {
    oss << "* " << item <<"\n";
  }
};

#endif