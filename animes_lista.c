#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    //André Kenji Takahashi

typedef struct lista{
    char nome[70];
    int duracao;
    float nota_imdb;
    struct lista *proximo;
    struct lista *anterior;
} Lista;

typedef struct {
    Lista *inicio;
    Lista *fim;
    int tam;
} Data;

void criando_lista(Data *data){
    data->inicio = NULL;
    data->fim = NULL;
    data->tam = 0;
}

void inserir_inicio(Data *data){
    char nome[70];
    int duracao;
    float nota_imbd;
    printf("\nNome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("Duracao do Anime: ");
    scanf("%d", &duracao);
    printf("Nota do IMDB: ");
    scanf("%f", &nota_imbd);

    Lista *new = malloc(sizeof(Lista));

    if(new != NULL) {
        strcpy(new->nome, nome);
        new->duracao = duracao;
        new->nota_imdb = nota_imbd;
        new->proximo = data->inicio;
        new->anterior = NULL;

        if(data->inicio != NULL) {
            data->inicio->anterior = new;
        } else {
            data->fim = new;
        }
        data->inicio = new;
        data->tam++;
    } else {
        printf("Erro de alocamento de memoria!\n");
        return;
    }
}

void inserir_fim(Data *data){

    char nome[70];
    int duracao;
    float nota_imbd;
    printf("\nNome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("Duracao do Anime: ");
    scanf("%d", &duracao);
    printf("Nota do IMDB: ");
    scanf("%f", &nota_imbd);

    Lista *new = malloc(sizeof(Lista));

    if(new != NULL){
        strcpy(new->nome, nome);
        new->duracao = duracao;
        new->nota_imdb = nota_imbd;
        new->proximo = NULL;
        new->anterior = data->fim;

        if(data->inicio == NULL){
            data->inicio = new;
        } else {
            data->fim->proximo = new;
        }
        data->fim = new;
        data->tam++;
    } else {
        printf("Erro de alocamento de memoria!\n");
    }
}

void exibir(Data *data){
    Lista *atual = data->inicio;

    if(atual == NULL){
        printf("A lista esta vazia!\n");
        return;
    }
    printf("\nListagem dos Animes cadastrados em ordem crescente: ");
    while(atual != NULL) {
        printf("\n\nNome do Anime: %s\n", atual->nome);
        printf("Duracao total: %d minutos\n", atual->duracao);
        printf("Nota do IMDB: %.1f", atual->nota_imdb);
        atual = atual->proximo;
    }
}

void exibir_inverso(Data *data) {

    Lista *atual = data->fim;

    if(atual == NULL){
            printf("A lista esta vazia!\n");
            return;
    }
    printf("Listagem de Animes cadastrados em ordem decrescente: ");
    while(atual != NULL) {
        printf("\n\nNome do Anime: %s\n", atual->nome);
        printf("Duracao total: %d minutos\n", atual->duracao);
        printf("Nota do IMDB: %.1f", atual->nota_imdb);
        atual = atual->anterior;
    }
}

void buscar(Data *data) {
    float nota_imdb;
    int find = 0;
    printf("\n--Para realizar uma  busca digite a nota do IMDB--\n\n");
    printf("Nota: ");
    scanf("%f", &nota_imdb);

    Lista *atual = data->inicio;

    while(atual != NULL){
        if(atual->nota_imdb == nota_imdb){
            printf("\nAnime registrado!\n");
            printf("\nNome do Anime: %s", atual->nome);
            printf("\nDuracao do Anime: %d", atual->duracao);
            printf("\nNota do IMDB: %.1f\n", atual->nota_imdb);
            find = 1;
            break;
        }
        atual = atual->proximo;
    }
    if(find == 0){
        printf("\nCadastro nao encontrado!!\n");
    }
}

Lista *remover(Data *data){
    char nome[70];
    int find = 0;
    printf("\n--Para realizar uma  remocao digite o nome do Anime--\n\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    Lista *aux = data->inicio;
    Lista *remover = NULL;

    while (aux) {
        if (strcmp(aux->nome, nome)==0) {
            remover = aux;
            if(aux->anterior) {
                aux->anterior->proximo = aux->proximo;
            } else {
                data->inicio = aux->proximo;
            }
            if(aux->proximo) {
                aux->proximo->anterior = aux->anterior;
            } else {
                data->fim = aux->anterior;
            }
            data->tam--;
            find = 1;
            break;
        }
        aux = aux->proximo;
    }
    if(find) {
        printf("Anime removido com sucesso!\n");
        free(remover);
    } else {
        printf("Anime nao encontrado!\n");
    }
    return remover;
}

main()
{
    Data *data;
    Lista *removido;
    criando_lista(&data);
    int op;

    printf("\n---Listagem de Animes---\n\n");

    while(1){
        printf("\n--------MENU---------\n");
        printf("\n[1] - Inserir no inicio");
        printf("\n[2] - Inserir no fim");
        printf("\n[3] - Exibir animes ordem crescente");
        printf("\n[4] - Exibir animes ordem decrescente");
        printf("\n[5] - Buscar animes por IMDB");
        printf("\n[6] - Remover anime pelo nome");
        printf("\n[7] - Sair do programa");

        printf("\n\nOpcao desejada:.. ");
        scanf("%d", &op);

        switch(op){

        case 1:
            inserir_inicio(&data);
            break;

        case 2:
            inserir_fim(&data);
            break;

        case 3:
            exibir(&data);
            break;

        case 4:
            exibir_inverso(&data);
            break;

        case 5:
            buscar(&data);
            break;

        case 6:
            remover(&data);
            break;

        case 7:
            printf("Leaving the software..");
            return 0;

        default:
            printf("\nOpcao invalida!!");
        }
    }
    }
