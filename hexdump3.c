#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "hex.h" 

int main(int argc, char *argv[])
{
        FILE *ptr_file;
        int errnum;
	ptr_file =fopen(argv[1],"rb");
	
	if (!ptr_file)
	{
          	errnum = errno;
      		fprintf(stderr, " %d\n", errno);
      		fprintf(stderr, " %s\n", strerror( errnum ));
        }

        else
	{
		fseek (ptr_file,0,2);
		long size=ftell(ptr_file);
		fseek(ptr_file,0,SEEK_SET);
		
		char buff[size];
		fgets(buff,size, ptr_file);
            	hexDump (&buff,size); 
		fclose(ptr_file);
		return 0;
	}
}
