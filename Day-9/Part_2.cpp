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
	cout << "Initial size of the string = " << input.size() << endl;
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
	int size_garbage = 0;

	for (unsigned int i = 0; i < input.size(); i++)
	{
		if (input.at(i) == '<')
		{
			for (unsigned int k = i; k < input.size(); k++)
			{
				if (input.at(k) == '>')
				{
					size_garbage += k - i-1;
					i = k;
					break;
				
				}
			}
		}
	}
	cout << "garbage size = "<< size_garbage << endl;

	return 0;
}