// remove vowels from string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *disemvowel(const char *str)
{
  char *result = (char *)malloc(strlen(str) + 1);
  int index_result = 0;
	int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] == 'a' || str[i] == 'A' || str[i] == 'E' ||str[i] == 'e' || str[i] == 'i' || str[i] == 'I' || str[i] == 'O' || str[i] == 'o' || str[i] == 'u' || str[i] == 'U'){
      continue;
    }
    else{
      result[index_result] = str[i];
      index_result++;
    }
  }
  result[index_result] = '\0';
  return result;
}

int main(){
    char *input, *after = NULL;
    size_t len = 0;
    printf("enter string: ");
    getline(&input, &len, stdin);
    if(input[strlen(input) - 1] = '\n'){
        input[strlen(input) - 1] == '\0';
    }

    after = disemvowel(input);
    printf("%s\n", after);

}