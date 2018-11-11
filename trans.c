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
			else if(term=='0')
			{
				if(args[i-1]==')')
					return "8b";
				else if(args[i+1]=='%')
					return "a1";
			}
			else if(term=='$')
			{			
				if(args[i+3]=='a')
					return "b8";
				else if(args[i+3]=='c')
					return "b9";
				else if(args[i+3]=='d')
				{
					if(args[a+4]=='x')
						return "ba";
					else if(args[a+4]=='i')
						return "bf";
					}
				else if(args[i+3]=='b')
				{
					if(args[a+4]=='x')
						return "bb";
					else if(args[a+4]=='p')
						return "bd";
				}
				else if(args[i+3]=='s')
				{
					if(args[a+4]=='p')
					return "bc";
					else if(args[a+4]=='i')
						return "be";
				}	
			}
		}	
	}
	return 1;	
}
