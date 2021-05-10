#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "funcoes.h"

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

Elemento* lst_cria (void){
    Elemento *aux;
    aux=(Elemento*)malloc(sizeof(Elemento));
    init=aux;
    return NULL;
}

Elemento* lst_insere (Elemento* lst, int val){
    Elemento* aux=init;
    int v=0;
    Elemento* novo =(Elemento*)malloc(sizeof(Elemento));
    novo->info = val;
    novo->prox = lst;
    if(v<1){
        aux->prox=novo;
        v=1;
    }
    return novo;
}

Elemento2* lst2_cria(void){
    return NULL;
}

void lst_imprime (Elemento* lst){
    Elemento* p;
    for (p = lst; p != NULL; p = p->prox){
        printf("%d -> ", p->info);
    }
    printf("NULL");
}

int lst2_imprime(Elemento2* lst,int r){
    Elemento2* p;
    srand(time(NULL));
    int ra=(rand() % (r - 1) + 1);

    while(p!=NULL){
        //printf(" %d -> ", p->info);
        if(p->prox==NULL){
            printf("\n");
            for(int i=0;i<ra;i++){
                //printf(" %d -> ", p->info);
                p=p->ant;
            }
            return p->info;
            break;
        }
        p=p->prox;
    }
}

void lst_imprimemov (Elemento* lst){
    Elemento* p;
    for (p = init->prox; p != NULL; p = p->prox)
    printf("info = %d\n", p->info);
}

void lst_libera (Elemento* lst){
    Elemento *p = lst, *t;
    while (p != NULL){
        t = p->prox; //guarda referência p/ próx. elemento
        free(p); //libera a memória apontada por p
        p = t; //faz p apontar para o próximo
    }
}

Elemento* lst_insere_ordenado (Elemento* lst, int val){
    Elemento* novo;
    Elemento* ant = NULL; //ponteiro para elemento anterior
    Elemento* p = lst; //ponteiro para percorrer a lista
    Elemento* rlst = lst; //ponteiro lista atualizado
    //procura posição de inserção
    while (p != NULL && p->info < val){
        ant = p; p = p->prox;
    }
    //cria novo elemento
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = val;
    //encadeia elemento
    if (ant == NULL){ //insere elemento no início
        novo->prox = lst; rlst = novo;
    }
    else { //insere elemento no meio da lista
        novo->prox = ant->prox; ant->prox = novo;
    }
    return rlst;
}

Elemento2* lst2_insere (Elemento2* lst, int val){
    Elemento2 *novo = (Elemento2*)malloc(sizeof(Elemento2));
    novo->info = val;
    novo->prox = lst;
    novo->ant = NULL;
    if (lst != NULL) //se lista não estava vazia
        lst->ant = novo; //ajusta ponteiro do antigo 1o elem
    return novo; //retorna ponteiro lista atualizada
}

void removdup(Elemento* lst){
    Elemento *segundaux, *aux;
    aux=lst->prox;
    segundaux=lst;
    while(aux!=NULL){
        if(aux->info == segundaux->info){
            segundaux->prox=aux->prox;
            free(aux);

            aux=segundaux->prox;
        }else{
            segundaux=aux;
            aux=aux->prox;
        }
    }
}

void pulareapagar(Elemento* lst,int m, int n){
    Elemento *aux,*segundaux;
    aux= lst;
    segundaux=lst;
    while(aux!=NULL){
        for(int i=0;i<m;i++){
            if(aux!=NULL){
                segundaux=aux;
                aux=aux->prox;
            }
        }
        for(int i=0;i<n;i++){
            if(aux!=NULL){
                segundaux->prox=aux->prox;
                free(aux);
                aux=segundaux->prox;
            }
        }
    }
}

void movinit(Elemento*lst){
    Elemento *segundaux, *aux,*tercaux,*quartaux;
    aux= init;
    segundaux=init;
    tercaux=init;
    quartaux=init->prox;
    while(aux!=NULL){
        tercaux=segundaux;
        segundaux=aux;
        aux=aux->prox;
    }
    tercaux->prox=NULL;
    init->prox=segundaux;
    segundaux->prox=quartaux;
    aux=init->prox;
}

int nova_lst_amba(Elemento* lst, Elemento* lst2){
    Elemento* p1,* p2,* p3,* lst3;
    lst3 = lst_cria();
    for (p1=lst; p1 != NULL;p1 = p1->prox){
        for(p2=lst2; p2 != NULL;p2 = p2->prox){
            if(p1->info == p2->info){
                lst3=lst_insere_ordenado(lst3,p2->info);
            }
        }
    }
    return lst3;
    lst_libera(lst3);
}

void inverta_lst(Elemento* lst){
    Elemento *pa, *p, *pd;
    if (lst != NULL){
       pa = NULL;
       p = lst;
       pd = p->prox;
       do{
          p->prox = pa;
           pa = p;
           p = pd;
           if (pd != NULL){
                pd = pd->prox;
           }
       }while (p != NULL);
       lst = pa;
    }
    printf("\n");
    lst_imprime(lst);
}



int main()
{
    setlocale(LC_ALL, "Portuguese");
/*__________________________________________exe1__________________________________*/
//    int resp, v;
//    Elemento* lst;
//
//    lst = lst_cria();
//
//    printf("quanta posições tera na lista?\n");
//    scanf("%d",&resp);
//
//    for(int i=0;i<resp;i++){
//        printf("qual o valor do %dº elemento?",i+1);
//        scanf("%d",&v);
//        lst = lst_insere_ordenado(lst, v);
//    }
//
//    removdup(lst);
//
//    lst_imprime(lst);
//    lst_libera(lst);

/*__________________________________________exe2__________________________________*/

//    int valor1,valor2, resp, v;
//
//    Elemento* lst;
//
//    lst = lst_cria();
//
//    printf("quanta posições tera na lista?\n");
//    scanf("%d",&resp);
//
//    for(int i=0;i<resp;i++){
//        printf("qual o valor do %dº elemento?",i+1);
//        scanf("%d",&v);
//        lst = lst_insere_ordenado(lst, v);
//    }
//
//        printf("gostária de pular quantos valores?\n");
//        scanf("%d",&valor1);
//
//        printf("gostária de apagar quantos valores?");
//        scanf("%d",&valor2);
//
//
//    pulareapagar(lst,valor1,valor2);
//
//    lst_imprime(lst);
//    lst_libera(lst);
/*__________________________________________exe3__________________________________*/
//    int resp, v;
//
//    Elemento* lst;
//
//    lst = lst_cria();
//
//    printf("quanta posições tera na lista?\n");
//    scanf("%d",&resp);
//
//    for(int i=0;i<resp;i++){
//        printf("qual o valor do %dº elemento?",i+1);
//        scanf("%d",&v);
//        lst = lst_insere(lst, v);
//    }
//
//    movinit(lst);
//    lst_imprimemov(lst);
//    lst_libera(lst);
/*__________________________________________exe4__________________________________*/

//    int resp, v;
//
//    Elemento2* lst;
//
//    lst = lst2_cria();
//
//    printf("quanta posições tera na lista?\n");
//    scanf("%d",&resp);
//
//    for(int i=0;i<resp;i++){
//        printf("qual o valor do %dº elemento?",i+1);
//        scanf("%d",&v);
//        lst = lst2_insere(lst,v);
//    }
//
//    int temp=lst2_imprime(lst,resp);
//
//    printf("o número retornado foi %d",temp);

/*__________________________________________exe5__________________________________*/

//        int resp, ac=0, v;
//
//        Elemento* lst, *lst2, *lst3;
//
//        lst = lst_cria();
//        lst2 = lst_cria();
//        lst3 = lst_cria();
//
//        printf("quanta posições tera na primeira lista?\n");
//        scanf("%d",&resp);
//
//        for(int i=0;i<resp;i++){
//            printf("qual o valor do %dº elemento?",i+1);
//            scanf("%d",&v);
//            lst = lst_insere_ordenado(lst, v);
//        }
//
//        printf("\nquanta posições tera na segunda lista?\n");
//        scanf("%d",&resp);
//
//        for(int i=0;i<resp;i++){
//            printf("qual o valor do %dº elemento?",i+1);
//            scanf("%d",&v);
//            lst2 = lst_insere_ordenado(lst2,v);
//        }
//
//        lst3=nova_lst_amba(lst,lst2);
//
//        printf("\nFirst List: ");
//        lst_imprime(lst);
//        printf("\nSecond List: ");
//        lst_imprime(lst2);
//        printf("\n\nOutput: ");
//        lst_imprime(lst3);

//        lst_libera(lst);
//        lst_libera(lst2);
//        lst_libera(lst3);

/*__________________________________________exe6__________________________________*/


//  int resp, ac=0, v;
//
//        Elemento* lst;
//
//        lst = lst_cria();
//
//        printf("quanta posições tera na primeira lista?\n");
//        scanf("%d",&resp);
//
//        for(int i=0;i<resp;i++){
//            printf("qual o valor do %dº elemento?",i+1);
//            scanf("%d",&v);
//            lst = lst_insere(lst, v);
//        }
//
//        lst_imprime(lst);
//        inverta_lst(lst);
//        lst_libera(lst);


    return 0;
}
