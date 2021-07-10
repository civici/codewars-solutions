// https://www.codewars.com/kata/554a44516729e4d80b000012/train/c

#include <stdlib.h>

int* nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth) 
{
	int months = 1;
	double currentMoney = 0;
	double newCarCurrent = startPriceNew;
	double oldCarCurrent = startPriceOld;
	for ( ; currentMoney + oldCarCurrent <= newCarCurrent; months++)
	{
		if (months != 0 && months % 2 == 0)
			percentLossByMonth += 0.5;
		oldCarCurrent -= (oldCarCurrent * percentLossByMonth) / 100;
		newCarCurrent -= (newCarCurrent * percentLossByMonth) / 100;
		currentMoney += savingperMonth;
	}
	int* result = malloc(sizeof(int) * 2);
	double temp = (currentMoney + oldCarCurrent) - newCarCurrent;
	if ((temp - (int) temp) >= 0.5)
	{
		temp = (int) temp + 1;
	}
	result[0] = months - 1;
	result[1] = temp;
	printf("%d %d\n", result[0], result[1]);
	return result;
}

int main()
{
	nbMonths(18000, 32000, 1500, 1.25);
}