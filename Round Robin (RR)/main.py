from entities.Processo import Processo
import utils.roundRobin

# Definição dos processos
tarefas = [
    Processo("T1", 5, 10),
    Processo("T2", 15, 30),
    Processo("T3", 10, 20),
    Processo("T4", 0, 40)
]

# Parâmetros do escalonador
quantum = 15
troca_contexto = 4

# Executar algoritmo
ordem, tm_vida, tm_espera = utils.roundRobin.round_robin(tarefas, quantum, troca_contexto)

print("Ordem de execução:", " -> ".join(ordem))
print("Tempo médio de vida:", tm_vida, "u.t")
print("Tempo médio de espera:", tm_espera, "u.t")