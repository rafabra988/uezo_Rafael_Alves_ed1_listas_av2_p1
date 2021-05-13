#ifndef HEADERV2_H_INCLUDED
#define HEADERV2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct elemento{
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct elemento2 {
    int info;
    struct elemento2 *ant;
    struct elemento2 *prox;
};
typedef struct elemento2 Elemento2;

Elemento *init;

Elemento* lst_cria (void);

Elemento* lst_insere (Elemento* lst, int val);

Elemento2* lst2_cria(void);

void lst_imprime (Elemento* lst);

int lst2_imprime(Elemento2* lst,int r);

void lst_imprimemov (Elemento* lst);

void lst_libera (Elemento* lst);

Elemento* lst_insere_ordenado (Elemento* lst, int val);

Elemento2* lst2_insere (Elemento2* lst, int val);

void removdup(Elemento* lst);

void pulareapagar(Elemento* lst,int m, int n);

void movinit(Elemento*lst);

int nova_lst_amba(Elemento* lst, Elemento* lst2);

void inverta_lst(Elemento* lst);


#endif // HEADERV2_H_INCLUDED
