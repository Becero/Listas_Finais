#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_MAX 10

typedef struct sLISTA
{
    int ultimo;
    char elem[TAM_MAX];
}LISTA;

void iniciar_lista(LISTA *lista)
{
    lista->ultimo = -1;
}

int verificar_lista_CHEIA(LISTA *lista)
{
    if(lista->ultimo == (TAM_MAX -1))
    {
        printf("\nLISTA CHEIA\n");
        return 1;
    }
    else
        return 0;

}

int verificar_lista_VAZIA(LISTA *lista)
{
    if(lista->ultimo < 0)
    {
        printf("\nLISTA VAZIA\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_FIM_lista(LISTA *lista, char elemento)
{
    if(verificar_lista_CHEIA(lista))
    {
        printf("\nERRO!!!\nLISTA CHEIA!!!\n\n");
        system("pause");
        return 0; //falso
    }
    lista->ultimo++;
    lista->elem[lista->ultimo] = elemento;
    return 1;
}

int modificar_ELEMENTO_EXISTENTE_lista(LISTA *lista, int posicao, char elemento)
{
    if(verificar_lista_VAZIA(lista))
    {
        printf("\nNENHUM ELEMENTO NA LISTA");
        return 0;
    }
    if(0 <= posicao && posicao <= lista->ultimo)
    {
        lista->elem[posicao] = elemento;
        printf("\nELEMENTO INSERIDO COM SUCESSO\n");
        return 1;
    }
    else
    {
        printf("\nPOSICAO INVALIDA\n");
        return 0;
    }
}
int remover_ELEMENTO_EXISTENTE_lista(LISTA *lista, int posicao)
{

    if(verificar_lista_VAZIA(lista))
    {
        printf("\nERRO!!!\nLISTA VAZIA!!!\n");
        return 0;
    }
    if(posicao < 0 || posicao > lista->ultimo)
    {
        printf("\nERRO!!!\nPOSICAO INVALIDA!\n");
        return 0;
    }

    for(int i = posicao; i < lista->ultimo; i++)
    {
        lista->elem[i] = lista->elem[i+1];
    }
    lista->ultimo--;
    return 1;
}

int pesquisar_ELEMENTO_lista (LISTA *lista, char elemento)
{
    if(verificar_lista_VAZIA(lista))
    {
        printf("\nERRO!!!\nLISTA VAZIA!!!\n");
        return -1;
    }
    for(int i = 0; i <= lista->ultimo; i++)
    {
        if(lista->elem[i] == elemento)
        {
            return i;
        }
    }

    printf("\nERRO!!!\nELEMENTO NAO ENCONTRADO!!!\n");
    return -1;
}
void retornar_TAMANHO_lista(LISTA *lista)
{
    printf("\nExistem %d elementos na lista\n", lista->ultimo+1);
}

void imprimir_TODOS_ELEMENTOS_lista(LISTA *lista)
{
    if(verificar_lista_VAZIA(lista))
    {
        printf("\nERRO!!! LISTA VAZIA\n");
        return;
    }
    printf("\n-> ");
    for(int i = 0; i <= lista->ultimo; i++)
    {
        printf("%c ", lista->elem[i]);
    }
    printf("<-\n");
    return;
}

int inserir_ELEMENTO_QUALQUER_POS_lista(LISTA *lista, char elemento, int posicao)
{
    int i;
    if(verificar_lista_VAZIA(lista))
    {
        printf("\nERRO!!! LISTA VAZIA!!!\n");
        return 0;
    }
    if(verificar_lista_CHEIA(lista))
    {
        printf("\nERRO!!! LISTA CHEIA!!!\n");
        return 0;
    }
    if(posicao < 0 || posicao > lista->ultimo)
    {
        printf("\nERRO!!! POSICAO INVALIDA!!!\n");
        return 0;
    }
    for(i = lista->ultimo+1; i > posicao; i--)
    {
        lista->elem[i] = lista->elem[i-1];
    }
    lista->elem[i] = elemento;
    lista->ultimo++;
    printf("\nElemento inserido com sucesso\n");
    return 1;

}
void ORDENAR_lista(LISTA *lista, char listaAUXILIAR)
{
    int verifica1, verifica2;
    if(verificar_lista_VAZIA(lista))
    {
        printf("\nERRO!!! LISTA VAZIA!!!\n");
        return;
    }
    for(int i = 0; i <= lista->ultimo; i++)
    {
        for(int j = 0; j < lista->ultimo; j++)
        {
            verifica1=lista->elem[j];
            verifica2=lista->elem[j+1];
            if(verifica1 > verifica2)
            {
                listaAUXILIAR = lista->elem[j];
                lista->elem[j] = lista->elem[j + 1];
                lista->elem[j + 1] = listaAUXILIAR;
            }
        }
    }
    printf("\nLISTA ORDENADA COM SUCESSO");
}
void INVERTER_lista(LISTA *lista, char listaAUXILIAR)
{
    if(verificar_lista_VAZIA(lista))
    {
        printf("\nERRO!!! LISTA VAZIA!!!\n");
        return;
    }
    int contador;
    contador = (lista->ultimo + 1) /2;

    for(int i = 0; i <= contador; i++)
    {
        listaAUXILIAR = lista->elem[i];
        lista->elem[i] =lista->elem[lista->ultimo-i];
        lista->elem[lista->ultimo-i] = listaAUXILIAR;

    }
    printf("\n\nLISTA INVERTIDA COM SUCESSO");
}

int main(void)
{
    LISTA *lista;
    char listaAUXILIAR;
    char elemento;
    int posicao;
    lista = (LISTA *)malloc(sizeof(LISTA));
    if(lista == NULL)
    {
        printf("\nSEM ESPACO SUFICIENTE\n");
        exit(0);
    }
    iniciar_lista(&lista);
    int op;
    do{
        printf("======================================================");
        printf("\n|ESCOLHA UMA OPCAO ABAIXO:                           |\n");
        printf("======================================================");
        printf("\n|1. INSERIR ELEMENTO AO FINAL DA LISTA               |");
        printf("\n|2. MODIFICAR ELEMENTO EXISTENTE DA LISTA            |");
        printf("\n|3. REMOVER ELEMENTO EEXISTENTE DA LISTA             |");
        printf("\n|4. PESQUISAR ELEMENTO NA LISTA                      |");
        printf("\n|5. RETORNAR O TAMANHO DA LISTA                      |");
        printf("\n|6. IMPRIMIR TODOS OS ELEMENTOS DA LISTA             |");
        printf("\n|7. INSERIR UM ELEMENTO EM QUALQUER POSICAO DA LISTA |");
        printf("\n|8. ORDENAR LISTA POR ORDEM ALFABETICA               |");
        printf("\n|9. INVERTER LISTA                                   |");
        printf("\n|0. FINALIZAR EXECUCAO DO PROGRAMA                   |");
        printf("\n======================================================");
        printf("\nOPCAO SELECIONADA: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\nDigite o ELEMENTO a ser inserido: ");

            while(getchar()!= '\n');
            scanf("%c", &elemento);
            if(inserir_FIM_lista(&lista, elemento))
            {
                printf("\nENDERECO inserido com sucesso\n");
            }
            break;

        case 2:
            while(getchar() != '\n');
            printf("\nQual elemento deseja inserir? ->");
            scanf("%c", &elemento);
            printf("\nEm qual posicao? ->");
            scanf("%d", &posicao);
            modificar_ELEMENTO_EXISTENTE_lista(&lista, posicao, elemento);
            break;

        case 3:
            printf("\nQual posicao deseja remover da lista? ->");
            scanf("%d", &posicao);
            remover_ELEMENTO_EXISTENTE_lista(&lista, posicao);
            break;

        case 4:
            printf("\nQual elemento deseja procurar? ->");
            while(getchar() != '\n');
            scanf("%c", &elemento);
            posicao = pesquisar_ELEMENTO_lista(&lista, elemento);
            if((posicao) != -1);
            {
                printf("Elemento na posicao: %d\n", posicao);
            }
            break;

        case 5:
            retornar_TAMANHO_lista(&lista);
            break;

        case 6:
            imprimir_TODOS_ELEMENTOS_lista(&lista);
            break;

        case 7:
            printf("\nQual elemento deseja inserir? ->");
            while(getchar()!='\n');
            scanf("%c", &elemento);
            printf("\nQual posicao deseja inserir? ->");
            scanf("%d", &posicao);
            inserir_ELEMENTO_QUALQUER_POS_lista(&lista, elemento, posicao);

            break;

        case 8:
            ORDENAR_lista(&lista, &listaAUXILIAR);
            break;

        case 9:
            INVERTER_lista(&lista, listaAUXILIAR);
            break;

        case 0:
            printf("\nObrigada por Utilizar o programa!!!!\n\n");
            break;

        default:
            printf("\nOpcao Invalida selecionada\n");
        }
    system("pause");
    system("cls");
    }while(op != 0 );
}
