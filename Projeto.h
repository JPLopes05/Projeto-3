#ifndef PROJETO_H
#define PROJETO_H

struct Tarefa {
  int prioridade;
  char categoria[100];
  char descricao[300];
  char status[100];
};

// Função responsável por limpar as informações da variável para poder armazenar
// novas informações
void limpa();

// Lê e armazena as tarefas
void ler(struct Tarefa *armazena);

// Exclui as tarefas escolhidas
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);

// Altera as tarefas escolhidas
void alterar_tarefa(struct Tarefa *tarefas, int cont);

// Filtra as tarefas por prioridade, categoria, Status e Prioridade/Categoria
void filtrar_tarefas(struct Tarefa *tarefas, int cont, int opcao);

// Exporta as tarefas por prioridade, categoria, Status e Prioridade/Categoria
void exportar_tarefas(struct Tarefa *tarefas, int cont, int opcao);

#endif // PROJETO_H
