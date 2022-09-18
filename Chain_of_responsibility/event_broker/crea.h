#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <string>
using std::string;

#include "boost/signals2.hpp"

//命令模式
class Query {
 public:
  const string creatureName_;
  enum Argument { kAttack, kDefense } argument_;
  int result_;

  Query(const string& name, const Argument& argument, const int& result) 
    : creatureName_(name), argument_(argument), result_(result){
  }
};

class Creature{
 public:
  const string name_;
  //观察者模式
  boost::signals2::signal<void(Query&)> queries_;

  Creature(const string& name, const int& attack, const int& defense)
    : name_(name), attack_(attack), defense_(defense){
  }

//当我们需要查询的时候，我们创建一个查询对象，然后观察者模式通知所有的订阅者（creatureModifier）来修改
  int getAttack() {
    //Query query(name_, Query::Argument::kAttack, attack_);
    Query query(name_, Query::Argument::kAttack, attack_);
    queries_(query);
    return query.result_;
  }
 private:
  int attack_, defense_;


};


class CreatureModifier{
 protected:
  Creature& creature_;
  //boost::signals2::connection conn_;
 public:
  CreatureModifier(Creature& creature)
    : creature_(creature){
  }
};

class DoubleAttackModifier : public CreatureModifier {
 public:
 //modifier构造时注册到该creature的观察者中
  DoubleAttackModifier(Creature& creature)
    : CreatureModifier(creature){
    conn_ = creature_.queries_.connect(
      [&](Query& query){
        if(query.argument_ == Query::Argument::kAttack){
          query.result_ *= 2;
          return query;
        }
      }
    );
  }
  
  //析构时从该creature的观察者中移除
  ~DoubleAttackModifier(){
    conn_.disconnect();
  }

 private:
  boost::signals2::connection conn_;
};


#endif