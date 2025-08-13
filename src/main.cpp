#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#include <ncurses.h>

#include "config.h"
#include "map.h"

int main(int argc, char* argv[]) {
	Map test_map = Map(std::filesystem::path("resources/maps/milestone1.ppmap"));

	// Initialize ncurses
	initscr();
	noecho();
	cbreak();

	// Print greeting
	printw("Project Parallax VER%d.%d.%d loading...", ProjectParallax_VERSION_MAJOR, ProjectParallax_VERSION_MINOR, ProjectParallax_VERSION_PATCH);
	refresh();
	std::this_thread::sleep_for(std::chrono::seconds(3));

	// Game
	clear();
	refresh();
	printw("Reading TASKENV27::PERCEPT::DIST_SENS");
	while (true) {
		for (int y = 0; y < test_map.get_height(); ++y)
			for (int x = 0; x < test_map.get_width(); ++x)
				mvaddch(y + 2, x, test_map.get_tile_char(x, y));
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	// Clean up and exit
	endwin();
}
