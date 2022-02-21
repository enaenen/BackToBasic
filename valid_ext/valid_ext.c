#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int	i;
	int	j;

	i = 0;
	j = 0;

	if (!s1 || !s2)
		return (0);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}

void	ft_putstr_fd(char *str, int fd)
{
	if(!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	valid_ext(char *file, char *ext)
{
	int	i;

	i = ft_strlen(file) - ft_strlen(ext);
	while (i < (int)ft_strlen(file))
	{
		if (file[i] != *ext)
			print_error(ft_strjoin("File Extention Wrong. Need ", ext));
		ext++;
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		print_error("Need More than 1 ARG");

	valid_ext(argv[1],argv[2]);
}
