#ifndef PROJECT_PARALLAX_I_ROBOT_VIEW_H
#define PROJECT_PARALLAX_I_ROBOT_VIEW_H

#include "map.h"

class IRobotView {
public:
	virtual const char* get_name() = 0;
	virtual char* make_raster(Map& map) = 0;
};

#endif
