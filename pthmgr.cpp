/*
	pthmgr.cpp

	Windows path environment variable command line manager.
*/
#include <iostream>
#define EDITENV_STATIC
#include <editenv.hpp>

void inline add_path(const char* folder) {
	pathAdd(editenv::es_user, folder);
	pathAdd(editenv::es_system, folder);
	std::cout << "Added '" << folder << "' to path." << std::endl;
}

void inline remove_path(const char* folder) {
	pathRemove(editenv::es_user, folder);
	pathRemove(editenv::es_system, folder);
	std::cout << "Removed '" << folder << "' from path." << std::endl;
}

int main(int argc, char* argv[]) {
	std::string command;
	if (argc < 2) {
		std::cout << "Windows(R) Path Environment Variable Manager\nUsage:\n    pthmgr add <folder>\n    pthmgr remove <folder>" << std::endl;
	}
	else {
		command = argv[1];
		if (command == "add") {
			add_path(argv[2]);
		}
		else if(command == "remove") {
			remove_path(argv[2]);
		}
	}
	return 0;
}
