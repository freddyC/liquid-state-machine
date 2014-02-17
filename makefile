all: main.cpp
	g++ -std=c++11 -g -O3 main.cpp neuron.cpp liquid.cpp -o hlsm
