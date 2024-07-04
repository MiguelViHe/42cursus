int	ft_fdprintf(char const *str, ...)
{
	int			i;
	int			counter;
	va_list		args;
	int			control;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			control = ft_putchar(str[i]);
		else
			control = ft_putoption(str[++i], args);
		if (control < 0)
			return (control);
		counter += control;
		i++;
	}
	va_end(args);
	return (counter);
}