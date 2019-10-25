#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

const int ROW = 11;
const int SIZE = 13;
const string block = "\u25A0";

struct WallIndex 
{
	int i;
	int j;
};

bool isCorner(WallIndex opening)
{
	if ( (opening.i == 0 && opening.j == 0) ||
		 (opening.i == 0 && opening.j == SIZE) ||
		 (opening.i == ROW && opening.j == 0) ||
		 (opening.i == ROW && opening.j == SIZE)) 
		return true;
	return false;
}

bool isOppositeWall(WallIndex entrance, WallIndex exit)
{
	if (entrance.i == 0 && exit.i == 0)
		return false;
	else if (entrance.i != 0 && exit.i != 0)
		return false;
	else if (entrance.j == 0 && exit.j == 0)
		return false;
	else if (entrance.j != 0 && exit.j != 0)
		return false;
	return true;
}

// TODO: NOT WORKING PROPERLY
void create_maze_walls(string array[][SIZE], const int SIZE)
{
	vector<WallIndex> wall_index;

	string random_ch[2] = {"\u25A0", " "};
	int rand_count = 0;
	string space = " ";
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < ROW ; j++)
		{
			if ( (i == 0)        ||
				 (i == SIZE - 1) ||
				 (j == 0)        ||
				 (j == ROW - 1)) 
			{
				array[j][i] = block;
				wall_index.push_back({i, j});
			}
			else
			{
				array[j][i] = block;
			}
		}
	}

	WallIndex entrance;
	WallIndex exit;
	int count = 0;
	int rand_index;
	int entrance_i;
	int entrance_j;
	int exit_i;
	int exit_j;
	int entrance_idx;
	int exit_idx;

	// CREATE OPENING INDEX
	do
	{
		rand_index = rand()%(wall_index.size() - 0 + 1) - 0;
		entrance_idx = rand_index;
		entrance_j = wall_index[entrance_idx].j;
		entrance_i = wall_index[entrance_idx].i;
		entrance.i = entrance_i;
		entrance.j = entrance_j;
	} while (!isCorner(entrance));

	array[entrance_j][entrance_j] = " ";

	do
	{
		do 
		{
			rand_index = rand()%(wall_index.size() - 0 + 1) - 0;
			exit_idx = rand_index;

		}
		while (entrance_idx == exit_idx);

		exit_j = wall_index[exit_idx].j;
		exit_i = wall_index[exit_idx].i;
		exit.i = exit_i;
		exit.j = exit_j;
	}
	while (!isOppositeWall(entrance, exit));
	array[exit_j][exit_j] = " ";

}

void init_array(string array[][SIZE], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			array[j][i] = " ";

		}
	}
}

void print_maze(string array[][SIZE], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			cout << array[j][i];
		}
		cout << endl;
	}

}

int main()
{

	srand(time(NULL));
	string maze[ROW][SIZE];	
	init_array(maze, SIZE);
	create_maze_walls(maze, SIZE);
	print_maze(maze, SIZE);
	// create_maze_walls(maze, SIZE);
}
