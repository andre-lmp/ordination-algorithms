#include <iostream>
using namespace std;

// Todo nó da lista tem um valor, um anterior e um próximo.
struct No
{
    int valor;
    No *anterior;
    No *proximo;
};

class ListaDupla
{
private:
    //ATRIBUTOS
    No *primeiro;
    No *ultimo;

public:
    //METODOS
    ListaDupla();                 // CONSTRUTOR
    void insereInicio(int valor); // INSERE NO INÍCIO
    void insereFinal(int valor);  // INSERE NO FIM
    void mostraLista();           // EXIBE A LISTA
    void bubbleSort();            // FAZ A ORDENAÇÃO
};

//MAIN
int main()
{
    ListaDupla lista1; // INSTÂNCIA DA CLASSE
    int opcao, valor;

    lista1.insereFinal(1);
    lista1.insereFinal(7);
    lista1.insereFinal(5);
    lista1.insereFinal(4);
    lista1.insereFinal(5);
    lista1.insereFinal(4);
    lista1.insereFinal(4);
    lista1.insereFinal(4);
    lista1.insereFinal(0);
    lista1.insereFinal(9);
    lista1.insereFinal(9);
    lista1.insereInicio(1);
    lista1.insereInicio(1);
    lista1.insereInicio(7);
    lista1.insereInicio(7);
    lista1.insereInicio(7);
    lista1.insereInicio(7);
    lista1.insereInicio(7);
    
    lista1.bubbleSort();
    
    lista1.mostraLista();

    return 0;
}

ListaDupla::ListaDupla() // CONSTRUTOR
{
    primeiro = NULL;
    ultimo = NULL;
}
void ListaDupla::insereInicio(int valor) // INSERE NO INÍCIO
{
    No *Novo = new No;
    Novo->valor = valor;
    if (primeiro == NULL)
    {
        primeiro = Novo;
        ultimo = Novo;
    }
    else
    {
        No *Temp;
        Temp = primeiro;
        Novo->proximo = Temp;
        Temp->anterior = Novo;
        primeiro = Novo;
    }
}
void ListaDupla::insereFinal(int valor) // INSERE OS VALORES NO FINAL
{
    No *Novo = new No;
    Novo->valor = valor;
    if (primeiro == NULL)
    {
        primeiro = Novo;
        ultimo = Novo;
    }
    else
    {
        No *Temp;
        Temp = ultimo;
        Novo->anterior = Temp;
        Temp->proximo = Novo;
        ultimo = Novo;
    }
}

void ListaDupla::bubbleSort() // BUBBLESORT
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
                int Temp = atual->valor;
                atual->valor = atual->proximo->valor;
                atual->proximo->valor = Temp;
            }
        }
        fim = atual;
    }
}

void ListaDupla::mostraLista() // EXIBE A LISTA
{
    No *Temp;
    Temp = primeiro;
    while (Temp != NULL)
    {
        cout << Temp->valor << endl;
        Temp = Temp->proximo;
    }
}
