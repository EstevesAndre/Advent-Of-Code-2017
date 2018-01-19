#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-5\\Input.txt");
	string line;
	vector<int> val;
	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, line);
			if (line.at(0) == '-') {
				line = line.substr(2, line.size() - 1);
				int a = stoi(line);
				val.push_back(-a);
			}
			else {
				val.push_back(stoi(line));
			}
		}
	}

	int counter = 0, i = 0;
	while (i < val.size()) {
		int a = i;
		i += val.at(i);
		if (val.at(a) < 3)
			val.at(a) += 1;
		else
			val.at(a) -= 1;
		counter++;
		if (i >= val.size())
			break;
	}
	cout << "sum = " << counter << endl;

	return 0;
}