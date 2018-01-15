#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
# include "hex.h" 
#define SIZE 10000

int main()
{
        FILE *ptr_file;
        char buff[SIZE];
	 int errnum;
		   
	ptr_file =fopen("input.txt","rb");
		
   	if (!ptr_file)
	{
          	errnum = errno;
      		fprintf(stderr, "Value of errno: %d\n", errno);
      		perror("Error printed by perror");
      		fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
        }

        else
	{
		fgets(buff,SIZE, ptr_file);
            	hexDump ( &buff, strlen(buff));
		fclose(ptr_file);
		return 0;
	}
}
    
