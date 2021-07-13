#include <iostream>
#include <Windows.h>
#include <ctime>
#include "input.h"
#include "clicker.h"

using namespace std;

bool input::get_key_pressed(int key)
{
	return GetAsyncKeyState(key) & 1;
}

bool input::get_key_held(int key)
{
	return GetAsyncKeyState(key);
}

void input::handle_input()
{

}