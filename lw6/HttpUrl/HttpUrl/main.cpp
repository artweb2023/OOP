#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
	std::string url;
	while (std::getline(std::cin, url))
	{
		try
		{
			CHttpUrl httpUrl(url);
			std::cout << "URL: " << httpUrl.GetURL() << "\n";
			std::cout << "Domain: " << httpUrl.GetDomain() << "\n";
			std::cout << "Document: " << httpUrl.GetDocument() << "\n";
			std::cout << "Protocol: " << (httpUrl.GetProtocol() == Protocol::HTTPS ? "https" : "http") << "\n";
			std::cout << "Port: " << httpUrl.GetPort() << "\n";
		}
		catch (const CUrlParsingError& e)
		{
			std::cerr << "Error: " << e.what() << "\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	return 0;
}