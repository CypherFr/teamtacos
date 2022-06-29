/*
** EPITECH PROJECT, 2022
** SYN calendar
** File description:
** requirement.c
*/

#include "requirement.h"

int my_revlist_synthesis(list_t ** begin)
{
    list_t *first = *begin;
    list_t *second = *begin;
    list_t *third = *begin;

    while (first->next != NULL) {
        second = first->next;
        first->next = second->next;
        second->next = third;
        third = second;
    }
    if (first == NULL)
        return (0);
    *begin = third;
    return (0);
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref,
int(*cmp)(void*, void*))
{
    list_t *first = begin;

    if (first == NULL)
        return (NULL);
    while (first != NULL) {
        if (cmp(first->data, data_ref) == 0)
            return (first);
        first = first->next;
    }
    return (NULL);
}
