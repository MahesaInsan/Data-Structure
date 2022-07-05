#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students{
    char name[20];
    int age;
    float grade;
};

void main(){
    struct students student1, student2;
    
    student1.age = 17;
    student1.grade = 9.0;
    strcpy(student1.name, "Budi");
    
    printf("Student's name: %s\n", student1.name);
    printf("Student's age: %d\n", student1.age);
    printf("Student's grade: %f\n", student1.grade);

    student2.age = 18;
    student2.grade = 9.0;

    printf("Student's age: %d\n", student2.age);
    printf("Student's grade: %f\n", student2.grade);

    struct students student3 = {
        .name = "Asep",
        .age = 18,
        .grade = 9.0
    };

    printf("Student's name: %s\n", student3.name);
    printf("Student's age: %d\n", student3.age);
    printf("Student's grade: %f\n", student3.grade);

    struct students *pointerStudent;
    pointerStudent = &student3;

    printf("Student's name: %s\n", (*pointerStudent).name);
    printf("Student's age: %d\n", pointerStudent->age);
    printf("Student's grade: %f\n", pointerStudent->grade);

}