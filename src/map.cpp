#include <filesystem>
#include <fstream>

#include "map.h"

Map::Map(std::filesystem::path filepath) {
	std::ifstream file = std::ifstream(filepath);
	file >> this->width;
	file >> this->height;
	file >> this->start_x;
	file >> this->start_y;
	this->tiles = (char*)calloc(this->width * this->height, sizeof(char));
	for (unsigned int y = 0; y < this->height; ++y) {
		file.ignore();
		for (unsigned int x = 0; x < this->width; ++x)
			this->tiles[this->width * y + x] = file.get();
	}
	/* NOTE: map file format is (top left is origin):
	   <width> <height>
	   <player start x> <player start y>
	   <map row tiles>
	   ...
	*/
}

Map::~Map() {
	delete[] this->tiles;
}

bool Map::can_move_into(unsigned int x, unsigned int y) {
	return this->get_tile_char(x, y) == Map::FLOOR;
}

unsigned int Map::get_height() {
	return this->height;
}

char Map::get_tile_char(unsigned int x, unsigned int y) {
	if (x > this->width || y > this->height)
		return Map::EMPTY;
	return this->tiles[this->width * y + x];
}

unsigned int Map::get_width() {
	return this->width;
}
