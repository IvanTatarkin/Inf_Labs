#include <stdio.h>
#include <stdlib.h>


#define STR_SIZE 24

typedef struct Student_d{
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    char gender;
    int  group;
    int  dm, ma, la, cs, hi;
} Student;

void student_write_bin(Student *s, FILE *out)
{
    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
    fwrite(&(s->gender), sizeof(char), 1, out);
    fwrite(&(s->group), sizeof(int), 1, out);
    fwrite(&(s->dm), sizeof(int), 1, out);
    fwrite(&(s->ma), sizeof(int), 1, out);
    fwrite(&(s->la), sizeof(int), 1, out);
    fwrite(&(s->cs), sizeof(int), 1, out);
    fwrite(&(s->hi), sizeof(int), 1, out);
}

int student_read_txt(Student *s, FILE *in)
{
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", s->initials);
    fscanf(in, " %c", &(s->gender));
    fscanf(in, "%d", &(s->group));
    fscanf(in, "%d", &(s->dm));
    fscanf(in, "%d", &(s->ma));
    fscanf(in, "%d", &(s->la));
    fscanf(in, "%d", &(s->cs));
    fscanf(in, "%d", &(s->hi));

    return !feof(in);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage:\n\t./generate FILE_FROM FILE_TO\n");
        exit(0);
    }

    FILE *in  = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (!in || !out) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Student s;

    while (student_read_txt(&s, in)) {
        student_write_bin(&s, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}

