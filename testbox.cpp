#include <stdio.h>

#include "my_arrays.h"

int main(){

    int ARRAY_SIZE = 8;

    util::dynamic_array<int> arr( ARRAY_SIZE );

    for(int i = 0; i < arr.size(); i++){
        arr.get(i) = i * i;
    }

    printf("PRINT VALUES, SIZE: %i\n", arr.size());
    for(int i = 0; i < arr.size(); i++){
        printf("%i\t|", arr.get(i));
    }

    printf("\n\nADD 2 ITEMS TO THE END...\n");
    arr.add_cells(2, true);

    printf("PRINT VALUES, SIZE: %i\n", arr.size());
    for(int i = 0; i < arr.size(); i++){
        printf("%i\t|", arr.get(i));
    }

    printf("\n\nDELETE FIRST 2 ITEMS...\n");
    arr.rem_cells(2, false);

    printf("PRINT VALUES, SIZE: %i\n", arr.size());
    for(int i = 0; i < arr.size(); i++){
        printf("%i\t|", arr.get(i));
    }
    return 0;
}