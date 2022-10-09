# C111 PracticeHomework
## C1110912
![Image](https://i.imgur.com/dgW9rg0.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	printf("Hello World!");
	return 0;
}
```
## C1110919
![Image](https://i.imgur.com/GKR0Mnk.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{	
	int a, c;
	char b[10];
	scanf("%d",&a);
	scanf("%s", b);
	scanf("%d", &c);
	printf("%d %s %d", a, b, c);
	return 0;
}
```

![Image](https://i.imgur.com/1PVXw9o.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{	
	float n1,n2,ans;
	scanf("%f",&n1);
	scanf("%f", &n2);

	ans = n1 + n2;
	printf("%.2f + %.2f = %.2f\n", n1 , n2,ans);
	ans = n1 - n2;
	printf("%.2f - %.2f = %.2f\n", n1 , n2,ans);
	ans = n1 * n2;
	printf("%.2f * %.2f = %.2f\n", n1 , n2,ans);
	ans = n1 / n2;
	printf("%.2f / %.2f = %.2f\n", n1 , n2,ans);
	return 0;
}
```

![Image](https://i.imgur.com/yCU0GBN.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{	
	int a, c;
	char b[10];
	scanf("%d",&a);
	scanf("%s", b);
	scanf("%d", &c);
	printf("%d %s %d", a, b, c);
	return 0;
}
```
## C1110926
![Image](https://i.imgur.com/DHtX370.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int main()
{
	float n1, n2;
	scanf("%f", &n1);
	scanf("%f", &n2);
	float length, unit1,unit2;
	length = sqrt(pow(n1,2) + pow(n2,2));
	printf("%.2f\n", length);
	unit1 = n1 / length;
	unit2 = n2 / length;
	printf("%.2f %.2f\n", unit1, unit2);
	return 0;
}
```
![Image](https://i.imgur.com/doRmCqX.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int main()
{
	float n1[2][2],addX,addY,subX,subY,result3;
	scanf("%f %f %f %f", &n1[0][0], &n1[0][1], &n1[1][0], &n1[1][1]);

	addX = n1[0][0] + n1[1][0];
	addY = n1[0][1] + n1[1][1];
	printf("%.2f %.2f\n", addX, addY);

	subX = n1[0][0] - n1[1][0];
	subY = n1[0][1] - n1[1][1];
	printf("%.2f %.2f\n", subX,subY);

	result3 = (n1[0][0] * n1[1][0]) + (n1[0][1] * n1[1][1]);
	printf("%.2f\n", result3);

	return 0;
}
```
## C1111003
![Image](https://i.imgur.com/EoR3nrO.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	float n1, n2;
	char op;
	float ans;

	scanf("%f%c%f", &n1, &op, &n2);

	if (op == '+') {
		ans = n1 + n2;
		printf("%.2f+%.2f=%.2f", n1, n2, ans);
	}
	else if (op == '-') {
		ans = n1 - n2;
		printf("%.2f-%.2f=%.2f", n1, n2, ans);
	}
	else if (op == '*') {
		ans = n1 * n2;
		printf("%.2f*%.2f=%.2f", n1, n2, ans);
	}
	else if (op == '/') {
		ans = n1 / n2;
		printf("%.2f/%.2f=%.2f", n1, n2, ans);
	}


	
	return 0;
}
```
![Image](https://i.imgur.com/zQy6eAg.png)
```c
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - i - 2; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i * 2 ; k++) {
			printf("%c", 'A' + i);
		}
		if (i != n - 1) {
			printf("\n");
		}
	}
	return 0;
}
```


