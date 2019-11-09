#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <set>
#include <ncurses.h>
#include <menu.h>
#include "2048.hpp"

game::game()
{
	board.resize(size * size);
	backup_board.resize(size * size);
	backup_score = score = 0;

	for (int i = 0; i < size * size; ++i)
	{
		free_indexes.insert(i);
	}

	srand((unsigned)time(NULL));
	int how_to_init = rand() % 3;
	init_board(how_to_init);
}

void game::init_board(int how_to_init)
{
	switch (how_to_init)
	{
		case 0:
		{
			std::vector<int> side_indexes;

			for (size_t row = 0; row < size; ++row)
			{
				for (size_t col = 0; col < size; ++col)
				{
					if (row == 0 || row == size - 1 || col == 0 || col == size - 1)
					{
						side_indexes.push_back(row * size + col);
					}
				}
			}

			const size_t side_size = side_indexes.size();
			int index_1 = rand() % side_size;
			int index_2 = rand() % side_size;
			while (index_2 == index_1)
			{
				int index_2 = rand() % side_size;
			}

			board[side_indexes[index_1]] = 2;
			board[side_indexes[index_2]] = rand() % 2 ? 2 : 4;
			free_indexes.erase(side_indexes[index_1]);
			free_indexes.erase(side_indexes[index_2]);
			break;
		}

		case 1:
		{
			std::vector<int> side_indexes;
			std::vector<int> internal_indexes;

			for (size_t row = 0; row < size; ++row)
			{
				for (size_t col = 0; col < size; ++col)
				{
					if (row == 0 || row == size - 1 || col == 0 || col == size - 1)
					{
						side_indexes.push_back(row * size + col);
					}
					else
					{
						internal_indexes.push_back(row * size + col);
					}
				}
			}

			int index_1 = rand() % side_indexes.size();
			int index_2 = rand() % internal_indexes.size();
			board[side_indexes[index_1]] = 2;
			board[internal_indexes[index_2]] = rand() % 2 ? 2 : 4;
			free_indexes.erase(side_indexes[index_1]);
			free_indexes.erase(internal_indexes[index_2]);
			break;
		}

		case 2:
		{
			std::vector<int> internal_indexes;

			for (size_t row = 0; row < size; ++row)
			{
				for (size_t col = 0; col < size; ++col)
				{
					if (!(row == 0 || row == size - 1 || col == 0 || col == size - 1))
					{
						internal_indexes.push_back(row * size + col);
					}
				}
			}

			const size_t internal_size = internal_indexes.size();
			int index_1 = rand() % internal_size;
			int index_2 = rand() % internal_size;
			while (index_2 == index_1)
			{
				int index_2 = rand() % internal_size;
			}

			board[internal_indexes[index_1]] = 2;
			board[internal_indexes[index_2]] = rand() % 2 ? 2 : 4;
			free_indexes.erase(internal_indexes[index_1]);
			free_indexes.erase(internal_indexes[index_2]);
			break;
		}
	}
}

void game::start_ncurses_mode() const
{
	initscr();
	curs_set(FALSE);
}

void game::show_menu() const
{
	int y;
	int x;
	getmaxyx(stdscr, y, x);
	WINDOW *logo_win = newwin(y, x, 0, 0);
	//mvwprintw(logo_win, y/3,x/3,"00000010 00000000 00000100 00001000");
	int x_coord = x / 2 - x / 9;
	int y_coord = y / 5;
	mvwprintw(logo_win, y_coord, x_coord, " ___     ___    _  _    ___  ");
	mvwprintw(logo_win, y_coord + 1, x_coord, "|__ \\   / _ \\  | || |  / _ \\");
	mvwprintw(logo_win, y_coord + 2, x_coord, "   ) | | | | | | || | | (_) |");
	mvwprintw(logo_win, y_coord + 3, x_coord, "  / /  | | | | |__  |  > _ < ");
	mvwprintw(logo_win, y_coord + 4, x_coord, " / /_  | |_| |    | | | (_) |");
	mvwprintw(logo_win, y_coord + 5, x_coord, "|____|  \\___/     |_|  \\___/ ");
	keypad(logo_win, TRUE);

	noecho();
	cbreak();
	curs_set(FALSE);

	const char *choices[] = { "classic (4x4)", "big (5x5)", "bigger (8x8)", "tiny (3x3)" };
	int item_count = sizeof(choices) / sizeof(choices[0]);
	ITEM **items = (ITEM **)calloc(item_count, sizeof(ITEM *));
	for (int i = 0; i < item_count; ++i)
	{
		items[i] = new_item(choices[i], "");
	}
	MENU *menu = new_menu((ITEM **)items);

	WINDOW *menu_win = newwin(y / 3, 29, 2 * y_coord, x_coord);

	set_menu_win(menu, menu_win);
	set_menu_sub(menu, derwin(menu_win, 6, 20, 4, 2));

	set_menu_mark(menu, "");
	//box(menu_win, 0, 0);

	mvwprintw(menu_win, 1, 2, "select:");
	//mvwaddch(menu_win, 2, 0, ACS_LTEE);
	mvwhline(menu_win, 2, 1, ACS_HLINE, 28);
	//mvwaddch(menu_win, 2, 28, ACS_RTEE);

	post_menu(menu);

	wrefresh(logo_win);
	wrefresh(menu_win);

	keypad(menu_win, TRUE);
	int choice;

	while ((choice = wgetch(menu_win)) != 10)
	{ // 10 - enter
		switch (choice)
		{
			case KEY_DOWN:
				menu_driver(menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(menu, REQ_UP_ITEM);
				break;
		}
		wrefresh(menu_win);
	}
}

void game::create_windows() const
{
	int y;
	int x;
	getmaxyx(stdscr, y, x);
	score_win = newwin(y, x, y / 9, 1.2 * x / 4);
	board_win = newwin(y, x, 3 * y / 9, 1.2 * x / 4);
}

void game::end_ncurses_mode()
{
	delwin(score_win);
	delwin(board_win);
	endwin();
}

void game::draw_windows() const
{
	wattron(score_win, A_BOLD);
	mvwprintw(score_win, 2, 0, "2048.cpp");
	wattroff(score_win, A_BOLD);
	mvwprintw(score_win, 3, 0, "score: %d", score);
	mvwprintw(score_win, 5, 0, "join the numbers and get 2048!");
	wrefresh(score_win);

	int col_distance = 9;
	int row_height = 3;
	for (int row = 0; row <= size; ++row)
	{
		for (int col = 0; col <= size; ++col)
		{
			mvwprintw(board_win, size * row, col_distance * col, "+");
			mvwhline(board_win, size * row, col_distance * (col - 1) + 1, '-', col_distance - 1);
			mvwvline(board_win, size * (row - 1) + 1, col_distance * col, '|', row_height);
		}
	}
	attron(A_BOLD);
	mvwprintw(board_win, size * size + 2, 0, "HOW TO PLAY: ");
	attroff(A_BOLD);
	mvwprintw(board_win, size * size + 2, 13, "use arrow keys to move\nthe tiles. when two tiles with the\nsame number touch, they merge into one!");

	wrefresh(board_win);
}

void game::print_board() const
{
	int row_offset = 2;
	int col_offset = 4;
	int col_distance = 9;
	for (int row = 0; row < size; ++row)
	{
		for (int col = 0; col < size; ++col)
		{
			int i = row * size + col;
			if (board[i] != 0)
			{
				mvwprintw(board_win, size * row + row_offset, col_distance * col + col_offset - 1, "      ");
				if (board[i] < 128)
				{
					mvwprintw(board_win, size * row + row_offset, col_distance * col + col_offset, "%d", board[i]);
				}
				else if (board[i] < 1024)
				{
					mvwprintw(board_win, size * row + row_offset, col_distance * col + col_offset - 1, "%d", board[i]);
				}
			}
			else
			{
				mvwprintw(board_win, size * row + row_offset, col_distance * col + col_offset - 1, "    ");
			}
		}
	}
	wrefresh(board_win);
}

bool game::moves_available() const
{
	if (!free_indexes.empty()) { return true; }
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (board[i * size + j] == board[(i + 1) * size + j] || board[i * size + j] == board[i * size + j + 1])
			{
				return true;
			}
		}
	}
	for (int i = 0; i < size - 1; ++i)
	{
		if (board[i * size + size - 1] == board[(i + 1) * size + size - 1]) { return true; }
	}
	return false;
}

void game::start()
{

	start_ncurses_mode();
	show_menu();
	create_windows();
	draw_windows();
	print_board();

	noecho();
	cbreak();
	keypad(board_win, TRUE);

	int y;
	int x;
	getmaxyx(stdscr, y, x);
	WINDOW *win = newwin(y, x, 0, 0);

	while (moves_available())
	{
		if (std::find(board.begin(), board.end(), 2048) != board.end())
		{
			mvwprintw(win, y / 2, x / 2, "you won!");
			mvwprintw(win, y / 2 + 1, x / 2, "score: %d", score);
			wgetch(win);
			delwin(win);
			end_ncurses_mode();
			return;
		}
		else
		{
			int key = wgetch(board_win);
			MEVENT event;
			switch (key)
			{
				case KEY_UP:    case 'w': backup(); key_up_execute();     break;
				case KEY_DOWN:  case 's': backup(); key_down_execute();   break;
				case KEY_LEFT:  case 'a': backup(); key_left_execute();   break;
				case KEY_RIGHT: case 'd': backup(); key_right_execute();  break;
					// case KEY_MOUSE:
					//   if(getmouse(&event) == OK) {
					//     if(event.bstate && BUTTON1_PRESSED) {

					//     }
					//   }
					// break;
				case 'u':
					board = backup_board;
					free_indexes = backup_free_indexes;
					score = backup_score;
					mvwprintw(score_win, 3, 7, "       ");
					break;
				case 'r':
					std::fill(board.begin(), board.end(), 0); // board.clear(); - UB
					free_indexes.clear();
					score = 0;
					mvwprintw(score_win, 3, 7, "       ");
					init_board(rand() % 3);
					break;
				case 'h':
					mvwprintw(win, y / 2, x / 2, "you won!");
					wgetch(win);
					delwin(win);
					break;
				case 'q': end_ncurses_mode(); break;
				default: key = wgetch(board_win);
			}

			print_board();
			print_score();
		}
	}
	mvwprintw(win, y / 2, x / 2, "you lost :(");
	mvwprintw(win, y / 2 + 1, x / 2, "score: %d", score);
	wgetch(win);
	delwin(win);
	end_ncurses_mode();
}

void game::backup()
{
	backup_board = board;
	backup_free_indexes = free_indexes;
	backup_score = score;
}

void game::key_up_execute()
{
	bool moved = false;
	bool merged = false;
	for (int row = 1; row < size; ++row)
	{
		for (int col = 0; col < size; ++col)
		{
			if (board[row * size + col] == 0)
			{
				continue;
			}
			if (board[row * size + col] == board[(row - 1) * size + col])
			{
				board[(row - 1) * size + col] = 2 * board[row * size + col];
				board[row * size + col] = 0;
				score += board[(row - 1) * size + col];
				moved = true;
				merged = true;
			}
			else if (board[(row - 1) * size + col] == 0)
			{
				int new_row = row - 1;
				while (new_row > 0 && board[(new_row - 1) * size + col] == 0)
				{
					--new_row;
				}
				board[new_row * size + col] = board[row * size + col];
				board[row * size + col] = 0;
				if (!merged && (new_row > 0) && (board[new_row * size + col] == board[(new_row - 1) * size + col]))
				{
					board[(new_row - 1) * size + col] = 2 * board[new_row * size + col];
					board[new_row * size + col] = 0;
					score += board[(new_row - 1) * size + col];
				}
				moved = true;
				merged = false;
			}
		}
	}
	add_new_tile(moved);
}

void game::key_down_execute()
{
	bool moved = false;
	bool merged = false;
	for (int row = size - 2; row >= 0; --row)
	{
		for (int col = 0; col < size; ++col)
		{
			if (board[row * size + col] == 0)
			{
				continue;
			}
			if (board[row * size + col] == board[(row + 1) * size + col])
			{
				board[(row + 1) * size + col] = 2 * board[row * size + col];
				board[row * size + col] = 0;
				score += board[(row + 1) * size + col];
				moved = true;
				merged = true;
			}
			else if (board[(row + 1) * size + col] == 0)
			{
				int new_row = row + 1;
				while (new_row < size - 1 && board[(new_row + 1) * size + col] == 0)
				{
					++new_row;
				}
				board[new_row * size + col] = board[row * size + col];
				board[row * size + col] = 0;
				if (!merged && (new_row < size - 1) && (board[new_row * size + col] == board[(new_row + 1) * size + col]))
				{
					board[(new_row + 1) * size + col] = 2 * board[new_row * size + col];
					board[new_row * size + col] = 0;
					score += board[(new_row + 1) * size + col];
				}
				moved = true;
				merged = false;
			}
		}
	}
	add_new_tile(moved);
}

void game::key_right_execute()
{
	bool moved = false;
	bool merged = false;
	for (int row = 0; row < size; ++row)
	{
		for (int col = size - 2; col >= 0; --col)
		{
			if (board[row * size + col] == 0)
			{
				continue;
			}
			if (board[row * size + col] == board[row * size + col + 1])
			{
				board[row * size + col + 1] = 2 * board[row * size + col];
				board[row * size + col] = 0;
				score += board[row * size + col + 1];
				moved = true;
				merged = true;
			}
			else if (board[row * size + col + 1] == 0)
			{
				int new_col = col + 1;
				while (new_col < size - 1 && board[row * size + new_col + 1] == 0)
				{
					++new_col;
				}
				board[row * size + new_col] = board[row * size + col];
				board[row * size + col] = 0;
				if (!merged && (new_col < size - 1) && (board[row * size + new_col] == board[row * size + new_col + 1]))
				{
					board[row * size + new_col + 1] = 2 * board[row * size + new_col];
					board[row * size + new_col] = 0;
					score += board[row * size + new_col + 1];
				}
				moved = true;
				merged = false;
			}
		}
	}
	add_new_tile(moved);
}

void game::key_left_execute()
{
	bool moved = false;
	bool merged = false;
	for (int row = 0; row < size; ++row)
	{
		for (int col = 1; col < size; ++col)
		{
			if (board[row * size + col] == 0)
			{
				continue;
			}
			if (board[row * size + col] == board[row * size + col - 1])
			{
				board[row * size + col - 1] = 2 * board[row * size + col];
				board[row * size + col] = 0;
				score += board[row * size + col - 1];
				moved = true;
			}
			else if (board[row * size + col - 1] == 0)
			{
				int new_col = col - 1;
				while (new_col > 0 && board[row * size + new_col - 1] == 0)
				{
					--new_col;
				}
				board[row * size + new_col] = board[row * size + col];
				board[row * size + col] = 0;
				if ((new_col > 0) && (board[row * size + new_col] == board[row * size + new_col - 1]))
				{
					board[row * size + new_col - 1] = 2 * board[row * size + new_col];
					board[row * size + new_col] = 0;
					score += board[row * size + new_col - 1];
				}
				moved = true;
				merged = true;
			}
		}
	}
	add_new_tile(moved);
}

void game::add_new_tile(bool moved)
{
	if (moved)
	{
		free_indexes.clear();
		for (int row = 0; row < size; ++row)
		{
			for (int col = 0; col < size; ++col)
			{
				if (board[row * size + col] == 0)
				{
					free_indexes.insert(row * size + col);
				}
			}
		}
	}
	if (moved && !free_indexes.empty())
	{
		std::set<int>::const_iterator it = free_indexes.begin();
		std::advance(it, rand() % free_indexes.size());
		free_indexes.erase(*it);
		board[*it] = 2;
	}
}

void game::print_score() const
{
	int score_y = 3;
	int score_x = 7;
	mvwprintw(score_win, score_y, score_x, "%d", score);
	wrefresh(score_win);
}
