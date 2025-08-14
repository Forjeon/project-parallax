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
		for (unsigned int x = 0; x < this->width; ++x) {
			char tile = file.get();
			this->tiles[this->width * y + x] = tile;
			
			// Track camera positions
			// TODO
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
	return this->get_tile_char(x, y) == MAP_TILE_CHARS[MapTiles::FLOOR];
}

size_t Map::get_camera_count() {
	return this->camera_coords.size() / 2;
}

unsigned int Map::get_camera_x(unsigned int id) {
	// TODO
}

unsigned int Map::get_camera_y(unsigned int id) {
	// TODO
}

unsigned int Map::get_height() {
	return this->height;
}

unsigned int Map::get_start_x() {
	return this->start_x;
}

unsigned int Map::get_start_y() {
	return this->start_y;
}

char Map::get_tile_char(unsigned int x, unsigned int y) {
	if (x > this->width || y > this->height)
		return MAP_TILE_CHARS[MapTiles::EMPTY];
	return this->tiles[this->width * y + x];
}

unsigned int Map::get_width() {
	return this->width;
}
