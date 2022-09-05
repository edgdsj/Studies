#include <stdio.h>
#include <stdlib.h>

int main(){
    int *z;
    z = (int *)malloc(sizeof(int));
    *z = 100;
    free(z);
}