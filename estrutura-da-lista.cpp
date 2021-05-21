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
    bool listaCheia();            // ISFULL
    bool listaVazia();            // ISEMPTY
    void mostraLista();           // EXIBE A LISTA
    void insertSort();
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


    lista1.insertSort();
    lista1.mostraLista();

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

void ListaDupla::insertSort()
{
    No * inicio;
    No * deuspfv;
    No * temp;
    for(inicio = primeiro; inicio->proximo != NULL; inicio = inicio->proximo)
    {
        for(deuspfv = inicio->proximo; inicio->proximo != NULL; deuspfv = inicio->proximo->proximo)
        {
            if(deuspfv < inicio)
            {
                temp = deuspfv;
                deuspfv = inicio;
                inicio = temp;
            };
        };
    };
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
