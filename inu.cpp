#include <cstdio>
#include <iostream>
#include <filesystem>

int
main(int argc, char** argv)
{
	if (argc < 2 ) { printf("inu: argument 1: name directory");  }

	for (int i = 1; i < argc; i++)
	{
		std::string path = argv[i];
		if (!std::filesystem::exists(argv[i]) || !std::filesystem::is_directory(argv[i])) {
			std::cout << "not found entry or not a directory: " << path << "\n";
			continue;
		}
		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(path))
			{
				std::cout << entry.path().filename().string() << "\n";
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cout << "inu: err \n" << e.what();
		}
	}

	return 0;
}