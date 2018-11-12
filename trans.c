#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	int i,n,count=0;
	char term;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		strcpy(mcode, "error");
		return 0;
	}


	strcpy(mcode, "AB CD EF");
	term = args[0];
	if(term == '(')
		strcpy(mcode, "8b");	
	for(i = 1 ; i < strlen(args) ; i++)
	{
		if(args[i]=='(')
			count++;	
		if(args[i]==',')
		{
			if(count!=0)
				strcpy(mcode,"8b");			
			else if(term == '%')
			{
				if(args[i+1] == '%')
					strcpy(mcode, "89");
				else if(args[i+1] == '0')
					strcpy(mcode, "a3");
			}
			else if(term=='0')
			{
				if(args[i+1]=='%')
					strcpy(mcode, "a1");
			}
			else if(term=='$')
			{			
				if(args[i+3]=='a')
					strcpy(mcode, "b8");
				else if(args[i+3]=='c')
					strcpy(mcode, "b9");
				else if(args[i+3]=='d')
				{
					if(args[i+4]=='x')
						strcpy(mcode, "ba");
					else if(args[i+4]=='i')
						strcpy(mcode, "bf");
					}
				else if(args[i+3]=='b')
				{
					if(args[i+4]=='x')
						strcpy(mcode, "bb");
					else if(args[i+4]=='p')
						strcpy(mcode, "bd");
				}
				else if(args[i+3]=='s')
				{
					if(args[i+4]=='p')
						strcpy(mcode, "bc");
					else if(args[i+4]=='i')
						strcpy(mcode, "be");
				}	
			}
		}	
	}
	return 1;	
}
