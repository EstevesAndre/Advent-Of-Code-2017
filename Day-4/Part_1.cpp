#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-4\\Input.txt");
	string line;
	int count = 0;

	if (!in.fail()) {
		while (!in.eof()) {
			getline(in, line);
			bool valid = true;
			vector<string> words;
			stringstream val(line);
			while (!val.eof()) {
				val >> line;
				for (unsigned int i = 0; i < words.size(); i++) {
					if (words.at(i) == line) {
						valid = false;
						break;
					}
				}
				if (!valid)
					break;
				words.push_back(line);
			}
			if (valid)
				count++;
		}
	}
	cout << "number = " << count << "\n";	

	return 0;
}