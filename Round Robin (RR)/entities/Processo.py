class Processo:
    def __init__(self, nome, ingresso, duracao):
        self.nome = nome
        self.ingresso = ingresso
        self.duracao = duracao
        self.tempo_restante = duracao
        self.tempo_finalizacao = 0
        self.tempo_espera = 0
        self.tempo_executado = 0
