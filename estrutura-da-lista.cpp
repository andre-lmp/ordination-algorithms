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
};

//MAIN
int main()
{
    ListaDupla lista1; // INSTÂNCIA DA CLASSE
    int opcao, valor;

    do
    {
        cin >> opcao;

        if (opcao == 1)
        {
            cin >> valor;
            lista1.insereInicio(valor);
        }
        else if (opcao == 2)
        {
            cin >> valor;
            lista1.insereFinal(valor);
        }

    } while (opcao != 0);

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
void ListaDupla::mostraLista() // EXIBE A LISTA
{
    No *Temp;
    Temp = primeiro;
    while (Temp)
    {
        cout << Temp->valor << endl;
        Temp = Temp->proximo;
    }
}
