#include <iostream>
#include <fstream>

int main(int argc, const char *argv[]) {
	std::string base_dir;
	for (int i { 1 }; i < argc; ++i) {
		std::string arg { argv[i] };
		if (arg.substr(0, 7) == "--base=") {
			base_dir = arg.substr(7);
		} else {
			auto f { arg };
			if (! base_dir.empty() && f.substr(0, base_dir.size()) == base_dir) {
				f = f.substr(base_dir.size());
			}
			std::cout << "#line 1 \"" << f << "\"\n";
			std::ifstream in { arg.c_str() };
			std::cout << in.rdbuf() << '\n';
		}
	}
}
