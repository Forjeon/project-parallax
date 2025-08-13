#include <random>

#include <ncurses.h>

#include "map.h"
#include "player.h"

Player::Player(Map* map) : map(map) {
	std::random_device rd;
	this->rand_eng = std::default_random_engine(rd());
	this->sensors_trust_distrib = std::uniform_int_distribution<>(0, 19);
}

void Player::draw_view() {
	for (int y = 0; y < this->map->get_height(); ++y)
		for (int x = 0; x < this->map->get_width(); ++x) {
			char view_tile_char;
			int lie_result = this->sensors_trust_distrib(this->rand_eng);
			if (lie_result <= MapTiles::WALL)
				view_tile_char = MAP_TILE_CHARS[lie_result];
			else
				view_tile_char = this->map->get_tile_char(x, y);
			mvaddch(y + 2, x, view_tile_char);
		}
}
