#include <stdio.h>
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
    size_t arraySize = 40;
    intArray A(arraySize), B(arraySize);
    int *a = (int*)A;
    int *b = (int*)B;

    printArray(&A);
    printArray(&B);
    
    int time = util::function_duration( util::duff_device, 1, a, arraySize);
    printf("Array size: %i\nelapsed time: %ins\n", arraySize ,time );
    
    time = util::function_duration( util::duff_device, 2, b, arraySize);
    printf("Array size: %i\nelapsed time: %ins\n", arraySize ,time );

    printArray(&A);
    printArray(&B);
    
    time = util::function_duration( util::duff_device, a, b, arraySize);
    printf("Array size: %i\nelapsed time: %ins\n", arraySize ,time );
    
    return 0;
}