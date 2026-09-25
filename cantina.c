#include <stdio.h>

/* ---------- "Caderno" da sessao (variaveis globais) ---------- */
int total_pedidos = 0;
int total_itens = 0;
float faturamento_bruto = 0.0f;
float total_descontos = 0.0f;
float faturamento_final = 0.0f;

/* ---------- Prototipos ---------- */
int ler_inteiro(void);
float ler_float(void);

float preco_produto(int codigo);
int ler_codigo_produto(void);
int ler_quantidade(void);

float obter_percentual(float total);
float calcular_desconto(float total);

void novo_pedido(void);
void calculadora(void);
float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

void simular_desconto(void);
void mostrar_relatorio(void);

/* ---------- main: so coordena ---------- */
int main(void) {
    int opcao;

    do {
        printf("\n================================\n");
        printf("          CANTINA UCB\n");
        printf("================================\n");
        printf("1 - Novo pedido\n");
        printf("2 - Calculadora rapida\n");
        printf("3 - Simular desconto\n");
        printf("4 - Relatorio da sessao\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao: ");
        opcao = ler_inteiro();

        switch (opcao) {
            case 1: novo_pedido();       break;
            case 2: calculadora();       break;
            case 3: simular_desconto();  break;
            case 4: mostrar_relatorio(); break;
            case 0: printf("\nSaindo do programa... ate logo!\n"); break;
            default: printf("\nOpcao invalida! Digite um numero de 0 a 4.\n");
        }
    } while (opcao != 0);

    return 0;
}

/* ---------- Leitura de numeros ---------- */

/* Le um inteiro. Se vier algo que nao e numero, o scanf falha
   e pedimos de novo, ate o usuario digitar certo. */
int ler_inteiro(void) {
    int valor;
    int ok;

    ok = scanf("%d", &valor);
    while (ok != 1) {
        printf("Entrada invalida. Digite um numero: ");
        scanf("%*s");        /* descarta o que foi digitado errado */
        ok = scanf("%d", &valor);
    }
    return valor;
}

/* Igual ao ler_inteiro, mas para numeros com casas decimais */
float ler_float(void) {
    float valor;
    int ok;

    ok = scanf("%f", &valor);
    while (ok != 1) {
        printf("Entrada invalida. Digite um numero: ");
        scanf("%*s");
        ok = scanf("%f", &valor);
    }
    return valor;
}

/* ---------- Cardapio e precos ---------- */

float preco_produto(int codigo) {
    if (codigo == 1) {
        return 12.0f;
    } else if (codigo == 2) {
        return 6.0f;
    } else if (codigo == 3) {
        return 8.0f;
    } else if (codigo == 4) {
        return 7.0f;
    } else if (codigo == 5) {
        return 4.0f;
    } else {
        return 0.0f; /* codigo invalido */
    }
}

/* Repete ate o usuario digitar um codigo de 1 a 5 */
int ler_codigo_produto(void) {
    int codigo;

    do {
        printf("Codigo do produto (1-Sanduiche 2-Refri 3-Suco 4-Salgado 5-Cafe): ");
        codigo = ler_inteiro();
        if (codigo < 1 || codigo > 5) {
            printf("Codigo invalido! Escolha de 1 a 5.\n");
        }
    } while (codigo < 1 || codigo > 5);

    return codigo;
}

/* Repete ate a quantidade ser maior que zero */
int ler_quantidade(void) {
    int quantidade;

    do {
        printf("Quantidade: ");
        quantidade = ler_inteiro();
        if (quantidade <= 0) {
            printf("Quantidade invalida! Digite um numero maior que zero.\n");
        }
    } while (quantidade <= 0);

    return quantidade;
}

/* ---------- Regra de desconto (escrita uma unica vez) ---------- */

float obter_percentual(float total) {
    if (total >= 100.0f) {
        return 15.0f;
    } else if (total >= 60.0f) {
        return 10.0f;
    } else if (total >= 30.0f) {
        return 5.0f;
    } else {
        return 0.0f;
    }
}

float calcular_desconto(float total) {
    return total * obter_percentual(total) / 100.0f;
}

/* ---------- Opcao 1: Novo pedido ---------- */

void novo_pedido(void) {
    int codigo, quantidade;
    int continuar;
    int itens_do_pedido = 0;
    float subtotal;
    float total_bruto = 0.0f;
    float desconto, total_final;

    printf("\n[Novo pedido]\n");

    /* varios itens: do...while garante pelo menos um */
    do {
        codigo = ler_codigo_produto();
        quantidade = ler_quantidade();

        subtotal = preco_produto(codigo) * quantidade;
        total_bruto = total_bruto + subtotal;        /* acumulador */
        itens_do_pedido = itens_do_pedido + quantidade;

        printf("Subtotal do item: R$ %.2f | Total parcial: R$ %.2f\n",
               subtotal, total_bruto);

        printf("Adicionar outro item? 1-Sim / 0-Nao: ");
        continuar = ler_inteiro();

    } while (continuar == 1);

    desconto = calcular_desconto(total_bruto);
    total_final = total_bruto - desconto;

    printf("\n================================\n");
    printf("        RESUMO DO PEDIDO\n");
    printf("================================\n");
    printf("Itens registrados: %d\n", itens_do_pedido);
    printf("Total bruto:  R$ %.2f\n", total_bruto);
    printf("Desconto:     R$ %.2f\n", desconto);
    printf("Total final:  R$ %.2f\n", total_final);
    printf("================================\n");
    printf("Pedido registrado com sucesso!\n");

    /* escreve no "caderno" da sessao */
    total_pedidos = total_pedidos + 1;
    total_itens = total_itens + itens_do_pedido;
    faturamento_bruto = faturamento_bruto + total_bruto;
    total_descontos = total_descontos + desconto;
    faturamento_final = faturamento_final + total_final;
}

/* ---------- Opcao 2: Calculadora rapida ---------- */

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

/* So deve ser chamada quando b for diferente de zero */
float dividir(float a, float b) {
    return a / b;
}

void calculadora(void) {
    int opcao;
    float a, b;

    do {
        printf("\n=== CALCULADORA ===\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        opcao = ler_inteiro();

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite o primeiro numero: ");
            a = ler_float();
            printf("Digite o segundo numero: ");
            b = ler_float();
        }

        switch (opcao) {
            case 1:
                printf("Resultado: %.2f\n", somar(a, b));
                break;
            case 2:
                printf("Resultado: %.2f\n", subtrair(a, b));
                break;
            case 3:
                printf("Resultado: %.2f\n", multiplicar(a, b));
                break;
            case 4:
                if (b == 0.0f) {
                    printf("Erro: nao e possivel dividir por zero.\n");
                } else {
                    printf("Resultado: %.2f\n", dividir(a, b));
                }
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Digite um numero de 0 a 4.\n");
        }
    } while (opcao != 0);
}

/* ---------- Opcao 3: Simular desconto ---------- */

void simular_desconto(void) {
    float valor, percentual, desconto, total_final;

    printf("\n[Simular desconto]\n");
    printf("Valor da compra: ");
    valor = ler_float();

    percentual = obter_percentual(valor);
    desconto = calcular_desconto(valor);
    total_final = valor - desconto;

    printf("\nFaixa encontrada: %.0f%%\n", percentual);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Valor final: R$ %.2f\n", total_final);
}

/* ---------- Opcao 4: Relatorio ---------- */

void mostrar_relatorio(void) {
    printf("\n======= RELATORIO =======\n");
    printf("Pedidos realizados:   %d\n", total_pedidos);
    printf("Itens vendidos:       %d\n", total_itens);
    printf("Faturamento bruto:    R$ %.2f\n", faturamento_bruto);
    printf("Descontos concedidos: R$ %.2f\n", total_descontos);
    printf("Faturamento final:    R$ %.2f\n", faturamento_final);
    printf("=========================\n");
}