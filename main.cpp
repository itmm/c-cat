#include <iostream>
#include <set>
#include <fstream>

int main(int argc, const char *argv[]) {
	std::set<std::string> files;
	for (int i { 1 }; i < argc; ++i) {
		files.insert(argv[i]);
	}
	for (const auto &file : files) {
		std::cout << "#line 1 \"" << file << "\"\n";
		std::ifstream in { file.c_str() };
		std::cout << in.rdbuf() << '\n';
	}
}
