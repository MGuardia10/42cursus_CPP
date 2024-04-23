#include "FileManager.hpp"

int main( int argc, char **argv ) {
	
	if (argc != 4) {
		std::cout << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		return 1;
	}

	for(int i = 1; argv[i]; i++) {
		std::string aux = argv[i];
		if (aux.empty() && i != 3) {
			std::cout << RED << "Error: arguments 1 and 2 cannot be empty." << RESET << std::endl;
			return 1;
		}
	}

	std::string stringFile = argv[1];
	std::string stringSearch = argv[2];
	std::string stringReplace = argv[3];

	FileManager file(stringFile);
	FileManager newFile(stringFile + ".replace");

	/* Read from file argv 1 */
	std::string content = file.readFromFile();

	/* Copy content on new file */
	newFile.writeToFile( content );

	/* Replace argv 2 with argv 3 */
	newFile.replaceString( stringSearch, stringReplace );

	std::cout << GREEN << "Strings replaced successfully!!!" << RESET << std::endl;
	
	return 0;
}