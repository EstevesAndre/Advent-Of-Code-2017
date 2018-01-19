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
	
	for (unsigned int i = 0; i < vals.size() / 2; i++) {
		if (vals.at(i) == vals.at(vals.size()/2 + i)) {
			cout << "i = " << i << " : " << vals.at(i) << " -> " << "i = " << vals.size() / 2 + i << " : "<< vals.at(vals.size() / 2 + i) << endl;
			counter += 2*((int)vals.at(i) - (int)'0');
			cout << "sum = " << counter << endl;
		}
	}
	cout << vals.size() << endl;
	cout << "sum = " << counter << endl;

	return 0;

}