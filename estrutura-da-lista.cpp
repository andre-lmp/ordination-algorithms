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
    ListaDupla();                 // CONSTRUTOR
    void insereInicio(int valor); // INSERE NO INÍCIO
    void insereFinal(int valor);  // INSERE NO FIM
    bool listaCheia();            // ISFULL
    bool listaVazia();            // ISEMPTY
    void mostraLista();           // EXIBE A LISTA
    void trocarValores(No *, No *);
    void selectSort();
};

//MAIN
int main()
{
    ListaDupla lista1; // INSTÂNCIA DA CLASSE

    lista1.insereFinal(1);
    lista1.insereFinal(1);
    lista1.insereFinal(7);
    lista1.insereFinal(5);
    lista1.insereFinal(4);
    lista1.insereInicio(10);
    lista1.insereInicio(6);
    lista1.insereInicio(3);
    
    lista1.selectSort();

    lista1.mostraLista();
    system("PAUSE");

    return 0;
}

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

void ListaDupla::insereFinal(int valor) // INSERE NO FINAL
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

//SELECTSORT
void ListaDupla::selectSort()
{
    No *atual = primeiro;
    No *fim = ultimo;
    No *maior = primeiro;

    for (fim; fim->anterior != primeiro; fim = fim->anterior)
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
