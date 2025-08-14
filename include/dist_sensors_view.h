#ifndef PROJECT_PARALLAX_DIST_SENSORS_H
#define PROJECT_PARALLAX_DIST_SENSORS_H

#include <random>
#include <string>

#include "i_robot_view.h"
#include "map.h"

class DistSensorsView : public IRobotView {
	std::default_random_engine rand_eng;
	std::uniform_int_distribution<> reliability_distr;
	const char* NAME = "DIST_SENS";

public:
	DistSensorsView();
	const char* get_name();
	char* make_raster(Map& map);
};

#endif
