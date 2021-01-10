/*
 ============================================================================
 Name        : HW7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include "liblinked-list.so"
#include "grades.h"
#include "linked-list.h"


struct grades{
	char *course;
	int grade;
	struct grades *next;
};

/* Defined elsewhere */
struct node{
	char *name;
	int id, avg;
	struct grades *grade;
	struct node *next;
};

//typedef struct node grades;
typedef struct node node;
typedef struct grades grades;



/* User function, clone “element” to “output”. Returns 0 on success */
typedef int(*node_clone)(void *element, void **output);
typedef void(*element_destroy_t)(void *element);



int *elemet_clone_t(void *element, void **output){
	node *arg = (node*)element;
	node *out = (node*)output;
	out->name = (char*)malloc(sizeof(char)*(strlen(arg->name)+1));
	out->grade = (grades*)malloc(sizeof(grades));
	out->next =  (node*)malloc(sizeof(node));

	strcpy(arg->name,out->name);
	out->id = arg->id;
	out->next = arg->next;


	strcpy(arg->grade-course,out->course);
	out->grade = arg->grade;

	out->

};

struct list{
	node* head,tail;
	element_clone_t elem_clone;
	element_destroy_t list_destroy;
};




/**
 * @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */


struct grades* grades_init(){
	struct list* grades_init = list_init(elem_clone, elem_destroy);
	return (!grades_init)? NULL : grades_init ;
};

/**
 * @brief Destroys "grades", de-allocate all memory!
 */
void grades_destroy(struct grades *grades){

};

/**
 * @brief Adds a student with "name" and "id" to "grades"
 * @returns 0 on success
 * @note Failes if "grades" is invalid, or a student with
 * the same "id" already exists in "grades"
 */
int grades_add_student(struct grades *grades, const char *name, int id);

/**
 * @brief Adds a course with "name" and "grade" to the student with "id"
 * @return 0 on success
 * @note Failes if "grades" is invalid, if a student with "id" does not exist
 * in "grades", if the student already has a course with "name", or if "grade"
 * is not between 0 to 100.
 */
int grades_add_grade(struct grades *grades,
                     const char *name,
                     int id,
                     int grade);

/**
 * @brief Calcs the average of the student with "id" in "grades".
 * @param[out] out This method sets the variable pointed by "out" to the
 * student's name. Needs to allocate memory. The user is responsible for
 * freeing the memory.
 * @returns The average, or -1 on error
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note If the student has no courses, the average is 0.
 * @note On error, sets "out" to NULL.
 */
float grades_calc_avg(struct grades *grades, int id, char **out);

/**
 * @brief Prints the courses of the student with "id" in the following format:
 * STUDENT-NAME STUDENT-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note The courses should be printed according to the order
 * in which they were inserted into "grades"
 */
int grades_print_student(struct grades *grades, int id);

/**
 * @brief Prints all students in "grade", in the following format:
 * STUDENT-1-NAME STUDENT-1-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * STUDENT-2-NAME STUDENT-2-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid
 * @note The students should be printed according to the order
 * in which they were inserted into "grades"
 * @note The courses should be printed according to the order
 * in which they were inserted into "grades"
 */
int grades_print_all(struct grades *grades);

