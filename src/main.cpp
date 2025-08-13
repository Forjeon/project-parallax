#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#include <ncurses.h>

#include "config.h"
#include "map.h"
#include "player.h"

int main(int argc, char* argv[]) {
	Map test_map = Map(std::filesystem::path("resources/maps/milestone1.ppmap"));
	Player player = Player(&test_map);

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
		player.draw_view();

		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / ProjectParallax_FRAMERATE));
	}

	// Clean up and exit
	endwin();
}
