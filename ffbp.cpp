#include "ffbp.h"

void FFBP::getInput (std::vector<float> input) {
  assert(input.size() == inLayer.size());
  for (auto i = 0; i < input.size(); ++i) {
    inLayer[i]->recieveInput(input[i]);
  }
}

void FFBP::init (int inSize, int outSize) {
  inLayer.empty();
  for (auto i = 0; i < inSize; ++i) {
    inLayer.push_back( std::make_shared<Neuron>() );
  }

  outLayer.empty();
  for (auto i = 0; i < inSize; ++i) {
    outLayer.push_back( std::make_shared<Neuron>() );
  }

  h1Layer.empty();
  for (auto i = 0; i < 5000; ++i) {
    h1Layer.push_back( std::make_shared<Neuron>() );
  }

  h1Layer.empty();
  for (auto i = 0; i < 1000; ++i) {
    h1Layer.push_back( std::make_shared<Neuron>() );
  }

  for (auto i : inLayer) {
    for (auto k : h1Layer)
    if (getRand() > 0.2) { // percent of connections to the next layer
      auto temp = std::shared_ptr<Neuron>();
      temp = k;
      i->connections.push_back(temp);
    }
  }

  for (auto i : h1Layer) {
    for (auto k : h2Layer)
    if (getRand() > 0.2) { // percent of connections to the next layer
      auto temp = std::shared_ptr<Neuron>();
      temp = k;
      i->connections.push_back(temp);
    }
  }

  for (auto i : h2Layer) {
    for (auto k : outLayer)
    if (getRand() > 0.2) { // percent of connections to the next layer
      auto temp = std::shared_ptr<Neuron>();
      temp = k;
      i->connections.push_back(temp);
    }
  }
}


float FFBP::getRand () {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  return dis(gen);
}
