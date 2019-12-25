#include "txtfind.h"
#include <stdio.h>
#define LINE 256
#define WORD 30

int getLine(char s[])
{
    int i = 0;
    char car = ' ';
    car = getc(stdin);
    if(car == EOF)
	{
		return 0;
	}
	
    while (i < LINE && car!=EOF && car != '\n')// While not at the end of the file/line
    {
        *(s+i) = car;
        car = getc(stdin);
        i++;
    }
	
    *(s+i) = 0;
	
    return i-1;
}

int getWord(char s[])
{
	char car = getc(stdin);
    int counter = 0;
    
    while(car == '\t'|| car == '\n' || car == ' ') // While not at the end 
	{
		car = getc(stdin);
	}
	
    while (counter < WORD &&  car != ' ' && car != '\t' && car != '\n' && car!=EOF) // While not at the end 
    {
        *(s+counter) = car;
        car = getc(stdin);
        counter+=1;
    }
	
    *(s+counter) = 0;
	
    return counter;
}

void print_lines(char *str)
{
    char st[LINE] = {0};
    char* h = st;
    int num = getLine(h);
	
    while (num != 0) // While is not 0.
    {
        if (substring(st, str) != 0) // If indeed substring then should print it.
        {
            printf("%s\n",st);
        }
		
        h = st;
        num = getLine(h);
    }
}

int substring(char *str1, char *str2)
{
    int q = 0, counter1 = 0, counter2 = 0;
    while (*(str2 + counter2) != 0) // Make counter2
	{
        counter2+=1;
    }
	
    while (*(str1 + counter1) != 0)// Make counter1
    {
        counter1+=1;
    }

    for (int i = 0; i < counter1; i+=1)
    {
        q = 1;
		
        for (int j = 0; j < counter2; j+=1)
        {
            if(*(str1+i+j)!= *(str2+j))
            {
                q = 0;
            }
        }
        if(q == 1) 
		{
			return q;
		}
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
	char *p1 = s;
    char *p2 = t;
    int lenS = 0, lenT=0;
    while (*(s+lenS) != 0)
	{
		lenS+=1;
	}	
	
    while (*(s+lenT) != 0)
	{
		lenT+=1;
	}
	
    while (*p1 != 0)
    {
        if (*p1 != *p2)
        {
            if(n == 0)
			{
                return n;
            }
            p1 += 1;
            n -= 1;
        }
        p1 += 1;
        p2 += 1;
    }
	
    if( *p2 == 0 && *p1 == 0 && n == 0)
	{
		return 1;
    }
	
    return 0;
}

void print_similar_words(char *str)
{
	char st[WORD] = {' '};
    int word1 = 1;
    
    while (word1 != 0)
    {
        word1 = getWord(st);
		
        if (similar(st,str,0) || similar(st, str, 1))
        {
            printf("%s\n",st);
        }
    }
}

int main()
{
    char st[WORD] = {0};
	char word0[WORD]= {' '};
    char *ptr = st;
    int sizeOfWord = getWord(ptr);
    int counter = 0;
	char chosen = ' ';
	
    for (counter = 0; counter <= sizeOfWord; counter++)
    {
        *(word0+counter) = *(st+counter);
    }
	
    *(word0+counter+1) = 0;
    ptr = st;
    chosen = getc(stdin);
	getc(stdin);
	switch (chosen)
	{
		case 'a':
			print_lines(word0);
			break;
		case 'b':
			print_similar_words(word0);
			break;
		default:
			printf("Invalid input \n");
	}
}