#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
bool analise_words(string w1, string w2) {

	if (w1.size() != w2.size())
		return false;
	
	for (int i = 0; i < w1.size(); i++) {
		bool found = true;
		for (int j = 0; j < w2.size(); j++) {
			if ((int)w2.at(j) == (int)w1.at(i)) {
				string aux_w1,aux_w2;
				for (unsigned int k = 0; k < w1.size(); k++) {
					if (k != i)
						aux_w1 += w1.at(k);
				}
				w1 = aux_w1;
				for (unsigned int k = 0; k < w2.size(); k++) {
					if (k != j)
						aux_w2 += w2.at(k);
				}
				w2 = aux_w2;
				i--;
				j--;
				found = false;
				break;
			}
		}
		if (found)
			return false;
	}
	if (w1 == "" && w2 == "")
		return true;

	return false;
}

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
					if (analise_words(line, words.at(i))) {
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