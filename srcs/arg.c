
#include "corewar.h"

/*
** verify a char is in LABEL_CHARS
*/

int		is_in_label_chars(char c)
{
	int		i;
	char	*str;
	
	i = -1;
	str = LABEL_CHARS;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}


/*
** Define type of arg
*/

int		define_type(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	if (ft_strchr(str, '%'))
		return (T_DIR);
	else if (str[0] == 'r' && ft_atoi(str++) <= REG_NUMBER)
		return (T_REG);
	while (str[++i] && ft_isalpha(str[i]))
		if (str[i + 1] = '\0')
			return (T_IND);
	i = -1;
	while (str[++i] && is_label_chars(str[i]))
		if (str[i + 1] = '\0')
			return (T_LAB);
	return (0);
}
