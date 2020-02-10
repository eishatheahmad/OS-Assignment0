#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//q2


void userMenu()
{

printf("%s", "\n----------------------MENU----------------------\n");
printf("%s", "Press 1 to Add Student Record\n");
printf("%s", "Press 2 to Read Student Record\n");
printf("%s", "Press 3 to delete Student Record\n");
printf("%s", "Press 4 to exit program\n");
printf("%s", "\n------------------------------------------------\n");

}




void addStudent()
{
	FILE *fPtr;

	fPtr= fopen("record.txt","a");
	char temp[500];

	printf("%s","\nEnter Name[tab],Roll Number[tab] and Email ID:\n");

	fgetc(stdin);
	fgets(temp,500,stdin);
	fputs(temp,fPtr);

	fclose(fPtr);

}


void deleteRecord()
{
	FILE *fptr1, *fptr2;
    char ch;
    int id=0, count = 1;
 
  
    fptr1 = fopen("record.txt", "r");
 
    printf("\n Enter valid number to delete student information: ");
    scanf("%d", &id);
  
  
    fptr2 = fopen("copy.txt", "w");
    ch = getc(fptr1);
    while (ch != EOF)
    {
        ch = getc(fptr1);
        if (ch == '\n')
            count++;
          
            if (count != id)
            {
                putc(ch, fptr2); //storing in copy file
            }
    }
	
    fclose(fptr1);
    fclose(fptr2);
	
    remove("record.txt");
    rename("copy.txt", "record.txt");
	
	printf("After deletion\n");
	
	fptr1=fopen("record.txt,"r");
	ch=getc(fptr1);
	
	while(ch!=EOF)
	{
		printf("%s",ch);
		ch=getc(fptr1);
	}
	fclose(fptr1);

}





void readRecord()
{

	FILE *fPtr;

	fPtr= fopen("record.txt","r");
	printf("Enter a valid number to display information of student: ");
	char n[2];
	char str[500];
	int id=0;
	
	//input of number
	fgetc(stdin);
	fgets(n,2,stdin);
	id=atoi(n);
	id++;

	int count=0;

	while(fgets(str,500,fPtr)!=NULL)
	{
		count++;
		if(count==id)
		{
			printf("Student Found \n");
			printf("[Name],[Roll Number],[Email Id] : %s", str);
		}

	}
fclose(fPtr);

}

int main()
{

	FILE *fPtr;
	char data[100];


	int choice=0;
	char ch[2];


	userMenu();
	//printf(" %s","\nEnter number:");
	while(choice!=4)
	{


		printf("\nEnter number:");

		fgets(ch,2,stdin);
		choice=atoi(ch);



		if(choice==1)
		{	
			printf("%s","\nEnter the details of the student\n");
			addStudent();
		}


	if(choice==2)
		{
			printf("%s","\nView details of the student\n");
			readRecord();
		}

	if(choice==3)
	{
			printf("%s","\nDelete details of the student\n");
			deleteRecord();
	}

}

return 0;
}