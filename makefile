all: main.cpp ffbp.o ffbp-neuron.o liquid.o liquid-neuron.o
	g++ -std=c++11 -g -O3 main.cpp ffbp-neuron.o ffbp.o liquid.o liquid-neuron.o -o hlsm

ffbp.o: ffbp.cpp
	g++ -std=c++11 -g -c -O3 ffbp.cpp -o ffbp.o

ffbp-neuron.o: ffbp-neuron.cpp ffbp-neuron.h
	g++ -std=c++11 -g -c -O3 ffbp-neuron.cpp -o ffbp-neuron.o

liquid-neuron.o: neuron.cpp
	g++ -std=c++11 -g -c -O3 neuron.cpp -o liquid-neuron.o

liquid.o: liquid.cpp
	g++ -std=c++11 -g -c -O3 liquid.cpp -o liquid.o
