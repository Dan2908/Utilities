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
    size_t arraySize = 400;
    intArray A(arraySize);
    
    util::testing::timer t;
    
    t.start();
    intArray B(A); //cpy constructor
    t.end();

    printf("Copying %i elements from array took %i[ns]\n", arraySize, t.get_nanoseconds());

    printf("\n Arrays are %s", (A == B) ? "equal." : "not equal.");
    return 0;
}