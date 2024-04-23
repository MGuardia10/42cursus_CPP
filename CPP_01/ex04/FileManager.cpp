#include "FileManager.hpp"

FileManager::FileManager( std::string fileName ) {
	this->fileName = fileName;
}

FileManager::~FileManager( void ) {}

std::string	FileManager::readFromFile( void ) {

	std::ifstream	readFile;
	std::string		content = "";
	std::string		aux;

	readFile.open(this->fileName, std::ios::in);
	if (!readFile.is_open()) {
		std::cout << RED << "Error: Cannot open the file specified." << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	while (std::getline(readFile, aux)) {
		content += aux;
		if (!readFile.eof())
			content += '\n';
	}

	readFile.close();

	return content;
}

void	FileManager::writeToFile( std::string content ) {
	
	std::ofstream	writeFile;

	writeFile.open(this->fileName, std::ios::out | std::ios::trunc);
	if (!writeFile.is_open()) {
		std::cout << RED << "Error: Cannot open the file specified." << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	writeFile << content;

	writeFile.close();

}

void	FileManager::replaceString( std::string str1, std::string str2 ) {
	
	std::string content = this->readFromFile();
	if (content.find(str1) == std::string::npos)
		return ;

	std::fstream	modFile(this->fileName, std::ios::out | std::ios::trunc);
	if (!modFile.is_open()) {
		std::cout << RED << "Error: Cannot open the file specified." << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	size_t		posFound;
	size_t		posContent = 0;
	std::string	aux;

	while (1) {
		posFound = content.find(str1, posContent);
		aux = content.substr(posContent, posFound - posContent);
		modFile << aux;
		if (posFound == std::string::npos) 
			break ;
		modFile << str2;
		posContent = posFound + str1.length();
	}

	modFile.close();
}
