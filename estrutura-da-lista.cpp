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
    bool listaCheia();              // ISFULL
    bool listaVazia();              // ISEMPTY
    void mostraLista();             // EXIBE A LISTA
    void trocarValores(No *, No *); // TROCA O VALOR DE 2 NÓS
    void InsertSort();              // ORDENA A LISTA
};

// CONSTRUTOR
ListaDupla::ListaDupla()
{
    primeiro = NULL;
    ultimo = NULL;
}

// VERIFICA SE A LISTA ESTÁ VAZIA
bool ListaDupla::listaVazia()
{
    return primeiro == NULL;
}

// VERIFICA SE A LISTA (MEMÓRIA DO COMPUTADOR) ESTÁ CHEIA
bool ListaDupla::listaCheia()
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

// INSERE UM VALOR NO INÍCIO DA LISTA
void ListaDupla::insereInicio(int valor)
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

// INSERE UM VALOR NO FINAL DA LISTA
void ListaDupla::insereFinal(int valor)
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

// TROCA OS VALORES DE DOIS NÓS
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

// INSERTSORT
void ListaDupla::InsertSort()
{
    No *inicio;
    No *deuspfv;

    for (inicio = primeiro; inicio != NULL; inicio = inicio->proximo)
    {
        for (deuspfv = primeiro; deuspfv != inicio; deuspfv = deuspfv->proximo)
        {
            if (deuspfv->valor >= inicio->valor)
            {
                trocarValores(inicio, deuspfv);
            }
        }
    }
}

// EXIBE OS ELEMENTOS DA LISTA
void ListaDupla::mostraLista()
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
