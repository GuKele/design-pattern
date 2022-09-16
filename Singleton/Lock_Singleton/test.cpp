#include "Database_lock.h"

#include <iostream>

int main(){
  auto database = Database::instance();
  std::cout << "finished" << std::endl;
  return 0;
}