#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int step = 0;			
char* output[3];	
void hanoi_function(int t,int d, char A, char B, char C)
{
	if (d == 1) 
	{
		step++;
		if (step == t)
		{
			output[0] = A;
			output[1] = B;
			output[2] = d;
		}
		return;
	}
	hanoi_function(t, d - 1, A, C, B);
	step++;
	if (step == t)
	{
		output[0] = A;
		output[1] = B;
		output[2] = d;
	}
	hanoi_function(t, d - 1, C, B, A);
}

int main()
{
	int d, t;
	scanf("%d", &d);
	scanf("%d", &t);
	if (d < 1)
	{
		printf("Invalid disk number\n");
	}
	else if (t > ((1 << d) - 1))
	{
		printf("Step out of range\n");
	}
	else
	{
		hanoi_function(t, d, 'A', 'C', 'B');
		printf("Disk %d moved from %c to %c", output[2], output[0], output[1]);
	}

	return 0;
}