#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//q3

//reverses a word
void reverseToken(char *str) {
  
	int l=strlen(str)-1; //pointer to last index
	for(int i=0; i<=l/2;i++)
	{
		char temp1= str[i];
		char temp2= str[l];
		
		str[l]=temp1;
		l--;
		str[i]=temp2;

	}
}

//returns false if no vowel, otherwise true
bool containsVowel(char *str)
{
	bool flag=false;
	for(int i=0; str[i]!='\0';i++)
	{
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
		{
			flag=true; //true means contains vowels
			return flag;



		} 

		if(str[i]=='A'|| str[i]=='E' || str[i]=='O' || str[i]=='I' || str[i]=='U')
		{

			flag=true; //true means contains vowels
			return flag;
		}


	}

	flag=false; //false means no vowel. word should be reversed
	return flag;



}

void reverseWords(char *str)
{
	char token[100];
	char *ptr1=str;
	char *ptr2;
	int wordLength = 0;

	bool flag=false;

	while(*ptr1!='\0') 
	{      
		//tpkenize
		while(*ptr1 != ' ' && *ptr1 != '\0') 
		{
			token[wordLength] = *ptr1;
			ptr1++;
			wordLength++;
		}
		token[wordLength] = '\0'; //insert null add end of token
		wordLength = 0; //reset for next token

		flag= containsVowel(token); //false if no vowel

		//if no vowel reverse the word/token
		if(flag==false)
		{
			reverseToken(token); 
		}

		//put the reversed token back into string
		ptr2 = token;

		while (*ptr2!='\0')
		{ 
			*str = *ptr2;
			ptr2++;
			str++;
		}
		
		if (*str == ' ') 
		{
			str++;
		}


		//point to the next word/token
		ptr1 = str;                             \
	
	
	}	

}


int main(int argc, char*arg[])
{
	char* filename= arg[1];
	
	FILE *fp;
	FILE *fptr;

	char input[1000]; //for reading string from file

	fp= fopen(filename,"r");


	//reading string from file and storing it in "input"
	fscanf(fp,"%[^\n]",input);
	printf("Data: %s\n",input); 

	reverseWords(input);
	fptr= fopen("reversed.txt","w");
	
	if(fptr==NULL)
	{
		printf("%s","Unable to create new file.\n");;
		exit(EXIT_FAILURE);
	}

	
		//storing string to output file after processing
		
		fputs(input,fptr);
		fclose(fptr);
		fclose(fp);
	

	//printf("\nOutput: %s\n",input);



	return 0;


}