/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: Alysa
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	// BuildHeap on the list
	buildHeap(A, n);
	
	int i;
	while (n > 0){
		swap(&A[n-1], &A[0]); // swap A[n-1] with A[0] (since A[0] is the smallest)
		n--; // A[n-1] now sorted in place, so decrement n
		for (i = 0; i < n; i++){ // heapify; leave newly sorted element alone
			heapify(A, i, n);
		}
	}
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	// heapify() every element from A[n/2] to A[0]
	int i;
	for (i = n/2; i >= 0; i--){
		heapify(A, i, n);
	}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	// stop recursion if i is not within range
	if (i >= n){
		return;
	}

	// get index of left child of element i
	int l = 2*(i+1) - 1;
	// get index of right child of element i
	int r = 2*(i+1);

	// stop recursion if left child is not within range (meaning the right
	// child is also not within range)
	if (l >= n){
		return;
	}

	int smaller; // index of child with smaller salary
	if (l < n && r == n){ // if only left child is within range
		smaller = l;
	}
	else if (A[l].salary < A[r].salary){
		smaller = l;
	}
	else{
		smaller = r;
	}

	if (A[i].salary > A[smaller].salary){ // check if salary at A[i] > salary at A[smaller]
		swap(&A[i], &A[smaller]); // if so, swap the two
		heapify(A, smaller, n); // recursively heapify A[smaller]
	}
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	return &A[0]; // since the given list is a min-heap, A[0] has the lowest salary
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp; 
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	int i;
	for (i = 0; i < n-1; i++){
		printf("[id=%s sal=%d], ", A[i].name, A[i].salary);
	}
	printf("[id=%s sal=%d]\n", A[n-1].name, A[n-1].salary);
}