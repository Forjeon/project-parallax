#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#include <ncurses.h>

#include "config.h"
#include "map.h"

int main(int argc, char* argv[]) {
	std::cout << "Hello, world! I'm Project Parallax." << std::endl;
	std::cout << "I am currently version " << ProjectParallax_VERSION_MAJOR << '.' << ProjectParallax_VERSION_MINOR << '.' << ProjectParallax_VERSION_PATCH << '.' << std::endl;

	Map test_map = Map(std::filesystem::path("resources/maps/milestone1.ppmap"));

	// Initialize ncurses
	initscr();
	noecho();
	cbreak();

	// Print initial lines
	printw("Line 1");
	printw("Line 2");
	printw("Line 3");
	refresh();

	// Test updating lines without reprinting
	for (int i = 0; i < 100; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		move(1, 0);
		clrtoeol();
		printw("Line 2 %d", i);
		move(4, 0);
		refresh();
	}

	// Clean up and exit
	endwin();
}
