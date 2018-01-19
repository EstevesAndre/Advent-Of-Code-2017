#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	vector <string> vals;
	string aux;

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-2\\Input.txt");

	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, aux);
			vals.push_back(aux);
		}
	}
	int sum = 0;
	for (unsigned int i = 0; i < vals.size(); i++) {

		stringstream line(vals.at(i));

		int valor;
		line >> valor;

		vector<int> numbers;
		numbers.push_back(valor);
		while (!line.eof()) {
			line >> valor;
			numbers.push_back(valor);
		}
		for (unsigned int k = 0; k < numbers.size()-1; k++) {
			for (unsigned int j = k + 1; j < numbers.size(); j++) {
				if (numbers.at(k) > numbers.at(j)) {
					if (numbers.at(k) % numbers.at(j) == 0) {
						sum += numbers.at(k) / numbers.at(j);
						break;
					}
				}
				else {
					if (numbers.at(j) % numbers.at(k) == 0) {
						sum += numbers.at(j) / numbers.at(k);
						break;
					}
				}
			}
		}
	}

	cout << "Sum = " << sum << endl;
	return 0;

}