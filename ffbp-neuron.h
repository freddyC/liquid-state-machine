#ifndef FFBP_NEURON_H
#define FFBP_NEURON_H

#include <vector>
#include <memory>
#include <random>

class Neuron{
  public:
    float multiplier;
    float threshold;
    std::vector<std::shared_ptr<Neuron>> connections;

    Neuron();
    void recieveInput (float);
    void recieveInput (float, float);
  private:

    void transmit (float);
    float randomRange (int = -1, int = 1);

};

#endif
