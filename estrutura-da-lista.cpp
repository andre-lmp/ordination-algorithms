#include <iostream>
#include <cstdlib>
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
    void bubbleSort();
    void selectSort();
    void insertSort();
    void MergeSort();
};

//MAIN
int main()
{
    int escolha;

    // INSTÂNCIA DA CLASSE
    ListaDupla lista1;

    // GERA 10 NUMEROS ALÉATORIOS DE 1 A 100
    for (int i = 0; i < 10; i++)
    {
        lista1.insereInicio(1 + (rand() % 100));
    }

    cout << "1- BubbleSort \n2- SelectSort \n3- InsertSort \n4- MergeSort" << endl;
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        lista1.bubbleSort();
        break;
    case 2:
        lista1.selectSort();
        break;
    case 3:
        lista1.insertSort();
        break;
    case 4:
        lista1.MergeSort();
        break;
    default:
        cout << "Numero invalido!";
    }
    if (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4)
    {
        cout << endl;
        lista1.mostraLista();
    }
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

// INSERTSORT
void ListaDupla::insertSort()
{
    No *chave;
    No *deuspfv;
    int backup;

    for (chave = primeiro->proximo; chave != NULL; chave = chave->proximo)
    {
        backup= chave->valor;
        
        // EMPURRA ELEMENTOS ATÉ ENCONTRAR SEU LUGAR NA LISTA
        for (deuspfv = chave->anterior; deuspfv != NULL && deuspfv->valor >= backup; deuspfv = deuspfv->anterior)
        {
            (deuspfv->proximo)->valor = deuspfv->valor;
        }

        if (deuspfv == NULL)
        {
            deuspfv= primeiro;
            deuspfv->valor= backup;
        }
        else{
            deuspfv->proximo->valor= backup;
        }
    }
}

//SELECTSORT
void ListaDupla::selectSort()
{
    No *atual = primeiro;
    No *fim = ultimo;
    No *maior = primeiro;

    for (fim; fim->anterior != primeiro->anterior; fim = fim->anterior)
    {
        maior = primeiro;

        for (atual = primeiro; atual != fim; atual = atual->proximo)
        {
            if (maior->valor <= atual->valor)
            {
                maior = atual;
            }
        }
        if (maior->valor > fim->valor)
        {
            trocarValores(fim, maior);
        }
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
