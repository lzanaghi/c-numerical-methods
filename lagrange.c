/* 
 * Nome: Ronaldo Simeone Antonio
 * RA: 190232
 */

#include <stdio.h>
#include <stdlib.h>

//função para receber os pontos da tabela
void receberPontos(double **x, double **fx, int *n) {
    printf("Digite a quantidade de pontos conhecidos: ");
    scanf("%d", n);

    //alocação dinâmica
    *x = (double*)malloc(*n * sizeof(double));
    *fx = (double*)malloc(*n * sizeof(double));

    if (*x == NULL || *fx == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("Informe os valores de x e f(x):\n");
    
    int i;
	for (i = 0; i < *n; i++) {
        printf("Ponto %d:\n", i + 1);
        printf("  x%d: ", i + 1);
        scanf("%lf", &(*x)[i]);
        printf("  f(x%d): ", i + 1);
        scanf("%lf", &(*fx)[i]);
    }
}

//função para calcular os Lk(x) da interpolação de Lagrange
void calcularLagrange(double *x, double *fx, int n, double x_interp, double *resultado) {
    *resultado = 0.0;
	
	int i;
    for (i = 0; i < n; i++) {
        double L = 1.0;

		int j;
        for (j = 0; j < n; j++) {
            if (i != j)
                L *= (x_interp - x[j]) / (x[i] - x[j]);
        }

        printf("L%d(%.2lf) = %.6lf\n", i, x_interp, L);
        *resultado += fx[i] * L;
    }
}

int main() {
    double *x = NULL, *fx = NULL;
    int n;
    char continuar = 's';

    receberPontos(&x, &fx, &n);

    while (continuar == 's' || continuar == 'S') {
        double x_interp, resultado;

        printf("\nDigite o valor de x a ser interpolado: ");
        scanf("%lf", &x_interp);

        calcularLagrange(x, fx, n, x_interp, &resultado);

        printf("f(%.2lf) = %.6lf\n", x_interp, resultado);

        printf("\nDeseja interpolar outro valor? (s/n): ");
        scanf(" %c", &continuar);
    }

    //liberar memória
    free(x);
    free(fx);

    return 0;
}
