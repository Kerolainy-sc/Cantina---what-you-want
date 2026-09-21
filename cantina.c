#include <stdio.h>
#include <stdlib.h>

int totalPedidos = 0;
int totalItens = 0;

float faturamentoBruto = 0.0;
float descontos = 0.0;
float faturamentoFinalS = 0.0;

int main() {
   int opcaoMenu;

   do{

    printf("\n-------------------------------------\n");
    printf("        Cantina - WHAT YOU WANT?        \n");
    printf("----------------------------------------\n");

        printf("1 - FAZER PEDIDO <3\n");
        printf("2 - CALCULADORA RAPIDA\n");
        printf("3 - SIMULAR DESCONTO -_-\n");
        printf("4 - RELATORIO DA SESSAO\n");
        printf("0 - SAIR \n");
        printf("----------------------------------\n");
        printf("Escolha uma opcao: :)");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                printf("\n[ Modulo Novo Pedido]\n");
                break;
            case 2:
                printf("\n[ Calculadora Rapida]\n");
                break;
            case 3:
                printf("\n[Simular Desconto]\n");
                break;
            case 4:
                printf("\n[] Relatorio da Sessao]\n");
                break;
            case 0:
                printf("\nSaindo do programa... bye bye!\n");
                break;
            default:
                printf("\nOpcao invalida! Digite um numero de 0 a 4.\n");
        }

    } while (opcaoMenu != 0); // Repete enquanto NAO for 0

   }