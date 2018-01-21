#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-9\\Input.txt");
	string input;

	if (!in.fail()) {
		getline(in, input);
		in.close();
	}
	cout << input.size() << endl;
	bool existe = true;
	while (existe) { // all "!X" erased
		existe = false;
		for (unsigned int i = 0; i < input.size(); i++) {
			if (input.at(i) == '!') {
				input.erase(i, 2);
				i--;
				existe = true;
			}
		}
	}
	for (unsigned int i = 0; i < input.size(); i++)
	{
		if (input.at(i) == '<')
		{
			for (unsigned int k = i; k < input.size(); k++)
			{
				if (input.at(k) == '>')
				{
					input.erase(i, k - i + 1);
					existe = true;
					i--;
					break;
				}
			}
		}
	}

	
	int open_bracket = 0, score = 0;

	for (unsigned  int c = 0; c < input.size(); c++) {
		if (input.at(c) == '{') {
			open_bracket += 1;
			score += open_bracket;
		}
		else if (input.at(c) == '}')
			open_bracket -= 1;
	}

	cout << "score = " << score << endl;

	return 0;
}