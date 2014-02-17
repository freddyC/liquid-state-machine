#include <vector>
#include <memory>
#include <iostream>
#include "liquid.h"

int main(){
	Liquid liquid({3, 3, 3});
	for(auto &neuron : liquid.neurons){
		std::cout<<"(";
		for(auto &coord : neuron->position){
			std::cout<<coord<<" ";
		}
		std::cout<<", #conn: "<<neuron->connections.size()<<")";
		std::cout<<std::endl;
	}
}
