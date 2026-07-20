#include <stdio.h>
#include <locale.h>

/*
 * Exibe o primeiro menu com todos os atributos disponíveis.
 */
void exibirPrimeiroMenu(void) {
    printf("\n==================================================\n");
    printf("          ESCOLHA O PRIMEIRO ATRIBUTO\n");
    printf("==================================================\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
}

/*
 * Exibe o segundo menu sem mostrar o atributo
 * escolhido anteriormente.
 */
void exibirSegundoMenu(int primeiroAtributo) {
    printf("\n==================================================\n");
    printf("           ESCOLHA O SEGUNDO ATRIBUTO\n");
    printf("==================================================\n");

    switch (primeiroAtributo) {
        case 1:
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Numero de Pontos Turisticos\n");
            printf("5 - Densidade Demografica\n");
            break;

        case 2:
            printf("1 - Populacao\n");
            printf("3 - PIB\n");
            printf("4 - Numero de Pontos Turisticos\n");
            printf("5 - Densidade Demografica\n");
            break;

        case 3:
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("4 - Numero de Pontos Turisticos\n");
            printf("5 - Densidade Demografica\n");
            break;

        case 4:
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("5 - Densidade Demografica\n");
            break;

        case 5:
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Numero de Pontos Turisticos\n");
            break;

        default:
            printf("Erro ao montar o segundo menu.\n");
    }
}

/*
 * Limpa os caracteres que ainda estiverem
 * armazenados no buffer do teclado.
 */
void limparBufferEntrada(void) {
    int caractere;

    while (
        (caractere = getchar()) != '\n' &&
        caractere != EOF
    ) {
        /* Apenas remove os caracteres restantes. */
    }
}

/*
 * Lê uma opção numérica e evita problemas
 * quando o usuário digita letras.
 */
int lerOpcao(void) {
    int opcao;

    if (scanf("%d", &opcao) != 1) {
        limparBufferEntrada();
        return 0;
    }

    limparBufferEntrada();

    return opcao;
}

/*
 * Retorna o nome do atributo escolhido.
 */
const char *obterNomeAtributo(int atributo) {
    switch (atributo) {
        case 1:
            return "Populacao";

        case 2:
            return "Area";

        case 3:
            return "PIB";

        case 4:
            return "Numero de Pontos Turisticos";

        case 5:
            return "Densidade Demografica";

        default:
            return "Atributo invalido";
    }
}

/*
 * Retorna o valor do atributo escolhido para uma carta.
 */
double obterValorAtributo(
    int atributo,
    unsigned long int populacao,
    float area,
    float pib,
    int pontosTuristicos,
    float densidadeDemografica
) {
    switch (atributo) {
        case 1:
            return (double)populacao;

        case 2:
            return (double)area;

        case 3:
            return (double)pib;

        case 4:
            return (double)pontosTuristicos;

        case 5:
            return (double)densidadeDemografica;

        default:
            return 0.0;
    }
}

/*
 * Exibe o valor com a unidade correspondente ao atributo.
 */
void exibirValorAtributo(
    int atributo,
    const char *pais,
    double valor
) {
    switch (atributo) {
        case 1:
            printf(
                "%s: %.0f habitantes\n",
                pais,
                valor
            );
            break;

        case 2:
            printf(
                "%s: %.2f km2\n",
                pais,
                valor
            );
            break;

        case 3:
            printf(
                "%s: %.2f bilhoes de dolares\n",
                pais,
                valor
            );
            break;

        case 4:
            printf(
                "%s: %.0f pontos turisticos\n",
                pais,
                valor
            );
            break;

        case 5:
            printf(
                "%s: %.2f hab/km2\n",
                pais,
                valor
            );
            break;

        default:
            printf("Atributo invalido.\n");
    }
}

/*
 * Compara um atributo.
 *
 * Retorno:
 * 1 = Carta 1 venceu
 * 2 = Carta 2 venceu
 * 0 = Empate
 */
int compararAtributo(
    int atributo,
    double valorCarta1,
    double valorCarta2
) {
    /*
     * Para densidade demográfica, o menor valor vence.
     */
    if (atributo == 5) {
        if (valorCarta1 < valorCarta2) {
            return 1;
        } else if (valorCarta2 < valorCarta1) {
            return 2;
        } else {
            return 0;
        }
    } else {
        /*
         * Para os demais atributos, o maior valor vence.
         */
        if (valorCarta1 > valorCarta2) {
            return 1;
        } else if (valorCarta2 > valorCarta1) {
            return 2;
        } else {
            return 0;
        }
    }
}

/*
 * Exibe o vencedor de uma comparação individual.
 */
void exibirVencedorAtributo(
    int vencedor,
    const char *pais1,
    const char *pais2
) {
    const char *resultado;

    /*
     * Uso do operador ternário para definir
     * a mensagem do resultado.
     */
    resultado =
        vencedor == 1
            ? pais1
            : (
                vencedor == 2
                    ? pais2
                    : "Empate"
            );

    if (vencedor == 0) {
        printf("Resultado individual: Empate!\n");
    } else {
        printf(
            "Resultado individual: %s venceu!\n",
            resultado
        );
    }
}

int main(void) {
    setlocale(LC_ALL, "");

    /* ==================================================
       CARTA 1: BRASIL
       ================================================== */

    char pais1[] = "Brasil";
    char codigo1[] = "A01";

    unsigned long int populacao1 = 203080756UL;
    float area1 = 8510417.77f;
    float pib1 = 2173.67f;
    int pontosTuristicos1 = 55;

    float densidadeDemografica1;

    /* ==================================================
       CARTA 2: ARGENTINA
       ================================================== */

    char pais2[] = "Argentina";
    char codigo2[] = "B02";

    unsigned long int populacao2 = 45810000UL;
    float area2 = 2780400.00f;
    float pib2 = 640.59f;
    int pontosTuristicos2 = 45;

    float densidadeDemografica2;

    /* Opções selecionadas pelo jogador. */
    int primeiroAtributo;
    int segundoAtributo;

    /* Controle da validação dos menus. */
    int primeiraOpcaoValida = 0;
    int segundaOpcaoValida = 0;

    /* Valores dos atributos escolhidos. */
    double primeiroValorCarta1;
    double primeiroValorCarta2;

    double segundoValorCarta1;
    double segundoValorCarta2;

    /* Resultados individuais. */
    int vencedorPrimeiroAtributo;
    int vencedorSegundoAtributo;

    /* Soma final dos atributos. */
    double somaCarta1;
    double somaCarta2;

    const char *resultadoFinal;

    /* ==================================================
       CÁLCULO DAS DENSIDADES
       ================================================== */

    densidadeDemografica1 =
        (float)populacao1 / area1;

    densidadeDemografica2 =
        (float)populacao2 / area2;

    /* ==================================================
       EXIBIÇÃO DAS CARTAS
       ================================================== */

    printf("==================================================\n");
    printf("             SUPER TRUNFO DE PAISES\n");
    printf("==================================================\n");

    printf("\nCarta 1\n");
    printf("--------------------------------------------------\n");
    printf("Pais: %s\n", pais1);
    printf("Codigo: %s\n", codigo1);
    printf("Populacao: %lu habitantes\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de dolares\n", pib1);
    printf(
        "Numero de Pontos Turisticos: %d\n",
        pontosTuristicos1
    );
    printf(
        "Densidade Demografica: %.2f hab/km2\n",
        densidadeDemografica1
    );

    printf("\nCarta 2\n");
    printf("--------------------------------------------------\n");
    printf("Pais: %s\n", pais2);
    printf("Codigo: %s\n", codigo2);
    printf("Populacao: %lu habitantes\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de dolares\n", pib2);
    printf(
        "Numero de Pontos Turisticos: %d\n",
        pontosTuristicos2
    );
    printf(
        "Densidade Demografica: %.2f hab/km2\n",
        densidadeDemografica2
    );

    /* ==================================================
       ESCOLHA DO PRIMEIRO ATRIBUTO
       ================================================== */

    do {
        exibirPrimeiroMenu();

        printf("\nDigite a primeira opcao: ");
        primeiroAtributo = lerOpcao();

        switch (primeiroAtributo) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                primeiraOpcaoValida = 1;
                break;

            default:
                printf(
                    "\nOpcao invalida! Escolha um numero de 1 a 5.\n"
                );
                primeiraOpcaoValida = 0;
        }
    } while (primeiraOpcaoValida == 0);

    /* ==================================================
       ESCOLHA DO SEGUNDO ATRIBUTO
       ================================================== */

    do {
        exibirSegundoMenu(primeiroAtributo);

        printf("\nDigite a segunda opcao: ");
        segundoAtributo = lerOpcao();

        switch (segundoAtributo) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                if (segundoAtributo == primeiroAtributo) {
                    printf(
                        "\nEsse atributo ja foi escolhido."
                        " Escolha outro!\n"
                    );

                    segundaOpcaoValida = 0;
                } else {
                    segundaOpcaoValida = 1;
                }

                break;

            default:
                printf(
                    "\nOpcao invalida! Escolha uma opcao"
                    " apresentada no menu.\n"
                );

                segundaOpcaoValida = 0;
        }
    } while (segundaOpcaoValida == 0);

    /* ==================================================
       OBTENÇÃO DOS VALORES ESCOLHIDOS
       ================================================== */

    primeiroValorCarta1 = obterValorAtributo(
        primeiroAtributo,
        populacao1,
        area1,
        pib1,
        pontosTuristicos1,
        densidadeDemografica1
    );

    primeiroValorCarta2 = obterValorAtributo(
        primeiroAtributo,
        populacao2,
        area2,
        pib2,
        pontosTuristicos2,
        densidadeDemografica2
    );

    segundoValorCarta1 = obterValorAtributo(
        segundoAtributo,
        populacao1,
        area1,
        pib1,
        pontosTuristicos1,
        densidadeDemografica1
    );

    segundoValorCarta2 = obterValorAtributo(
        segundoAtributo,
        populacao2,
        area2,
        pib2,
        pontosTuristicos2,
        densidadeDemografica2
    );

    /* ==================================================
       COMPARAÇÕES INDIVIDUAIS
       ================================================== */

    vencedorPrimeiroAtributo = compararAtributo(
        primeiroAtributo,
        primeiroValorCarta1,
        primeiroValorCarta2
    );

    vencedorSegundoAtributo = compararAtributo(
        segundoAtributo,
        segundoValorCarta1,
        segundoValorCarta2
    );

    /* ==================================================
       SOMA DOS ATRIBUTOS
       ================================================== */

    somaCarta1 =
        primeiroValorCarta1 +
        segundoValorCarta1;

    somaCarta2 =
        primeiroValorCarta2 +
        segundoValorCarta2;

    /* ==================================================
       EXIBIÇÃO DO RESULTADO
       ================================================== */

    printf("\n==================================================\n");
    printf("             RESULTADO DA BATALHA\n");
    printf("==================================================\n");

    printf("\nCarta 1: %s\n", pais1);
    printf("Carta 2: %s\n", pais2);

    printf("\n--------------------------------------------------\n");
    printf(
        "Primeiro atributo: %s\n",
        obterNomeAtributo(primeiroAtributo)
    );
    printf("--------------------------------------------------\n");

    exibirValorAtributo(
        primeiroAtributo,
        pais1,
        primeiroValorCarta1
    );

    exibirValorAtributo(
        primeiroAtributo,
        pais2,
        primeiroValorCarta2
    );

    exibirVencedorAtributo(
        vencedorPrimeiroAtributo,
        pais1,
        pais2
    );

    printf("\n--------------------------------------------------\n");
    printf(
        "Segundo atributo: %s\n",
        obterNomeAtributo(segundoAtributo)
    );
    printf("--------------------------------------------------\n");

    exibirValorAtributo(
        segundoAtributo,
        pais1,
        segundoValorCarta1
    );

    exibirValorAtributo(
        segundoAtributo,
        pais2,
        segundoValorCarta2
    );

    exibirVencedorAtributo(
        vencedorSegundoAtributo,
        pais1,
        pais2
    );

    printf("\n--------------------------------------------------\n");
    printf("SOMA DOS ATRIBUTOS\n");
    printf("--------------------------------------------------\n");
    printf("%s: %.2f\n", pais1, somaCarta1);
    printf("%s: %.2f\n", pais2, somaCarta2);

    /*
     * O operador ternário determina o resultado final.
     */
    resultadoFinal =
        somaCarta1 > somaCarta2
            ? "Carta 1 venceu!"
            : (
                somaCarta2 > somaCarta1
                    ? "Carta 2 venceu!"
                    : "Empate!"
            );

    printf("\n==================================================\n");

    if (somaCarta1 > somaCarta2) {
        printf(
            "RESULTADO FINAL: Carta 1 - %s venceu!\n",
            pais1
        );
    } else if (somaCarta2 > somaCarta1) {
        printf(
            "RESULTADO FINAL: Carta 2 - %s venceu!\n",
            pais2
        );
    } else {
        printf("RESULTADO FINAL: Empate!\n");
    }

    printf("Operador ternario: %s\n", resultadoFinal);

    printf("==================================================\n");
    printf("Batalha finalizada com sucesso!\n");
    printf("==================================================\n");

    return 0;
}