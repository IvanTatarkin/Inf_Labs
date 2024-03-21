#include <stdio.h>
#include <stdlib.h>

//#define _STUDENT_H_

#define STR_SIZE 24

typedef struct Student_d{
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    char gender;
    int  group;
    int  dm, ma, la, cs, hi;
} Student;

int student_read_bin(Student *s, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);
    fread(&(s->gender), sizeof(char), 1, in);
    fread(&(s->group), sizeof(int), 1, in);
    fread(&(s->dm), sizeof(int), 1, in);
    fread(&(s->ma), sizeof(int), 1, in);
    fread(&(s->la), sizeof(int), 1, in);
    fread(&(s->cs), sizeof(int), 1, in);
    fread(&(s->hi), sizeof(int), 1, in);

    return !feof(in);
}

void student_print(Student *s)
{
    printf("Name: %s %s\n", s->surname, s->initials);
    printf("Gender: %c\n", s->gender);
    printf("Group: %d\n", s->group);
    printf("Discrete math: %d\n", s->dm);
    printf("Calculus: %d\n", s->ma);
    printf("Linear algebra: %d\n", s->la);
    printf("Computer science: %d\n", s->cs);
    printf("History: %d\n", s->hi);

    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    if (argc != 2) {
        printf("Usage:\n\t./print DB_FILE\n");
        exit(0);
    }
    
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    
    Student s;
    
    while (student_read_bin(&s, in)) {
        student_print(&s);
    }
    
    fclose(in);

    return 0;
}

