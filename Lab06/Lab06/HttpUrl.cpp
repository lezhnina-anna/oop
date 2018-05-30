#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

namespace
{
std::string ProtocolToString(const Protocol& protocol)
{
	switch (protocol)
	{
	case Protocol::HTTP:
		return "http";
	case Protocol::HTTPS:
		return "https";
	default:
		throw std::invalid_argument("Error when parsed protocol");
	}
}

bool IsValidPort(const int port)
{
	return (port > 0 && port <= 65535);
}

bool IsValidDocument(const std::string& document)
{
	return (document.find(' ') == std::string::npos);
}

bool IsValidDomain(const std::string& domain)
{
	if (domain.empty())
	{
		throw CUrlParsingError("Empty domain");
	}

	return (domain.find(' ') == std::string::npos);
}
Protocol ParseProtocol(const std::string& url)
{
	auto protocolEnd = url.find("://");
	if (protocolEnd == std::string::npos)
	{
		throw CUrlParsingError("Invalid protocol");
	}

	std::string protocol(url.begin(), url.begin() + protocolEnd);

	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Invalid protocol");
	}
}

std::string ParseDomain(const std::string& url)
{
	auto domainEnd = url.find(':');

	if (domainEnd == std::string::npos)
	{
		domainEnd = url.find("/");

		if (domainEnd == std::string::npos)
		{
			domainEnd = url.length();
		}
	}

	std::string domain(url.begin(), url.begin() + domainEnd);

	if (!IsValidDomain(domain))
	{
		throw CUrlParsingError("Invalid domain");
	}

	return domain;
}

unsigned short ParsePort(const std::string& url)
{
	auto portEnd = url.find('/');

	if (portEnd == std::string::npos)
	{
		portEnd = url.length();
	}

	std::string strPort(url.begin() + 1, url.begin() + portEnd);

	if (strPort.find(' ') != std::string::npos)
	{
		throw CUrlParsingError("Unexpected symbol");
	}

	try
	{
		int port = stoi(strPort);
		if (!IsValidPort(port))
		{
			throw CUrlParsingError("Port is out of range.");
		}
		return port;
	}
	catch (std::invalid_argument)
	{
		throw CUrlParsingError("Invalid port");
	}
}

std::string ParseDocument(const std::string& url)
{
	if (url.empty())
	{
		return "/";
	}

	auto document = url;
	if (!IsValidDocument(document))
	{
		throw CUrlParsingError("Invalid document");
	}

	return document;
}

} // namespace

unsigned short CHttpUrl::GetPortByProtocol() const
{
	switch (m_protocol)
	{
	case Protocol::HTTP:
		return 80;
	case Protocol::HTTPS:
		return 443;
	default:
		throw std::invalid_argument("Error when parsed protocol");
	}
}

std::ostream& operator<<(std::ostream& output, const Protocol& value)
{
	output << ProtocolToString(value);
	return output;
}

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Empty url");
	}

	m_protocol = ParseProtocol(url);
	auto restOfUrl = url.substr(ProtocolToString(m_protocol).size() + 3, url.size() - 1);

	m_domain = ParseDomain(restOfUrl);
	restOfUrl = restOfUrl.substr(m_domain.size(), restOfUrl.size());

	if (restOfUrl[0] == ':')
	{
		m_port = ParsePort(restOfUrl);
		restOfUrl = restOfUrl.substr(std::to_string(m_port).size() + 1, restOfUrl.size() - 1);
	}
	else
	{
		m_port = GetPortByProtocol();
	}

	m_document = ParseDocument(restOfUrl);
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
{
	if (!IsValidDomain(m_domain) || !IsValidPort(m_port) || !IsValidDocument(m_document))
	{
		throw std::invalid_argument("Invalid url");
	}
	m_port = GetPortByProtocol();
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)
{
	if (!IsValidDomain(m_domain) || !IsValidPort(m_port) || !IsValidDocument(m_document))
	{
		throw std::invalid_argument("Invalid url");
	}
}

std::string CHttpUrl::GetURL() const
{
	std::string url = ProtocolToString(m_protocol)
		+ "://"
		+ m_domain;

	if ((m_port == 80 && m_protocol == Protocol::HTTP)
		|| (m_port == 443 && m_protocol == Protocol::HTTPS))
	{
		return url += m_document;
	}

	return (url += ":" + std::to_string(m_port) + m_document);
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}
