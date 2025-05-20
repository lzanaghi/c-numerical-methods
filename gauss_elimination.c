/*
Nome: Ronaldo Simeone Antonio
RA: 190232
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fun��es principais
void lerDados(int *n, double **x, double **y);
void montarSistema(int n, int grau, double *x, double *y, double **matriz, double *vetorB);
void eliminacaoGauss(int grau, double **matriz, double *vetorB);
void substituicaoReversa(int grau, double **matriz, double *vetorB, double *solucao);
void imprimirPolinomio(int grau, double *coef);

// Fun��o principal
int main() {
    int n, grau;
    double *x, *y;

    // Entrada de dados do usu�rio
    lerDados(&n, &x, &y);

    // Defini��o do grau do polin�mio
    do {
        printf("Informe o grau do polinomio (1 ou 2): ");
        scanf("%d", &grau);
    } while (grau != 1 && grau != 2);

    // Aloca��o da matriz do sistema e vetor B
    double **matriz = (double **)malloc((grau + 1) * sizeof(double *));
    double *vetorB = (double *)malloc((grau + 1) * sizeof(double));
    for (int i = 0; i <= grau; i++) {
        matriz[i] = (double *)malloc((grau + 1) * sizeof(double));
    }

    // Montar o sistema linear pelos m�nimos quadrados
    montarSistema(n, grau, x, y, matriz, vetorB);

    // Exibir sistema montado
    printf("\nSistema Linear:\n");
    for (int i = 0; i <= grau; i++) {
        for (int j = 0; j <= grau; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("= %.2lf\n", vetorB[i]);
    }

    // Resolver o sistema com elimina��o de Gauss
    eliminacaoGauss(grau, matriz, vetorB);

    // Exibir sistema escalonado
    printf("\nSistema ap�s elimina��o de Gauss:\n");
    for (int i = 0; i <= grau; i++) {
        for (int j = 0; j <= grau; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("= %.2lf\n", vetorB[i]);
    }

    // Obter os coeficientes com substitui��o reversa
    double *coef = (double *)malloc((grau + 1) * sizeof(double));
    substituicaoReversa(grau, matriz, vetorB, coef);

    // Exibir resultado final
    imprimirPolinomio(grau, coef);

    // Libera��o de mem�ria alocada dinamicamente
    for (int i = 0; i <= grau; i++) free(matriz[i]);
    free(matriz);
    free(vetorB);
    free(coef);
    free(x);
    free(y);

    return 0;
}

// L� os pontos da fun��o fornecidos pelo usu�rio
void lerDados(int *n, double **x, double **y) {
    printf("Informe a quantidade de pontos: ");
    scanf("%d", n);

    // Aloca��o din�mica para os vetores x e y
    *x = (double *)malloc(*n * sizeof(double));
    *y = (double *)malloc(*n * sizeof(double));

    // Coleta dos pares ordenados
    printf("Digite os pares (x, f(x)):\n");
    for (int i = 0; i < *n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &(*x)[i]);
        printf("f(x[%d]) = ", i);
        scanf("%lf", &(*y)[i]);
    }
}

// Monta o sistema linear normal a partir do m�todo dos m�nimos quadrados
void montarSistema(int n, int grau, double *x, double *y, double **matriz, double *vetorB) {
    for (int i = 0; i <= grau; i++) {
        for (int j = 0; j <= grau; j++) {
            double soma = 0;
            for (int k = 0; k < n; k++) {
                soma += pow(x[k], i + j);
            }
            matriz[i][j] = soma;
        }

        double somaB = 0;
        for (int k = 0; k < n; k++) {
            somaB += y[k] * pow(x[k], i);
        }
        vetorB[i] = somaB;
    }
}

// Aplica o m�todo de elimina��o de Gauss para triangular a matriz
void eliminacaoGauss(int grau, double **matriz, double *vetorB) {
    int n = grau + 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double fator = matriz[j][i] / matriz[i][i];
            for (int k = i; k < n; k++) {
                matriz[j][k] -= fator * matriz[i][k];
            }
            vetorB[j] -= fator * vetorB[i];
        }
    }
}

// Realiza a substitui��o reversa para encontrar os coeficientes do polin�mio
void substituicaoReversa(int grau, double **matriz, double *vetorB, double *solucao) {
    int n = grau + 1;
    for (int i = n - 1; i >= 0; i--) {
        solucao[i] = vetorB[i];
        for (int j = i + 1; j < n; j++) {
            solucao[i] -= matriz[i][j] * solucao[j];
        }
        solucao[i] /= matriz[i][i];
    }
}

// Exibe o polin�mio ajustado na tela
void imprimirPolinomio(int grau, double *coef) {
    printf("\nPolinomio ajustado:\np(x) = ");
    for (int i = 0; i <= grau; i++) {
        if (i > 0 && coef[i] >= 0) printf("+");
        printf("%.4lf", coef[i]);
        if (i > 0) printf("x^%d ", i);
        else printf(" ");
    }
    printf("\n");
}
