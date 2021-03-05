#include <stdbool.h>

// https://www.codewars.com/kata/5894134c8afa3618c9000146

bool chess_board_cell_color(const char* cell1, const char *cell2)
{
	unsigned char fCellX = cell1[0] - 'A' + 1;
	unsigned char fCellY = cell1[1] - '0';

	unsigned char sCellX = cell2[0] - 'A' + 1;
	unsigned char sCellY = cell2[1] - '0';

	if (fCellX % 2 == sCellX % 2)
	{
		if (fCellY % 2 == sCellY % 2)
			return true;
	} else{
		if (fCellY % 2 != sCellY % 2)
			return true;
	}

    return false;
}