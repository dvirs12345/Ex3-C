// Author: Dvir Sadon
#include <stdio.h>
#define LENGTH_FOR_MAIN 5

// Gets an array and a place in it and shifts all elements from i.
void shift_element(int* arr, int i)
{
	int num=*(arr);
	int num2=0;
	for(int i=0;i<=i+1;i++)
	{
		num2 = *(arr+i+1);
		*(arr+i+1) = num;
		num=num2;
	}
}
// Swaps between two pointers.
void swap (int* p1, int* p2)
{
    int temp = *(p1);
    *(p1) = *(p2);
    *(p2) = temp;
}

// Insertion sort implementation.
void insertion_sort(int* arr , int len)
{
	int placeBefore = 0;
    for(int i = 0; i < len; i++)
    {
        if(*(arr+i-1)>*(arr+i))
		{
			placeBefore = i-1;
			while(placeBefore>0&&*(arr+i-1)>*(arr+i))
			{
				swap(*(arr+placeBefore-1),*(arr+placeBefore));
				placeBefore-=1;
			}
		}
    }
}

// Prints array.
void printarr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            printf("%d", *arr);
        }
        else
        {
            printf("%d,", *arr);
        }
        (arr++);
    }
    arr = arr - len;
}

int main()
{
    int numberArray[LENGTH_FOR_MAIN]={0};
	int i;
	for (i = 0; i < LENGTH_FOR_MAIN; i++)
    {
		printf("Enter a number: ");
        scanf("%d", &numberArray[i]);
    }
    insertion_sort(numberArray,LENGTH_FOR_MAIN);
    printarr(numberArray, sizeof(numberArray)/sizeof(numberArray[0]));
	printf("\n");
	shift_element(numberArray,2);
	printarr(numberArray, sizeof(numberArray)/sizeof(numberArray[0]));
    return 0;
}