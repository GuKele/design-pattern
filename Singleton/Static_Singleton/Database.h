#ifndef _DATABASE_STATIC_H_
#define _DATABASE_STATIC_H_

#include <vector>
#include <string>

class Database
{
 protected:
  Database(){}
  //static Database database_;
 public:
  static Database& get(){ 
    static Database* database = new Database();
    return *database; 
  }
};


#endif