#pragma once

#include <iostream>
#include <regex>
#include <sstream>
#include <string>

enum class Protocol
{
	HTTP = 80,
	HTTPS = 443,
};

class CHttpUrl
{
public:
	CHttpUrl(const std::string& url);
	CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port);
	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
private:
	void ParseURL(const std::string& url);
	Protocol m_protocol;
	std::string m_url;
	std::string m_domain;
	int m_port;
	std::string m_document;
};