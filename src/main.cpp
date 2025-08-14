#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#include <ncurses.h>

#include "config.h"
#include "camera_view.h"
#include "dist_sensors_view.h"
#include "i_robot_view.h"
#include "map.h"
#include "player.h"

void move_player(int in_key, Map& map, Player& player) {
	unsigned int new_x = player.x;
	unsigned int new_y = player.y;

	switch(in_key) {
		case 'w':
			--new_y;
			break;

		case 'a':
			--new_x;
			break;

		case 's':
			++new_y;
			break;

		case 'd':
			++new_x;
			break;
	}

	if (map.can_move_into(new_x, new_y)) {
		player.x = new_x;
		player.y = new_y;
	}
}

void render_frame(IRobotView& view, Map& map, Player& player) {
	// Draw view source title
	move(0, 0);
	printw("Reading TASKENV27::PERCEPT::%s", view.get_name());

	// Draw sensors view 
	char* view_raster = view.make_raster(map);
	for (int y = 0; y < map.get_height(); ++y)
		for (int x = 0; x < map.get_width(); ++x)
			mvaddch(y + 2, x, view_raster[map.get_width() * y + x]);

	// Draw player (+2 to give space for view source title)
	mvaddch(player.y + 2, player.x, MAP_TILE_CHARS[MapTiles::PLAYER]);
	move(map.get_height() + 2, 0);

	// Clean up raster
	delete[] view_raster;
}

int main(int argc, char* argv[]) {
	// Initialize game objects
	Map map = Map(std::filesystem::path("resources/maps/milestone1.ppmap"));
	Player player{map.get_start_x(), map.get_start_y()};
	DistSensorsView sensors_view{};
	CameraView test_cam_view{0, 0, 0};

	// Initialize ncurses
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, true);

	// Print greeting
	printw("Project Parallax VER%d.%d.%d loading...", ProjectParallax_VERSION_MAJOR, ProjectParallax_VERSION_MINOR, ProjectParallax_VERSION_PATCH);
	refresh();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	// Game
	clear();
	refresh();
	printw("Reading TASKENV27::PERCEPT::DIST_SENS");
	while (true) {
		// Handle input
		move_player(getch(), map, player);

		// Render frame
		render_frame(test_cam_view, map, player);
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / ProjectParallax_FRAMERATE));
	}

	// Clean up and exit
	endwin();
}
