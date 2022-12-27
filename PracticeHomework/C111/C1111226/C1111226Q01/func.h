#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure represents the value of each point
struct point
{
    // Axis values of x and y
    float x, y;

    // Pointer to next point
    struct point* next;
};

/// <summary>
/// Convert the given point list into a linked list using 'point' structure.
/// </summary>
/// <param name="size">The size of list.</param>
/// <param name="data">The point list.</param>
/// <returns>The first node of the created linked list.</returns>
struct point* convert(int size, float data[][2])
{
    struct point* first = malloc(sizeof(struct point));
    first->x = data[0][0];
    first->y = data[0][1];
    first->next = NULL;
    struct point* head = first;
    for (int i = 1; i < size; i++)
    {
        struct point* next = malloc(sizeof(struct point));
        next->x = data[i][0];
        next->y = data[i][1];
        next->next = NULL;
        first->next = next;
        first = next;
    }
    return head;
}
// Comparison function for qsort
int compare(const void* a, const void* b)
{
    struct point* pa = (struct point*)a;
    struct point* pb = (struct point*)b;

    // x 小到大排序
    if (pa->x != pb->x)
    {
        return pa->x - pb->x;
    }
    else
    {
        return pa->y - pb->y;
    }

    // x 大到小排序
    //if (pa->x != pb->x)
    //{
    //    return pb->x - pa->x;
    //}
    //else
    //{
    //    return pb->y - pa->y;
    //}

    //y 大到小排序
    //if (pa->x != pb->x)
    //{
    //    return pb->y - pa->y; 
    //}
    //else
    //{
    //    return pb->x - pa->x;
    //}

    //y 小到大排序
    //if (pa->x != pb->x)
    //{
    //    return pa->y - pb->y;
    //}
    //else
    //{
    //    return pa->x - pb->x;
    //}
}

/// <summary>
/// Sort points in ascending order prioritizing on the x value.
/// </summary>
/// <param name="size">The first node of the linked list.</param>
/// <returns>The first node of the sorted linked list.</returns>
struct point* sort(struct point* list)
{
    int size = 0;
    struct point* current = list;
    while (current)
    {
        size++;
        current = current->next;
    }

    struct point* array = malloc(size * sizeof(struct point));

    current = list;
    for (int i = 0; i < size; i++)
    {
        array[i] = *current;
        current = current->next;
    }

    qsort(array, size, sizeof(struct point), compare);

    struct point* head = NULL;
    current = NULL;
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = &array[i];
            current = head;
        }
        else
        {
            current->next = &array[i];
            current = current->next;
        }
    }
    current->next = NULL;

    return head;
}