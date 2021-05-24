#include <iostream>
#include <cmath>

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
    void trocarValores(No *, No *); // TROCA O VALOR DE 2 NO
    void mergeSort(No *ini, No *fim);
    void merge(No *ini, No *meio, No *fim);
    void contaNo();
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

    lista1.mostraLista();
    lista1.contaNo();


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
/*
void ListaDupla::contaNo()
{
    No *Temp = primeiro;
    No *cont;
    cont->valor = 0;

    while (Temp != NULL)
    {
        Temp = Temp->proximo;
        cont->valor = cont->valor + 1;
    }
    cout << "Teste: " << cont->valor << endl;
}
*/

// INCOMPLETO, AINDA EM TESTE.
void ListaDupla::mergeSort(No *ini, No *fim)
{
    if (ini->proximo != NULL)
    {
        No *cont;
        No *meio;
        No *Temp = primeiro;
        
        cont->valor = 0;
        while (Temp != NULL)
        {
            Temp = Temp->proximo;
            cont->valor = cont->valor + 1;
        }
        meio->valor = floor(cont->valor / 2); // recebe o valor que representa o meio da lista (divisão inteira).
        mergeSort(ini, meio);
        mergeSort(meio, fim);
        merge(ini, meio, fim); // merge ainda não feito.
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
