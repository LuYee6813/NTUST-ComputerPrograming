#include <stdio.h>
#include <string.h>

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	char dictionaryKey[100][75];
	int dictionaryValue[100] = { 0 };
	int dictionaryKeyLength[100] = { 0 };
	int count = 0;
	int i = 0, j = 0;
	for (i = 0; i < n; i++) {
		char temp[75];
		scanf(" %s", &temp);
		char temp2 = 'A';
		while (temp2 != '\n')
			scanf_s("%c", &temp2, 1);
		int have = 0;
		for (j = 0; j < count; j++)
		{
			int compare = 1;
			if (strlen(dictionaryKey[j]) == strlen(temp))
			{
				int z = 0;
				for (z = 0; z < strlen(temp); z++)
					if (temp[z] != dictionaryKey[j][z])
					{
						compare = 0;
						break;
					}
			}
			else {
				compare = 0;
			}
			if (compare == 1) {
				dictionaryValue[j] ++;
				have = 1;
				break;
			}
		}
		if (have == 0)
		{
			for (j = 0; j < strlen(temp); j++)
				dictionaryKey[count][j] = temp[j];
			dictionaryKeyLength[count] = strlen(temp);
			dictionaryValue[count] ++;
			count++;
		}
	}
	for (i = 0; i < count; i++) {
		for (j = 0; j < count - 1; j++) {
			int minStrlen = dictionaryKeyLength[j] < dictionaryKeyLength[j + 1] ? dictionaryKeyLength[j] : dictionaryKeyLength[j + 1];
			int maxStrlen = dictionaryKeyLength[j] >= dictionaryKeyLength[j + 1] ? dictionaryKeyLength[j] : dictionaryKeyLength[j + 1];
			int z = 0;
			for (z = 0; z < minStrlen; z++) {
				if (dictionaryKey[j][z] - 65 > dictionaryKey[j + 1][z] - 65 || dictionaryKeyLength[j + 1] < z)
				{
					//					printf("%c %c\n", dictionaryKey[j][z], dictionaryKey[j + 1][z]);
					char aset[75] = { '\n' };
					int l = 0;
					for (l = 0; l < maxStrlen; l++)
						aset[l] = dictionaryKey[j][l];
					for (l = 0; l < maxStrlen; l++)
						dictionaryKey[j][l] = dictionaryKey[j + 1][l];
					for (l = 0; l < maxStrlen; l++)
						dictionaryKey[j + 1][l] = aset[l];
					int tempInt = dictionaryValue[j];
					dictionaryValue[j] = dictionaryValue[j + 1];
					dictionaryValue[j + 1] = tempInt;
					int tempInt2 = dictionaryKeyLength[j];
					dictionaryKeyLength[j] = dictionaryKeyLength[j + 1];
					dictionaryKeyLength[j + 1] = tempInt2;
					//					int a = 0, b = 0;
					//					for(a = 0; a < count; a ++)
					//						{
					//							for(b = 0; b < dictionaryKeyLength[a]; b ++)
					//							printf("%c", dictionaryKey[a][b]);
					//							printf("\n");
					//						}
					break;
				}
				else if (dictionaryKey[j][z] - 65 < dictionaryKey[j + 1][z] - 65)
					break;
			}
		}
	}
	for (i = 0; i < count; i++) {
		for (j = 0; j < dictionaryKeyLength[i]; j++)
			printf("%c", dictionaryKey[i][j]);
		printf(" %d", dictionaryValue[i]);
		if (i != count - 1)
			printf("\n");
	}
	return 0;
}