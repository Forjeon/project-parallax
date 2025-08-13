#ifndef PROJECT_PARALLAX_MAP_H
#define PROJECT_PARALLAX_MAP_H

#include <filesystem>
#include <string>

class Map {
	static const char CAMERA = 'P';
	static const char DOOR = '#';
	static const char EMPTY = ' ';
	static const char FLOOR = '_';
	static const char PLAYER = '@';
	static const char WALL = '|';
	inline static const std::string FILE_EXTENSION = ".ppmap";

	char* tiles;
	int width;
	int height;
	int start_x;
	int start_y;

public:
	Map(std::filesystem::path filepath);
	~Map();
	bool can_move_into(int x, int y);
	int get_height();
	char get_tile_char(int x, int y);
	int get_width();
};

#endif
