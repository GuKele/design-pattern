#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>
#include <vector>
using std::vector;
#include <initializer_list>

//假设我们的BankAccount账户已经创建好了，
//我们现在需要在deposit、withdraw每次调用时记录它们以方便审计。但是我们不想更改BankAccount类了
class BankAccount {
 private:
  int balance_ = 0;
  int overdraftLimit_ = -500;

 public:
  BankAccount() = default;
  BankAccount(const int& balance, const int& overdraftLimit)
    : balance_(balance), overdraftLimit_(overdraftLimit){
  }

  //可以将deposit等接口设置为private，然后将BankAccountCommand设置为友元类
  bool deposit(const int& amount) {
    balance_ += amount;
    std::cout << "deposit " << amount << " balance is now " << balance_ << std::endl;
    return true;
  }

  bool withdraw(const int& amount) {
    if(balance_ - amount >= overdraftLimit_){
      balance_ -= amount;
      std::cout << "withdraw " << amount << " balance is now " << balance_ << std::endl;
      return true;
    }
    return false;
  }

};

class Commmand {
 public:
  virtual bool call() = 0;
  virtual bool undo() = 0;
};

class BankAccountCommand : public Commmand {
 public:
  enum Action { kDeposit, kWithdraw };
  
  BankAccountCommand(BankAccount& bankAccount, const Action& action, const int& amount)
    : bankAccount_(bankAccount), action_(action), amount_(amount) {
  }

  virtual bool call() override {
    if(successed_){
      return false;
    }
    switch (action_)
    {
    case kDeposit:
      successed_ = bankAccount_.deposit(amount_);
      std::cout << "记录" << std::endl;
      //记录调用
      return successed_;
      break;
    
    case kWithdraw:
      successed_ = bankAccount_.withdraw(amount_);
      //记录调用
      return successed_;
      break;
    }
    return false;
  }

  //撤销操作,其实对于真正的账户来说，不允许撤销，万一你存的钱后来又取了，你还怎么撤销之前存的钱
  virtual bool undo() override {
    if (!successed_) {
      return false;
    }
    switch(action_) {
      case kDeposit:
        bankAccount_.withdraw(amount_);
        //记录撤销
        successed_ = false;
        return true;
        break;
      case kWithdraw:
        bankAccount_.deposit(amount_);
        //记录撤销
        successed_ = false;
        return true;
        break;
    }
    return false;
  }

 private:
  BankAccount& bankAccount_;
  int amount_;
  //记录call是否调用成功，成功了才能undo撤销
  bool successed_ = false;
  Action action_;
};

//组合command，加入我们想实现转账操作,例如A取钱，B存钱，我们把这两个命令组合起来
class ComposeBankAccountCommand : public Commmand, public vector<BankAccountCommand> {
 public:
  ComposeBankAccountCommand(const std::initializer_list<value_type>& items)
    : vector<BankAccountCommand>(items){
  }

 //实际上根本没这么简单，如果上一步不成功，我们复原的过程中又出错了呢？
  virtual bool call() override {
    //这样好傻，实现了begin、end成员的就可以直接范围for循环
    //for (auto& cmd = begin() ; cmd != end() ; ++cmd)
    bool isContinue = true;
    for (auto it = begin(); it != end(); ++it) {
      //上一步成功我们在进行下一步
      if(isContinue){
        isContinue = it->call();
      }else{ //上一步不成功，我们要撤销之前所有的（如果撤销操作又出错了呢？）
        for ( ; it >= begin() ; --it) {
          it->undo();
        }
        return false;
      }
    }
    return true;
  }

  virtual bool undo() override {
    bool isContinue = true;
    for(auto it = rbegin() ; it != rend() ; ++it){
      if (isContinue) {
        isContinue = it->undo();
      } else {  //上一步不成功，我们要撤销之前所有的
        for (; it <= rend(); --it) {
          it->call();
        }
        return false;
      }
    }
    return true;
  }
};


#endif