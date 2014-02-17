#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <memory>

class Neuron{
	public:
		float potential;
		float newPotential;
		float multiplier;
		float threshold;
		std::vector<std::shared_ptr<Neuron>> connections;
		std::vector<int> position;
		//refractory period?
		Neuron(float threshold, float multiplier, std::vector<int> position);
};

#endif
