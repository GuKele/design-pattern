#include "Neuron.h"

int main(){
  Neuron n1, n2;
  NeuronLayer l1(5), l2(3);

  n1.connect_to(n2);
  n1.connect_to(l1);
  l1.connect_to(n2);
  l1.connect_to(l2);

  return 0;
}