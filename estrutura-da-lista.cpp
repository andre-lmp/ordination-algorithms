#include <iostream>
using namespace std;

// Todo nó da lista tem um valor, um anterior e um próximo.
struct No
{
    int valor;
    No* anterior = NULL;
    No* proximo = NULL;
};

class ListaDupla
{
private:
    //ATRIBUTOS
    No* primeiro;
    No* ultimo;

public:
    //METODOS
    ListaDupla();                   // CONSTRUTOR
    void insereInicio(int valor);   // INSERE NO INÍCIO
    void insereFinal(int valor);    // INSERE NO FIM
    bool listaCheia();              // ISFULL
    bool listaVazia();              // ISEMPTY
    void mostraLista();             // EXIBE A LISTA
    void trocarValores(No*, No*); // TROCA O VALOR DE 2 NO
    void MergeSort();
};

//MAIN
int main()
{
    ListaDupla lista1; // INSTÂNCIA DA CLASSE

    lista1.insereFinal(1);
    lista1.insereFinal(7);
    lista1.insereFinal(5);
    lista1.insereFinal(4);
    lista1.insereFinal(2);
    lista1.insereFinal(8);
    lista1.insereFinal(6);
    lista1.insereFinal(5);

    lista1.MergeSort();
    lista1.mostraLista();

    return 0;
}
void mergeSort(No**);

ListaDupla::ListaDupla() // CONSTRUTOR
{
    primeiro = NULL;
    ultimo = NULL;
}

bool ListaDupla::listaVazia() // VERIFICA SE A LISTA ESTÁ VAZIA
{
    return primeiro == NULL;
}

bool ListaDupla::listaCheia() // VERIFICA SE A LISTA ESTÁ CHEIA
{
    No* Novo;
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
        No* Novo = new No;
        Novo->valor = valor;
        if (primeiro == NULL)
        {
            primeiro = Novo;
            ultimo = Novo;
        }
        else
        {
            No* Temp;
            Temp = primeiro;
            Novo->proximo = Temp;
            Temp->anterior = Novo;
            primeiro = Novo;
        }
    }
}

void ListaDupla::insereFinal(int valor) // INSERE NO FINAL
{
    if (listaCheia())
    {
        return;
    }
    else
    {
        No* Novo = new No;
        Novo->valor = valor;
        if (primeiro == NULL)
        {
            primeiro = Novo;
            ultimo = Novo;
        }
        else
        {
            No* Temp;
            Temp = ultimo;
            Novo->anterior = Temp;
            Temp->proximo = Novo;
            ultimo = Novo;
        }
    }
}

void ListaDupla::trocarValores(No* v1, No* v2)
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

//MERGESORT
void ListaDupla::MergeSort()
{
    mergeSort(&primeiro);
}

void dividirLista(No*, No**, No**);
No* sortedMerge(No*, No*);

void mergeSort(No** primeiro) //Faz o controle das funções
{
    No* lista = *primeiro;
    No* ini, * meio;
    if (lista == NULL || lista->proximo == NULL)
    {
        return;
    }
    dividirLista(lista, &ini, &meio);

    mergeSort(&ini);
    mergeSort(&meio);

    *primeiro = sortedMerge(ini, meio);
}

//MERGESORT - DIVISÃO DA LISTA
void dividirLista(No* lista, No** ini, No** meio)
{
    No* slow = lista;
    No* fast = lista->proximo;

    while (fast != NULL)
    {
        fast = fast->proximo;
        if (fast != NULL)
        {
            fast = fast->proximo;
            slow = slow->proximo;
        }
    }
    *ini = lista;
    *meio = slow->proximo;

    (slow->proximo)->anterior = NULL;
    slow->proximo = NULL;
}

// UNE E ORGANIZA OS NÓS
No* sortedMerge(No* A, No* B)
{
    No* lista = NULL;

    if (A == NULL) { return B; }
    else if (B == NULL) { return A; }

    if (A->valor <= B->valor)
    {
        lista = A;
        lista->proximo = sortedMerge(A->proximo, B);
    }
    else if (B->valor <= A->valor)
    {
        lista = B;
        lista->proximo = sortedMerge(B->proximo, A);
    }
    (lista->proximo)->anterior = lista;
    return lista;
}

void ListaDupla::mostraLista() // EXIBE A LISTA
{
    if (listaVazia())
    {
        return;
    }
    else
    {
        No* Temp;
        Temp = primeiro;
        while (Temp != NULL)
        {
            cout << Temp->valor << endl;
            Temp = Temp->proximo;
        }
    }
}
