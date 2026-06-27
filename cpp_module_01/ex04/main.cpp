#include <string>
#include <fstream>

std::string readContent(std::ifstream& in) {
	std::string content, line;
	while (std::getline(in, line)) {
		if (!content.empty())
			content += "\n";
		content += line;
	}
	in.close();
	return content;
}

void replaceText(std::string& content, const std::string& s1, const std::string& s2) {
	size_t pos = 0;

	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
}

int writeFile(const std::string filename, std::string& content) {
	std::ofstream out(filename.c_str());
	if (!out.is_open())
		return (1);
	out << content;
	out.close();
	return (0);
}

int	main(int argc, char** argv) {
	if (argc != 4)
		return (1);

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
		return(1);

	std::ifstream in(filename.c_str());
	if (!in.is_open())
		return (1);

	std::string content = readContent(in);
	replaceText(content, s1, s2);
	
	std::string newFilename = filename + ".replace";
	return (writeFile(newFilename, content));
}
