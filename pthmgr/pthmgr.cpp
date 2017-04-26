/*
	pthmgr.cpp

	Windows path environment variable command line manager.
*/
#include <iostream>
#include <editenv.hpp>

int main(int argc, char* argv[]) {
	std::string command, folder;
	if (argc < 2) {
		std::cout << "Windows(R) Path Environment Variable Manager\nUsage:\n    pthmgr add <folder>\n    pthmgr remove <folder>" << std::endl;
	}
	else {
		command = argv[1];
		folder = argv[2];
		if (command == "add") {
			pathAdd(editenv::es_user, folder.c_str());
			pathAdd(editenv::es_system, folder.c_str());
			std::cout << "Added '" + folder + "' to path." << std::endl;
		}
		else if(command == "remove") {
			pathRemove(editenv::es_user, folder.c_str());
			pathRemove(editenv::es_system, folder.c_str());
			std::cout << "Removed '" + folder + "' from path." << std::endl;
		}
	}
	return 0;
}
