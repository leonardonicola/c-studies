#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char name[30];
  int age;
};

#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS
void writeToFile(const struct Person * person);
void printPersonName();
#endif

FILE * file_ptr;

void writeToFile(struct Person const * pessoa) {
  file_ptr = fopen("person1.txt", "w");
  if (file_ptr == NULL) {
    perror("Erro ao ler arquivo");
    exit(EXIT_FAILURE);
  }
  fprintf(file_ptr, "Olá, me chamo: %s \n", pessoa->name);
  fprintf(file_ptr, "E tenho: %d anos.", pessoa->age);
  fclose(file_ptr);
};

void printPersonName() {
  file_ptr = fopen("person2.txt", "r");
  if (file_ptr == NULL) {
    perror("Erro ao ler arquivo");
    exit(EXIT_FAILURE);
  };
  char lines[256];
  char * colonPos;
  // Loop pelas linhas do código
  while (fgets(lines, sizeof(lines), file_ptr) != NULL) {
    colonPos = strstr(lines, "chamo:");
    if (colonPos != NULL) {
      colonPos += 7;
      printf("Nome: %s", colonPos);
    }
  }
  // Sem necessidade de liberar memória do ponteiro pois o fclose faz isso
  // automaticamente
  fclose(file_ptr);
}

int main(int argc, char * argv[]) {
  struct Person vulgodj = {"Vulgo DJ", 20};
  writeToFile(&vulgodj);
  printPersonName();
  return 0;
}