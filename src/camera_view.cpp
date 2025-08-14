#include <string>

#include "camera_view.h"

const char* CameraView::get_name() {
	return this->NAME.c_str();
}

char* CameraView::make_raster(Map& map) {
	char* view_raster = (char*)calloc(map.get_width() * map.get_height(), sizeof(char));

	// Draw camera view
	for (int y = 0; y < map.get_height(); ++y)
		for (int x = 0; x < map.get_width(); ++x)
			view_raster[map.get_width() * y + x] = map.get_tile_char(x, y);

	return view_raster;
}
