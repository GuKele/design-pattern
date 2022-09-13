#ifndef _NEURON_H_
#define _NEURON_H_

#include <vector>
#include <iostream>

template <typename Self>
class BaseNeuron
{
  //通过begin/end将单个对象伪装成集合后，使用模板来实现单个对象和集合相同接口
  //duck typing，一个对象有效语义由　当前方法和属性的集合　来决定
 public:
  template <typename Other>
  void connect_to(Other& other){
    //static_cast<Self>，才会不报错说没有begin、end以及out_ 、 in_
    for(auto& from : *static_cast<Self*>(this)){
      for(auto& to : other){
        from.out_.push_back(&to);
        to.in_.push_back(&from);
        std::cout << from.getId() << " connect " << to.getId() << std::endl;
      }
    }
  }

};

class Neuron : public BaseNeuron<Neuron>
{
private:
  static unsigned int count_;
  unsigned int id_;

 public:  

  std::vector<Neuron*> in_, out_;

  Neuron() : id_(count_++) {}; 
  ~Neuron() = default;
// begin/end 实现了将单个对象伪装成集合
  Neuron* begin() { return this; }
  Neuron* end() { return this + 1; }

  unsigned int getId() const { return id_; }
};

class NeuronLayer : public std::vector<Neuron>, public BaseNeuron<NeuronLayer>
{
 public:
  NeuronLayer(int count){ 
    while(count-- > 0){
      emplace_back(Neuron());
    }
  }
/* 
  可以两个类中都单独写一个模板函数，也可以直接继承一个模板类，该模板类中有通用模板函数
  template <typename Other>
  void connect(Other& other){
    for(auto& from : this){
      for(auto& to : other){
        from.out_.push_back(&to);
        to.in_.push_back(&from);
      }
    }
  }
*/
};




#endif