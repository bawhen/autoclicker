#pragma once

//the input namespace for everything involving user input.
//once again, names should explain what they do.
//handle input is not being used right now.

namespace input {
	bool get_key_pressed(int key);
	bool get_key_held(int key);
	//void handle_input();

	int left_key;
	int right_key;
}