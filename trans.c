#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	int i,n;
	char term;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");
	term = args[0];
	if(term == '(')
		return "8b;	
	for(i = 1 ; i < strlen(args) ; i++)
	{
		if(args[i]==',')
			{
				if(term == '%')
				{
					if(args[i+1] == '%')
						return "89";
					else if(args[i+1] == '0')
						return "a3";
				}
				else if(
			}	
	}
	return 1;	
}
