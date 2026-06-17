#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

    struct petShop {
    int ativo;
    int id;
    float peso;
    float preco;
    char raca[20];
    char dono[20];
    char pet[20];
};

void limpar()
{
    system("cls");
}

    struct petShop pedidos[10];
    int pdd=0; //pedidos

void inserir_dados()
{
    if(pdd >= 10) {
        printf("Numero máximo de pedidos atingidos\n");
        return 0;
    }
    printf("ID: ");
    scanf("%d", &pedidos[pdd].id);
    printf("Nome do pet: ");
    scanf("%s", pedidos[pdd].pet);
    printf("Nome do dono: ");
    scanf("%s", pedidos[pdd].dono);
    printf("Raca: ");
    scanf("%s", pedidos[pdd].raca);
    printf("Peso (kg): ");
    scanf("%f", &pedidos[pdd].peso);
    printf("Preco (R$): ");
    scanf("%f", &pedidos[pdd].preco);

    pedidos[pdd].ativo = 1; // marca como ativo, ele deixa ativo é simples
    pdd++;  //aumenta o indice da struct
}

//funcão do menu do petshop
void menu_inicial()
{
    printf(" ----- MENU -----  \n");
    printf("[1] Inserir\n");
    printf("[2] Listar\n");
    printf("[3] Buscar\n");
    printf("[4] Editar\n");
    printf("[5] Excluir\n");
    printf("[6] Sair\n\n");
    printf("> Insira a opção: ");
}

 int main()
{
    int opcao=0;
 //pontuação
setlocale(LC_ALL, "Portuguese");

    while(opcao != 6) { //esse while deixa o programa rodando caso a entrada seja 6, ele sai :0
    menu_inicial();
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
    inserir_dados();        //colocar a função de listagem
    break;

    case 2:
    //star_dados();
    break;

    case 3:
   //uscar_dados();
    break;

    case 4:
   //ditar_dados();
    break;

    case 5:
   //xcluir_dados();
    break;
    }

    while(opcao < 1 || opcao > 6) {
        limpar();
        printf("Digite um valor valido!\n\n");
        menu_inicial();
        scanf("%d", &opcao);
        }
    }
return 0;
}

