#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COADA 100

typedef struct Nod{
    int cheie;
    struct Nod* st;
    struct Nod* dr;
}Nod;

Nod* creareNod(int cheie){
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    if(nodNou == NULL){
      printf("Eroare la alocarea dinamica de memorie!\n");
      exit(0);
    }

    nodNou->cheie = cheie;
    nodNou->st = NULL;
    nodNou->dr = NULL;

    return nodNou;
}

Nod* inserareNod(int cheie, Nod* n){
    if(n == NULL){
      return creareNod(cheie);
    }
    if(cheie < n->cheie){
        n->st = inserareNod(cheie, n->st);
    }else if(cheie > n->cheie){
        n->dr = inserareNod(cheie, n->dr);
    }
    
    return n;
}

void inordine(Nod* n){
  if(n != NULL){
    inordine(n->st);
    printf("%d ", n->cheie);
    inordine(n->dr);
  }
}

void preordine(Nod* n){
  if(n != NULL){
     printf("%d ", n->cheie);
     preordine(n->st);
     preordine(n->dr);
  }
}

void postordine(Nod* n){
  if (n != NULL) {
     postordine(n->st);
     postordine(n->dr);
     printf("%d ", n->cheie);
  }
}

void nivel(Nod* radacina){
  if(radacina == NULL){
    printf("Arborele este gol!\n");
    return;
  }

  Nod* coada[MAX_COADA];
  int inceput = 0, sfarsit = 0;

  coada[inceput] = radacina;
  inceput++;

  printf("Traversare pe nivel (level-order traversal):\n");
  while(inceput < sfarsit){
      Nod* curent = coada[inceput];
      inceput++;
      printf("%d ", curent->cheie);

      if(curent->st != NULL){
        coada[inceput] = curent->st;
        inceput++;
      }

      if(curent->dr != NULL){
        coada[inceput] = curent->dr;
        inceput++;
      }
  }
}

int main(){
    int opt, val, i, n = 10;
    int minim = 1, maxim = 50;
    Nod* radacina = NULL;
    srand(time(NULL));
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
        for(i = 0; i < n; i++){
          val = rand() % (maxim - minim + 1) + minim;
          radacina = inserareNod(val, radacina);
        }
        printf("Au fost inserate aleator 10 noduri in arbore.\n");
        break;
      case 2:
        printf("Traversare pre-ordine:\n");
        preordine(radacina);
        printf("\n");
        break;
      case 3:
        printf("Traversare in-ordine:\n");
        inordine(radacina);
        printf("\n");
        break;
      case 4:
        printf("Traversare post-ordine:\n");
        postordine(radacina);
        printf("\n");
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