#include "main.h"
/**
*binary_to_uint - converts a binary number to an unsigned int.
*@b: binary number
*Return: the converted number
*/

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int ret_val = 0;

	if (!b)
	{
		return (0);
	}
	while (b[i])
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		ret_val = 2 * ret_val + (b[i] - '0');
		i++;
	}

	return (ret_val);
}
