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
    void MergeSort();               // ORDENA A LISTA
};

//MAIN
int main()
{
    // INSTÂNCIA DA CLASSE
    ListaDupla lista1;

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
    system("PAUSE");
    return 0;
}
void mergeSort(No **);

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

// FAZ A TROCA DOS VALORES DE DOIS NÓS
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

//MERGESORT
void ListaDupla::MergeSort()
{
    mergeSort(&primeiro);
}

void dividirLista(No *, No **, No **);
No *sortedMerge(No *, No *);

// MERGESORT - CONTROLE DAS FUNÇÕES
void mergeSort(No **primeiro)
{
    No *lista = *primeiro;
    No *ini, *meio;
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
void dividirLista(No *lista, No **ini, No **meio)
{
    No *slow = lista;
    No *fast = lista->proximo;

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

// MERGESORT - UNE E ORGANIZA OS NÓS
No *sortedMerge(No *A, No *B)
{
    No *lista = NULL;

    if (A == NULL)
    {
        return B;
    }
    else if (B == NULL)
    {
        return A;
    }

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
