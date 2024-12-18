#include <stdio.h>
#include <string.h>

double converter(double valor, char unidade_origem[], char unidade_destino[]) {
    // Fatores de conversão para metros
   double fatores_para_metros[] = {1.0, 0.01, 0.0254, 1609.34, 0.3048, 0.9144,1000};
    char unidades[][15] = {"metros", "centimetros", "polegadas", "milhas", "pes", "jardas","KM"};


    
    int origem = -1, destino = -1;

    // Encontrar os índices das unidades de origem e destino
    for (int i = 0; i < 7; i++) {
        if (strcmp(unidade_origem, unidades[i]) == 0) {
            origem = i;
        }
        if (strcmp(unidade_destino, unidades[i]) == 0) {
            destino = i;
        }
    }

    if (origem == -1 || destino == -1) {
        printf("Unidade inválida. Tente novamente.\n");
        return -1;
    }

    // Converter para metros
    double valor_em_metros = valor * fatores_para_metros[origem];

    // Converter de metros para a unidade de destino
    double valor_convertido = valor_em_metros / fatores_para_metros[destino];

    return valor_convertido;
}

int main() {
    double valor, resultado;
    char unidade_origem[15], unidade_destino[15];

    printf("Conversor de Unidades\n");
    printf("Unidades disponíveis: metros, centimetros, polegadas, milhas\n");

    // Entrada de dados
    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);
    printf("Digite a unidade de origem (metros, centimetros, polegadas, milhas): ");
    scanf("%s", unidade_origem);
    printf("Digite a unidade de destino (metros, centimetros, polegadas, milhas): ");
    scanf("%s", unidade_destino);

    // Realizar a conversão
    resultado = converter(valor, unidade_origem, unidade_destino);

    // Mostrar o resultado
    if (resultado != -1) {
        printf("%.4f %s é igual a %.4f %s\n", valor, unidade_origem, resultado, unidade_destino);
    }

    return 0;
}
