#ifndef _USER_H_
#define _USER_H_

#include <string>
using std::string;

#include "boost/flyweight.hpp"

class User{
 public:
  User(const string& fristName, const string& lastName)
    : firstName_(fristName), lastName_(lastName){
  }

  boost::flyweight<string> firstName_, lastName_;

};

#endif