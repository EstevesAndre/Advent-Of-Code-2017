#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-7\\Input.txt");
	string line;
	vector<string> vals;

	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, line);
			if (line.find('>') != string::npos) {
				vals.push_back(line);
			}
		}
	}

	for (unsigned int i = 0; i < vals.size(); i++) {
		int indice = 0;
		for (unsigned int k = 0; k < vals.at(i).size(); k++) {
			if (vals.at(i).at(k) == ' ') {
				indice = k;
				break;
			}
		}
		string name = vals.at(i).substr(0, indice);
		bool existe = false;
		for (unsigned int k = 0; k < vals.size(); k++) {
			if (k != i) {
				size_t found = vals.at(k).find(name);
				if (found != string::npos) {
					existe = true;
					break;
				}
			}
		}
		if (!existe) {
			cout << "bottom = " << name << endl;
			return 0;
		}
	}

	return 0;
}