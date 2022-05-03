/* Lucas Voron
 * COEN 10
 * Lab 6
 * Monday 2:15pm
 * */

#include <stdio.h>

int main()
{
	int schedule[5] = {0,0,0,0,0};
	int counter = 0;
	int x;
	int y;
	int i;

	while(1)//forever loop
	{
		printf("Welcome to Stinky Pet Spa!\n");
		printf("Press 1 to create new appointment\n");
		printf("Press 2 to cancel an appointment\n");
		printf("Press 3 to list today's schedule\n");
		printf("Press 9 to quit\n");//printf - menu
		scanf("%d", &x);

		if(x==1) //new appointment
		{
			for(i=0; i<5; i++)
			{
				if(schedule[i]==0)
				{
					schedule[i] = 1;
					printf("An appointment has been scheduled for you at %dpm\n", i+1);
					counter = counter+1;
					break;
				}
			}
			if(counter==5)
				printf("Today's schedule is full, please come back tomorrow\n");	
		}
	
		else if(x==2) //cancel
		{
			if(counter==0)
				printf("There are no appointments to cancel\n");
			else
			{
				printf("Which appointment would you like to cancel?\n");
				scanf("%d", &y);
					if(schedule[y-1]==0)
						printf("There are no appointments scheduled at this time.\n");
				
				schedule[y-1]=0;
				counter--;
				if(schedule[y-1]==1)
					printf("Your appointment at %dpm has been canceled\n", y);
			}
		}

		else if(x==3) //list
		{
			if(schedule[i]==0)
				printf("All appointments are available.\n");
			else
				for(i=0; i<5; i++)
				{
					if(schedule[i]==0)
						printf("%dpm: free\n", i+1);
					else
						printf("%dpm: busy\n", i+1);
				}
		}

		else if(x==9) //exit
		{
			return 1;
		}
		else
		{
			printf("Bad option\n");
		}
	}
}
