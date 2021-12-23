#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, const char *argv[]) {
	std::vector<std::string> files;
	std::string base_dir;
	for (int i { 1 }; i < argc; ++i) {
		std::string f { argv[i] };
		if (f.substr(0, 7) == "--base=") {
			base_dir = f.substr(7);
		} else {
			files.push_back(f);
		}
	}
	for (const auto &file : files) {
		std::string f { file };
		if (! base_dir.empty() && f.substr(0, base_dir.size()) == base_dir) {
			f = f.substr(base_dir.size());
		}
		std::cout << "#line 1 \"" << f << "\"\n";
		std::ifstream in { file.c_str() };
		std::cout << in.rdbuf() << '\n';
	}
}
