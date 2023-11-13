#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Projeto.h"

//João Pedro Lopes - RA: 24.123.071-3

int main() {
    struct Tarefa t[100];
    FILE *arquivo_binario = fopen("tarefas.txt", "rb");
    int cont = 0;
    if (arquivo_binario) {
        while (fread(&t[cont], sizeof(struct Tarefa), 1, arquivo_binario) == 1) {
            cont++;
        }
        fclose(arquivo_binario);
    }#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Projeto.h"

//João Pedro Lopes - RA: 24.123.071-3

//Menu principal que chama as funções
int main() {
    struct Tarefa t[100];
    FILE *arquivo_binario = fopen("tarefas.txt", "rb");
    int cont = 0;
    if (arquivo_binario) {
        while (fread(&t[cont], sizeof(struct Tarefa), 1, arquivo_binario) == 1) {
            cont++;
        }
        fclose(arquivo_binario);
    }

    int posicao = 0;

    while (1) {
        printf(" 1 - Criar\n");
        printf(" 2 - Alterar\n");
        printf(" 3 - Excluir\n");
        printf(" 4 - Listar\n");
        printf(" 5 - Sair\n");
        printf(" 6 - Filtrar\n");
        printf(" 7 - Exportar\n");
        printf("Digite o numero da opcao que deseja usar: ");

        char *p, s_opcao[100];
        char *p_posicao, s_posicao[100];
        int opcao;
        fgets(s_opcao, sizeof(s_opcao), stdin);
        opcao = strtol(s_opcao, &p, 10);

        if (opcao == 1) {
            ler(&t[cont]);
            printf("Tarefa criada!\n\n");
            cont++;
            //opção selecionada pelo usuário, que listará e armazenará uma nova tarefa ao arquivo binário
        } else if (opcao == 2){
           alterar_tarefa(t, cont);
        } else if (opcao == 3) {
            printf("Digite o numero da tarefa que deseja excluir: ");
            fgets(s_posicao, sizeof(s_posicao), stdin);
            posicao = strtol(s_posicao, &p_posicao, 10);
            if (p_posicao == s_posicao || *p_posicao != '\n') {
                printf("Valor invalido!\n\n");
            } else {
                excluir_tarefa(t, &cont, posicao);
                //opção selecionada pelo usuário que irá chamar a função excluir tarefa
        }
        } else if (opcao == 4) {
            printf("Lista:\n\n");
            for (int x = 0; x < cont; x++) {
                printf("Tarefa %d\n", x + 1);
                printf("Prioridade: %d\n", t[x].prioridade);
                printf("Categoria: %s\n", t[x].categoria);
                printf("Descricao: %s\n", t[x].descricao);
                printf("Status: %s\n\n", t[x].status);
            }
            //opção selecionada pelo usuário que fará a listagem de todas as tarefas que estão armazenadas no arquivo binário
        } else if (opcao == 5) {
            arquivo_binario = fopen("tarefas.txt", "wb");
            if (arquivo_binario) {
                fwrite(t, sizeof(struct Tarefa), cont, arquivo_binario);
                fclose(arquivo_binario);
            }
            printf("Saindo\n");
            break;
            //opção selecionada pelo usuário que fará com que o arquivo feche
      } else if (opcao == 6) {
          int opcao_filtro;
          //Menu para escolher o filtro
          printf("Escolha o tipo de filtro:\n");
          printf("1 - Categoria\n");
          printf("2 - Prioridade\n");
          printf("3 - Status\n");
          printf("4 - Categoria e prioridade\n");
          printf("Digite o numero da opcao que deseja usar: ");
          scanf("%d", &opcao_filtro);
          filtrar_tarefas(t, cont, opcao_filtro);
      } int opcao_filtro;
        if (opcao == 7) {
          //Menu para filtrar
              printf("Escolha o tipo de filtro para exportar:\n");
              printf("1 - Categoria\n");
              printf("2 - Prioridade\n");
              printf("3 - Status\n");
              printf("4 - Categoria e Prioridade\n");
              printf("Digite o numero da opcao que deseja usar: ");
              scanf("%d", &opcao_filtro);
              exportar_tarefas(t, cont, opcao_filtro);
      } else {
          printf("Valor invalido!\n\n");
      }
    }
    return 0;
}

    int posicao = 0;

    while (1) {
        printf(" 1 - Criar\n");
        printf(" 2 - Alterar\n");
        printf(" 3 - Excluir\n");
        printf(" 4 - Listar\n");
        printf(" 5 - Sair\n");
        printf(" 6 - Filtrar\n");
        printf("Digite o numero da opcao que deseja usar: ");

        char *p, s_opcao[100];
        char *p_posicao, s_posicao[100];
        int opcao;
        fgets(s_opcao, sizeof(s_opcao), stdin);
        opcao = strtol(s_opcao, &p, 10);

        if (opcao == 1) {
            ler(&t[cont]);
            printf("Tarefa criada!\n\n");
            cont++;
            //opção selecionada pelo usuário, que listará e armazenará uma nova tarefa ao arquivo binário
        } else if (opcao == 2){
           alterar_tarefa(t, cont);
        } else if (opcao == 3) {
            printf("Digite o numero da tarefa que deseja excluir: ");
            fgets(s_posicao, sizeof(s_posicao), stdin);
            posicao = strtol(s_posicao, &p_posicao, 10);
            if (p_posicao == s_posicao || *p_posicao != '\n') {
                printf("Valor invalido!\n\n");
            } else {
                excluir_tarefa(t, &cont, posicao);
                //opção selecionada pelo usuário que irá chamar a função excluir tarefa
        }
        } else if (opcao == 4) {
            printf("Lista:\n\n");
            for (int x = 0; x < cont; x++) {
                printf("Tarefa %d\n", x + 1);
                printf("Prioridade: %d\n", t[x].prioridade);
                printf("Categoria: %s\n", t[x].categoria);
                printf("Descricao: %s\n", t[x].descricao);
                printf("Status: %s\n\n", t[x].status);
            }
            //opção selecionada pelo usuário que fará a listagem de todas as tarefas que estão armazenadas no arquivo binário
        } else if (opcao == 5) {
            arquivo_binario = fopen("tarefas.txt", "wb");
            if (arquivo_binario) {
                fwrite(t, sizeof(struct Tarefa), cont, arquivo_binario);
                fclose(arquivo_binario);
            }
            printf("Saindo\n");
            break;
            //opção selecionada pelo usuário que fará com que o arquivo feche
        } else if (opcao == 6) {
          int opcao_filtro;
            printf("Escolha o tipo de filtro:\n");
            printf("1 - Categoria\n");
            printf("2 - Prioridade\n");
            printf("3 - Status\n");
            printf("4 - Categoria e prioridade\n");
            printf("Digite o numero da opcao que deseja usar: ");
            scanf("%d", &opcao_filtro);
            filtrar_tarefas(t, cont, opcao_filtro);
        }
          else {
            printf("Valor invalido!\n\n");

      }
    }
    return 0;
}
