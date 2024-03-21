#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//#include "io.c"
#define STR_SIZE 24

typedef struct StudentStatistics {
    char name[50];
    double score;
} StudentStatistics;

double avg_mark(Student *s){
    return (s->dm + s->ma + s->la + s->cs + s->hi) / 5.0;
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
    if (argc != 3) {
        printf("Usage:\n\t./execute DB_FILE p\n");
        exit(0);
    }
    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    double avg = 0.0;
    int students_qty = 0;

    StudentStatistics students[100];

    Student student;
    while (student_read_bin(&student, in)) {
        avg = avg_mark(&student);
        strcpy(students[students_qty].name, student.surname);
        students[students_qty].score = avg;
        students_qty++;
    }
    qsort(students, students_qty, sizeof(struct StudentStatistics), compare);

    int p = atoi(argv[2]);

    printf("Top %d students:\n", p);

    for (int i = 0; i < p && i < students_qty ; i++) {
        printf("%s %f\n", students[i].name, students[i].score);
    }

    fclose(in);
    return 0;
}
