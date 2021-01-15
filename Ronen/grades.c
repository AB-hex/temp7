#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include "stddef.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"
#include "grades.h"



typedef struct grades my_grades;
typedef struct current_student current_student;
typedef struct current_course current_course;


struct grades{
	struct list *list_of_students;
	element_clone_t new_students;
	element_clone_t new_courses;
	element_destroy_t destroy_students;
	element_destroy_t destroy_courses;

};

struct current_student{
	int id, avg;
	char* name_of_student;
	struct list *new_course;

};

struct current_course{
	int grade;
	char* name_of_course;

};







 int new_element_student(void *element, void **output){
	 current_student *get_elem = (current_student*)element;
	 current_student *out_put = (current_student*)malloc(sizeof(current_student)); 
	 if(!out_put){
	 	return -1;
	 }

	 *output = out_put;

	out_put->name_of_student = (char*)malloc(strlen(get_elem->name_of_student)+1); // +1 for \n
	if(out_put->name_of_student == NULL){return -1;}
	else{
		strcpy(out_put->name_of_student, get_elem->name_of_student);
	}

	out_put->id = get_elem->id;

	return 0;

}
int new_element_course(void *element, void **output){
	current_course *get_elem = (current_course*)element;
	current_course *out_put = (current_course*)malloc(sizeof(current_course));
	if(!out_put){
		return -1;
	}

	*output = out_put;
	out_put->name_of_course = (char*)malloc(strlen(get_elem->name_of_course)+1); // +1 for \n
	if(out_put->name_of_course == NULL){return -1;}
	else{
		strcpy(out_put->name_of_course, get_elem->name_of_course);
	}
	out_put->grade = get_elem->grade;
	return 0;

}


void destroy_element_student(void *element){
	 current_student *get_elem = (current_student*)element;
	 free(get_elem->name_of_student);

 }

void destroy_element_course(void *element){
	 current_course *get_elem = (current_course*)element;
 	 free(get_elem->name_of_course);

  }


/* @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */


struct grades* grades_init(){
	struct grades* grades =(struct grades*)malloc(sizeof(struct grades));
	if(grades==NULL) return NULL;
	else{
		grades->list_of_students = list_init(new_element_student,destroy_element_student);
		return grades;
	}
}




void grades_destroy(struct grades *grades){

	struct node* it= list_begin(grades->list_of_students);
	current_student *student;
	while(!it){
	student = (current_student*)list_get(it);
	list_destroy(student->new_course);
	it = list_next(it);
	}
	list_destroy(grades->list_of_students);

}

/**
 * @brief Adds a student with "name" and "id" to "grades"
 * @returns 0 on success
 * @note Failes if "grades" is invalid, or a student with
 * the same "id" already exists in "grades"
 */
/**int grades_add_student(struct grades *grades, const char *name, int id){




}*/


/**
 * @brief Adds a student with "name" and "id" to "grades"
 * @returns 0 on success
 * @note Failes if "grades" is invalid, or a student with
 * the same "id" already exists in "grades"
 */
int grades_add_student(struct grades *grades, const char *name, int id){

	if (!grades){return 1;}
	int my_size = list_size(grades->list_of_students);
	struct node *my_iterator=list_begin(grades->list_of_students);
	if(my_size !=0){
		while(my_iterator!=NULL){
			current_student *last_student=(current_student*)list_get(my_iterator);
			if(last_student == NULL) return-1;
			if(last_student->id == id){
				return 1;
			}
			else{
				my_iterator = list_next(my_iterator);
			}
		}
	}

	struct node *my_last_iterator=list_end(grades->list_of_students);
	if((my_last_iterator == NULL) && (my_size !=0)){return -1;}

		current_student *first_stud = (current_student*)malloc(sizeof(current_student));
		if(first_stud == NULL) return -1;
		
		first_stud->name_of_student = (char*)malloc(strlen(name)+1);
		if(first_stud->name_of_student == NULL){
			free(first_stud);
			return -1;
		}

		strcpy(first_stud->name_of_student, name);
		first_stud->id = id;
		first_stud->avg=0;
		first_stud->new_course=list_init(new_element_course,destroy_element_course);
		int first_succes = list_push_back(grades->list_of_students, first_stud);
		if(first_succes == 0) return 0;
		else {
			return -1;
		}
}
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
                     int grade){

	struct node *my_iterator=list_begin(grades->list_of_students);
	if(my_iterator == NULL){return 1;}
	if(grade > 100 || grade < 0 || !grades) {return 1;}
	while(my_iterator){
		current_student *last_student=(current_student*)list_get(my_iterator);
		if(last_student->id == id){
			struct node *course_itertor = list_begin(last_student->new_course);
			while(course_itertor){
				current_course *course =(current_course*)list_get(my_iterator);
				if(course->name_of_course == name){
				return 1;
				}
				course_itertor = list_next(course_itertor);
			}
			struct node *it_for_last_course =list_end(last_student->new_course);
			struct current_course *last_course = (current_course*)list_get(it_for_last_course);
			int success = list_insert(last_student->new_course,it_for_last_course,last_course);
			if(success == 0){
			last_course->grade = grade;
			strcpy(last_course->name_of_course,name);
			last_student->avg += grade;
			return 0;
			}
			else{
				return 1;
			}
		}
		else{
			my_iterator = list_next(my_iterator);
		}
	}
	return 1;

}








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
float grades_calc_avg(struct grades *grades, int id, char **out){
	float size;
	if (!grades){return 1;}
	struct node *my_iterator=list_begin(grades->list_of_students);
	current_student *correct_student=(current_student*)list_get(my_iterator);
	out = (char**)malloc(sizeof(correct_student));
	if(out == NULL){return -1;}
	*out =strcpy((char*)out,correct_student->name_of_student);
	if(my_iterator == NULL){return -1;}
	while(my_iterator){
		current_student *correct_student=(current_student*)list_get(my_iterator);
		if(correct_student == NULL){return -1;}
		if(correct_student->id == id){
			size =list_size(correct_student->new_course);
			if(size == 0){
				return 0;
			}
			else{
				return ((correct_student->avg)/size);
			}
		}
		else{
			my_iterator = list_next(my_iterator);
		}
	}
	return -1;

}

/**
 * @brief Prints the courses of the student with "id" in the following format:
 * STUDENT-NAME STUDENT-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note The courses should be printed according to the order
 * in which they were inserted into "grades"
 */
int grades_print_student(struct grades *grades, int id){
	struct node *my_iterator=list_begin(grades->list_of_students);
		if(my_iterator == NULL){return 1;}
		while(my_iterator){
			current_student *student=(current_student*)list_get(my_iterator);
			if(student == NULL) return -1;
			if(student->id == id){
				printf("STUDENT-%s STUDENT-%d: ",student->name_of_student, student->id);
				struct node *course_itertor = list_begin(student->new_course);
				while(course_itertor){
				current_course *course =(current_course*)list_get(my_iterator);
				printf("COURSE-1-%s COURSE-1-%d, ", course->name_of_course,course->grade);
					course_itertor = list_next(course_itertor);
				}
				return 0;
			}
			my_iterator = list_next(my_iterator);
		}
		return -1;
}






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
int grades_print_all(struct grades *grades){
	if (!grades){return 1;}
	struct node *my_iterator=list_begin(grades->list_of_students);
	if (my_iterator == NULL) return 1;
	int counter = 1;
		if(my_iterator == NULL){return 1;}
		while(my_iterator){
			current_student *student=(current_student*)list_get(my_iterator);
			printf("STUDENT-%d-%s STUDENT-%d-%d: ",counter,student->name_of_student, counter,student->id);
			struct node *course_itertor = list_begin(student->new_course);
			if(course_itertor == NULL){return 1;}
			while(course_itertor){
		    current_course *course =(current_course*)list_get(my_iterator);
			printf("COURSE-1-%s COURSE-1-%d, ", course->name_of_course,course->grade);
		    course_itertor = list_next(course_itertor);
			}
			my_iterator = list_next(my_iterator);
		}
		return 0;

}











