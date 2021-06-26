
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
