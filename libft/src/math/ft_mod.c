int	ft_mod(int a, int b)
{
	int	r;

	r = a % b;
	if (r < 0)
		return (r + b);
	return (r);
}
