#ifndef DORM_H
#define DORM_H

// Include the gender.h header file which defines the gender_t enum
#include "gender.h"



// menstruct untuk memunculkan dormitorynya
struct dorm_t
{
  char name[20]; // deklarasikan name dormitory dengan panjang stringnya sebanyak 20
  unsigned short capacity; // dari asrama kita inisialisasi dengan tipe unsigned short
  enum gender_t gender; // Gender allowed in the dormitory, an enum of type gender_t
  unsigned short residents_num; // Current number of residents in the dormitory, an unsigned short integer
};

// create dormitory dengan memberikan input string create dormitory di atas
struct dorm_t create_dorm(char *input);

// mencetak informasi dari informasi jenis dormitory nya
void print_dorm(struct dorm_t drm);

// mencetak detail dari dormitory
void print_dorm_detail(struct dorm_t drm);

// Function prototype to find a dormitory by its name in an array of dormitories
int find_dorm(char *asrama, int zdrm, struct dorm_t *drm);

#endif