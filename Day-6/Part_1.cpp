#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


bool found(vector<vector<int> > banks, vector<int> move) {
	for (unsigned int i = 0; i < banks.size(); i++) {
		if (move == banks.at(i))
			return true;
	}
	return false;
}
unsigned int get_indice_max(vector<int> val) {
	int v = -1;
	unsigned int i, x = 0;
	for (i = 0; i < val.size(); i++) {
		if (v < val.at(i)) {
			v = val.at(i);
			x = i;
		}
	}
	return x;
}

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-6\\Input.txt");
	string line;

	if (!in.fail())
		getline(in, line);
	in.close();

	stringstream l(line);
	int v;
	vector<int> val;
	while (!l.eof()) {
		l >> v;
		val.push_back(v);
	}

	int sum = 1;
	vector<vector<int> > banks;
	banks.push_back(val);
	vector<int> move = val;

	while (1) {

		unsigned int indice = get_indice_max(move), j = indice + 1, times = move.at(indice);

		for (unsigned int i = 0; i < times; i++) {
			if (j == move.size())
				j = 0;
			move.at(j) += 1;
			move.at(indice) -= 1;
			j++;

		}

		if (found(banks, move))
			break;
		sum++;
		banks.push_back(move);

	}

	cout << "sum = " << sum << endl;

	return 0;
}