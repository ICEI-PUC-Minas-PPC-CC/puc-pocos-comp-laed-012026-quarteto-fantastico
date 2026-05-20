#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao = 2;

    switch (opcao) {
        case 1:
            printf("Serviço Desejado. \n");
            break;
        case 2:
            printf("Indique seu Horário. \n");
            break;
        default:
            printf("Horário Indisponível! \n");
    }

    return 0;
}
