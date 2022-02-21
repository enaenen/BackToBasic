#include "libft.h"

int	main(void)
{
	char *source = "123456";
	char *destination;
	char *o_dest;

	destination = (char *)malloc(sizeof(char) * ft_strlen(source) + 1);
	o_dest  = (char *)malloc(sizeof(char) * strlen(source) + 1);
	
//	ft_strlcpy(destination, source, ft_strlen(source) + 1);
	ft_strlcpy(destination, source, 0);
//	strlcpy(o_dest, source, strlen(source) + 1);
	strlcpy(o_dest, source, 0);

	printf("ft_strlen = %s \n", destination);
	printf("strlen = %s \n", o_dest);
}
