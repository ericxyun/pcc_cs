
// get row and 
void compHunt(PlayerBoard &target, 			// target's board
			  vector<Point> &compMemory,
			  string &compDirection)
{
	int row;
	int col;

	row = rand() % 10;
	do
	{
		if (row % 2 == 0)
		{
			do 
			{
				col = rand() % 10;
			}
			while ( col % 2 == 0 );
		}
		else if ( row % 2 != 0  )
		{
			do 
			{
				col = rand() % 10;
			}
			while ( col % 2 != 0 );
		}
	}
	while (!checkInList(compMemory, row, col));
	compFireShot(target, row, col, compMemory);
	compMemory.push_back({row, col});
}
bool checkTargetHit(PlayerBoard &target, int x, int y)
{
	int t = targetHit(target, x, y);
	if (target.fleet[t].hitCount == target.fleet[t].size)
		return true;
	return false;
}

void compTarget(PlayerBoard &target,
				vector<Point> &compMemory, 
				string &compDirection,
				int &compMoveCount,
				char &fireMode)
{
	int x;
	int y;
	int lastElem;
	char lastHit;

	lastElem = compMemory.size() - 1;
	x = compMemory[lastElem].rows;
	y = compMemory[lastElem].cols;
	lastHit = target.board[x][y];

	if (x == 0 || x == 9 ||
		y == 0 || y == 0)
	{
		if (x == 9)
		{
			x = x - 1;
		}
		else if (x == 0)
		{
			x = x + 1;
		}
		else if (y == 0)
		{
			y = y + 1;
		}
		else if (y == 9)
		{
			y = y - 1;
		}
		else 
		{
			compHunt(target, compMemory, compDirection);
		}
	}

	else if (x > 1 && y > 1 &&
			 x < 9 && y < 9)
	{
		cout << "compMoveCount: " << compMoveCount << endl;
		if (compMoveCount == 0)
		{
			x = x - 1;
			compMoveCount++;
		}
		else if (compMoveCount == 1)
		{
			x = x + 2;
			compMoveCount++;
		}
		else if (compMoveCount == 2)
		{
			x = x - 1;
			y = y - 1;
			compMoveCount++;
		}
		else if (compMoveCount == 3)
		{
			y = y + 2;
			compMoveCount = 0;
		}
		else 
		{
			compHunt(target, compMemory, compDirection);
		}
	}

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	if (!checkInList(compMemory, x, y))
	{
		compFireShot(target, x, y, compMemory);
		compMemory.push_back({x, y});
	}

	else 
	{
		compHunt(target, compMemory, compDirection);
	}
		
			





}

void compFire(PlayerBoard &target, 
		      vector<Point> &compMemory, 
			  string &compDirection,
			  int &compMoveCount,
			  char &fireMode)
{
	int x;
	int y;
	int lastElem;
	
 
	if (compMemory.size() == 0)
	{
		compHunt(target, compMemory, compDirection);
		return;
	}

	lastElem = compMemory.size() - 1;
	x = compMemory[lastElem].rows;
	y = compMemory[lastElem].cols;

	if (target.board[x][y] == 'M')
		compHunt(target, compMemory, compDirection);

	else
	{
		compTarget(target, compMemory, compDirection, compMoveCount, fireMode);
	}




}
void compfireshot(playerboard &target, 			// target's board
				  int row,
