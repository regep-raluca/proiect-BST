#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int cheie;
    struct Nod* st;
    struct Nod* dr;
}Nod;

int main(){
    int opt;
    do{
      printf("Meniu:\n");
      printf("0. Iesire din program\n");
      printf("1. Inserare nod in arbore\n");
      printf("2. Traversarea arborelui in pre-ordine\n");
      printf("3. Traversarea arborelui in in-ordine\n");
      printf("4. Traversarea arborelui in post-ordine\n");
      printf("5. Traversarea arborelui pe nivel\n");
      printf("Introduceti optiunea dorita: ");
      scanf("%d", &opt);

      switch (opt)
      {
      case 0:
        printf("Iesire din program...");
        exit(0);
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      default:
        printf("Optiune invalida\n");
        break;
      }
    }while(opt!=0);
    return 0;
}