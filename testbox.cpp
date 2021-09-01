#include <iostream>
#include <algorithm>
#include "utilities.h"

#define TITLE(x) std::cout << "\n-- " << x << std::endl
#define VAR_NAME(x) #x
#define PRINT_ARRAY(x) printf("Array: %s\n", VAR_NAME(x)); printArray(x)

const int g_array_tab_size = 7;

template <class dataType>
void printArray(dataType *p_array, int p_count)
{
    int width = 0; 
    for (int i = 0; i < p_count; i++)
    {
        std::cout << p_array[i] << ", ";
        if(width++ == g_array_tab_size ){
            printf("\n");
            width = 0;
        }
    }
    printf(" (null)\n\n");
}
template <class dataType>
void printArray(util::dynamic_array<dataType>& p_array)
{
    printArray(&p_array[0], p_array.size());
}

typedef util::dynamic_array<int> intArray;

int main()
{
    size_t arraySize = 10;
    intArray A(arraySize);
    intArray B;
    
    //Access
    TITLE("Access operator [] --");
    for(size_t i = 0; i < arraySize; i++){
        A[i] = i+1;
    }
    
    PRINT_ARRAY(A);
    //Assignation
    TITLE("ASSIGNATION operator =  --");
    PRINT_ARRAY(B);   
    TITLE("assign to B contents of A...");
    B = A;
    PRINT_ARRAY(B);   
    //copy ctor
    TITLE("COPY constructor --");
    TITLE("get array C from A --");
    intArray C(A);
    PRINT_ARRAY(C);
    //Comparation
    TITLE("COMPARATION operator == --");
    B[4] = 65;
    PRINT_ARRAY(A);
    PRINT_ARRAY(B);
    PRINT_ARRAY(C);
    printf("Array %s and %s are %s\n", VAR_NAME(A), VAR_NAME(B), (A == B) ? "equal" : "not equal"); // not equal
    printf("Array %s and %s are %s\n", VAR_NAME(A), VAR_NAME(C), (A == C) ? "equal" : "not equal"); // equal
    //Resize
    TITLE("RESIZE --");
    B.resize(5);
    A.resize(30);

    printf("size of %s: %i\n", VAR_NAME(A), A.size());
    printf("size of %s: %i\n", VAR_NAME(B), B.size());

    PRINT_ARRAY(A);
    PRINT_ARRAY(B);
    
    return 0;
}