#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <set>
#include <ncurses.h>
#include <menu.h>

class game
{
public:
	game();
	void start();
private:
	size_t score;
	size_t backup_score;
	static const size_t size = 4;
	std::vector<int> board;
	std::vector<int> backup_board;
	std::set<int> free_indexes;
	std::set<int> backup_free_indexes;

	mutable WINDOW *score_win;
	mutable WINDOW *board_win;

	void init_board(int);
	void draw_windows() const;
	void start_ncurses_mode() const;
	void show_menu() const;
	void create_windows() const;
	void print_board() const;
	void print_score() const;
	void end_ncurses_mode();

	bool moves_available() const;
	void add_new_tile(bool);
	void backup();

	void key_up_execute();
	void key_down_execute();
	void key_left_execute();
	void key_right_execute();
};

#endif
