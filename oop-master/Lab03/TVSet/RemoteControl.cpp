#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"

using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTVSet& tv, std::istream& input, std::ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "TurnOn", [this](std::istream& strm) { return TurnOn(strm); } },
		  { "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) },
		  { "Info", bind(&CRemoteControl::Info, this, _1) },
		  { "SelectChannel", bind(&CRemoteControl::SelectChannel, this, _1) },
		  { "SelectPreviousChannel", bind(&CRemoteControl::SelectPreviousChannel, this, _1) } })
{
}

bool CRemoteControl::TurnOn(std::istream&)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << std::endl;
	return true;
}

bool CRemoteControl::TurnOff(std::istream&)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << std::endl;
	return true;
}

bool CRemoteControl::Info(std::istream&)
{
	std::string info = (m_tv.IsTurnedOn())
		? ("TV is turned on\nChannel is: " + std::to_string(m_tv.GetChannel()) + "\n")
		: "TV is turned off\n";

	m_output << info;

	return true;
}

bool CRemoteControl::SelectChannel(std::istream& args)
{
	int channel;
	args >> channel;
	if (!m_tv.IsTurnedOn())
	{
		m_output << "Can't select channel because TV is turned off\n" ;
	}
	else if (!m_tv.SelectChannel(channel))
	{
		m_output << "Invalid channel\n";
	}
	else
	{
		m_output << "Channel selected\n";
	}

	return true;
}

bool CRemoteControl::SelectPreviousChannel(std::istream&)
{
	if (!m_tv.IsTurnedOn())
	{
		m_output << "Can't select channel because TV is turned off\n";
	}
	else
	{
		m_tv.SelectPreviousChannel();
		m_output << "Channel selected\n" ;
	}

	return true;
}

bool CRemoteControl::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}
