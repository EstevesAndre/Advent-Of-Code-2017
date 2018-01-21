#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

	unsigned int k = 0;
	for (unsigned int i = 0; i < line.size(); i++) {
		if (line.at(i) == ',') {
			string num = line.substr(k, i - k);
			k = i + 1;
			lengths.push_back(stoi(num));
		}
		else if (i == line.size() - 1) {
			string num = line.substr(k, i - k + 1);
			lengths.push_back(stoi(num));
		}
	}

	unsigned int pointer = 0; // initial position
	int skip_size = 0;

	for (unsigned int i = 0; i < lengths.size(); i++) {
		rev(pointer, lengths.at(i), list, skip_size);
	}

	cout << "Result = " << list.at(0) * list.at(1) << endl;

	return 0;
}