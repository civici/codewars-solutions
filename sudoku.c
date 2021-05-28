/* https://www.codewars.com/kata/529bf0e9bdf7657179000008/ */

char check(unsigned int* array)
{
	int min = 1;
	for (int i = 0; i < 9; i++)
	{
		if (array[i] == min)
		{
			if (min == 9)
				return 1;
			min++;
			i = -1;
		}
	}

	return 0;
}

char validSolution(unsigned int board[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		if (check(board[i]) == 0)
			return 0;
	}

	unsigned int horizontal[9];
	unsigned int* indexer = horizontal;

	unsigned char column = 0;

	while (column < 9)
	{
		for (int i = 0; i < 9; i++)
		{
			*indexer = board[i][column];
			indexer++;
		}

		if (!check(horizontal))
		{
			return 0;
		}

		indexer = horizontal;
		column++;
	}

	unsigned char block = 0;
	unsigned int blockarray[9];
	indexer = blockarray;

	while (block < 9)
	{
		unsigned int col = (block % 3) * 3;
		unsigned int colLimit = col + 2;
		unsigned int line = ( (int)(block / 3) ) * 3;
		unsigned int lineLimit = line + 2;

		while (line <= lineLimit)
		{
			*indexer = board[line][col];
			indexer++;
			if (col == colLimit)
			{
				col = colLimit - 2;
				line++;
				continue;
			}
			col++;
		}
		indexer = blockarray;
		block++;

		if (!check(blockarray))
			return 0;
	}

	return 1;
}