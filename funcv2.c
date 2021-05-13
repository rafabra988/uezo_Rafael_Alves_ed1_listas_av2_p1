#include "headerv2.h"

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
        t = p->prox; //guarda refer�ncia p/ pr�x. elemento
        free(p); //libera a mem�ria apontada por p
        p = t; //faz p apontar para o pr�ximo
    }
}

Elemento* lst_insere_ordenado (Elemento* lst, int val){
    Elemento* novo;
    Elemento* ant = NULL; //ponteiro para elemento anterior
    Elemento* p = lst; //ponteiro para percorrer a lista
    Elemento* rlst = lst; //ponteiro lista atualizado
    //procura posi��o de inser��o
    while (p != NULL && p->info < val){
        ant = p; p = p->prox;
    }
    //cria novo elemento
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = val;
    //encadeia elemento
    if (ant == NULL){ //insere elemento no in�cio
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
    if (lst != NULL) //se lista n�o estava vazia
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
