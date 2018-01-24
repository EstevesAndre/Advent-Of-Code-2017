#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-13\\Input.txt");

	string line;
	// txt file, last number is 88
	vector<pair<int, int>> layers;
	for (unsigned int i = 0; i < 89; i++) {
		pair<int, int> aux = make_pair(i, 0);
		layers.push_back(aux);
	}

	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, line);
			stringstream val(line);
			string layer;
			int depth, layer_n;
			val >> layer;
			val >> depth;
			layer = layer.substr(0, layer.size() - 1);
			layer_n = stoi(layer);
			//depth = (depth - 1) * 2; // time to get back to top of the layer
			for (unsigned int i = 0; i < layers.size(); i++) {
				if (layers.at(i).first == layer_n) {
					layers.at(i).second = depth;
					break;
				}
			}
		}
		in.close();
	}



	//updates pointer
	//checks firewall
	//increments picosec


	int severity = 0;

	for (unsigned int i = 0; i < layers.size(); i++) {
		if (i == 0 || layers.at(i).second != 0)
		{
			if ((layers.at(i).first + 54411102)  % ((layers.at(i).second -1) * 2) == 0)
				severity += layers.at(i).second * layers.at(i).first;
		}
	}

	cout << "Result = " << severity << endl;

	return 0;
}