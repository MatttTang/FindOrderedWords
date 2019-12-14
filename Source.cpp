// Author: Matthew Tang
// 
//
//
//
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
	//Issue with amount of arguments
	if (argc != 2) {
		std::cerr << "Invalid command line argument." << std::endl;
		return -1;
	}

	//Open the file using the command line argument
	std::ifstream rFile;
	rFile.open(argv[1]);

	//Create a variable to hold each line of text from the file
	std::string line;

	//Iterate through the file line by line
	while (std::getline(rFile, line))
	{
		bool isOrdered = true;
		// Iterate through each line, if the current char is of lower ASCII value than the last, the line is not ordered
		for (int i = 1; i < line.size(); i++) {
			if (tolower(line[i]) <= tolower(line[i - 1])) {
				isOrdered = false;
				break;
			}
				
		}
		
		if (isOrdered) {
			std::cout << line << std::endl;
		}
	}
	return 0;
}