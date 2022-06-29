/*
** EPITECH PROJECT, 2022
** SYN calendar
** File description:
** main
*/

#include "../include/calendar.h"

bool is_prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

int display(employee_t *list_employees)
{
	printf("%s\n", "******************************");
	printf("%s\n", list_employees->first_name);
	printf("%s\n", list_employees->last_name);
	printf("position: %s\n", list_employees->city);
	printf("city: %s\n", list_employees->zipcode);
	return (0);
}

int add_employee(employee_t **list_employees, char *id, char *last_name, char *first_name, char *zipcode, char *city)
{
    employee_t *employee = malloc(sizeof(employee_t));
    employee_t *tmp = *list_employees;
    employee_t *tmp2 = *list_employees;

    if (employee == NULL)
        return (4);
    employee->id = id;
    employee->last_name = last_name;
    employee->first_name = first_name;
    employee->zipcode = zipcode;
    employee->city = city;
    employee->next = NULL;

    if (*list_employees == NULL)
        *list_employees = employee;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = employee;
    }
    return (0);
}

int search_employee(employee_t *list_employees, char *id, char *last_name, char *first_name, char *zipcode, char *city)
{
    employee_t *tmp = list_employees;
    employee_t *tmp2 = list_employees;
    int i = 0;
    
    while (tmp != NULL) {
        if (is_prefix(id, tmp->id)) {
            display(tmp);
            i++;
        }
        tmp = tmp->next;
    }
    if (i == 0)
        printf("%s\n", "No employee found");
    return (0);
}

int search_meeting(meeting_t *list_meetings, char *id, char *last_name, char *first_name, char *zipcode, char *city)
{
    meeting_t *tmp = list_meetings;
    meeting_t *tmp2 = list_meetings;
    int i = 0;
    
    while (tmp != NULL) {
        if (is_prefix(id, tmp->id)) {
            printf("%s\n", "******************************");
            printf("%s\n", tmp->first_name);
            printf("%s\n", tmp->last_name);
            printf("position: %s\n", tmp->city);
            printf("city: %s\n", tmp->zipcode);
            i++;
        }
        tmp = tmp->next;
    }
    if (i == 0)
        printf("%s\n", "No meeting found");
    return (0);
}

int add_meeting(meeting_t **list_meetings, char *first_name, char *last_name, char *city, char *id, char *zipcode)
{
    meeting_t *meeting = malloc(sizeof(meeting_t));
    meeting_t *tmp = *list_meetings;
    meeting_t *tmp2 = *list_meetings;
    
    if (meeting == NULL)
        return (5);
    meeting->first_name = first_name;
    meeting->last_name = last_name;
    meeting->city = city;
    meeting->id = id;
    meeting->zipcode = zipcode;
    meeting->next = NULL;

    if (*list_meetings == NULL)
        *list_meetings = meeting;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = meeting;
    }
    return (0);
}

int main(int ac, char **av)
{
    employee_t *list_employees = NULL;
    meeting_t *list_meetings = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    while (av[i] != NULL) {
        if (is_prefix("employee", av[i])) {
            if (ac != 7)
                return (9);
            add_employee(&list_employees, av[i + 1], av[i + 2], av[i + 3], av[i + 4], av[i + 5]);
        }
        if (is_prefix("meeting", av[i])) {
            if (ac != 7)
                return (10);
            search_meeting(list_meetings, av[i + 1], av[i + 2], av[i + 3], av[i + 4], av[i + 5]);
        }
        i++;
    }
    return (0);
}