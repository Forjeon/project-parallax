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
	for (int y = 0; y < this->height; ++y) {
		file.ignore();
		for (int x = 0; x < this->width; ++x)
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

bool Map::can_move_into(int x, int y) {
	// TODO
	return true;
}

int Map::get_height() {
	return this->height;
}

char Map::get_tile_char(int x, int y) {
	// TODO
	return '%';
}
