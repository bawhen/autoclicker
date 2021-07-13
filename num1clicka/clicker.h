#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>

//one of the namespacse for our variables, for organizing purposes.
//all of their names should explain what they are for.

namespace clicker {
	void click();
	void menu();

	bool enabled = false;
	bool legit = false;

	std::string mode;

	int legit_delay;
	int rage_delay = 1;
}