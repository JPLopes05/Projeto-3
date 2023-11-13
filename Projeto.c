#include "Projeto.h"
#include <stdio.h>

//João Pedro Lopes - RA: 24.123.071-3

void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
//função responsável por limpar as informações da variável para poder armazenar novas informações

void ler(struct Tarefa *armazena) {
    printf("Prioridade: ");
    scanf("%d", &armazena->prioridade);
    limpa();

    printf("Descricao: ");
    scanf("%299[^\n]", armazena->descricao);
    limpa();

    printf("Categoria: ");
    scanf("%99[^\n]", armazena->categoria);
    limpa();

    printf("Status (1 - Não iniciado, 2 - Em andamento, 3 - Completo): ");
    int escolha_status;
    scanf("%d", &escolha_status);
    limpa();

    switch (escolha_status) {
        case 1:
            strncpy(armazena->status, "Não iniciado", sizeof(armazena->status));
            break;
        case 2:
            strncpy(armazena->status, "Em andamento", sizeof(armazena->status));
            break;
        case 3:
            strncpy(armazena->status, "Completo", sizeof(armazena->status));
            break;
        default:
            printf("Opcao invalida para o status. Definindo como 'Não iniciado'\n");
            strncpy(armazena->status, "Não iniciado", sizeof(armazena->status));
            break;
    }
}
//função responsável por ler as informações do usuário e salvar no arquivo binário

void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao) {
    if (posicao >= 1 && posicao <= *cont) {
        for (int i = posicao - 1; i < *cont - 1; i++) {
            tarefas[i] = tarefas[i + 1];
        }
        (*cont)--;
        printf("Tarefa deletada\n\n");
    } else {
        printf("Posição inválida!\n\n",*cont);
        }
}
//função responsável por excluir alguma tarefa que está armazenada no arquivo binário

void alterar_tarefa(struct Tarefa *tarefas, int cont) {
    int posicao;
    printf("Digite o numero da tarefa que deseja alterar: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= cont) {
        printf("Escolha o campo a ser alterado:\n");
        printf("1 - Prioridade\n");
        printf("2 - Categoria\n");
        printf("3 - Descricao\n");
        printf("4 - Status\n");

        int opcao;
        printf("Digite o numero da opcao que deseja alterar: ");
        scanf("%d", &opcao);

        limpa(); // Limpa o buffer do teclado

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite a nova informacao: ");
            char novaInformacao[300]; // Use o tamanho adequado ao campo que pode ser alterado
            fgets(novaInformacao, sizeof(novaInformacao), stdin);
            novaInformacao[strcspn(novaInformacao, "\n")] = '\0'; // Remove a quebra de linha do final

            switch (opcao) {
                case 1:
                    tarefas[posicao - 1].prioridade = atoi(novaInformacao);
                    break;
                case 2:
                    strncpy(tarefas[posicao - 1].categoria, novaInformacao, sizeof(tarefas[posicao - 1].categoria));
                    break;
                case 3:
                    strncpy(tarefas[posicao - 1].descricao, novaInformacao, sizeof(tarefas[posicao - 1].descricao));
                    break;
                case 4:
                    strncpy(tarefas[posicao - 1].status, novaInformacao, sizeof(tarefas[posicao - 1].status));
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }

            printf("Tarefa alterada!\n\n");
        } else {
            printf("Opcao invalida!\n\n");
        }
    } else {
        printf("Posicao invalida!\n\n");
    }
}
