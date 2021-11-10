	while (wo / base)
	{
		wo /= base;
		tt++;
	}
	print_buf[tt + 1] = '\0';
	while (u)
	{
		if (u%base> 9)
			print_buf[tt--] = u % base % 10 + (char *)letbase;
		else
			print_buf[tt--] = u % base + '0';
		u /= base;
	}
	s = print_buf;