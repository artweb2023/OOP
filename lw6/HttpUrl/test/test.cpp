#define CATCH_CONFIG_MAIN

#include "../HttpUrl/CHttpUrl.h"
#include "../HttpUrl/CUrlParsingError.h"
#include "/OOP/catch2/catch.hpp"


SCENARIO("Testing CHttpUrl")
{
	GIVEN("CHttpUrl instance created with full URL")
	{
		WHEN("Creating class CHttpUrl with full URL")
		{
			CHttpUrl httpUrl("https://www.website.com/document");
			THEN("Check url information")
			{
				REQUIRE(httpUrl.GetURL() == "https://www.website.com/document");
				REQUIRE(httpUrl.GetDomain() == "www.website.com");
				REQUIRE(httpUrl.GetPort() == 443);
				REQUIRE(httpUrl.GetDocument() == "/document");
				REQUIRE(httpUrl.GetProtocol() == Protocol::HTTPS);
			}
		}
		WHEN("Creating class CHttpUrl with default port for HTTP")
		{
			CHttpUrl httpUrl("http://www.website.com/document");
			THEN("Check url information")
			{
				REQUIRE(httpUrl.GetURL() == "http://www.website.com/document");
				REQUIRE(httpUrl.GetDomain() == "www.website.com");
				REQUIRE(httpUrl.GetPort() == 80);
				REQUIRE(httpUrl.GetDocument() == "/document");
				REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
			}
		}
		WHEN("Creating class CHttpUrl with domain, document and protocol")
		{
			CHttpUrl httpUrl("www.website.com", "/document", Protocol::HTTP);
			THEN("Check url information")
			{
				REQUIRE(httpUrl.GetURL() == "http://www.website.com/document");
				REQUIRE(httpUrl.GetDomain() == "www.website.com");
				REQUIRE(httpUrl.GetPort() == 80);
				REQUIRE(httpUrl.GetDocument() == "/document");
				REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
			}
		}
		WHEN("Creating class CHttpUrl with domain, document, protocol, and custom port")
		{
			CHttpUrl httpUrl("www.website.com", "/document", Protocol::HTTPS, 8080);
			THEN("Check url information")
			{
				REQUIRE(httpUrl.GetURL() == "https://www.website.com:8080/document");
				REQUIRE(httpUrl.GetDomain() == "www.website.com");
				REQUIRE(httpUrl.GetPort() == 8080);
				REQUIRE(httpUrl.GetDocument() == "/document");
				REQUIRE(httpUrl.GetProtocol() == Protocol::HTTPS);
			}
		}
		WHEN("Creating class CHttpUrl with domain, document, protocol, and custom port")
		{
			CHttpUrl httpUrl("http://www.website.com:1/document");
			THEN("Class instance is created")
			{
				REQUIRE(httpUrl.GetURL() == "http://www.website.com:1/document");
				REQUIRE(httpUrl.GetDomain() == "www.website.com");
				REQUIRE(httpUrl.GetPort() == 1);
				REQUIRE(httpUrl.GetDocument() == "/document");
				REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
			}
		}
		WHEN("Creating class CHttpUrl with domain, document, protocol, and custom port")
		{
			CHttpUrl httpUrl("http://www.website.com:65535/document");
			THEN("Class instance is created")
			{
				REQUIRE(httpUrl.GetURL() == "http://www.website.com:65535/document");
				REQUIRE(httpUrl.GetDomain() == "www.website.com");
				REQUIRE(httpUrl.GetPort() == 65535);
				REQUIRE(httpUrl.GetDocument() == "/document");
				REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
			}
		}
		WHEN("Creating class CHttpUrl with an invalid URL")
		{
			THEN("Throw CUrlParsingError")
			{
				REQUIRE_THROWS_AS(CHttpUrl("invalid_url"), CUrlParsingError);
			}
			THEN("Throw CUrlParsingError")
			{
				REQUIRE_THROWS_AS(CHttpUrl("http://www.website.com:0/document.html"), CUrlParsingError);
			}
			THEN("Throw CUrlParsingError")
			{
				REQUIRE_THROWS_AS(CHttpUrl("http://www.website.com:65536/document.html"), CUrlParsingError);
			}
			THEN("Throw CUrlParsingError")
			{
				REQUIRE_THROWS_AS(CHttpUrl("http:///www.website.com/docs/document1.html"), CUrlParsingError);
			}
		}

	}
}