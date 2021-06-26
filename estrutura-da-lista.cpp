#include <iostream>
using namespace std;

// Todo nó da lista tem um valor, um anterior e um próximo.
struct No
{
    int valor;
    No *anterior = NULL;
    No *proximo = NULL;
};

class ListaDupla
{
private:
    //ATRIBUTOS
    No *primeiro;
    No *ultimo;

public:
    //METODOS
    ListaDupla();                   // CONSTRUTOR
    void insereInicio(int valor);   // INSERE NO INÍCIO
    void insereFinal(int valor);    // INSERE NO FIM
    bool listaVazia();              // ISEMPTY
    bool listaCheia();              // ISFULL
    void mostraLista();             // EXIBE A LISTA
    void trocarValores(No *, No *); // TROCA O VALOR DE 2 NÓS
    void bubbleSort();              // FAZ A ORDENAÇÃO
};

// BUBBLESORT
void ListaDupla::bubbleSort()
{
    if (listaVazia())
    {
        return;
    }
    else
    {
        No *ini;
        No *fim = NULL;
        No *atual;

        for (ini = primeiro; ini->proximo != NULL; ini = ini->proximo)
        {
            for (atual = primeiro; atual->proximo != fim; atual = atual->proximo)
            {
                if (atual->valor > atual->proximo->valor)
                {
                    trocarValores(atual, atual->proximo);
                }
            }
            fim = atual;
        }
    }
}
