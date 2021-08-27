#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include "utilities.h"

template <class dataType>
void printArray(util::dynamic_array<dataType> *p_array)
{
    printf("PRINT VALUES, SIZE: %i\n|", p_array->size());
    for (int i = 0; i < p_array->size(); i++)
    {
        printf("%i\t|", p_array->get(i));
    }
    printf("\n\n");
}

typedef util::dynamic_array<int> intArray;

int main()
{
    int arraySize = 40000;


    return 0;
}