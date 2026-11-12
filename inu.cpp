#include <cstdio>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"


char*
open_path(char * dirname) {

	if (!fs::exists(dirname) || !fs::is_directory(dirname)) {
        std::cout << "not found entry or not a directory :" << dirname << "\n"; 
		return NULL;
	} 

	return dirname;
}

int
main(int argc, char ** argv)
{
	if (argc < 2) { printf("usage: inu directory path"); return 1; }

	for (int i = 1; i < argc; i++)
	{
		char* directory = open_path(argv[i]);

		if (directory == 0x0) { continue; }
		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(directory))

			{
                if (entry.is_directory()) {
                    std::cout << COLOR_GREEN << entry.path().filename().string() << COLOR_RESET << '\n';
                } else {
                    std::cout << entry.path().filename().native() << '\n';
                }
			}
		}

		catch (const std::filesystem::filesystem_error& e) {
			std::cout << "inu: error \n" << e.what();
		}
	}

	return 0;
}
