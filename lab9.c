/* Lucas Voron
 * COEN10
 * Lab 9
 * Monday 2:15pm
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
#define SIZE 20

int main(void);
void input(void);
void reverse(void);
void uppercase(void);
void info(void);
void output(void);

char words[MAX][SIZE];
int length[MAX];
int counter = 0;

int main(void)
{
	input();
	reverse();
	uppercase();
	info();
	return 1;
}

void input(void)
{
	int i;
	int x;
	int j;
	char temp[20];
	char entry[20];
	
	if(counter <= 10)
	{
		for(i=0; i<MAX; i++)
		{
			printf("Please input string here: ");
			if(scanf("%s", entry) < 1)
				break;
			else
			{
				strcpy(words[i], entry);
				counter++;
			}
		}
	}
	for(i=0; i<counter; i++)
	{
		for(j=i+1; j<counter; j++)
		{
			if(strcmp(words[i], words[j])>0)
			{
				strcpy(temp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], temp);
			}
		}
	}
	printf("Strings:\n");
	output();
}

void reverse(void)
{
	int i;
	int j;
	char temp[20];

	for(i=0, j=counter-1; i<j; i++, j--)
	{
		strcpy(temp, words[i]);
		strcpy(words[i], words[j]);
		strcpy(words[j], temp);
	}
	printf("Reverse:\n");
	output();
}

void uppercase(void)
{
	int i = 0;
	int j = 0;
	int x = 0;

	char *p = words[i];
	int flag = 0;
	
	for(i=0; i<counter; i++)
	{
		j=0;
		while(words[i][j] != '\0')
		{
			words[i][j] = toupper(words[i][j]);
			j++;
		}
		flag=0;
		p = words[i];
		while(*p != '\0')
		{
			flag++;
			p++;
		}
		length[i] = flag;
	}

	printf("Uppercase:\n");
	output();
}

void info(void)
{
	int i =0;
	int l;
	int s;
	int sum = 0;
	int num = 0;

	printf("Info:\n");
	if(length[i]<length[i+1])
		s = i;
	else
		s = i+1;
	for(i=0; i<counter; i++)
	{
		if(length[i]<length[i+1] && length[i]<length[s])
			s = i;
	}

	printf("smallest: %s\n", words[s]);

	if(length[i]>length[i+1])
		l = i;
	else
		l = i+1;
	for(i=0; i<counter; i++)
	{
		if(length[i]>length[i+1] && length[i]>length[l])
		{
			l = i;
		}
	}

	printf("largest: %s\n", words[l]);

	for(i=0; i<counter; i++)
	{
		sum += length[i];
	}
	num = (sum/counter);
	
	printf("average word length: %d\n", num);

	printf("entry that isn't a word:\n");
	for(i=0; i<counter && words[i] != '\0'; i++)
	{
		if(isalpha(words[i][0]) == 0)
			printf("%s\n", words[i]);
	}
}

void output(void)
{
	int i=0;

	if(counter==0)
		printf("There are no inputs.\n");
	else
	{
		i=0;
		while(i<counter)
		{
			printf("%s\n", words[i]);
			i++;
		}
	}
}

