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
    void trocarValores(No *, No *); // TROCA O VALOR DE 2 No
    void bubbleSort();              // FAZ A ORDENAÇÃO
};

//MAIN
int main()
{
    ListaDupla lista1; // INSTÂNCIA DA CLASSE

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

bool ListaDupla::listaVazia() // ISEMPTY
{
    return primeiro == NULL;
}

bool ListaDupla::listaCheia() // ISFULL
{
    No *Novo;
    try
    {
        Novo = new No;
        delete Novo;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

void ListaDupla::insereInicio(int valor) // INSERE NO INÍCIO
{
    if (listaCheia())
    {
        return;
    }
    else
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
}
void ListaDupla::insereFinal(int valor) // INSERE OS VALORES NO FINAL
{
    if (listaCheia())
    {
        return;
    }
    else
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
}

void ListaDupla::trocarValores(No *v1, No *v2)
{
    if (v1->valor == v2->valor)
    {
        return;
    }
    else
    {
        int aux = v1->valor;
        v1->valor = v2->valor;
        v2->valor = aux;
    }
}

void ListaDupla::bubbleSort() // ORDENA A LISTA
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

void ListaDupla::mostraLista() // EXIBE A LISTA
{
    if (listaVazia())
    {
        return;
    }
    else
    {
        No *Temp;
        Temp = primeiro;
        while (Temp != NULL)
        {
            cout << Temp->valor << endl;
            Temp = Temp->proximo;
        }
    }
}
