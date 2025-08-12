#include "map.h"

Map::Map(std::string filepath) {
	// TODO: must be '.ppmap' file
	/* NOTE: map file format is (top left is origin):
	   <width> <height>
	   <player start x> <player start y>
	   <map row tiles>
	   ...
	*/
	// TODO: calloc this->tiles
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
