/*
	pthmgr.cpp

	Windows path environment variable command line manager.
*/
#include <iostream>
#include "pathstuff.hpp"


int main(int argc, char* argv[]) {
	std::string command;
	if (argc < 2) {
		std::cout << PTHMGR_DESCRIPTION << " v" << PTHMGR_VERSION
			<< "\nUsage:\n    " << INTERNAL_NAME << " add <folder>\n    "
			<< INTERNAL_NAME << " remove <folder>" << std::endl;
	} else {
		command = argv[1];
		if (command == "add") {
			add_path(argv[2]);
		} else if(command == "remove") {
			remove_path(argv[2]);
		}
	}
	return 0;
}
