#include <cstdio>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"


char*
open_path(char** name) {
	if (name == NULL || *name == NULL) { return NULL; }

	char* path = *name;
	if (!fs::exists(*name) || !fs::is_directory(*name)) {
        std::cout << "not found entry or not a directory :" << path << "\n"; 
		return NULL;
	} 

	return path;
}

int
main(int argc, char** argv)
{
	if (argc < 2) { printf("usage: inu directory path"); return 1; }
	for (int i = 1; i < argc; i++)
	{
		char* directory = open_path(&argv[i]);
		if (directory == NULL) { continue; }
		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(directory))
			{
                if (entry.is_directory()) {
                    std::cout << COLOR_GREEN << entry.path().filename().string() << COLOR_RESET << '\n';
                }

                std::cout << entry.path().filename().native() << '\n';
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cout << "inu: error \n" << e.what();
		}
	}

	return 0;
}
