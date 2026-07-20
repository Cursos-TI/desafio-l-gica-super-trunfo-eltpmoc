#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    /* =====================================================
       DADOS PREDEFINIDOS DA CARTA 1
       ===================================================== */

    char estado1[] = "SP";
    char codigo1[] = "A01";
    char nomeCidade1[] = "Sao Paulo";

    int populacao1 = 12325000;
    float area1 = 1521.11f;
    float pib1 = 699.28f;
    int pontosTuristicos1 = 50;

    float densidadePopulacional1;
    float pibPerCapita1;

    /* =====================================================
       DADOS PREDEFINIDOS DA CARTA 2
       ===================================================== */

    char estado2[] = "RJ";
    char codigo2[] = "B02";
    char nomeCidade2[] = "Rio de Janeiro";

    int populacao2 = 6748000;
    float area2 = 1200.25f;
    float pib2 = 300.50f;
    int pontosTuristicos2 = 30;

    float densidadePopulacional2;
    float pibPerCapita2;

    /* =====================================================
       CALCULO DOS ATRIBUTOS DERIVADOS
       ===================================================== */

    densidadePopulacional1 =
        (float)populacao1 / area1;

    densidadePopulacional2 =
        (float)populacao2 / area2;

    /*
     * O PIB foi informado em bilhoes de reais.
     * Por isso, ele e multiplicado por 1 bilhao antes
     * de ser dividido pela populacao.
     */
    pibPerCapita1 =
        (pib1 * 1000000000.0f) / (float)populacao1;

    pibPerCapita2 =
        (pib2 * 1000000000.0f) / (float)populacao2;

    /* =====================================================
       EXIBICAO DAS CARTAS
       ===================================================== */

    printf("============================================\n");
    printf("       SUPER TRUNFO DE CIDADES\n");
    printf("============================================\n");

    printf("\nCarta 1:\n");
    printf("--------------------------------------------\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d habitantes\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf(
        "Numero de Pontos Turisticos: %d\n",
        pontosTuristicos1
    );
    printf(
        "Densidade Populacional: %.2f hab/km2\n",
        densidadePopulacional1
    );
    printf(
        "PIB per Capita: %.2f reais\n",
        pibPerCapita1
    );

    printf("\nCarta 2:\n");
    printf("--------------------------------------------\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d habitantes\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf(
        "Numero de Pontos Turisticos: %d\n",
        pontosTuristicos2
    );
    printf(
        "Densidade Populacional: %.2f hab/km2\n",
        densidadePopulacional2
    );
    printf(
        "PIB per Capita: %.2f reais\n",
        pibPerCapita2
    );

    /* =====================================================
       COMPARACAO ENTRE AS CARTAS
       Atributo escolhido diretamente no codigo: Populacao
       ===================================================== */

    printf("\n============================================\n");
    printf("          COMPARACAO DE CARTAS\n");
    printf("============================================\n");

    printf("\nAtributo escolhido: Populacao\n\n");

    printf(
        "Carta 1 - %s (%s): %d habitantes\n",
        nomeCidade1,
        estado1,
        populacao1
    );

    printf(
        "Carta 2 - %s (%s): %d habitantes\n",
        nomeCidade2,
        estado2,
        populacao2
    );

    /*
     * Para populacao, a carta com o maior valor vence.
     */
    if (populacao1 > populacao2) {
        printf(
            "\nResultado: Carta 1 (%s) venceu!\n",
            nomeCidade1
        );
    } else if (populacao2 > populacao1) {
        printf(
            "\nResultado: Carta 2 (%s) venceu!\n",
            nomeCidade2
        );
    } else {
        printf(
            "\nResultado: As duas cartas empataram!\n"
        );
    }

    printf("\n============================================\n");
    printf("Comparacao finalizada com sucesso!\n");
    printf("============================================\n");

    return 0;
}