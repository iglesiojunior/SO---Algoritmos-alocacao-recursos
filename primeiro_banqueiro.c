#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

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

void imprimir_estado_atual(int disponibilidade[], int processos[][NUM_RECURSOS], int recursos[][NUM_RECURSOS], int necessidade[][NUM_RECURSOS]) {
    printf("\nEstado Inicial:\n");
    printf("Disponibilidade: ");
    for (int i = 0; i < NUM_RECURSOS; i++) {
        printf("%d ", disponibilidade[i]);
    }
    printf("\n");
    
    printf("\nProcessos (Alocação Atual):\n");
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < NUM_RECURSOS; j++) {
            printf("%d ", processos[i][j]);
        }
        printf("\n");
    }
    
    printf("\nRecursos Máximos Necessários:\n");
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < NUM_RECURSOS; j++) {
            printf("%d ", recursos[i][j]);
        }
        printf("\n");
    }
    
    printf("\nNecessidade Restante:\n");
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < NUM_RECURSOS; j++) {
            printf("%d ", necessidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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

    imprimir_estado_atual(disponibilidade, processos, recursos, necessidade);
    
    int processos_finalizados = 0;
    while (processos_finalizados < NUM_PROCESSOS) {
        bool encontrou_processo = false;

        for (int i = 0; i < NUM_PROCESSOS; i++) {
            if (!finalizado[i] && pode_atender(necessidade[i], disponivel)) {
                printf("\nProcesso P%d pode ser atendido. Recursos alocados:\n", i);
                for (int j = 0; j < NUM_RECURSOS; j++) {
                    printf("%d ", processos[i][j]);
                }
                printf("\nLiberando recursos após execução do processo P%d\n", i);
                
                for (int j = 0; j < NUM_RECURSOS; j++) {
                    disponivel[j] += processos[i][j];
                }

                finalizado[i] = true;
                sequencia_segura[processos_finalizados++] = i;
                encontrou_processo = true;
                
                printf("Novo estado de disponibilidade: ");
                for (int j = 0; j < NUM_RECURSOS; j++) {
                    printf("%d ", disponivel[j]);
                }
                printf("\n");
            }
        }

        if (!encontrou_processo) {
            printf("\nO sistema está em estado de deadlock! Nenhuma sequência segura encontrada.\n");
            return;
        }
    }

    printf("\nO sistema está em um estado seguro. Sequência segura:\n");
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("P%d ", sequencia_segura[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
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
