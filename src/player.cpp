#include <random>

#include <ncurses.h>

#include "map.h"
#include "player.h"

Player::Player(Map* map) : x(map->get_start_x()), y(map->get_start_y()), map(map) {
	std::random_device rd;
	this->rand_eng = std::default_random_engine(rd());
	this->sensors_trust_distrib = std::uniform_int_distribution<>(0, 5);
}

void Player::draw_view() {
	// Draw sensors view 
	for (int y = 0; y < this->map->get_height(); ++y)
		for (int x = 0; x < this->map->get_width(); ++x) {
			char view_tile_char;

			// Have sensors lie
			int lie_result = this->sensors_trust_distrib(this->rand_eng);
			switch (this->sensors_trust_distrib(this->rand_eng)) {
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
					view_tile_char = this->map->get_tile_char(x, y);
					view_tile_char = (view_tile_char == MAP_TILE_CHARS[MapTiles::FLOOR]) ? view_tile_char : MAP_TILE_CHARS[MapTiles::WALL];
			}

			// Draw tile (+2 to give space for view source title)
			mvaddch(y + 2, x, view_tile_char);
		}

	// Draw player (+2 to give space for view source title)
	mvaddch(this->y + 2, this->x, Player::TILE_CHAR);
	move(this->map->get_height() + 2, 0);
}
