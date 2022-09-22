#include <stdio.h>

int Towers(int n, char a, char b, char c, int* steps, int target) {

	if (n == 1) {
		*steps += 1;
		if (*steps == target)
			printf("Disk %d moved from %c to %c", n, a, c);
	}
	else {
		Towers(n - 1, a, c, b, &*steps, target);
		*steps += 1;
		if (*steps == target)
			printf("Disk %d moved from %c to %c", n, a, c);
		Towers(n - 1, b, a, c, &*steps, target);
	}
	return 0;
}
int main()
{
	int disks = 0, target = 0;
	int steps = 0;
	scanf_s("%d", &disks);
	scanf_s("%d", &target);
	if (disks < 1)
		printf("Invalid disk number");
	else {
		Towers(disks, 'A', 'B', 'C', &steps, target);
		if (steps < target)
			printf("Step out of range");
	}
}

