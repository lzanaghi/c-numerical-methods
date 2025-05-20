/* 
 * Nome: [Ronaldo Simeone Antonio]
 * RA: [190232]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Função: lerDados
 * ----------------
 * Lê os dados de entrada do usuário: grau do polinômio, coeficientes, intervalo [a, b]
 * e o número de subintervalos n.
 *
 * Parâmetros:
 *  - grau: ponteiro para armazenar o grau do polinômio
 *  - coef: ponteiro para vetor de coeficientes (alocado dinamicamente)
 *  - a: ponteiro para limite inferior do intervalo
 *  - b: ponteiro para limite superior do intervalo
 *  - n: ponteiro para o número de subintervalos
 */
void lerDados(int *grau, double **coef, double *a, double *b, int *n) {
    printf("\n--- Entrada de Dados ---\n");
    printf("Informe o grau do polinomio: ");
    scanf("%d", grau);

    // Alocação dinâmica do vetor de coeficientes
    *coef = (double *)malloc((*grau + 1) * sizeof(double));
    if (*coef == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    // Leitura dos coeficientes do polinômio
    for (int i = *grau; i >= 0; i--) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%lf", &(*coef)[i]);
    }

    // Leitura dos limites de integração
    printf("Intervalo de integracao [a, b]:\n");
    printf("a = ");
    scanf("%lf", a);
    printf("b = ");
    scanf("%lf", b);

    // Leitura do número de divisões (subintervalos)
    printf("Numero de subintervalos (n): ");
    scanf("%d", n);
}

/*
 * Função: calcularPolinomio
 * -------------------------
 * Calcula o valor do polinômio em um ponto x, usando os coeficientes fornecidos.
 *
 * Parâmetros:
 *  - x: ponto no qual o polinômio será avaliado
 *  - coef: vetor com os coeficientes do polinômio
 *  - grau: grau do polinômio
 *
 * Retorno:
 *  - Valor de f(x)
 */
double calcularPolinomio(double x, double *coef, int grau) {
    double resultado = 0.0;
    for (int i = grau; i >= 0; i--) {
        resultado += coef[i] * pow(x, i); // coef[i] * x^i
    }
    return resultado;
}

/*
 * Função: regraDosTrapezios
 * -------------------------
 * Aplica a Regra dos Trapézios para estimar a integral do polinômio no intervalo [a, b].
 *
 * Parâmetros:
 *  - a: limite inferior da integral
 *  - b: limite superior da integral
 *  - n: número de subintervalos
 *  - coef: vetor com coeficientes do polinômio
 *  - grau: grau do polinômio
 *
 * Retorno:
 *  - Valor aproximado da integral
 */
double regraDosTrapezios(double a, double b, int n, double *coef, int grau) {
    double h = (b - a) / n; // Tamanho de cada subintervalo
    double soma = calcularPolinomio(a, coef, grau) + calcularPolinomio(b, coef, grau);

    // Soma os valores dos pontos intermediários
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        soma += 2 * calcularPolinomio(xi, coef, grau);
    }

    // Retorna a estimativa da integral
    return (h / 2.0) * soma;
}

/*
 * Função: main
 * ------------
 * Função principal que controla o fluxo do programa. Permite ao usuário repetir o processo
 * de cálculo da integral quantas vezes desejar.
 */
int main() {
    int repetir = 1;

    while (repetir) {
        int grau, n;
        double *coef; // Ponteiro para os coeficientes
        double a, b;  // Intervalo [a, b]

        // Leitura dos dados de entrada
        lerDados(&grau, &coef, &a, &b, &n);

        // Cálculo da integral
        double resultado = regraDosTrapezios(a, b, n, coef, grau);

        // Exibição do resultado
        printf("\n--- Resultado ---\n");
        printf("Valor aproximado da integral: %.6lf\n", resultado);

        // Liberação da memória alocada
        free(coef);

        // Pergunta se o usuário deseja repetir
        printf("\nDeseja realizar um novo calculo? (1 - Sim / 0 - Nao): ");
        scanf("%d", &repetir);
    }

    printf("Programa encerrado.\n");
    return 0;
}
