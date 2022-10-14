#include <stdio.h>
#include <stdlib.h>

//Free is diferent than delete. 
//Free dealoccate the memory but not call the destructor of the objects.

int main(){
    int *z;
    z = (int *)malloc(sizeof(int));
    *z = 100;
    free(z);
}