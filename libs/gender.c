#include "gender.h" 
#include <stdio.h>

void print_gender(enum gender_t gender) {
    switch(gender) {
        case GENDER_MALE:
            printf("Male\n");
            break;
        case GENDER_FEMALE:
            printf("Female\n");
            break;
        default:
            printf("Invalid gender\n");
            break;
    }
}

