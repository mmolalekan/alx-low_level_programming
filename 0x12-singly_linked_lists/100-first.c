#include <stdio.h>

void first(void) __attribute__ ((constructor));
/**
* first - You're beat! and yet, you must allow,\n
*	I bore my house upon my back!\n
*/

void first(void)
{
	printf("You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n");
}
