#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

void rev(unsigned int &pointer, unsigned int size, vector<int> &list, int &skip_size) {
	vector<int> aux;
	unsigned int pointer_aux = pointer;
	for (unsigned int i = 0; i < size; i++) {
		if (pointer_aux == list.size()) pointer_aux = 0;
		aux.push_back(list.at(pointer_aux));
		pointer_aux++;
	}

	for (int i = aux.size() - 1; i >= 0; i--) {
		if (pointer == list.size())
			pointer = 0;
		list.at(pointer) = aux.at(i);
		pointer++;
	}

	pointer = (pointer + skip_size) % list.size();

	skip_size++;
}

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-10\\Input.txt");

	string line;

	if (!in.fail()) {
		getline(in, line);
		in.close();
	}

	vector<int> list;

	for (unsigned int i = 0; i < 256; i++)
		list.push_back(i);

	vector<int> lengths;

	for (unsigned int i = 0; i < line.size(); i++) {
		lengths.push_back(int(line.at(i)));
	}

	lengths.push_back(17);
	lengths.push_back(31);
	lengths.push_back(73);
	lengths.push_back(47);
	lengths.push_back(23);

	unsigned int pointer = 0; // initial position
	int skip_size = 0;

	for (unsigned int j = 0; j < 64; j++) {
		for (unsigned int i = 0; i < lengths.size(); i++) {
			rev(pointer, lengths.at(i), list, skip_size);
		}
	}

	vector<int> dense_hash;
	for (unsigned int i = 0; i < 16; i++) {
		int hash = list.at(i * 16);
		for (unsigned int j = 1; j < 16; j++)
			hash ^= list.at(i * 16 + j);
		dense_hash.push_back(hash);
	}

	for (unsigned int i = 0; i < dense_hash.size(); i++)
		cout << hex << setw(2) << setfill('0') << dense_hash.at(i);

	cout << endl;

	return 0;
}