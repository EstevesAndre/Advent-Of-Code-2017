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
	int high, small;
	for (unsigned int i = 0; i < vals.size(); i++) {

		stringstream line(vals.at(i));

		int valor;
		line >> valor;
		high = valor;
		small = valor;

		while (!line.eof()) {
			line >> valor;
			cout << valor << endl;

			if (valor > high)
				high = valor;
			else if (valor < small)
				small = valor;
		}
		cout << high << " - " << small << endl;
		sum += high - small;
	}

	cout << "Sum = " << sum << endl;
	return 0;

}