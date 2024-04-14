#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _STUDENT_H_
#define _STUDENT_H_

#define STR_SIZE 24

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    char gender;
    int  group;
    int  dm, ma, la, cs, hi;
} Student;

int student_read_txt(Student *s, FILE *in) {
    fscanf(in, "%23s", s->surname); // Читаем не более 23 символов, чтобы оставить место для нулевого символа
    fscanf(in, "%23s", s->initials); // Читаем не более 23 символов, чтобы оставить место для нулевого символа
    fscanf(in, " %c", &(s->gender));
    fscanf(in, "%d", &(s->group));
    fscanf(in, "%d", &(s->dm));
    fscanf(in, "%d", &(s->ma));
    fscanf(in, "%d", &(s->la));
    fscanf(in, "%d", &(s->cs));
    fscanf(in, "%d", &(s->hi));

    s->surname[STR_SIZE - 1] = '\0'; // Гарантированно завершаем строку фамилии нулевым символом
    s->initials[STR_SIZE - 1] = '\0'; // Гарантированно завершаем строку инициалов нулевым символом

    return !feof(in);
}


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

void student_write_bin(Student *s, FILE *out)
{
    size_t surname_len = strlen(s->surname) + 1; // Длина строки фамилии, включая нулевой символ
    size_t initials_len = strlen(s->initials) + 1; // Длина строки инициалов, включая нулевой символ

    fwrite(s->surname,  sizeof(char), surname_len, out);
    fwrite(s->initials, sizeof(char), initials_len, out);
    fwrite(&(s->gender), sizeof(char), 1, out);
    fwrite(&(s->group), sizeof(int), 1, out);
    fwrite(&(s->dm), sizeof(int), 1, out);
    fwrite(&(s->ma), sizeof(int), 1, out);
    fwrite(&(s->la), sizeof(int), 1, out);
    fwrite(&(s->cs), sizeof(int), 1, out);
    fwrite(&(s->hi), sizeof(int), 1, out);
}

void student_print(Student *s)
{
    s->surname[STR_SIZE - 1] = '\0'; // Гарантированно завершаем строку фамилии нулевым символом
    s->initials[STR_SIZE - 1] = '\0'; // Гарантированно завершаем строку инициалов нулевым символом

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
#endif

