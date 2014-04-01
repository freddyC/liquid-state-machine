#include "ffbp-neuron.h"

Neuron::Neuron()
  : threshold(randomRange())
  , multiplier(randomRange())
{}

void Neuron::recieveInput (float input, float weight) {
  if (input * weight > threshold) {
    transmit(input * weight);
  }
}

void Neuron::recieveInput (float input) {
  // for input layer
  if (input > threshold) {
    transmit(input);
  }
}

void Neuron::transmit (float value) {
  for (auto neuron : connections) {
    neuron->recieveInput(value, multiplier);
  }
}

float Neuron::randomRange (int min, int max){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(min, max);
  return dis(gen);
}
