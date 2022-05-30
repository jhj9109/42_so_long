int	create_trgb_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t_int(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r_int(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g_int(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b_int(int trgb)
{
	return (trgb & 0xFF);
}
