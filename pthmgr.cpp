/*
	pthmgr.cpp

	Windows path environment variable command line manager.
*/
#include <iostream>
#include "pathstuff.hpp"


int main(int argc, char* argv[]) {
	std::string command;
	if (argc < 2) {
		show_usage();
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
