def round_robin(processos, quantum, troca_contexto):
    tempo_atual = 0
    fila = []
    ordem_execucao = []
    processos.sort(key=lambda p: p.ingresso)  # Ordena processos por tempo de ingresso
    processos_executados = []
    
    tempos_espera = {p.nome: 0 for p in processos}
    tempos_vida = {p.nome: 0 for p in processos}

    while processos or fila:
        # Adiciona processos que chegaram ao tempo atual
        while processos and processos[0].ingresso <= tempo_atual:
            fila.append(processos.pop(0))

        if fila:
            processo = fila.pop(0)
            ordem_execucao.append(processo.nome)
            exec_time = min(quantum, processo.tempo_restante)  # Tempo de execução
            processo.tempo_restante -= exec_time
            processo.tempo_executado += exec_time
            tempo_atual += exec_time

            # Adiciona novos processos que chegaram durante a execução
            while processos and processos[0].ingresso <= tempo_atual:
                fila.append(processos.pop(0))

            if processo.tempo_restante > 0:
                fila.append(processo)  # Reinsere na fila se ainda não terminou
            else:
                processo.tempo_finalizacao = tempo_atual
                processos_executados.append(processo)
                tempos_vida[processo.nome] = processo.tempo_finalizacao - processo.ingresso
                tempos_espera[processo.nome] = tempos_vida[processo.nome] - processo.duracao

            # Aplica troca de contexto após cada execução
            tempo_atual += troca_contexto
        else:
            # Se não há processos na fila, avança o tempo
            tempo_atual += 1

    # Cálculo dos tempos médios
    tm_vida = sum(tempos_vida.values()) / len(tempos_vida)
    tm_espera = sum(tempos_espera.values()) / len(tempos_espera)

    return ordem_execucao, round(tm_vida, 2), round(tm_espera, 2)
