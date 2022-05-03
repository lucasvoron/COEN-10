/* Lucas Voron
 * COEN 10
 * Lab 8
 * Monday 2:15pm
 * */

#include <stdio.h>
#include <string.h>

void request();
void cancelAppointment();
void list();
void letter();
void numberOfPets();

char schedule[5][20] = {'\0', '\0', '\0', '\0', '\0'};
char phoneNumbers[5][20] = {'\0', '\0', '\0', '\0', '\0'};
int petNumbers[5] = {0, 0, 0, 0, 0};
int counter = 0;

int main()
{
	int x;

	while(1)//forever loop
	{
		printf("Welcome to Stinky Pet Spa!\n");
		printf("Press 1 to create new appointment\n");
		printf("Press 2 to cancel an appointment\n");
		printf("Press 3 to list today's schedule\n");
		printf("Press 4 to search up your name with its first letter\n");
		printf("Press 5 to search up an appointment by number of pets\n");
		printf("Press 9 to quit\n");//printf - menu
		scanf("%d", &x);
		
		switch(x)
		{
			case 1://new appointment
				request();
				break;
			case 2: //cancel
				cancelAppointment();
				break;
			case 3: //list
				list();
				break;
			case 4: //show names with letter
				letter();
				break;
			case 5: //show appointments based on #of pets
				numberOfPets();
				break;
			case 9: //quit
				printf("Exiting program.\n\n");
				return 0;
				break;
			default:
				printf("That command does not exist, please try again.\n");
				break;
		}
	}
	return 0;
}

void request()	
{
	char name[20];
	char phone[20];
	int y;
	int j;
	int i;

	if(counter==5)
		printf("Today's schedule is full, please come back tomorrow\n");
	else
	{
		printf("Please enter your name.\n");
		scanf("%s", name);

		j=0;
		while(j<5)
		{
			if(strcmp(schedule[i], name)==0)
			{
				printf("An appointment has already been scheduled under this name.\n");
				return;
			}
			j++;
		}

		printf("Please enter your phone number.\n");
		scanf("%s", phone);

		printf("Please enter the number of pets for this appointment.\n");
		scanf("%d", &y);

		i=0;
		while(i<5)
		{
			if(schedule[i][0]=='\0')
			{
				strcpy(schedule[i], name);
				strcpy(phoneNumbers[i], phone);
				petNumbers[i] = y;
				printf("An appointment has been scheduled for %s at %dpm\n", name, i+1);
				counter = counter+1;
				break;
			}
			i++;
		}
	}
}

void cancelAppointment()
{
	char cancel[20];
	char null[20] = {'\0'};
	int i;
	int flag = 0;

	if(counter==0)
		printf("There are no appointments to cancel\n");
	else
	{
		printf("Which appointment would you like to cancel?\n");
		scanf("%s", cancel);
					
		i=0;
		while(i<counter)
		{
			if(strcmp(schedule[i], cancel)==0)
			{
				counter--;
				printf("Your appointment for %s at %dpm has been canceled.\n", cancel, i+1);
				while(i<counter)
				{
					strcpy(schedule[i], schedule[i+1]);
					strcpy(phoneNumbers[i], phoneNumbers[i+1]);
					petNumbers[i] = petNumbers[i+1];
					flag++;
					i++;
					printf("%s's (%s) appintment has been moved to %dpm.\n", schedule[i], phoneNumbers[i], i);
				}
				strcpy(schedule[i], null);
				strcpy(phoneNumbers[i], null);
				petNumbers[i] = 0;
			}
			i++;
		}
		if(flag==0)
			{
				printf("This name does not have an appointment.\n");
			}
	}
}

void list()
{
	int i;

	if(counter==0)
	{
		printf("All appointments are available.\n");
	}
	else
	{
		printf("Time  Name  Phone Number  Pets\n");
		i=0;
		while(i<5)
		{
			if(schedule[i][0]=='\0')
				printf("%dpm: free\n", i+1);
			else
				printf("%dpm: %s %s %d\n", i+1, schedule[i], phoneNumbers[i], petNumbers[i]);
					i++;
		}
	}
}	

void letter()
{
	char c;
	int i;
	int flag = 0;

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
				printf("%s at %dpm\n", schedule[i], i+1);
			}
			i++;
		}
		if(flag==0)
		{
			printf("No names starting with %c were found.\n", c);
		}
	}
}

void numberOfPets()
{
	int z;
	int i;
	int flag =0;

	if(counter==0)
		printf("There are no appointments scheduled yet.\n");
	else
	{
		printf("Enter the number of pets for the appointment you are looking for.\n");
		scanf(" %d", &z);
		
		i=0;
		while (i<counter)
		{
			if(petNumbers[i]==z)
			{
				printf("%dpm: %s\n", i+1, schedule[i]);
				flag++;
			}
			i++;
		}
		if(flag==0)
			printf("There are no appointments with this number of pets.\n");
	}
}
