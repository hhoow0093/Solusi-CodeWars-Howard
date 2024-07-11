/*
Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t descendingOrder(uint64_t n) {
  int length_of_number = snprintf(NULL, 0, "%llu", n); // untuk mengetahui seberapa panjang uint64_t n dalam angka
  char *string = (char *)malloc((length_of_number+1) * sizeof(char)); // alokasi memori secara dinamis menjadi string dari variabel length_of_number
  snprintf(string, length_of_number+1, "%llu", n ); //assign nomor n sebagai string
  
  //sorting menggunakan selection sort secara descending
  //-1 karena cuman vaiabel j yang akan nyentuh data char teakhir dari string
  for(int i = 0; i < length_of_number -1; i++ ){
    for(int j = i+1; j < length_of_number; j++ ){
      if(string[i] < string[j]){
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
      }
    }
  } 
  uint64_t result = strtoull(string, NULL, 10); //NULL karena tidak ada alamat vaiable string ditulis, base 10 biar decimal
  free(string);
  return result;
}

int main(){
    uint64_t number = 12345;
    uint64_t hasil = descendingOrder(number);
    printf("%d", hasil);
    return 0;
}