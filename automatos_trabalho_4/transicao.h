#ifndef TRANSICAO_H
#define TRANSICAO_H
#include "lista.h"

lista* funcao_transicao(lista* estado, char c){

    lista* estados = inicializar();

    tno* aux = estado->inicio;

    while (aux) {
        if(aux->info == '0' && c == '&')
            inserir_lista(estados, '0');

        if(aux->info == '0' && c == 'a'){
            inserir_lista(estados, '0');
            inserir_lista(estados, '1');
        }
        if(aux->info == '0' && c == 'b'){
            inserir_lista(estados, '0');
        }
        if(aux->info == '1' && (c == 'a' || c == 'b')){
            inserir_lista(estados, '2');
        }
        if(aux->info == '2' && (c == 'a' || c == 'b')){
            inserir_lista(estados, '3');
        }

        aux = aux->prox;
    }


    return estados;
}

lista* funcao_transicao_estendida(lista* palavra){
    lista* estados = inicializar();
    inserir_lista(estados, '0');

    while(palavra->inicio->info != '&'){
        estados = funcao_transicao(estados, remover_primeiro(palavra));
    }


    return estados;
}

bool verifica(lista* estados){
    bool flag = false;

    tno* aux = estados->inicio;
    while(aux){
        //Parte do código onde mostra em quais estados parou!
        std::cout << "q" << aux->info << std::endl;
        if(aux->info == '3')
            flag = true;

        aux = aux->prox;
    }

    return flag;

}

#endif // TRANSICAO_H
