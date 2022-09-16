#ifndef _DATABASE_LOCK_H_
#define _DATABASE_LOCK_H_

#include <mutex>


class Database 
{
 protected:
  Database() {}
  static std::mutex mtx_;
  static Database* database_;
 public:
  static Database& instance() {
    if(!database_){
      //仍然会出现脏读的情况，应该使用std::atomic<Database*>和   直接看书把
      std::unique_lock<std::mutex> lk(mtx_, std::try_to_lock);
      if(!database_){
        database_ = new Database();
      }
    }
    return *database_;
  }
};

std::mutex Database::mtx_;
Database* Database::database_ = nullptr;

#endif