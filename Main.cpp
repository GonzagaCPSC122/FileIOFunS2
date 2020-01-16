#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void openFile(ifstream&, string);
void processFile(ifstream&);

int main() {
	// open the file
	ifstream inFile;
	openFile(inFile, "sentence.txt");
	// process file
	processFile(inFile);
	// close file
	inFile.close();

	return 0;
}

void processFile(ifstream& inFile) {
	string line, word;
	istringstream iss;
	
	while (!inFile.eof()) {
		// read line by line from the file
		getline(inFile, line);
		if (inFile.good()) {
			//cout << line << endl;
			// read word by word from the line
			iss.clear();
			iss.str(line);
			while (iss.good()) {
				iss >> word;
				//cout << word << endl;
				// read char by char from word
				for (char c : word) {
					cout << c << endl;
				}
			}
		}
	}
}

void openFile(ifstream& inFile, string fname) {
	inFile.open(fname);
	if (inFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
