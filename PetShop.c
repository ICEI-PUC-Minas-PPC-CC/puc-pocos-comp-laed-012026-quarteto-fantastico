#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#define TAMANHO_VETOR 100

struct Pet {

    char especie[20];

    char raca[20];

    char nomePet[20];

    char dono[20];

    char porte[10];

    float preco;

    int ativo; // 1 = ativo | 0 = inativo

};

// Verifica se há espaço no vetor

int temEspaco(int indice) {

    return indice < TAMANHO_VETOR;

}

// Função para inserir um novo pet

void inserirPet(struct Pet pets[], int *indice, char especie[]) {

    if (!temEspaco(*indice)) {

        printf("\nNão há espaço disponível para novos registros!\n");

        return;

    }

    printf("\n=== Cadastro do Pet ===\n");

    strcpy(pets[*indice].especie, especie);

    printf("Nome do Pet: ");

    scanf(" %19[^\n]", pets[*indice].nomePet);

    printf("Raça: ");

    scanf(" %19[^\n]", pets[*indice].raca);

    printf("Nome do Dono: ");

    scanf(" %19[^\n]", pets[*indice].dono);

    printf("Porte: ");

    scanf(" %9s", pets[*indice].porte);

    printf("Preço do serviço: ");

    scanf("%f", &pets[*indice].preco);

    // Validação básica

    if(strlen(pets[*indice].nomePet) == 0 ||

       strlen(pets[*indice].dono) == 0 ||

       pets[*indice].preco <= 0) {

        printf("\nDados inválidos! Cadastro cancelado.\n");

        return;

    }

    pets[*indice].ativo = 1;

    (*indice)++;

    printf("\nPet cadastrado com sucesso!\n");

}

// Função para listar pets ativos

void listarPets(struct Pet pets[], int quantidade) {

    int encontrou = 0;

    printf("\n========== PETS CADASTRADOS ==========\n");

    for(int i = 0; i < quantidade; i++) {

        if(pets[i].ativo == 1) {

            encontrou = 1;

            printf("\nRegistro %d\n", i + 1);

            printf("-----------------------------\n");

            printf("Espécie: %s\n", pets[i].especie);

            printf("Nome: %s\n", pets[i].nomePet);

            printf("Raça: %s\n", pets[i].raca);

            printf("Dono: %s\n", pets[i].dono);

            printf("Porte: %s\n", pets[i].porte);

            printf("Preço: R$ %.2f\n", pets[i].preco);

        }

    }

    if(!encontrou) {

        printf("\nNenhum pet cadastrado.\n");

    }

    printf("\n======================================\n");

}

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao;

    int indice = 0;

    struct Pet pets[TAMANHO_VETOR];

    do {

        printf("\n=========================================\n");

        printf("             Menu do Petshop             \n");

        printf("=========================================\n");

        printf("1. Serviço de tosa para cachorro\n");

        printf("2. Serviço de tosa para gato\n");

        printf("3. Listar pets cadastrados\n");

        printf("0. Sair\n");

        printf("=========================================\n");

        printf("Escolha uma opção: ");

        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                inserirPet(pets, &indice, "Cachorro");

                break;

            case 2:

                inserirPet(pets, &indice, "Gato");

                break;

            case 3:

                listarPets(pets, indice);

                break;

            case 0:

                printf("\nSaindo do sistema...\n");

                break;

            default:

                printf("\nOpção inválida!\n");

        }

    } while(opcao != 0);

    return 0;

}
