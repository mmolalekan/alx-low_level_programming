#include "main.h"
/**
* _abs - computes the absolute value of an integer
* @n: the integer to be absoluted
*
* Return: the absolute value
*/

int _abs(int n)
{
	if (n >= 0)
		return (n);
	return ((-1) * n);
}
