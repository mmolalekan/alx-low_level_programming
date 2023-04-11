/**
 * clear_bit - sets the bit at a given index to 0
 * @n: pointer to the integer to modify
 * @index: index of the bit to clear (0-indexed)
 *
 * Return: 1 on success, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL;

	if (index > 63)
		return (-1);

	mask <<= index;
	*n &= ~mask;

	return (1);
}

