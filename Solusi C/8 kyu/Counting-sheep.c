/*
Consider an array/list of sheep where some sheep may be missing from their place. We need a function that counts the number of sheep present in the array (true means present).

For example,

{ true,  true,  true,  false,
  true,  true,  true,  true,
  true,  false, true,  false,
  true,  false, false, true,
  true,  true,  true,  true,
  false, false, true,  true }
The correct answer would be 17.

Hint: Don't forget to check for bad values like null/undefined
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

size_t count_sheep(const bool sheep[/* count */], size_t count)
{
  size_t present = 0;
  for(size_t i = 0; i < count; i++){
    if(sheep[i] == true){
      present++;
    }
    else{
      continue;
    }
  }
  return present;
}

int main(){
    size_t total = 24;
    const bool sheep[24] = { true,  true,  true,  false,
                            true,  true,  true,  true,
                            true,  false, true,  false,
                            true,  false, false, true,
                            true,  true,  true,  true,
                            false, false, true,  true };
    
    printf("number of sheep is %zu\n", count_sheep(sheep, total));
}