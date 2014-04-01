#include "liquid.h"
#include <algorithm>
#include <cmath>
#include <functional>

Liquid::Liquid(std::vector<int> dimensions)
	:neurons()
	,dimensions(dimensions)
	,rng(time(NULL))
	,dist(-1, 1){
		std::vector<int> indexes(dimensions.size());
		makeNeurons(dimensions.size(), indexes);
		connectNeurons();
}

void Liquid::connectNeurons(){
	for(int i = 0; i < neurons.size() - 1; ++i){
		for(int j = i + 1; j < neurons.size(); ++j){
			int tempSum = 0;
			for(int k = 0; k < neurons[i]->position.size(); ++k){
				tempSum += pow(neurons[i]->position[k] - neurons[j]->position[k], 2);
			}
			if(sqrt(tempSum) < 1.5){  //TODO: add randomness here
				neurons[i]->connections.push_back(neurons[j]);
			}
		}
	}
}

void Liquid::makeNeurons(int depth, std::vector<int> &indexes){
	if(depth > 0){
		for(int i = 0; i < dimensions[depth - 1]; ++i){
			indexes[depth - 1] = i;
			makeNeurons(depth - 1, indexes);
		}
	}
	else{
		neurons.push_back(std::make_shared<Neuron>(dist(rng), dist(rng), indexes));
	}
}