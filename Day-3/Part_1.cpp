#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-3\\Input.txt");

	string val;
	getline(in, val);

	int value = stoi(val);

	cout << "value = " << value << endl;
	
	int size = (int)sqrt(value) + 1;
	cout << "square size in that moment = " << size << endl;

	cout << "last digit = " << size*size << endl;

	cout << size*size - value << endl;

	int steps = size / 2 - value % size + 1;
	cout << size / 2 - value % size + 1 << endl;
	
	steps += size / 2;

	cout << "Steps = " << steps << endl;
	return 0;

}