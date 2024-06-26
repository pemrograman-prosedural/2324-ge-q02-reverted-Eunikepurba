// 12S23021 - Eunike Purba
// 12S23041 - Lisbeth Panjaitan 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

int main(int _argc, char **_argv)
{
  // Menginisialisasi variabelnya
  char input[75];
  int zdrm = 0;
  int size = 0;
  struct dorm_t *drm = malloc(size * sizeof(struct dorm_t));
  int zstd = 0;
  int sizee = 0;
  struct student_t *mhs = malloc(sizee * sizeof(struct student_t));
  char *token;

  // Infinite loop to process input
  while (1)
  {
    // setelah menerima input maka selanjutnya akan membaca input dari si user
    fgets(input, sizeof input, stdin);

    // Menggunakan fungsi newline or carriage return from input
    // menggunakan fungsi break juga dimana jika nilai nya nanti 0 atau NULL maka akan break
    while (1)
    {
      if (input[strlen(input) - 1] == '\n' || input[strlen(input) - 1]== '\r')
      {
        input[strlen(input) - 1] = '\0';
      }
      else
      {
        break;
      }
    }

    // menggunakan fungsi strtok dengan input nya akan dipisahkan oleh delimenter('#')
    token = strtok(input, "#");

    // memproses input dari nilai token pertama
    if (strcmp(token, "---") == 0)
    {
      // If token is "---", break the loop
      break;
    }
    else if (strcmp(token, "dorm-add") == 0)
    {
      // If token is "dorm-add", add a dorm
      size++;
      drm = realloc(drm, size * sizeof(struct dorm_t));
      drm[zdrm] = create_dorm(input);
      zdrm++;
    }
    else if (strcmp(token, "dorm-print-all") == 0)
    {
      // If token is "dorm-print-all", print all dorms
      for (int m = 0; m < zdrm; m++)
      {
        print_dorm(drm[m]);
      }
    }
    else if (strcmp(token, "dorm-print-all-detail") == 0)
    {
      // If token is "dorm-print-all-detail", print all dorms in detail
      for (int m = 0; m < zdrm; m++)
      {
        print_dorm_detail(drm[m]);
      }
    }
    else if (strcmp(token, "student-add") == 0)
    {
      // If token is "student-add", add a student
      sizee++;
      mhs = realloc(mhs, sizee * sizeof(struct student_t));
      mhs[zstd] = create_student(input);
      zstd++;
    }
    else if (strcmp(token, "student-print-all") == 0)
    {
      // If token is "student-print-all", print all students
      for (int m = 0; m < zstd; m++)
      {
        print_student(mhs[m]);
      }
    }
    else if (strcmp(token, "student-print-all-detail") == 0)
    {
      // If token is "student-print-all-detail", print all students in detail
      for (int m = 0; m < zstd; m++)
      {
        print_student_detail(mhs[m]);
      }
    }
    else if (strcmp(token, "assign-student") == 0)
    {
      // If token is "assign-student", assign a student to a dorm
      char *nim = strtok(NULL, "#");
      char *asrama = strtok(NULL, "#");
      assign_student(drm, mhs, nim, asrama, zstd, zdrm, find_id, find_dorm);
    }
    else if (strcmp(token, "move-student") == 0)
    {
      // If token is "move-student", move a student to a different dorm
      char *nim = strtok(NULL, "#");
      char *asrama = strtok(NULL, "#");
      move_student(drm, mhs, nim, asrama, zstd, zdrm, find_id, find_dorm);
    }
    else if (strcmp(token, "dorm-empty") == 0)
    {
      // If token is "dorm-empty", empty a dorm
      char *asrama = strtok(NULL, "#");
      dorm_empty(asrama, zstd, zdrm, mhs, drm, find_dorm);
    }
  }

  // menggunakan fungsi free untuk membebaskan memory nya
  free(mhs);
  free(drm);

  return 0;
}