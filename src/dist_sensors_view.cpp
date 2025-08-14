#include <random>

#include "dist_sensors_view.h"
#include "map.h"

DistSensorsView::DistSensorsView() : reliability_distr(0, 5) {
	std::random_device rd;
	this->rand_eng = std::default_random_engine(rd());
}

const char* DistSensorsView::get_name() {
	return this->NAME;
}

char* DistSensorsView::make_raster(Map& map) {
	char* view_raster = (char*)calloc(map.get_width() * map.get_height(), sizeof(char));

	// Draw sensors view 
	for (int y = 0; y < map.get_height(); ++y)
		for (int x = 0; x < map.get_width(); ++x) {
			char view_tile_char;

			// Have sensors lie
			switch (this->reliability_distr(this->rand_eng)) {
				case 0:
					view_tile_char = MAP_TILE_CHARS[MapTiles::EMPTY];
					break;

				case 1:
					view_tile_char = MAP_TILE_CHARS[MapTiles::FLOOR];
					break;

				case 2:
					view_tile_char = MAP_TILE_CHARS[MapTiles::WALL];
					break;

				default:
					view_tile_char = map.get_tile_char(x, y);
					view_tile_char = (view_tile_char == MAP_TILE_CHARS[MapTiles::FLOOR]) ? view_tile_char : MAP_TILE_CHARS[MapTiles::WALL];
			}

			view_raster[map.get_width() * y + x] = view_tile_char;
		}

	return view_raster;
}
