#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string vals;
	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-1\\Input.txt");
	if (!in.fail()) {
		getline(in, vals);
	}
	int counter = 0;
	for (unsigned int i = 0; i < vals.size()-1; i++) {
		if (vals.at(i) == vals.at(i + 1)) {
			counter += (int)vals.at(i) - (int)'0';
		}
	}

	if (vals.at(0) == vals.at(vals.size() - 1))
		counter += (int)(vals.at(0))-(int)'0';

	cout << "sum = " << counter << endl;

	return 0;

}