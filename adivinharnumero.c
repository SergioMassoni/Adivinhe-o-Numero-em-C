#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num, palpite, tentativas;
    char continuar;
    const int limite_tentativas = 3;

    srand((unsigned int)time(NULL));

    do {
        num = (rand() % 5) + 1;
        tentativas = 0;

        printf("\nAdivinhe o numero sorteado de 1 ate 5.\n");

        while (tentativas < limite_tentativas) {
            printf("Tentativa %d de %d. Informe seu palpite: ", tentativas + 1, limite_tentativas);
            scanf("%d", &palpite);
            tentativas++;

            if (palpite > num) {
                printf("Seu palpite e maior que o numero sorteado.\n");
            } else if (palpite < num) {
                printf("Seu palpite e menor que o numero sorteado.\n");
            } else {
                printf("Parabens! Voce acertou em %d tentativa(s).\n", tentativas);
                break;
            }
        }

        if (palpite != num) {
            printf("Voce atingiu o limite de tentativas.\n");
        }

        printf("O numero sorteado era: %d\n", num);
        printf("Deseja continuar jogando? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Obrigado por jogar!\n");
    return 0;
}