#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "hex.h" 


void hexDump ( void *addr, int len) {
   	int i;
	char c;
	unsigned char buffLine[17];
	unsigned char *pc = (unsigned char*)addr;

	for (i = 0; i < len; i++) 
	{
		if ((i % 16) == 0) 
		{
			if (i != 0)
				printf ("  %s\n", buffLine);
       			if (pc[i] == 0x00) exit(0);
				printf ("%08x: ", i);
        	}

       		printf ("%02x", pc[i]);
        	if ((i % 2) == 1) 
            		printf (" "); 
		if ((pc[i] < 0x20) || (pc[i] > 0x7e))
		{
            		buffLine[i % 16] = '.';
        	}
		else
		{
			buffLine[i % 16] = pc[i];
		}    
		buffLine[(i % 16) + 1] = '\0';
	}

	while ((i % 16) != 0)
	{
        	printf ("   ");
        	i++;
    	}
	printf ("  %s\n", buffLine);
}

	
	
   

