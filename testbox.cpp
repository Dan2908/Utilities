#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include "utilities.h"

template < class dataType >
  void printArray(util::dynamic_array < dataType > * p_array) {
    printf("PRINT VALUES, SIZE: %i\n|", p_array -> size());
    for (int i = 0; i < p_array -> size(); i++) {
      printf("%i\t|", p_array -> get(i));
    }
    printf("\n\n");
  }

typedef util::dynamic_array < int > intArray;

template<class T, class... Pp >
void test_function(T( * F)(Pp...), Pp... p_args) {
  auto start = std::chrono::high_resolution_clock::now();
  F(p_args...);
  auto end = std::chrono::high_resolution_clock::now();
  printf("it took %i ticks, or %f seconds.\n", start - end, (float)end / CLOCKS_PER_SEC);
}

int main() {
  int arraySize = 3000;

  intArray from(arraySize);
  intArray to(arraySize);

  for (int i = 0; i < arraySize; i++) {
    from.get(i) = (i * 2) + 1;
    to.get(i) = (i * 2);
  }
  
  printf("%li \n", CLOCKS_PER_SEC);


  auto start = std::chrono::high_resolution_clock::now();
  util::duff_copy(&from.get(0), &to.get(0), arraySize);
  auto end = std::chrono::high_resolution_clock::now();
  printf("it took %i ticks, or %f seconds.\n", end - start, 0);


  //printArray( & to);
  return 0;
}