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

void filtrar_tarefas(struct Tarefa *tarefas, int cont, int opcao) {
    char filtro[100]; // Tamanho adequado para categoria, prioridade ou status

    limpa(); // Limpa o buffer do teclado

    // Remova este trecho para a opção 4
    if (opcao != 4) {
        printf("Digite o filtro desejado: ");
        fgets(filtro, sizeof(filtro), stdin);
        filtro[strcspn(filtro, "\n")] = '\0'; // Remove a quebra de linha do final

        if (opcao == 3) {
            // Converte a escolha do usuário para o status correspondente
            switch (atoi(filtro)) {
                case 1:
                    strncpy(filtro, "Não iniciado", sizeof(filtro));
                    break;
                case 2:
                    strncpy(filtro, "Em andamento", sizeof(filtro));
                    break;
                case 3:
                    strncpy(filtro, "Completo", sizeof(filtro));
                    break;
                default:
                    printf("Opcao invalida para o status. Filtrando por todos os status.\n");
                    break;
            }
        }
    }

    // Adiciona uma nova opção para filtrar por categoria e prioridade simultaneamente
    char filtro_categoria[100];
    int filtro_prioridade = -1;

    if (opcao == 4) {
        printf("Digite a categoria desejada: ");
        fgets(filtro_categoria, sizeof(filtro_categoria), stdin);
        filtro_categoria[strcspn(filtro_categoria, "\n")] = '\0'; // Remove a quebra de linha do final

        printf("Digite a prioridade desejada: ");
        scanf("%d", &filtro_prioridade);
        limpa();
    }

    printf("Tarefas filtradas:\n");

    for (int i = 0; i < cont; i++) {
        int condicao;

        switch (opcao) {
            case 1:
                condicao = strcmp(tarefas[i].categoria, filtro) == 0;
                break;
            case 2:
                condicao = tarefas[i].prioridade == atoi(filtro);
                break;
            case 3:
                condicao = strcmp(tarefas[i].status, filtro) == 0;
                break;
            case 4:
                condicao = (strcmp(tarefas[i].categoria, filtro_categoria) == 0) && (tarefas[i].prioridade == filtro_prioridade);
                break;
            default:
                condicao = 0; // Opção inválida
                break;
        }

        if (condicao) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Status: %s\n\n", tarefas[i].status);
        }
    }
}

void exportar_tarefas(struct Tarefa *tarefas, int cont, int opcao) {
    FILE *arquivo_exportado;
    char nome_arquivo[100];
    char filtro_categoria[100];
    int filtro_prioridade = -1;

    limpa();

    if (opcao == 4) {
        printf("Digite a categoria desejada: ");
        fgets(filtro_categoria, sizeof(filtro_categoria), stdin);
        filtro_categoria[strcspn(filtro_categoria, "\n")] = '\0';

        printf("Digite a prioridade desejada: ");
        scanf("%d", &filtro_prioridade);
        limpa();
    } else if (opcao >= 1 && opcao <= 3) {
        printf("Digite o filtro desejado: ");
        fgets(filtro_categoria, sizeof(filtro_categoria), stdin);
        filtro_categoria[strcspn(filtro_categoria, "\n")] = '\0';
    }

    switch (opcao) {
        case 1:
            snprintf(nome_arquivo, sizeof(nome_arquivo), "export_categoria_%s.txt", filtro_categoria);
            break;
        case 2:
            snprintf(nome_arquivo, sizeof(nome_arquivo), "export_prioridade_%d.txt", filtro_prioridade);
            break;
        case 3:
            snprintf(nome_arquivo, sizeof(nome_arquivo), "export_status_%s.txt", filtro_categoria);
            break;
        case 4:
            snprintf(nome_arquivo, sizeof(nome_arquivo), "export_categoria_%s_prioridade_%d.txt", filtro_categoria, filtro_prioridade);
            break;
        default:
            printf("Opcao invalida para exportar.\n");
            return;
    }

    arquivo_exportado = fopen(nome_arquivo, "w");
    if (arquivo_exportado == NULL) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    for (int i = 0; i < cont; i++) {
        int condicao;

        switch (opcao) {
            case 1:
                condicao = strcmp(tarefas[i].categoria, filtro_categoria) == 0;
                break;
            case 2:
                condicao = tarefas[i].prioridade == filtro_prioridade;
                break;
            case 3:
                condicao = strcmp(tarefas[i].status, filtro_categoria) == 0;
                break;
            case 4:
                condicao = (strcmp(tarefas[i].categoria, filtro_categoria) == 0) && (tarefas[i].prioridade == filtro_prioridade);
                break;
            default:
                condicao = 0; // Opção inválida
                break;
        }

        if (condicao) {
            fprintf(arquivo_exportado, "%d, %s, %s, %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].status, tarefas[i].descricao);
        }
    }

    fclose(arquivo_exportado);
    printf("Tarefas exportadas para o arquivo: %s\n", nome_arquivo);
}
