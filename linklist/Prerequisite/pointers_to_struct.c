
/*

struct name {
  data_type1 member1;
  data_type2 member2;
    ...
};

int main ()
{
    # to make a pointer of 'name' strcut
    struct name *namePtr, Reja;
}

    Reja.memmber1 = value ;

    namePtr->member1 = value;

*/



#include <stdio.h>

struct person {
    int age;
    float weight;
};

int main()
{

    struct person *personPtr, Sristi;

    personPtr = &Sristi; // the address of Reja is stored in the pointer
 
    printf("\nEnter age: ");
    scanf("%d", &personPtr -> age); // &Reja.age;


    printf("Enter weight: ");
    scanf("%f", &personPtr -> weight); // &Reja.weight;


    // display 

    printf("\nYour age is : %d\n", personPtr->age);
    printf("\nYour weight is : %f\n", personPtr->weight);

    return 0;
}