# 📌 Algoritmos de Alocação de Recursos

Este repositório contém implementações de algoritmos clássicos para **alocação segura de recursos**, amplamente utilizados em sistemas operacionais e computação concorrente.

## 🏦 Algoritmo do Banqueiro
O **Algoritmo do Banqueiro** é um método utilizado para evitar *deadlocks* em sistemas que gerenciam múltiplos processos solicitando recursos. Ele verifica se um estado de alocação é seguro antes de conceder novos recursos.

### 🔹 Funcionamento
1. Cada processo declara sua demanda máxima de recursos.
2. O sistema mantém um controle dos recursos disponíveis, alocados e necessários.
3. Quando um processo solicita recursos, o sistema verifica se a concessão resultará em um estado seguro.
4. Se o estado continuar seguro, os recursos são alocados; caso contrário, a solicitação é adiada.

## 🔄 Algoritmo Circular
O **Algoritmo Circular** (ou *Circular Wait Prevention*) previne *deadlocks* impondo uma ordem hierárquica na solicitação de recursos. Dessa forma, os processos devem requisitar os recursos em uma sequência predefinida, evitando dependências circulares.

### 🔹 Funcionamento
1. Cada recurso recebe um número de prioridade.
2. Os processos devem requisitar recursos apenas em ordem crescente de prioridade.
3. Se um processo precisar de múltiplos recursos, ele deve solicitar todos de acordo com a hierarquia definida.
4. Isso impede a formação de ciclos de espera e, consequentemente, *deadlocks*.

## 🚀 Conteúdo do Repositório
- Implementações dos algoritmos em diferentes linguagens de programação
- Exemplos práticos e simulações
- Explicação teórica e comentários no código
- Testes e estudos de caso

📌 **Ideal para estudantes e profissionais que desejam entender e aplicar técnicas de gerenciamento de recursos em sistemas concorrentes!**

## Colaboradores:
- Iglésio Oliveira de Carvalho
- Kaio Gabriel de Sousa Carvalho
- Arthur Vieira Melo Silva
