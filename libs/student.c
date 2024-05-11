#include "student.h"
#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// create a new student
struct student_t create_student(char *input)
{
  // deklarasikan a new student structure
  struct student_t mhs;

  // Parse the input string to get the student's id, name, year, and gender
  strcpy(mhs.id, strtok(NULL, "#"));
  strcpy(mhs.name, strtok(NULL, "#"));
  strcpy(mhs.year, strtok(NULL, "#"));
  char *yoru = strtok(NULL, "#");

  // Set the gender of the student based on the parsed input
  if (strcmp(yoru, "male") == 0)
  {
    mhs.gender = GENDER_MALE;
  }
  else if (strcmp(yoru, "female") == 0)
  {
    mhs.gender = GENDER_FEMALE;
  }

  // Inisialisasi dormitory of the student dengan nilai unassigned
  // gunakan fungsi malloc
  mhs.dorm = NULL;
  mhs.dorm = malloc(1 * sizeof(struct dorm_t));
  strcpy(mhs.dorm->name, "unassigned");

  // return created student
  return mhs;
}

// mencetak informasi of a student
void print_student(struct student_t mhs)
{
  // Print the id, name, and year of the student
  printf("%s|%s|%s|", mhs.id, mhs.name, mhs.year);

  // Print the gender of the student
  if (mhs.gender == GENDER_MALE)
  {
    printf("male\n");
  }
  else if (mhs.gender == GENDER_FEMALE)
  {
    printf("female\n");
  }
}

// cetak detailed information of a student
void print_student_detail(struct student_t mhs)
{
  // Print the id, name, year, and gender of the student
  printf("%s|%s|%s|", mhs.id, mhs.name, mhs.year);
  if (mhs.gender == GENDER_MALE)
  {
    printf("male|");
  }
  else if (mhs.gender == GENDER_FEMALE)
  {
    printf("female|");
  }

  // Print the name of the dormitory of the student
  printf("%s\n", mhs.dorm->name);
}

// Function to find a student by its id in an array of students
int find_id(char *nim, int zstd, struct student_t *mhs)
{
  // Initialize the index to -1 (not found)
  int find_id = -1;

  // Loop through the array of students
  for (int m = 0; m < zstd; m++)
  {
    // If the id of the current student matches the input id, update the index
    if (strcmp(nim, mhs[m].id) == 0)
    {
      find_id = m;
    }
  }

  // tentukan index dari student, or -1 if not found 
  return find_id;
}

// assign a student to a dormitory
void assign_student(struct dorm_t *drm, struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim, int zstd, struct student_t *mhs), int find_dorm(char *asrama, int zdrm, struct dorm_t *drm))
{
  // mencari nilai index student and the dormitory
  int maha = find_id(nim, zstd, mhs);
  int asra = find_dorm(asrama, zdrm, drm);

  // If the student and the dormitory are found, the dormitory is not full, and the genders match, assign the student to the dormitory
  if (maha >= 0 && asra >= 0 && drm[asra].capacity != drm[asra].residents_num && mhs[maha].gender == drm[asra].gender)
  {
    strcpy(mhs[maha].dorm->name, asrama);
    drm[asra].residents_num++;
  }
}

// move a student from one dormitory to another
void move_student(struct dorm_t *drm, struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim, int zstd, struct student_t *mhs), int find_dorm(char *asrama, int zdrm, struct dorm_t *drm))
{
  // mencari index of the student
  int maha = find_id(nim, zstd, mhs);

  // Store the name of the current dormitory of the student
  char before[20];
  strcpy(before, mhs[maha].dorm->name);

  // Find the index of the current and the new dormitory
  int asrabefore = find_dorm(before, zdrm, drm);
  int asraafter = find_dorm(asrama, zdrm, drm);

  // If the student and the dormitories are found, the new dormitory is not full, and the genders match, move the student to the new dormitory
  if (maha >= 0 && asrabefore >= 0 && asraafter >= 0 && drm[asraafter].capacity != drm[asraafter].residents_num && mhs[maha].gender == drm[asraafter].gender)
  {
    drm[asrabefore].residents_num--;
    strcpy(mhs[maha].dorm->name, asrama);
    drm[asraafter].residents_num++;
  }
  else if (maha >= 0 && asrabefore == -1 && asraafter >= 0 && drm[asraafter].capacity != drm[asraafter].residents_num && mhs[maha].gender == drm[asraafter].gender)
  {
    strcpy(mhs[maha].dorm->name, asrama);
    drm[asraafter].residents_num++;
  }
}

// mengggunakan fungsi to empty a dormitory
void dorm_empty(char *asrama, int zstd, int zdrm, struct student_t *mhs, struct dorm_t *drm, int find_dorm(char *asrama, int zdrm, struct dorm_t *drm))
{
  // cari index of the dormitory
  int asra = find_dorm(asrama, zdrm, drm);

  // menggunakan looping for untuk array students
  for (int m = 0; m < zstd; m++)
  {
    // If the student is in the dormitory, unassign the student from the dormitory
    if (strcmp(asrama, mhs[m].dorm->name) == 0)
    {
      strcpy(mhs[m].dorm->name, "unassigned");
      drm[asra].residents_num--;
    }
  }
}