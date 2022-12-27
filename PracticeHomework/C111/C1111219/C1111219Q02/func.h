#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The string length of name
#define LEN_NAME 50

// A structure represents the information of each student
struct student
{
    // The name string
    // Parameter: name (string)
    char name[LEN_NAME];

    // The score of English
    // Parameter: english (integer)
    int english;

    // The score of Math
    // Parameter: math (integer)
    int math;

    // Pointer to next student
    // Parameter: next (pointer)
    struct student* next;
};

/// <summary>
/// Convert the given 2 arrays into a linked list using 'student' structure.
/// </summary>
/// <param name="names">The name list.</param>
/// <param name="scores">The score list</param>
/// <returns>The first node of the created linked list.</returns>
struct student* convert(char names[][50], int scores[][2])
{
    struct student* first = malloc(sizeof(struct student));
    strcpy(first->name, names[0]);
    first->english = scores[0][0];
    first->math = scores[0][1];
    first->next = NULL;
    struct student* head = first;
    for (int i = 1; names[i][0] != '\0'; i++)
    {
        struct student* next = malloc(sizeof(struct student));
        strcpy(next->name, names[i]);
        next->english = scores[i][0];
        next->math = scores[i][1];
        next->next = NULL;
        first->next = next;
        first = next;
    }
    return head;
}