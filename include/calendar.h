/*
** EPITECH PROJECT, 2022
** SYN calendar
** File description:
** calendar.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct employee
{
	char *id;
	char *last_name;
	char *first_name;
	char *zipcode;
    char *city;
    struct employee *next;
} employee_t;

typedef struct meeting
{
    char *first_name;
    char *last_name;
    char *city;
	char *id;
    int salary;
	char *day;
	char *zipcode;
    struct meeting *next;
} meeting_t;