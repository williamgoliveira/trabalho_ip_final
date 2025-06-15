#include "../include/prototypes.h"

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define CYAN        "\033[36m"
#define YELLOW      "\033[33m"
#define GREEN       "\033[32m"
#define RED         "\033[31m"
#define PURPLE      "\033[35m"

void menu() {
    system("cls"); // ou system("clear") no Linux/macOS
    int escolha;

    while (1) {
        system("cls"); // limpa a tela a cada loop

        printf("%s%s         L I B R A   T E C H         %s\n", BOLD, UNDERLINE, RESET);
        printf("\n");

        printf("%s[1]%s %sRegistrar Livro%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[2]%s %sMostrar Catálogo%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[3]%s %sBuscar Livros%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[4]%s %sEmprestar Livro%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[5]%s %sRelatório Geral%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[6]%s %sHistórico de Empréstimos%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[7]%s %sDevolução de Livros%s\n", PURPLE, RESET, BOLD, RESET);
        printf("%s[0]%s %sSair%s", PURPLE, RESET, BOLD, RESET);
        printf("\n%s                                      %s\n", UNDERLINE, RESET);
        printf("\n");
        printf("%sInforme a opção desejada: %s", GREEN, RESET);
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                registrar_Livro(); break;
            case 2:
                catalogo(); break;
            case 3:
                buscar_Livro(Livros, total_livros); break;
            case 4:
                emprestar_Livro(); break;
            case 5:
                relatorio_geral(); break;
            case 6:
                relatorio_emprestimos(); break;
            case 7:
                devolver_Livro(); break;
            case 0:
                salvar_Arquivos();
                printf("\n%sENCERRANDO O PROGRAMA...%s\n", RED, RESET);
                exit(0);
            default:
                printf("\n%sOpção inválida!%s\n", RED, RESET);
                break;
        }

        printf("\nPressione ENTER para continuar...");
        getchar(); getchar(); // pausa o programa até pressionar Enter
    }
}