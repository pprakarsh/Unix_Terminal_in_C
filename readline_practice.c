#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	while(1)
	{
		char* line = readline( "test> ");
	    	printf( "%s\n", line);
		add_history(line);
		free(line);
	}
    return 0;
}
