/*
Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.

Examples
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// inisialisasi linked list dalam stack
typedef struct node{
  char bracket;
  struct node *next;  
}node;

// membuat node baru yang akan digunakan untuk stack
node *create_node(char brack){
  node *newnode = (node *)malloc(sizeof(node));
  newnode->bracket = brack;
  newnode->next = NULL;
  return newnode;
}

// memmasukkan character ke dalam stack
void push(node **head, char data){
    node *newnode = create_node(data);
      newnode->next = *head; 
      *head = newnode; // head akan menjadi element paling tekahir dalam stack
}

//akan mengahpuskan kurung awal pada head jika ketemu tutup kurung
bool pop(node **head, char data){
  if(*head == NULL){ //jika kosong, otomatis false karena pop harus seimbang dengan push. Jika head sudah habis, pasti bukan valid
    return false;
  }
    if(((*head)->bracket == '[' && data == ']') || ((*head)->bracket == '(' && data == ')') || ((*head)->bracket == '{' && data == '}')){
      node *del = *head;
      *head = (*head)->next;
      free(del);
      return true;
    }
    else{
      return false;
    }
  
  
}

bool valid_braces (const char *braces)
{
  node* head = NULL;
  bool flag = true;
  int i = 0;
	while (braces[i] != '\0'){
    if(braces[i] == '(' || braces[i] == '[' || braces[i] == '{'){
     push(&head, braces[i]); 
    }
    else if(braces[i] == ')' || braces[i] == ']' || braces[i] == '}'){
     flag = pop(&head, braces[i]);
      if(flag == false){
        break;
      }
    }
    i++;
  }
  
  if(head != NULL){
    flag = false;
    while(head != NULL){
      node *temp = head;
      head = head->next;
      free(temp);
    }
    
  }
  return flag;
}

int main() {
    char *Brace_check = NULL; 
    bool result;
    size_t len = 0;
    printf("enter any braces: ");
    getline(&Brace_check, &len, stdin);

    if(Brace_check[strlen(Brace_check) - 1] == '\n'){
      Brace_check[strlen(Brace_check) - 1] == '\0';
    }

    result = valid_braces(Brace_check);
    printf("%s\n", result? "Valid" : "Invalid");


    return 0;
}