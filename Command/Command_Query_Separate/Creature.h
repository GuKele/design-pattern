#ifndef _CREATURE_H_
#define _CREATURE_H_


//命令：系统执行某些操作的指令，这些操作涉及状态的变化，但不产生任何值
//查询：这是对信息的请求，产生值但不改变状体

class Creature
{
private:
  int strength_, agility_;

public:
  enum CreatureAbility { kAtrength, kAgility };

  Creature(const int& strength, const int& agility) 
    : strength_(strength), agility_(agility) {
  }

  void command(const CreatureCommand& cc) {
    //使用CreatureCommand中的参数来执行真正的修改操作
  }

  int query(const CreatureQuery& cq) {
    //使用CreatureQuery中的参数来执行真正的查询操作
  }

};

//上边没有写完，他是将真正的修改和查询操作放在了Creature::command() 和 Creature::query()中
// CreatureCommand和CreatureQuery只是记录了参数，这样明明可以直接给Creature::command()传参
//没有搞明白为什么要这样，难道是方便设置更改和查询吗
class CreatureCommand {
 public: 
  Creature::CreatureAbility ability_;
  enum Action { set, increaseBy, decreaseBy } action_;
  int amount_;

  CreatureCommand(const Creature::CreatureAbility& ability, const Action action, const int& amount)
    : ability_(ability), action_(action), amount_(amount){
  }

};


class CreatureQuery {
  Creature::CreatureAbility ability_;
};



#endif