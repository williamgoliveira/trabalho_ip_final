#include "../include/prototypes.h"
#include <time.h>

void emprestar_Livro()
{
    system("cls");
    
    if (total_livros == 0)
    {
        printf("Nenhum livro cadastrado para empréstimo.\n");
        return;
    }

    char livro[100];
    int prazo, ID_usuario;

    printf("\n<-= EMPRÉSTIMO DE LIVRO =->\n");
    getchar();

    printf("Digite o título do livro: ");
    fgets(livro, sizeof(livro), stdin);
    livro[strcspn(livro, "\n")] = '\0';

    printf("\nDigite o ID do usuário: ");
    scanf("%d", &ID_usuario);

    printf("Digite o prazo em dias: ");
    while(scanf("%d", &prazo) != 1 || prazo <= 0)
    {
        printf("Valor inválido! Digite novamente: ");
        while(getchar() != '\n');
    }
    getchar();

    int indice = -1;
    for(int i = 0; i < total_livros; i++)
    {
        if(compare_strings(Livros[i].titulo, livro) && Livros[i].status == 1)
        {
            indice = i;
            break;
        }
    }

    if(indice == -1)
    {
        printf("\nLivro não encontrado ou indisponível.\n");
        return;
    }

    if(total_emprestimos >= 100)
    {
        printf("Limite máximo de empréstimos atingido!\n");
        return;
    }

    Livros[indice].status = 0;

    time_t data_atual_t = time(NULL);
    time_t data_devolucao_t = data_atual_t + (prazo * 86400);
    
    struct tm tm_emprestimo = *localtime(&data_atual_t);
    struct tm tm_devolucao = *localtime(&data_devolucao_t);

    Emprestimos[total_emprestimos].data_emprestimo = tm_emprestimo; 
    Emprestimos[total_emprestimos].data_devolucao = tm_devolucao;
    Emprestimos[total_emprestimos].status_emprestimo = 0;
    
    strcpy(Emprestimos[total_emprestimos].livro_emprestado, Livros[indice].titulo);
    Emprestimos[total_emprestimos].ID_usuario = ID_usuario;

    Emprestimos[total_emprestimos].prazo_devolucao = prazo;
    
    total_emprestimos++;
    salvar_Arquivos();
    
    printf("\nEmpréstimo registrado com sucesso!\n");
    printf("Data de devolução: %02d/%02d/%04d\n",
           Emprestimos[total_emprestimos-1].data_devolucao.tm_mday,
           Emprestimos[total_emprestimos-1].data_devolucao.tm_mon + 1,
           Emprestimos[total_emprestimos-1].data_devolucao.tm_year + 1900);
}