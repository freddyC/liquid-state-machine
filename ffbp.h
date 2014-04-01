#ifndef FFBP_H
#define FFBP_H

#include "ffbp-neuron.h"
#include <cassert>
#include <vector>
#include <memory>
#include <random>


class FFBP{
  public:
    std::vector<std::shared_ptr<Neuron>> inLayer;
    std::vector<std::shared_ptr<Neuron>> h1Layer;
    std::vector<std::shared_ptr<Neuron>> h2Layer;
    std::vector<std::shared_ptr<Neuron>> outLayer;

    void getInput (std::vector<float>);
    void init (int inSize, int outSize);
  private:
    float getRand ();
};

#endif
