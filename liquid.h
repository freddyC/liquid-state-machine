#ifndef LIQUID_H
#define LIQUID_H
	
#include "neuron.h"
#include <queue>
#include <random>
#include <ctime>

class Liquid{
	public:
		std::mt19937 rng;
		std::uniform_real_distribution<> dist;
		std::vector<std::shared_ptr<Neuron>> neurons;
		std::vector<int> dimensions;
		std::queue<std::shared_ptr<Neuron>> processQueue;
		Liquid(std::vector<int> dimensions);
		void makeNeurons(int depth, std::vector<int> &indexes);
		void connectNeurons();
};

#endif
