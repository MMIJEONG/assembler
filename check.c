#include "myas.h"
#include <string.h>

int is_valid(char *op, char *args)
{
	int i,c=0;
	if(args[0] == '%')
		c++;
	for(i = 1 ; i < strlen(args) ; i++)
	{
		if(args[i] == ',')
		{
			if(args[i+1] == '%')
			{
				c++;
				break;
			}
		}
	}
	if(c>=1)
		return 1;
	else
		return 0;
}
