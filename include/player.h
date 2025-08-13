#ifndef PROJECT_PARALLAX_PLAYER_H
#define PROJECT_PARALLAX_PLAYER_H

#include <random>

#include "map.h"

// TODO: template method pattern for this and camera views
class Player {
	static const char TILE_CHAR = '@';

	int x;
	int y;
	Map* map;
	std::default_random_engine rand_eng;
	std::uniform_int_distribution<> sensors_trust_distrib;
public:
	Player(Map* map);
	void draw_view();
};

#endif
