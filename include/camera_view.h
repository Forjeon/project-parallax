#ifndef PROJECT_PARALLAX_CAMERA_VIEW_H
#define PROJECT_PARALLAX_CAMERA_VIEW_H

#include <string>

#include "i_robot_view.h"

class CameraView : public IRobotView {
	static const unsigned int FOV_ANGLE = 90;

	const char* NAME_PREFIX = "SEC_CAM-";
	const std::string NAME;
	unsigned int x;
	unsigned int y;

public:
	CameraView(unsigned int id, unsigned int x, unsigned int y) : NAME(this->NAME_PREFIX + std::to_string(id)), x(x), y(y) {}
	const char* get_name();
	char* make_raster(Map& map);
};

#endif
