#include "stdafx.h"
#include "../TVSet/TVSet.h"
#include "../TVSet/RemoteControl.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// ����������� RemoteControl-� �������� � ������������ ���������,
// ����� ������������� �� �������� �� ��������������� ������ remote-��������
struct RemoteControlDependencies
{
	CTVSet tv;
	stringstream input;
	stringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlFixture()
		: remoteControl(tv, input, output)
	{
	}

	// ��������������� ������� ��� �������� ������ ������� command
	// ��� ��������� ��������� ����� ������ expectedChannel � expectedOutput
	void VerifyCommandHandling(const string& command, const optional<int> & expectedChannel, const string& expectedOutput)
	{
		// �������������� ������� ���������� ��������� ������
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.IsTurnedOn(), expectedChannel.is_initialized());
		BOOST_CHECK_EQUAL(tv.GetChannel(), expectedChannel.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)

BOOST_AUTO_TEST_CASE(can_handle_TurnOn_command)
{
	VerifyCommandHandling("TurnOn", 1, "TV is turned on\n");
}

BOOST_AUTO_TEST_CASE(dont_select_previous_channel_when_tv_is_first_on)
{
	tv.TurnOn();
	tv.SelectPreviousChannel();
	VerifyCommandHandling("SelectPreviousChannel", 1, "Channel selected\n");
}

BOOST_AUTO_TEST_CASE(can_turn_off_tv_which_is_on)
{
	tv.TurnOn();
	VerifyCommandHandling("TurnOff", none, "TV is turned off\n");
}

BOOST_AUTO_TEST_CASE(can_print_tv_info)
{
	// ��������� ��������� ������� Info, ��������� � ������������ ����������
	VerifyCommandHandling("Info", none, "TV is turned off\n");

	// ��������� ��������� ������� Info � ����������� ����������
	tv.TurnOn();
	tv.SelectChannel(42);
	VerifyCommandHandling("Info", 42, "TV is turned on\nChannel is: 42\n");
}

BOOST_AUTO_TEST_CASE(can_select_a_valid_channel_when_tv_is_on)
{
	tv.TurnOn();
	VerifyCommandHandling("SelectChannel 42", 42, "Channel selected\n");
}

BOOST_AUTO_TEST_CASE(cant_select_channel_when_tv_is_turned_off)
{
	VerifyCommandHandling("SelectChannel 42", none, "Can't select channel because TV is turned off\n");
	VerifyCommandHandling("SelectChannel 100", none, "Can't select channel because TV is turned off\n");
}

BOOST_AUTO_TEST_CASE(cant_select_an_invalid_channel_when_tv_is_on)
{
	tv.TurnOn();
	tv.SelectChannel(42);
	VerifyCommandHandling("SelectChannel 100", 42, "Invalid channel\n");
	VerifyCommandHandling("SelectChannel 0", 42, "Invalid channel\n");
}

BOOST_AUTO_TEST_CASE(can_select_previous_channel_when_tv_is_on)
{
	tv.TurnOn();
	tv.SelectChannel(10);
	tv.SelectChannel(20);
	VerifyCommandHandling("SelectPreviousChannel", 10, "Channel selected\n");
}

BOOST_AUTO_TEST_CASE(cant_select_previous_channel_when_tv_is_off)
{
	tv.SelectChannel(12);
	tv.SelectChannel(45);
	tv.SelectPreviousChannel();
	VerifyCommandHandling("SelectPreviousChannel", none, "Can't select channel because TV is turned off\n");
}

BOOST_AUTO_TEST_SUITE_END()