#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//q1
//1)Write a program to read a file and count the number of digits in it. 
//The file may contain an alphanumeric string.


int main(int argc, char*arg[])
{
	char* filename= arg[1];
	FILE *fp;
	int count=0;

	char c;
	fp= fopen(filename,"r");


	if(fp==NULL)
	{
		printf("Could not open or find file %s \n",filename);
		return 0;


	}


	for(c=getc(fp);c!=EOF;c=getc(fp))
	{
		if(c>='0' && c<='9')
		{
			count++;


		}
	}


	fclose(fp);

	printf("The file %s has %d digits/integers\n",filename,count);

	return 0;


}
