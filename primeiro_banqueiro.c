#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSOS 3
#define NUM_RECURSOS 4

bool pode_atender(int necessidade[], int disponibilidade[]) {
    for (int i = 0; i < NUM_RECURSOS; i++) {
        if (necessidade[i] > disponibilidade[i]) {
            return false;
        }
    }
    return true;
}

void algoritmo_banqueiro(int disponibilidade[], int processos[][NUM_RECURSOS], int recursos[][NUM_RECURSOS]) {
    int necessidade[NUM_PROCESSOS][NUM_RECURSOS];
    int sequencia_segura[NUM_PROCESSOS];
    bool finalizado[NUM_PROCESSOS] = {false};
    int disponivel[NUM_RECURSOS];

    for (int i = 0; i < NUM_RECURSOS; i++) {
        disponivel[i] = disponibilidade[i];
    }

    for (int i = 0; i < NUM_PROCESSOS; i++) {
        for (int j = 0; j < NUM_RECURSOS; j++) {
            necessidade[i][j] = recursos[i][j] - processos[i][j];
        }
    }

    int processos_finalizados = 0;
    while (processos_finalizados < NUM_PROCESSOS) {
        bool encontrou_processo = false;

        for (int i = 0; i < NUM_PROCESSOS; i++) {
            if (!finalizado[i] && pode_atender(necessidade[i], disponivel)) {

                for (int j = 0; j < NUM_RECURSOS; j++) {
                    disponivel[j] += processos[i][j]; 
                }

                finalizado[i] = true;
                sequencia_segura[processos_finalizados++] = i;
                encontrou_processo = true;
            }
        }

        if (!encontrou_processo) {
            printf("O sistema está em estado de deadlock! Nenhuma sequência segura encontrada.\n");
            return;
        }
    }

    printf("O sistema está em um estado seguro. Sequência segura:\n");
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("P%d ", sequencia_segura[i]);
    }
    printf("\n");
}

int main() {
    int recursos_totais[] = {5, 3, 7, 5};
    int disponibilidade[] = {3, 1, 1, 2};
    int processos[NUM_PROCESSOS][NUM_RECURSOS] = {
        {1, 2, 2, 1}, 
        {1, 0, 3, 3}, 
        {1, 1, 1, 0}
    };
    int recursos[NUM_PROCESSOS][NUM_RECURSOS] = {
        {3, 3, 2, 2},
        {1, 2, 3, 4},
        {1, 1, 5, 0}
    };

    algoritmo_banqueiro(disponibilidade, processos, recursos);

    return 0;
}
