/* Lucas Voron
 * COEN 10
 * Lab 7
 * Monday 2:15pm
 * */

#include <stdio.h>
#include <string.h>

int main()
{
	char schedule[5][20]={'\0', '\0', '\0', '\0', '\0'};
	int counter = 0;
	int x;
	int i;
	int j;
	char c;
	char cancel[20];
	char null[20]={'\0'};
	char name[20];
	int flag=0;

	while(1)//forever loop
	{
		printf("Welcome to Stinky Pet Spa!\n");
		printf("Press 1 to create new appointment\n");
		printf("Press 2 to cancel an appointment\n");
		printf("Press 3 to list today's schedule\n");
		printf("Press 4 to search up your name with its first letter\n");
		printf("Press 9 to quit\n");//printf - menu
		scanf("%d", &x);
		
		switch(x)
		{
			case 1: //new appointment
			{
				if(counter==5)
					printf("Today's schedule is full, please come back tomorrow\n");
				else
				{
					printf("Please enter your name.\n");
					scanf("%s", name);
					i=0;
					while(i<5)
					{

						if(schedule[i][0]=='\0')
						{
							strcpy(schedule[i], name);
							printf("An appointment has been scheduled for %s at %dpm\n", name, i+1);
							counter = counter+1;
							break;
						}
						i++;
					}
				}
			}
			break;
	
			case 2: //cancel
			{
				if(counter==0)
					printf("There are no appointments to cancel\n");
				else
				{
					printf("Which appointment would you like to cancel?\n");
					scanf("%s", cancel);
					
					i=0;
					while(i<5)
					{
						if(strcmp(schedule[i], cancel)==0)
						{
							strcpy(schedule[i], null);
							counter--;
							printf("Your appointment for %s at %dpm has been canceled.\n", cancel, i+1);
							while(i<4)
							{
								strcpy(schedule[i], schedule[i+1]);
								flag++;
								i++;
							}
							strcpy(schedule[i+1], null);
						}
						i++;
					}
					if(flag==0)
					{
						printf("This name does not have an appointment.\n");
					}
				}
			}
			break;

			case 3: //list
			{
				if(counter==0)
				{
					printf("All appointments are available.\n");
					break;
				}
				else
					i=0;
					while(i<5)
					{
						if(schedule[i][0]=='\0')
							printf("%dpm: free\n", i+1);
						else
							printf("%dpm: %s\n", i+1, schedule[i]);
						i++;
					}
			}
			break;

			case 4:
			{
				if(counter==0)
					printf("There are no existing appointments to search.\n");
				else	
				{
					printf("What is the first letter of your name?\n");
					scanf(" %c", &c);
	
					i=0;

					printf("Here are names found that start with %c.\n", c);
					while(i<5 && schedule[i]!='\0')
					{
						if(c==schedule[i][0])
						{
							flag++;
							printf("%s\n", schedule[i]);
						}
						i++;
					}
					if(flag==0)
					{
						printf("No names starting with %c were found.\n", c);
					}
				}
			}
			break;

			case 9: //exit
			{
				return 1;
			}
			break;
			
			default:
			{
				printf("Bad option\n");
			}
			break;
		}
	}
	return 0;
}
