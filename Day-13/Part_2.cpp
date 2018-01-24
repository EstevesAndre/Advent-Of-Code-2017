#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

unsigned int  k = 0;

bool is_caught( const vector<pair<int, int>>& layers, int wait)
{
	int s = 0;

	for (unsigned int i = 0; i < layers.size(); i++)
	{
		k++;
		s++;
		if ((wait + layers.at(i).first) % ((layers.at(i).second * 2) - 2) == 0) { 
			cout << k << " = " << s << endl;
			return true; }
	}

	return false;
}

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-13\\Input.txt");

	string line;
	// txt file, last number is 88
	vector<pair<int, int>> layers;

	int depth, layer_n;
	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, line);
			stringstream val(line);
			string layer;
			val >> layer;
			val >> depth;
			layer = layer.substr(0, layer.size() - 1);
			layer_n = stoi(layer);
			//depth = (depth - 1) * 2; // time to get back to top of the layer
			pair<int, int> aux = make_pair(layer_n, depth);
			layers.push_back(aux);
		}
		in.close();
	}
	
	int wait{ 0 };
	while (is_caught(layers, wait)) { ++wait; }

	cout << "Result = " << wait << endl;

	return 0;
}

//3960702
