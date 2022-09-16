#ifndef _USER_H_
#define _USER_H_

#include <string>
using std::string;
#include <iostream>

#include "boost/bimap.hpp"

class User {
 public:
  using Key = uint64_t;

  User(const string& firstName, const string& lastName) 
    : firstNameKey_(add(firstName)),
      lastNameKey_(add(lastName)){
    std::cout << "firstNameKey = " << firstNameKey_ 
              << "lastNameKey = " << lastNameKey_
              << std::endl;
  }


  friend std::ostream& operator<< (std::ostream& os, const User& obj){
    return os << "first name : " << obj.getFirstName()
              << " last name : " << obj.getLastName()
              << std::endl; 
  }

 private:
  static Key key_;
  static boost::bimap<Key, string> names_;
  Key firstNameKey_, lastNameKey_;

  Key add(const string& name){
    auto it = names_.right.find(name);
    if(it == names_.right.end()){
      std::cout << "insert " << name << " key = " << key_ << std::endl;
      names_.right.insert({name, key_++});
      
    }
    return names_.right.at(name);
  }

  string getFirstName() const {
    return names_.left.at(firstNameKey_);
  }

  string getLastName() const {
    return names_.left.at(lastNameKey_);
  }

};

User::Key User::key_ = 0;
boost::bimap<User::Key, string> User::names_;

#endif