/**
  * Trabalho 4 de Teoria da Computação, Linguagens Formais e Autômatos
  * Professor: Alexandre Rossini
  * Acadêmicos: Fernando Noleto e Suayder Milhomem
  *
  */

#include <iostream>
#include <string.h>
#include <cstring>
#include "lista.h"
#include "transicao.h"

using namespace std;

int main()
{
    char palavra[20];

    cout << "Acadêmicos: Fernando Noleto e Suayder Milhomem" << endl;
    cout << "Reconhecer palavra da expressão regular: (a+b)*a(a+b)(a+b)" << endl;
    cout << "Digite a palavra!" << endl;
    cin >> palavra;

    lista* lPalavra = inicializar();

    for(unsigned int i = 0; i < strlen(palavra); i++){
        inserir_lista(lPalavra, palavra[i]);
    }

    lista* estados = funcao_transicao_estendida(lPalavra);
    bool flag = verifica(estados);

    if(flag)
        cout << "A palavra " << palavra << " foi reconhecida!!" << endl;
    else
        cout << "A palavra " << palavra << " não foi reconhecida!!" << endl;


    return 0;
}
