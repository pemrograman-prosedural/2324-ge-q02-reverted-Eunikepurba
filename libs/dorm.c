#include "dorm.h" 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// menggunakan function dengan struct untuk mencreate nama asramanya
struct dorm_t create_dorm(char *input)
{
  // Mendeklarasikan struct dari asramanya
  // isi dari si struct terdiri dari dormitoryname,capacity dan gender
  struct dorm_t drm;

  // Parse the string untuk mendapatkan jenis asrama dari si student tadi
  // setelah mendapatkan dormitory name maka akan menginput string capacity dan gendernya
  // menggunakan strcpy untuk menyalin parse the string
  strcpy(drm.name, strtok(NULL, "#"));
  drm.capacity = atoi(strtok(NULL, "#"));
  char *yoru = strtok(NULL, "#");

  // menggunakan fungsi set gender dari jenis asramanya
  // menggunakan fungsi dari branching dan string compare
  if (strcmp(yoru, "male") == 0)
  {
    drm.gender = GENDER_MALE;
  }
  else if (strcmp(yoru, "female") == 0)
  {
    drm.gender = GENDER_FEMALE;
  }

  // menginisialisasi nomor resident number = 0 atau NULLL
  drm.residents_num=0;

  //mencreate dormitory
  return drm;
}

// Function to print basic information of a dormitory
void print_dorm(struct dorm_t drm)
{
  // mencetak nama si student dan capacity dari asrama tersebut
  printf("%s|%hu|", drm.name, drm.capacity);

  // Print the gender of the dormitory
  if (drm.gender == GENDER_MALE)
  {
    printf("male\n");
  }
  else if (drm.gender == GENDER_FEMALE)
  {
    printf("female\n");
  }
}

// Function to print detailed information of a dormitory
void print_dorm_detail(struct dorm_t drm)
{
  // Print the name, capacity, and gender of the dormitory
  printf("%s|%hu|", drm.name, drm.capacity);
  if (drm.gender == GENDER_MALE)
  {
    printf("male|");
  }
  else if (drm.gender == GENDER_FEMALE)
  {
    printf("female|");
  }

  // Print the number of residents in the dormitory
  printf("%hu\n", drm.residents_num);
}

// Function to find a dormitory by its name in an array of dormitories
int find_dorm(char *asrama, int zdrm, struct dorm_t *drm)
{
  // Initialize the index to -1 (not found)
  int find_dorm = -1;

  // Loop through the array of dormitories
  for (int m = 0; m < zdrm; m++)
  {
    // If the name of the current dormitory matches the input name, update the index
    if (strcmp(asrama, drm[m].name)==0)
    {
      find_dorm=m;
    }
  }

  // Return the index of the found dormitory, or -1 if not found
  return find_dorm;
}