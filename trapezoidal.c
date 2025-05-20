/* 
 * Nome: [Ronaldo Simeone Antonio]
 * RA: [190232]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Fun��o: lerDados
 * ----------------
 * L� os dados de entrada do usu�rio: grau do polin�mio, coeficientes, intervalo [a, b]
 * e o n�mero de subintervalos n.
 *
 * Par�metros:
 *  - grau: ponteiro para armazenar o grau do polin�mio
 *  - coef: ponteiro para vetor de coeficientes (alocado dinamicamente)
 *  - a: ponteiro para limite inferior do intervalo
 *  - b: ponteiro para limite superior do intervalo
 *  - n: ponteiro para o n�mero de subintervalos
 */
void lerDados(int *grau, double **coef, double *a, double *b, int *n) {
    printf("\n--- Entrada de Dados ---\n");
    printf("Informe o grau do polinomio: ");
    scanf("%d", grau);

    // Aloca��o din�mica do vetor de coeficientes
    *coef = (double *)malloc((*grau + 1) * sizeof(double));
    if (*coef == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    // Leitura dos coeficientes do polin�mio
    for (int i = *grau; i >= 0; i--) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%lf", &(*coef)[i]);
    }

    // Leitura dos limites de integra��o
    printf("Intervalo de integracao [a, b]:\n");
    printf("a = ");
    scanf("%lf", a);
    printf("b = ");
    scanf("%lf", b);

    // Leitura do n�mero de divis�es (subintervalos)
    printf("Numero de subintervalos (n): ");
    scanf("%d", n);
}

/*
 * Fun��o: calcularPolinomio
 * -------------------------
 * Calcula o valor do polin�mio em um ponto x, usando os coeficientes fornecidos.
 *
 * Par�metros:
 *  - x: ponto no qual o polin�mio ser� avaliado
 *  - coef: vetor com os coeficientes do polin�mio
 *  - grau: grau do polin�mio
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
 * Fun��o: regraDosTrapezios
 * -------------------------
 * Aplica a Regra dos Trap�zios para estimar a integral do polin�mio no intervalo [a, b].
 *
 * Par�metros:
 *  - a: limite inferior da integral
 *  - b: limite superior da integral
 *  - n: n�mero de subintervalos
 *  - coef: vetor com coeficientes do polin�mio
 *  - grau: grau do polin�mio
 *
 * Retorno:
 *  - Valor aproximado da integral
 */
double regraDosTrapezios(double a, double b, int n, double *coef, int grau) {
    double h = (b - a) / n; // Tamanho de cada subintervalo
    double soma = calcularPolinomio(a, coef, grau) + calcularPolinomio(b, coef, grau);

    // Soma os valores dos pontos intermedi�rios
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        soma += 2 * calcularPolinomio(xi, coef, grau);
    }

    // Retorna a estimativa da integral
    return (h / 2.0) * soma;
}

/*
 * Fun��o: main
 * ------------
 * Fun��o principal que controla o fluxo do programa. Permite ao usu�rio repetir o processo
 * de c�lculo da integral quantas vezes desejar.
 */
int main() {
    int repetir = 1;

    while (repetir) {
        int grau, n;
        double *coef; // Ponteiro para os coeficientes
        double a, b;  // Intervalo [a, b]

        // Leitura dos dados de entrada
        lerDados(&grau, &coef, &a, &b, &n);

        // C�lculo da integral
        double resultado = regraDosTrapezios(a, b, n, coef, grau);

        // Exibi��o do resultado
        printf("\n--- Resultado ---\n");
        printf("Valor aproximado da integral: %.6lf\n", resultado);

        // Libera��o da mem�ria alocada
        free(coef);

        // Pergunta se o usu�rio deseja repetir
        printf("\nDeseja realizar um novo calculo? (1 - Sim / 0 - Nao): ");
        scanf("%d", &repetir);
    }

    printf("Programa encerrado.\n");
    return 0;
}
