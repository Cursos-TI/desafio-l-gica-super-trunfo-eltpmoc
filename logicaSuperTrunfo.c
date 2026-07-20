#include <stdio.h>
#include <locale.h>

int main(void) {
    /* Configura a localização para exibição de caracteres em português. */
    setlocale(LC_ALL, "");

    /* =====================================================
       DADOS PREDEFINIDOS DA CARTA 1
       ===================================================== */

    char pais1[] = "Brasil";
    char codigo1[] = "A01";

    int populacao1 = 203080756;
    float area1 = 8510417.77f;
    float pib1 = 2173.67f;
    int pontosTuristicos1 = 55;

    float densidadeDemografica1;

    /* =====================================================
       DADOS PREDEFINIDOS DA CARTA 2
       ===================================================== */

    char pais2[] = "Argentina";
    char codigo2[] = "B02";

    int populacao2 = 45810000;
    float area2 = 2780400.00f;
    float pib2 = 640.59f;
    int pontosTuristicos2 = 45;

    float densidadeDemografica2;

    /* Opção escolhida no menu. */
    int opcao;

    /* =====================================================
       CÁLCULO DA DENSIDADE DEMOGRÁFICA
       ===================================================== */

    densidadeDemografica1 =
        (float)populacao1 / area1;

    densidadeDemografica2 =
        (float)populacao2 / area2;

    /* =====================================================
       EXIBIÇÃO DAS CARTAS
       ===================================================== */

    printf("==================================================\n");
    printf("             SUPER TRUNFO DE PAISES\n");
    printf("==================================================\n");

    printf("\nCarta 1\n");
    printf("--------------------------------------------------\n");
    printf("Pais: %s\n", pais1);
    printf("Codigo: %s\n", codigo1);
    printf("Populacao: %d habitantes\n", populacao1);
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
    printf("Populacao: %d habitantes\n", populacao2);
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

    /* =====================================================
       MENU INTERATIVO
       ===================================================== */

    printf("\n==================================================\n");
    printf("          ESCOLHA O ATRIBUTO DA BATALHA\n");
    printf("==================================================\n");

    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");

    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);

    printf("\n==================================================\n");
    printf("              RESULTADO DA BATALHA\n");
    printf("==================================================\n");

    printf("\nCarta 1: %s\n", pais1);
    printf("Carta 2: %s\n", pais2);

    /* =====================================================
       COMPARAÇÃO CONFORME A OPÇÃO ESCOLHIDA
       ===================================================== */

    switch (opcao) {
        case 1:
            /*
             * Na população, a carta com o maior valor vence.
             */
            printf("\nAtributo escolhido: Populacao\n");
            printf(
                "%s: %d habitantes\n",
                pais1,
                populacao1
            );
            printf(
                "%s: %d habitantes\n",
                pais2,
                populacao2
            );

            if (populacao1 > populacao2) {
                printf(
                    "\nResultado: Carta 1 - %s venceu!\n",
                    pais1
                );
            } else if (populacao2 > populacao1) {
                printf(
                    "\nResultado: Carta 2 - %s venceu!\n",
                    pais2
                );
            } else {
                printf("\nResultado: Empate!\n");
            }

            break;

        case 2:
            /*
             * Na área, a carta com o maior valor vence.
             */
            printf("\nAtributo escolhido: Area\n");
            printf(
                "%s: %.2f km2\n",
                pais1,
                area1
            );
            printf(
                "%s: %.2f km2\n",
                pais2,
                area2
            );

            if (area1 > area2) {
                printf(
                    "\nResultado: Carta 1 - %s venceu!\n",
                    pais1
                );
            } else if (area2 > area1) {
                printf(
                    "\nResultado: Carta 2 - %s venceu!\n",
                    pais2
                );
            } else {
                printf("\nResultado: Empate!\n");
            }

            break;

        case 3:
            /*
             * No PIB, a carta com o maior valor vence.
             */
            printf("\nAtributo escolhido: PIB\n");
            printf(
                "%s: %.2f bilhoes de dolares\n",
                pais1,
                pib1
            );
            printf(
                "%s: %.2f bilhoes de dolares\n",
                pais2,
                pib2
            );

            if (pib1 > pib2) {
                printf(
                    "\nResultado: Carta 1 - %s venceu!\n",
                    pais1
                );
            } else if (pib2 > pib1) {
                printf(
                    "\nResultado: Carta 2 - %s venceu!\n",
                    pais2
                );
            } else {
                printf("\nResultado: Empate!\n");
            }

            break;

        case 4:
            /*
             * Nos pontos turísticos, o maior valor vence.
             */
            printf(
                "\nAtributo escolhido: Pontos Turisticos\n"
            );
            printf(
                "%s: %d pontos turisticos\n",
                pais1,
                pontosTuristicos1
            );
            printf(
                "%s: %d pontos turisticos\n",
                pais2,
                pontosTuristicos2
            );

            if (pontosTuristicos1 > pontosTuristicos2) {
                printf(
                    "\nResultado: Carta 1 - %s venceu!\n",
                    pais1
                );
            } else if (
                pontosTuristicos2 > pontosTuristicos1
            ) {
                printf(
                    "\nResultado: Carta 2 - %s venceu!\n",
                    pais2
                );
            } else {
                printf("\nResultado: Empate!\n");
            }

            break;

        case 5:
            /*
             * Na densidade demográfica, a regra é invertida:
             * a carta com o menor valor vence.
             */
            printf(
                "\nAtributo escolhido: Densidade Demografica\n"
            );
            printf(
                "%s: %.2f hab/km2\n",
                pais1,
                densidadeDemografica1
            );
            printf(
                "%s: %.2f hab/km2\n",
                pais2,
                densidadeDemografica2
            );

            if (
                densidadeDemografica1 <
                densidadeDemografica2
            ) {
                printf(
                    "\nResultado: Carta 1 - %s venceu!\n",
                    pais1
                );
            } else if (
                densidadeDemografica2 <
                densidadeDemografica1
            ) {
                printf(
                    "\nResultado: Carta 2 - %s venceu!\n",
                    pais2
                );
            } else {
                printf("\nResultado: Empate!\n");
            }

            break;

        default:
            /*
             * O default trata opções que não existem no menu.
             */
            printf(
                "\nOpcao invalida! Escolha uma opcao de 1 a 5.\n"
            );
    }

    printf("\n==================================================\n");
    printf("Programa finalizado.\n");
    printf("==================================================\n");

    return 0;
}