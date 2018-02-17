unsigned int factorial(unsigned int x)
{
	return x <= 1 ? x : factorial(x-1)*x;
}
