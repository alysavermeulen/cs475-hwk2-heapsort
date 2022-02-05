/**
 * This file contains the driver function to test heapsort
 * @author Alysa
 *
 */

#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main()
{
	struct Employee employees[MAX_EMPLOYEES]; // array of employees
	int i = 0;
	char check = 'y'; // if 'y', user wants to add another employee; if 'n', they do not
	while (i < MAX_EMPLOYEES && check == 'y'){
		struct Employee e;
		printf("Name: ");
		scanf("%s", e.name);
		printf("Salary: ");
		scanf("%d", &e.salary);
		employees[i] = e;
		i++;
		if (i < MAX_EMPLOYEES){
			printf("Enter another user (y/n)? ");
			scanf(" %c", &check);
			while (check != 'y' && check != 'n'){ // while user input (for y/n) is invalid
				printf("\nPlease enter a valid input.\n");
				printf("Enter another user (y/n)? ");
				scanf(" %c", &check);
			}
		}
		printf("\n");
	}
	heapSort(employees,i);
	printList(employees,i);

	return 0;
}
