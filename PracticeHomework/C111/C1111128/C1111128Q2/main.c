#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main() {
    //3                     
    //Spain Donna Elvira    
    //England Jane Doe      
    //Spain Donna Anna     

    char country[2001][76];
    char name[76];
    char temp[76];
    int n,i;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", country[i]);
        gets(name);
    }

    // 排序字元->字典順序
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (strcmp(country[j], country[j + 1]) > 0) 
            {
                strcpy(temp, country[j]);
                strcpy(country[j], country[j + 1]);
                strcpy(country[j + 1], temp);
            }
        }
    }

    int flag = false;
    int count = 0;
    i = 0;
    while (i<n)
    {
        if (!flag)
        {
            printf("%s ", country[i]);
            count++;
            flag = true;
        }
        else if (flag)
        {
            //國家不一樣
            if (strcmp(country[i], country[i + 1]) == 0) 
            {
                count++;
            }
            //國家一樣
            else   
            {
                printf("%d\n", count);
                flag = false;
                count = 0;
            }
            i++;
        }
    }


    return 0;
}