char *read_line(int fd)
{
	char *buf;
	char c;
	int i;
	int n_read;

	buf = malloc(sizeof(char) * 50000);
	if (buf == NULL)
		return (NULL);
	n_read = 0;
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		n_read++;
		if (c == '\n')
			break;
		buf[i] = c;
		i++;
	}
	if (n_read == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return (buf);
}