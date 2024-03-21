#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//#include "io.c"
#define STR_SIZE 24

typedef struct StudentStatistics {
    char name[50];
    int score;
    char gender;
} StudentStatistics;

double sum_mark(Student *s){
    return (s->dm + s->ma + s->la + s->cs + s->hi);
}

int compare(const void *a, const void *b) {
    const StudentStatistics *studentA = (const StudentStatistics *)a;
    const StudentStatistics *studentB = (const StudentStatistics *)b;

    if (studentA->score > studentB->score) {
        return -1;  // для убывающего порядка
    } else if (studentA->score < studentB->score) {
        return 1;
    } else {
        return 0;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }
    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    int sum = 0;
    int i = 0;

    StudentStatistics students[100];

    Student student;
    while (student_read_bin(&student, in)) {
        if (sum_mark(&student) > sum){
            sum = sum_mark(&student);
        }
        strcpy(students[i].name, student.surname);
        if (student.cs > 3 && student.dm > 3 && student.hi > 3 && student.la > 3 && student.ma > 3){
            students[i].gender = student.gender;
        }
        else{
            students[i].gender = 'N';
        }
        students[i].score = sum;
        i++;
    }
    qsort(students, i, sizeof(struct StudentStatistics), compare);

    for (int j = 0; j < i ; j++) {
        if (students[j].score == sum && students[j].gender == 'F'){
            printf("%s\n", students[j].name);
        }
    }

    fclose(in);
    return 0;
}
