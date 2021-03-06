// https://www.codewars.com/kata/541c8630095125aba6000c00

int digital_root(int n) {

	int num = n, sum;
	MAINLOOP:
	for (sum = 0; num >= 1; num /= 10)
	{
		sum += num % 10;
	}
	if (sum >= 10)
	{
		num = sum;
		goto MAINLOOP;
	}
  return sum;
}