#include "stdafx.h"
#include "../Lab07/FindMaxEx.h"

struct Sportsman
{
	std::string name;
	float weight;
	float height;
};

struct SportsmanStruct
{
	std::vector<Sportsman> sportsmanVector;
};

BOOST_FIXTURE_TEST_SUITE(Find_Max_Ex, SportsmanStruct)

BOOST_AUTO_TEST_CASE(work_correct_with_empty_vector)
{
	Sportsman sportsman;
	BOOST_CHECK(!FindMax(sportsmanVector, sportsman, [](const auto& lv, const auto& rv) { return lv.height < rv.height; }));
}

BOOST_AUTO_TEST_SUITE_END()

struct Player_ : SportsmanStruct
{
	Player_()
	{
		sportsmanVector.push_back({"The First Player", 170, 70});
	}
};

BOOST_FIXTURE_TEST_SUITE(OnePlayer, Player_)
BOOST_AUTO_TEST_CASE(work_correct_with_vector_with_one_element)
{
	Sportsman player;

	BOOST_CHECK(FindMax(sportsmanVector, player, [](const auto& lv, const auto& rv) { return lv.height < rv.height; }));
	BOOST_CHECK(player.name == "The First Player");
}
BOOST_AUTO_TEST_SUITE_END()

struct Players_ : SportsmanStruct
{
	Players_()
	{
		sportsmanVector.push_back({ "The First Player", 80, 170 });
		sportsmanVector.push_back({ "The Second Player", 90, 170 });
		sportsmanVector.push_back({ "The Third Player", 70, 180 });
	}
};
BOOST_FIXTURE_TEST_SUITE(Team, Players_)
BOOST_AUTO_TEST_CASE(can_find_the_heaviest_player)
{
	Sportsman player;

	BOOST_CHECK(FindMax(sportsmanVector, player, [](const auto& lv, const auto& rv) { return lv.weight < rv.weight; }));
	BOOST_CHECK(player.name == "The Second Player");
	BOOST_CHECK(player.weight == 90);
}
BOOST_AUTO_TEST_CASE(can_find_the_highest_player)
{
	Sportsman player;

	BOOST_CHECK(FindMax(sportsmanVector, player, [](const auto& lv, const auto& rv) { return lv.height < rv.height; }));
	BOOST_CHECK(player.name == "The Third Player");
	BOOST_CHECK(player.height == 180);
}

BOOST_AUTO_TEST_SUITE_END()
