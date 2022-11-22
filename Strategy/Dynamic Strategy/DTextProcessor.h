#ifndef _TEXTPROCESSOR_H_
#define _TEXTPROCESSOR_H_

#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "ListStrategy.h"

using namespace std;

class DTextProcessor {
 public:
  static shared_ptr<ListStrategy> html, markdown;

  void appendList(const vector<string>& items) {
    listStrategy_->start(oss_);
    for(auto& item : items) {
      listStrategy_->addListItem(oss_, item);
    }
    listStrategy_->end(oss_);
  }

  bool setOutputFormat(const shared_ptr<ListStrategy>& strategy) {
    listStrategy_ = strategy;
  }

  string str() const { return oss_.str(); };
  
 private:
  ostringstream oss_;
  shared_ptr<ListStrategy> listStrategy_;
};

shared_ptr<ListStrategy> DTextProcessor::html = make_shared<HtmlListStrategy>();
shared_ptr<ListStrategy> DTextProcessor::markdown = make_shared<MarkDownListStrategy>();

#endif // _TEXTPROCESSOR_H_