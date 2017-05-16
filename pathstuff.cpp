/*
	path environment variable shortcut functions for pthmgr.
*/
#include <iostream>
#define EDITENV_STATIC
#include <editenv.hpp>
#include "versioninfo.hpp"
#include "pathstuff.hpp"

void show_usage() {
	std::cout << PTHMGR_DESCRIPTION << " v" << PTHMGR_VERSION
		<< "\nUsage:\n    " << INTERNAL_NAME << " add <folder>\n    "
		<< INTERNAL_NAME << " remove <folder>" << std::endl;
}

void add_path(const char* folder) {
	pathAdd(editenv::es_user, folder);
	pathAdd(editenv::es_system, folder);
	std::cout << "Added '" << folder << "' to path." << std::endl;
}

void remove_path(const char* folder) {
	pathRemove(editenv::es_user, folder);
	pathRemove(editenv::es_system, folder);
	std::cout << "Removed '" << folder << "' from path." << std::endl;
}
