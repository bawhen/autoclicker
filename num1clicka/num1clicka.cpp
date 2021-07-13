#include <iostream>
#include <Windows.h>
#include <ctime>
#include "input.h"
#include "clicker.h"

//i know all this code is cramped and kinda poop
//but if i made individual files to organize the functions
//i got errors :(

using namespace std;

//our function to check if a key is pressed (for toggles).
//i know i could just use default GetAsyncKeyState but
//why not be fancy ;)
bool input::get_key_pressed(int key)
{
	return GetAsyncKeyState(key) & 1;
}

bool input::get_key_held(int key)
{
	return GetAsyncKeyState(key);
}

void clicker::menu()
{
	//this just prints all of our text
	cout << "welcome to da bawhenclicker\n";
	cout << "press right shift to toggle the autoclicker\n";
	cout << "press mouse 5 to toggle the left button\n";
	cout << "press mouse 4 to toggle the right button\n";
	cout << "press right control to switch between semi-rage or legit mode\n";
}

void clicker::click()
{
	while (true)
	{
		//if right shift is pressed, toggle the clicker::enabled bool
		//and print its value in the console.
		if (input::get_key_pressed(VK_RSHIFT))
		{
			//this is what i call a toggle loop.
			//basically, if something happens, the bool will 
			//change to the opposite of what it currently is.
			clicker::enabled = !clicker::enabled;
			cout << "enabled: " << clicker::enabled << "\n";
		}

		//the string that changes the value from 1 or 0 to legit or semi-rage.
		std::string mode_var = clicker::legit == true ? "mode: legit\n" : "mode: semi-rage\n";

		//we use the same thing here.
		if (input::get_key_pressed(VK_RCONTROL))
		{
			clicker::legit = !clicker::legit;
			//here we use a different var because we want it to display
			//legit or semi-rage instead of 1 or 0.
			cout << mode_var;
		}

		//if mouse4 is being held and clicker::enabled is set to true, autoclick.
		if (input::get_key_held(VK_XBUTTON2) && clicker::enabled == true)
		{
			//here we use the windows api's mouse_event function.
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			//we use the question mark as sort of a shorter "if" statement.
			//it basically means "if clicker::legit is set to true, use a random
			//amount of milliseconds. otherwise, just use 1.
			Sleep(clicker::legit == true ? rand() & 60 + 20 : rand() & 100 + 20);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}

		//we do the same thing as above here.
		if (input::get_key_held(VK_XBUTTON1) && clicker::enabled == true)
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			Sleep(clicker::legit == true ? rand() & 60 + 20 : rand() & 150 + 20);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}
	}
}

int main()
{
	//calling our functions here so they actually do something.
	clicker::menu();
	clicker::click();
}
