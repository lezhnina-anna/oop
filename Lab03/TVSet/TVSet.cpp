// TVSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVSet.h"

bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

int CTVSet::GetChannel() const
{
	return m_isOn ? m_selectedChannel : 0;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

bool CTVSet::SelectChannel(int channel)
{
	if (m_isOn && channel > 0 && channel < 100)
	{
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}

	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		m_selectedChannel = m_previousChannel;
		return true;
	}

	return false;
}
