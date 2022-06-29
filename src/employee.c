/*
** EPITECH PROJECT, 2022
** SYN calendar
** File description:
** employee.c
*/

#include "../include/calendar.h"

employee_t *emps(char *id, char *last_name, char *first_name, char *zipcode, char *city)
{
    employee_t *employee = malloc(sizeof(employee_t));

    employee->id = id;
    employee->last_name = last_name;
    employee->first_name = first_name;
    employee->zipcode = zipcode;
    employee->city = city;
    return (employee);
}

meeting_t *meets(char *first_name, char *lastname, int day, int salary)
{
    meeting_t *meeting = malloc(sizeof(meeting_t));

    if (meeting == NULL)
        return (NULL);
    return (meeting);
}
