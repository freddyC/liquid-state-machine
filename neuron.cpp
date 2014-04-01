#include "neuron.h"

Neuron::Neuron(float threshold, float multiplier, std::vector<int> position)
  :threshold(threshold)
  ,multiplier(multiplier)
  ,position(position)
{}