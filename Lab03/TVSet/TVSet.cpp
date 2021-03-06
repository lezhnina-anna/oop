// TVSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVSet.h"

const int MAX_CHANNEL_NUMBER = 99;
const int MIN_CHANNEL_NUMBER = 1;

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
	if (m_isOn && channel >= MIN_CHANNEL_NUMBER && channel <= MAX_CHANNEL_NUMBER)
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
		int newPreviousChannel = m_selectedChannel;
		m_selectedChannel = m_previousChannel;
		m_previousChannel = newPreviousChannel;
		return true;
	}

	return false;
}
