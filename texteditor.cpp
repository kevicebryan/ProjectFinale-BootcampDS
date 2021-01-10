#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
  char word [255];
  Node *next;
  Node *prev;
}*head, *tail;

Node *createNode(const char word[]){
  Node *temp = (Node*)malloc(sizeof(Node));
  strcpy(temp->word, word);
  temp->next = temp->prev = NULL;
  return temp;
}

void pushTail(const char word[]){
  Node *temp = createNode(word);
  if (!head){
    head = tail = temp;
  }else{
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
}

void popTail(){
  if (!head){
    return;
  }else if (head==tail){
    head = tail = NULL;
    free(tail);
  }else{
    Node *temp = tail->prev;
    tail->prev = temp->next = NULL;
    tail = NULL;
    free(tail);
    tail = temp;
  }
}

void printLinkedList(){
  Node *curr = head;
  while(curr){
    printf("%s ", curr->word);
    curr = curr->next;
  }
  // puts("NULL");
}


int main (){
  printf("Welcome to Kevice's TextEditor!\n");
    puts("================================");
  bool inApp = true;
  while (inApp){
  puts("Press 1 to enter word");
  puts("Press 2 to delete last entered word");
  puts("press 3 to exit from program");
  int choice;
  do{
    scanf("%d", &choice);
    getchar();
  }while (choice != 1 && choice != 2 && choice != 3);

  switch (choice){
    case 1:
    char string[255];
    puts("<<NNN>> = newline = enter");
    printf("Enter your word: ");
    scanf("%[^\n]", string);
    getchar();
    if( strcmp (string, "NNN")== 0){
      strcpy (string, "\n");
    }
    printf("Word <<%s>> Added\n", string);
    puts("=============================");
    pushTail(string);
    printLinkedList();
    puts("");
    puts("=============================");
    break;

    case 2:
    popTail();
    puts("Succesfully Deleted");
    puts("=============================");
    printLinkedList();
    puts("");
    puts("=============================");
    break;

    case 3:
    inApp = false;
    break;
  }
  }

  return 0;
}
