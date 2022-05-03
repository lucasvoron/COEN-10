/* Lucas Voron
 * COEN 10
 * Lab 5
 * Monday 2:15pm
 * */

#include <stdio.h>

int main (void)
{
	srand((int) time (NULL));

	int i;
	int z;
	int counter=0;

	for(i=0; i<10; i++)
	{
		int x;
		int num1 = rand()%13;
		int num2 = rand()%13;
		int y;

		printf("%d x %d = \n", num1, num2);
	
		scanf("%d", &x);

		y = num1*num2;

		if (x==y)
		{
			counter++;
		}
	}
	
	z = counter*10;
	
	printf("Percentage of how many you got correct = %d \n", z);

	return 0;
}
