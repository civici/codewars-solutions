//https://www.codewars.com/kata/5544c7a5cb454edb3c000047

int bouncingBall(double h, double bounce, double window) 
{
	if (h <= 0 || bounce >= 1 || bounce <= 0 || window >= h) 
		return -1;
  
	int times = 1;
	for (double heightAfterBounce = h * bounce; heightAfterBounce > window; heightAfterBounce *= bounce) 
		times += 2;
	return times;
}