#ifndef PROJECT_PARALLAX_MAP_H
#define PROJECT_PARALLAX_MAP_H

#include <filesystem>
#include <string>

enum MapTiles {	// Match to MAP_TILE_CHARS
	CAMERA,	// 'P'
	DOOR,	// '#'
	EMPTY,	// ' '
	FLOOR,	// '_'
	PLAYER,	// '@'
	WALL	// '|'
};

static const char* MAP_TILE_CHARS = "P# _@|";	// Match to MapTiles enum

class Map {
	inline static const std::string FILE_EXTENSION = ".ppmap";

	char* tiles;
	unsigned int width;
	unsigned int height;
	unsigned int start_x;
	unsigned int start_y;

public:
	Map(std::filesystem::path filepath);
	~Map();
	bool can_move_into(unsigned int x, unsigned int y);
	unsigned int get_height();
	unsigned int get_start_x();
	unsigned int get_start_y();
	char get_tile_char(unsigned int x, unsigned int y);
	unsigned int get_width();
};

#endif
