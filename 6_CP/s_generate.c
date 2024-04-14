#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STUDENTS 20

typedef struct {
    char surname[50];
    char initials[3];
    char gender;
    int group_number;
    int marks[5];
} Student;

int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char random_letter() {
    return (char)('A' + rand() % 26);
}

void write_student(FILE *file, Student *student) {
    fwrite(student->surname, sizeof(char), strlen(student->surname) + 1, file); 
    fwrite(student->initials, sizeof(char), strlen(student->initials) + 1, file);
    fwrite(&(student->gender), sizeof(char), 1, file);
    fwrite(&(student->group_number), sizeof(int), 1, file);
    fwrite(student->marks, sizeof(int), 5, file);
}


Student generate_student() {
    Student student;
    for (int i = 0; i < 6; i++) {
        student.surname[i] = random_letter();
    }
    student.surname[6] = '\0';
    student.initials[0] = random_letter();
    student.initials[1] = random_letter();
    student.initials[2] = '\0';
    student.gender = random_range(0, 1) ? 'M' : 'F';
    student.group_number = random_range(1, 3);
    for (int i = 0; i < 5; i++) {
        student.marks[i] = random_range(2, 5);
    }
    return student;
}

int main() {
    srand(time(NULL));
    FILE *out = fopen("output.bin", "wb");
    if (!out) {
        printf("Ошибка при открытии файла для записи.\n");
        return 1;
    }

    int num_students = random_range(10, 20);
    for (int i = 0; i < num_students; i++) {
        Student student = generate_student();
        write_student(out, &student);
    }

    fclose(out);
    printf("Файл успешно создан.\n");
    return 0;
}
