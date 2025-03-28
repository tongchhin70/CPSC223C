#ifndef STUDENT_H
#define STUDENT_H

enum class_standing {Freshman, Sophomore, Junior, Senior};

#define MAX_NAME_LEN 50
#define MAX_MAJOR_LEN 30
#define MAX_CLASSES 10
#define MAX_COURSE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    unsigned int cwid;
    char major[MAX_MAJOR_LEN];
    enum class_standing standing;
    unsigned int number_classes_enrolled;
    char class_schedule[MAX_CLASSES][MAX_COURSE_LEN];
    unsigned long int phone;
    float parking_fee;
} Student;

#endif
