#include "Header.h"

int task3()
{
	std::vector<std::string> urls;
	urls.push_back("http://mytona.com/index.html");
	urls.push_back("https://mytona.com:8080/");
	urls.push_back("example.com");

	std::regex r();
	std::smatch m;
	std::regex e("(http|https)?(://)?([a-z.]+)?\\:?(\\d+)?\\/?([a-z.]+)?");
	for (std::vector<std::string>::iterator iter = urls.begin(); iter != urls.end(); iter++) {
		if (std::regex_match(*iter, m, e)) {
			std::string protocol = !m[1].str().empty() ? m[1].str() : "http";
			std::string host = !m[3].str().empty() ? m[3].str() : "host";
			std::string port = !m[4].str().empty() ? m[4].str() : "80";
			std::string page = !m[5].str().empty() ? m[5].str() : "/";
			std::cout << "Protocol: " + protocol + " Host: " + host + " Port: " + port + " Page: " + page << std::endl;
		}
	}
	system("pause");
	return 0;
}