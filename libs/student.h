#ifndef STUDENT_H
#define STUDENT_H

// Include the gender and dorm header files
#include "gender.h"
#include "dorm.h"

// membuat struct student yang terdiri dari id,name,year dan name dormitorynya
struct student_t
{
  char id[12]; // Student ID, kita di deklarasikan dengan panjang karakternya 11 
  char name[40]; // Student name, a string of up to 39 characters plus null terminator
  char year[5]; // Year of study, a string of up to 4 characters plus null terminator
  enum gender_t gender; // Student gender, an enumeration type
  struct dorm_t *dorm; // Pointer to the student's dormitory structure
};

// create a student from a string input
struct student_t create_student(char *input);

// print basic student information
void print_student(struct student_t mhs);

// print detailed student information
void print_student_detail(struct student_t mhs);

// assign a student to a dormitory
void assign_student(struct dorm_t *drm, struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim, int zstd, struct student_t *mhs), int find_dorm(char *asrama, int zdrm, struct dorm_t *drm));

// cari nilai student by their ID in an array of students
int find_id(char *nim, int zstd, struct student_t *mhs);

// gunakan fungsi move a student from one dormitory to another
void move_student(struct dorm_t *drm, struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim, int zstd, struct student_t *mhs), int find_dorm(char *asrama, int zdrm, struct dorm_t *drm));

// menggunakan empty a dormitory of all students
void dorm_empty(char *asrama, int zstd, int zdrm, struct student_t *mhs, struct dorm_t *drm, int find_dorm(char *asrama, int zdrm, struct dorm_t *drm));

#endif