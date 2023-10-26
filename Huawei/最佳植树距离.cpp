
#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

int A[] = { 1,5,3,6,10,7,13};

int countA = sizeof(A) / sizeof(A[0]);

int conntT = 3;

int cmpA( void const*a, void const* b)

{

	int aa = *(int*)a;

	int bb = *(int*)b;

	return aa-bb;

}

int minstep = 0;

int maxstep = 0;

int max(int a, int b)

{

	return a > b ? a : b;

}

int min(int a, int b)

{

	return a < b ? a : b;

}

int main()

{

	qsort(A, countA, sizeof(int), cmpA);

	minstep = A[1]-A[0];

	maxstep = A[countA-1] - A[0];

	for (size_t i = 0; i < countA - 1; i++)

	{

		minstep = min(minstep, min(minstep, A[i + 1] - A[i]));

	}

	

	for (size_t i = minstep; i < maxstep; i++)

	{

		int distance = 1 + i * (conntT - 1);

		if (distance <= A[countA - 1]) 

		{

			continue;

		}

		else

		{

			minstep = i-1;

			break;

		}

	}

	return 0;

}