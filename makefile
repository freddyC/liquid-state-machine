all: main.cpp
	g++ -std=c++11 -g -O3 main.cpp ffbp-neuron.cpp neuron.cpp liquid.cpp ffbp.cpp -o hlsm
