#ifndef LISTA_H
#define LISTA_H

typedef struct nol{
    char info;
    struct nol* prox;
}tno;

typedef struct{
    tno* inicio;
}lista;


lista* inicializar(){
    lista* l = (lista*) malloc (sizeof(lista));

    return l;
}

void inserir_lista(lista* l, char x){

    tno* no = (tno*) malloc (sizeof(tno));
    no->info = x;
    no->prox = NULL;

    if(!l->inicio){
        l->inicio = no;
    }
    else{
        tno* aux = l->inicio;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
}

void remover_lista(lista* l, char x){
    if(!l->inicio){
        return;
    }
    else{
        tno* aux = l->inicio;
        if(aux->info == x){
            l->inicio = aux->prox;
            free(aux);
            return;
        }
        tno* aux2 = aux->prox;
        while(aux2->prox != NULL){
            if(aux2->info == x)
                break;
            aux = aux2;
            aux2 = aux2->prox;
        }
        aux->prox = aux2->prox;
        free(aux2);
    }

}

void imprimir_lista(lista* l){
    tno* aux = l->inicio;
    puts("Lista");
    while(aux){
        printf("%c| ", aux->info);
        aux = aux->prox;
    }
    puts("");
}

char remover_ultimo(lista* l){

    char c;
    tno* aux = l->inicio;

    if(!aux->prox){
        c = aux->info;
        free(aux);
        l->inicio = NULL;
        inserir_lista(l, '&');
        return c;
    }


    tno* aux2 = aux->prox;
    while(aux2->prox){
        aux = aux->prox;
        aux2 = aux2->prox;
    }

    c = aux2->info;
    free(aux2);
    aux->prox = NULL;

    return c;
}

char remover_primeiro(lista* l){
    char c;
    tno* aux = l->inicio;
    if(!aux->prox){
        c = aux->info;
        free(aux);
        l->inicio = NULL;
        inserir_lista(l, '&');
        return c;
    }

    l->inicio = aux->prox;
    c = aux->info;
    free(aux);
    return c;
}

#endif // LISTA_H
