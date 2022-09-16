#include "SingletonBase.h"

int main(){
  /*我们并不会直接使用SingletonBase::get()，
  **而是在函数调用中传参或者在类中存储一个Base*,
  **这样更灵活，我们的代码不止局限于只能使用单例对象
  */
  Base *ob = &SingletonBase::get();
  ob->get_population("beijing");
} 