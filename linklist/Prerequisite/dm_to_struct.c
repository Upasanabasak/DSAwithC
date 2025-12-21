/*
Dymaic memory allocation of struct

malloc: 

ptr = (castType*)malloc(size)


int arr[size];



*/

#include <stdio.h>
#include <stdlib.h>

struct person {
    int age;
    float weight;
    char name[30];
};


int main()
{

    struct person *Personptr;

    int numberOfPerson = 2;

    Personptr = (struct person*)malloc(numberOfPerson * sizeof(struct person));

    /*
    address    person
    000      p1
    051      p2


    */

    for(int i = 0 ; i< numberOfPerson; ++i)
    {
        printf("\nEnter your age: ");
        scanf("%d", &(Personptr+i)->age);
        printf("\nEnter your weight: ");
        scanf("%f", &(Personptr+i)->weight);
        printf("\nEnter your name: ");
        scanf("%s", &(Personptr+i)->name); 
    }


    /// Displaying 

    for( int i =0 ; i< numberOfPerson; ++i){
        printf("Name: %s\tAge:%d\tWeight:%f \n",(Personptr+i)->name,(Personptr+i)->age,(Personptr+i)->weight);
    }

    return 0;
}