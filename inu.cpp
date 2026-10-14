#include <cstdio>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

char*
open_path(char** name) {
	if (name == 0x0 || *name == 0x0) { return 0x0; }

	char* path = *name;
	if (!fs::exists(*name) || !fs::is_directory(*name)) { std::cout << "not found entry or not a directory :" << path << "\n"; 
		return 0x0;

	} 

	return path;
}

int
main(int argc, char** argv)
{
	if (argc < 2) { printf("inu: argument 1: name directory"); return 1; }

	for (int i = 1; i < argc; i++)
	{
		char* directory = open_path(&argv[i]);
		if (directory == 0x0) { continue; }
		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(directory))
			{
				std::wcout << entry.path().filename().native() << "\n";
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cout << "inu: err \n" << e.what();
		}
	}

	return 0;
}