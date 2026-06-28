#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 //Primeiro período Ciências da computação
 //inacio, Anderson, Igor e Gabriel Marques

//-----------------------------------------------------------------------------------------------------

                             //ERRRRRRROS

//scanf nas outras strings  CORRIGIDO!! -> tava faltando o  %[^\n] só no editar dados

//barrar função editar,pois pode editar até as que não foram criadas  CORRIGIDO!! -> linhas 189 e 199

//o excluir exclui na lista mas não no buscar  CORRIGIDO!! -> linha 163

//após excluir tudo deve ser printado,pedidos não cadastrados

//arrumar função buscar (após excluir ainda aparece o pedido na função buscar) CORRIGIDO!! -> mesma coisa do terceiro erro

//na função buscar deve mostrar quais estao disponiveis para busca

// ao inserir o numero de pedidos deve limpar a tela antes de printar pedidos maximos excedidos  CORRIGIDO!! linha 66

//se buscar por exemplo 12 aparece deveria printar ivalido ou algo asssim

//se excluir um pedido deve liberar um espaço para um novo pedido  CORRIGIDO!! -> função inserir dados + int main

//----------------------------------------------------------------------------------------------------------


    //registro
    struct petShop {
    int ativo;
    float peso;
    float preco;
    char raca[20];
    char dono[20];
    char pet[20];
    char servico[20];
};
    int npedido;
void limpar()
{
    system("cls");
}

    struct petShop pedidos[10];
    int pdd=0; //pedidos

void inserir_dados()
{
    int pos = -1;
    int i;

    for(i = 0; i < 10; i++) {
        if(pedidos[i].ativo == 0) {
            pos = i;

            break;
        }
    }

    if(pos == -1) {
        limpar();
        printf("Numero maximo de pedidos atingidos\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", pedidos[pos].pet);
    printf("Nome do dono: ");
    scanf(" %[^\n]", pedidos[pos].dono);
    printf("Raca: ");
    scanf(" %[^\n]", pedidos[pos].raca);
    printf("Peso (kg): ");
    scanf("%f", &pedidos[pos].peso);
    printf("servico (banho/tosa):");
    scanf(" %[^\n]", pedidos[pos].servico);


    if(pedidos[pos].peso<=5) {
        pedidos[pos].preco = 30.0;
    }
    else if (pedidos[pos].peso <= 15)
    {
        pedidos[pos].preco = 50.0;
    } else {
        pedidos[pos].preco = 80.0;
    }

    pedidos[pos].ativo = 1;

    if(pos == pdd) {
        pdd++;
    }

    limpar();
    printf("------------------\n");
    printf("Animal cadastrado!\n");
    printf("Pedido: %d\n", pos + 1);
    printf("Valor: R$%.2f\n\n", pedidos[pos].preco);

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
    printf("[6] Sair\n");
    printf("-----------------\n");
    printf("> Insira a opcao: ");
}
//funcão do listar dados
void listar_dados()
{
    limpar();
    if( pdd == 0 ) {
    limpar();
    printf("----------------------------\n");
    printf("Nenhum pedido foi solicitado\n\n");
    return;
    }

    int i;
    for(i=0; i<pdd; i++)

    {
        if (pedidos[i].ativo == 1) {
    printf("\nPedido %d\n", i + 1); // Mostra i+1 para o usuário não ver o zero
    printf("---------------------\n");
    printf("Pet: %s\n", pedidos[i].pet);
    printf("Dono: %s\n", pedidos[i].dono);
    printf("Raca: %s\n", pedidos[i].raca);
    printf("Peso: %.2f kg\n", pedidos[i].peso);
    printf("Preco: R$%.2f\n", pedidos[i].preco);
    printf("servico: %s\n", pedidos[i].servico);
    printf("---------------------\n");
        }
    }
}
void buscar_dados()
{
    limpar();
    if(pdd == 0) {
    printf("----------------------------\n");
    printf("Nenhum pedido foi solicitado\n\n");
    return;
    }

    limpar();

    printf("Numero do pedido(1 a 10): ");
    scanf("%d", &npedido);
    npedido = npedido - 1;

    if(npedido < 0 || npedido >= pdd || pedidos[npedido].ativo == 0) {  //*
    printf("---------------------\n");
    printf("Pedido inexistente!\n");
    printf("---------------------\n");
    return;
}

    printf("---------------------\n");
    printf("Pedido: %d\n", npedido+1);
    printf("---------------------\n");
    printf("Pet: %s\n", pedidos[npedido].pet);
    printf("Dono: %s\n", pedidos[npedido].dono);
    printf("Raca: %s\n", pedidos[npedido].raca);
    printf("Peso: %.2f kg\n", pedidos[npedido].peso);
    printf("Preco: R$%.2f\n", pedidos[npedido].preco);
    printf("servico: %s\n", pedidos[npedido].servico);


    printf("---------------------\n");
}

void editar_dados()
{
    int num;
    limpar();

    if(pdd == 0) //*
    {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("qual pedido deseja editar: ");
    scanf("%d", &num);
    num = num-1;

    if(num < 0 || num >= pdd || pedidos[num].ativo == 0) //*
    {
        printf("Pedido inexistente!\n");
        return;
    }

    printf("\n--- Editando Pedido %d ---\n", num+1);
    printf("Novo Pet: ");
    scanf("%[^\n]", pedidos[num].pet);
    printf("Novo Dono: ");
    scanf("%[^\n]", pedidos[num].dono);
    printf("Nova raca: ");
    scanf("%[^\n]", pedidos[num].raca);
    printf("Novo peso (kg): ");
    scanf("%f", &pedidos[num].peso);
    printf("Novo servico (banho/tosa): ");
    scanf("%[^\n]", pedidos[num].servico);


   if(pedidos[num].peso<=5) {
        pedidos[num].preco = 30.0;
    }
    else if (pedidos[num].peso <= 15)
    {
        pedidos[num].preco = 50.0;
    } else {
        pedidos[num].preco = 80.0;
    }

    limpar();
    printf("------------------\n");
    printf("Dados atualizados!\n");
    printf("Novo Valor: R$%.2f\n\n", pedidos[num].preco);
}

void excluir_dados()
{
    int num;
    limpar();
    if(pdd == 0)
    {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }
    printf("Qual pedido deseja excluir: ");
    scanf("%d", &num);
    num = num - 1;
    if(num < 0 || num >= pdd || pedidos[num].ativo == 0)
    {
        printf("Pedido inexistente!\n");
        return;
    }
    pedidos[num].ativo = 0;
    limpar();
    printf("---------------------\n");
    printf("Pedido %d excluido com sucesso!\n", num + 1);
    printf("---------------------\n");
}


 int main()
{
    int opcao=0;
    int i;
 //pontuação
  setlocale(LC_ALL, "Portuguese");

    for(i = 0; i < 10; i++) {
        pedidos[i].ativo = 0;
    }

    while(opcao != 6) { //esse while deixa o programa rodando caso a entrada seja 6, ele sai :0
    menu_inicial();
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
    inserir_dados();        //colocar a função de listagem
    break;

    case 2:
    listar_dados();
    break;

    case 3:
    buscar_dados();
    break;

    case 4:
    editar_dados();
    break;

    case 5:
    excluir_dados();
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
