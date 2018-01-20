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
	vector<string> vals_comp;
	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, line);
			if (line.find('>') != string::npos) {
				vals.push_back(line);
			}
			else
				vals_comp.push_back(line);
		}
	}
	in.close();
	string bottom;
	for (unsigned int i = 0; i < vals.size(); i++) {
		size_t found = vals.at(i).find("fbgguv");
		if (found != string::npos) {
			bottom = vals.at(i);
			break;
		}
	}
		
	vector<pair<string, int> > sons;
	string weight;
	stringstream frase(bottom);
	frase >> bottom;
	frase >> weight;
	while (!frase.eof()) {
		string n;
		pair<string, int> aux;
		frase >> n;
		aux.first = n;
		aux.second = 0;
		sons.push_back(aux);
	}

	int valor = 1864;

	cout << "valor = " << valor << endl;
	/*
		fbgguv (57): bkomu42437 tynxlau32867 sfruur62 zxvbb56366 khupkt63041 xkntkvz44502
	*/

	return 0;
}