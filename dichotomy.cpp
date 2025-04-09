/* 
 * Autor: Ronaldo Simeone Antonio
 * RA: 190232
 * Descri��o: Programa que calcula a raiz de uma equa��o polinomial
 * de qualquer grau utilizando o m�todo da bissec��o.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Fun��o para receber os coeficientes do polin�mio
void receberCoeficientes(double **coef, int *grau) {
    printf("Digite o grau do polinomio: ");
    scanf("%d", grau);

    *coef = (double *)malloc((*grau + 1) * sizeof(double));

    printf("Digite os coeficientes do polinomio de grau %d (do maior para o menor grau):\n", *grau);
    for (int i = 0; i <= *grau; i++) {
        printf("Coeficiente de x^%d: ", *grau - i);
        scanf("%lf", &(*coef)[i]);
    }
}

// Fun��o que calcula f(x) para um dado x
double calcularFuncao(double x, double *coef, int grau) {
    double resultado = 0.0;
    for (int i = 0; i <= grau; i++) {
        resultado += coef[i] * pow(x, grau - i);
    }
    return resultado;
}

// Verifica se existe raiz no intervalo [a, b]
int verificaIntervalo(double a, double b, double *coef, int grau) {
    double fa = calcularFuncao(a, coef, grau);
    double fb = calcularFuncao(b, coef, grau);
    return (fa * fb < 0);
}

// M�todo da Bissec��o (Dicotomia)
void bisseccao(double a, double b, double erro, double *coef, int grau) {
    double fa, fb, fm, m;
    int iter = 0;

    printf("\nIter\t   a\t\t   b\t\t   m\t\t f(a)\t\t f(b)\t\t f(m)\t\t f(a)*f(m)     f(b)*f(m)\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    do {
        m = (a + b) / 2.0;
        fa = calcularFuncao(a, coef, grau);
        fb = calcularFuncao(b, coef, grau);
        fm = calcularFuncao(m, coef, grau);

        printf("%3d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",
               iter++, a, b, m, fa, fb, fm, fa * fm, fb * fm);

        if (fa * fm < 0)
            b = m;
        else
            a = m;
    } while (fabs(fm) > erro);

    printf("\nRaiz aproximada encontrada: %.6lf com erro < %.6lf\n", m, erro);
}

int main() {
    double *coeficientes;
    int grau;
    double a, b, erro;

    // Receber os dados
    receberCoeficientes(&coeficientes, &grau);

    //Receber intervalo e verificar se existe raiz
    do {
        printf("\nDigite o intervalo [a, b]:\n");
        printf("a: ");
        scanf("%lf", &a);
        printf("b: ");
        scanf("%lf", &b);

        if (!verificaIntervalo(a, b, coeficientes, grau)) {
            printf("f(a) * f(b) >= 0. O intervalo nao contem raiz. Tente novamente.\n");
        } else {
            break;
        }
    } while (1);

    // Receber erro
    printf("Digite o erro toleravel: ");
    scanf("%lf", &erro);

    // Executar m�todo da bissec��o
    bisseccao(a, b, erro, coeficientes, grau);

    // Liberar mem�ria
    free(coeficientes);

    return 0;
}
