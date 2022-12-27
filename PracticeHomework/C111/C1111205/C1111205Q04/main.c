#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include<string.h>
void recordCountry(char* Word, char* Country, int* Count, int* CountryCount, int* StopCount);
int repeatCountry(char* NewWord, char* originalCountry, int* Countrynumber, int* k);
int main()
{
    int number, InputCount = 0, StopCount, CountryCount = 0, InputCountryCount[100] = { 0 };
    char input, InputWord[75] = { '\0' }, NewInputWord[20] = { '\0' }, InputCountry[100][20] = { '\0' };
    scanf("%d", &number);
    scanf("\n");
    for (int i = 1; i <= number; i = i + 1) {
        while (1) {
            input = getchar();
            if (input != '\n') {
                InputWord[InputCount] = input;
                InputCount = InputCount + 1;
            }
            if (input == '\n') {
                InputCount = 0;
                break;
            }
        }
        for (int j = 1; j <= 20; j = j + 1) {
            if (InputWord[j - 1] != ' ') {
                NewInputWord[j - 1] = InputWord[j - 1];
            }
            if (InputWord[j - 1] == ' ') {
                StopCount = j - 1;
                break;
            }
        }
        for (int j = 1; j <= 75; j = j + 1) {
            InputWord[j - 1] = 0;
        }
        int c = 1;
        for (int k = 1; k <= CountryCount; k = k + 1) {
            c = repeatCountry(NewInputWord, InputCountry[k - 1], &InputCountryCount, &k);
            if (c == 0) {
                break;
            }
        }
        if (c == 1 && CountryCount != 0) {
            recordCountry(NewInputWord, InputCountry[CountryCount], &CountryCount, InputCountryCount, &StopCount);
        }
        if (c == 1 && CountryCount == 0) {
            recordCountry(NewInputWord, InputCountry[CountryCount], &CountryCount, InputCountryCount, &StopCount);
        }
        for (int j = 1; j <= 20; j = j + 1) {
            NewInputWord[j - 1] = 0;
        }
    }
    for (int i = 1; i <= CountryCount; i = i + 1) {
        for (int j = 1; j <= CountryCount; j = j + 1) {
            if (InputCountryCount[j - 1] < InputCountryCount[j]) {
                int t;
                t = InputCountryCount[j - 1];
                InputCountryCount[j - 1] = InputCountryCount[j];
                InputCountryCount[j] = t;
                for (int k = 1; k <= 20; k = k + 1) {
                    if (InputCountry[j - 1][k - 1] != '\0' || InputCountry[j][k - 1] != '\0') {
                        char a = InputCountry[j - 1][k - 1];
                        InputCountry[j - 1][k - 1] = InputCountry[j][k - 1];
                        InputCountry[j][k - 1] = a;
                    }
                }
            }
            if (InputCountryCount[j - 1] == InputCountryCount[j]) {
                if (InputCountry[j - 1][0] > InputCountry[j][0]) {
                    for (int k = 1; k <= 20; k = k + 1) {
                        if (InputCountry[j - 1][k - 1] != '\0' || InputCountry[j][k - 1] != '\0') {
                            char a = InputCountry[j - 1][k - 1];
                            InputCountry[j - 1][k - 1] = InputCountry[j][k - 1];
                            InputCountry[j][k - 1] = a;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= CountryCount; i = i + 1) {
        printf("%s %d\n", InputCountry[i - 1], InputCountryCount[i - 1]);
    }
    return 0;
}
void recordCountry(char* Word, char* Country, int* Count, int* CountryCount, int* StopCount) {
    char C;
    int a = *Count;
    for (int i = 1; i <= *StopCount; i = i + 1) {
        Country[i - 1] = Word[i - 1];
    }
    CountryCount[a] = CountryCount[a] + 1;
    //printf("CountryCount[a]:%d\n", CountryCount[a]);
    //printf("Country:%s\n", Country);
    *Count = *Count + 1;

}
int repeatCountry(char* NewWord, char* originalCountry, int* Countrynumber, int* k) {
    int sum;
    int a = *k - 1;
    sum = strcmp(NewWord, originalCountry);
    if (sum == 0) {
        Countrynumber[a] = Countrynumber[a] + 1;
        return 0;
    }
    if (sum != 0) {
        return 1;
    }
}