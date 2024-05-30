#include "CHttpUrl.h"
#include "CUrlParsingError.h"

namespace
{

	Protocol ParseProtocol(const std::string& protocol)
	{
		std::string result(protocol);
		std::transform(result.begin(), result.end(), result.begin(),
			[](unsigned char ch) { return std::tolower(ch); });
		if (result == "http")
		{
			return Protocol::HTTP;
		}
		if (result == "https")
		{
			return Protocol::HTTPS;
		}
		throw CUrlParsingError("Invalid protocol");
	}

	unsigned short ParsePort(const std::string& portStr)
	{
		if (portStr.empty())
		{
			throw CUrlParsingError("Invalid port");
		}
		for (char ch : portStr)
		{
			if (!std::isdigit(ch))
			{
				throw CUrlParsingError("Invalid port");
			}
		}
		int port = std::stoi(portStr);
		if (port < 1 || port > 65535)
		{
			throw CUrlParsingError("Invalid port");
		}
		return static_cast<unsigned short>(port);
	}

	std::string ParseDocument(const std::string& document)
	{
		if (document.empty() || document[0] != '/')
		{
			return "/" + document;
		}
		return document;
	}

	bool IsDefaultPort(unsigned short port, Protocol protocol)
	{
		return port == static_cast<unsigned short>(protocol);
	}

	std::string ComposeURL(Protocol protocol, const std::string& domain, unsigned short port, const std::string& document)
	{
		std::string url;
		switch (protocol)
		{
		case Protocol::HTTP:
			url.append("http://");
			break;
		case Protocol::HTTPS:
			url.append("https://");
			break;
		default:
			break;
		}
		if (domain == "/")
		{
			url.append("");
		}
		else
		{
			url.append(domain);
		}
		if (IsDefaultPort(port, protocol))
		{
			url.append("");
		}
		else
		{
			url.append(":" + std::to_string(port));
		}
		url.append(document);
		if (url.back() == '/')
		{
			url.pop_back();
		}
		return url;
	}
}

CHttpUrl::CHttpUrl(const std::string& url)
{
	ParseURL(url);
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol)
	: CHttpUrl(domain, document, protocol, static_cast<unsigned short>(protocol))
{
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
{
	if (domain.empty())
	{
		throw CUrlParsingError("Invalid URL");
	}
	if (port < 1 || port > 65535)
	{
		throw CUrlParsingError("Invalid port");
	}
	m_protocol = protocol;
	m_domain = domain;
	m_port = port;
	m_document = ParseDocument(document);
	m_url = ComposeURL(m_protocol, m_domain, m_port, m_document);
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void CHttpUrl::ParseURL(const std::string& url)
{
	std::regex urlRegex(R"((\w+):\/\/([^\/:]+)(?::([^\/]*))?\/?(.*?))");
	std::smatch result;

	if (!std::regex_match(url, result, urlRegex))
	{
		throw CUrlParsingError("Ivalid URL");
	}
	m_protocol = ParseProtocol(result[1]);
	if (result[3].matched)
	{
		m_port = ParsePort(result[3]);
	}
	else
	{
		m_port = static_cast<unsigned short>(m_protocol);
	}
	m_domain = result[2];
	m_document = ParseDocument(result[4]);
	m_url = ComposeURL(m_protocol, m_domain, m_port, m_document);
}