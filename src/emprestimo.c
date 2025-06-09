#include "../include/prototypes.h"
#include <time.h>

void emprestar_Livro()
{
    system("cls");
    
    if (total_livros == 0)
    {
        printf("Nenhum livro cadastrado para empr�stimo.\n");
        return;
    }

    char livro[100];
    int dias, ID_usuario;

    printf("\n<-= EMPR�STIMO DE LIVRO =->\n");
    getchar();

    printf("Digite o t�tulo do livro: ");
    fgets(livro, sizeof(livro), stdin);
    livro[strcspn(livro, "\n")] = '\0';

    printf("\nDigite o ID do usu�rio: ");
    scanf("%d", &ID_usuario);

    printf("Digite o prazo em dias: ");
    while(scanf("%d", &dias) != 1 || dias <= 0)
    {
        printf("Valor inv�lido! Digite novamente: ");
        while(getchar() != '\n');
    }
    getchar();

    int idx = -1;
    for(int i = 0; i < total_livros; i++)
    {
        if(compare_strings(Livros[i].titulo, livro) && Livros[i].status == 1)
        {
            idx = i;
            printf("Livro encontrado: %s\n", Livros[idx].titulo);

            break;
        }
    }

    if(idx == -1)
    {
        printf("\nLivro n�o encontrado ou indispon�vel.\n");
        return;
    }

    if(total_emprestimos >= 100)
    {
        printf("Limite m�ximo de empr�stimos atingido!\n");
        return;
    }

    Livros[idx].status = 0;

    time_t now = time(NULL);
    Emprestimos[total_emprestimos] = (Emprestimo)
    {
        .data_emprestimo = *localtime(&now),
        .data_devolucao = *localtime(&(time_t){now + dias * 86400}),
    };
    strcpy(Emprestimos[total_emprestimos].livro_emprestado, Livros[idx].titulo);
    Emprestimos[total_emprestimos].ID_usuario = ID_usuario;
    
    total_emprestimos++;
    salvar_Arquivos();
    
    printf("\nEmpr�stimo registrado com sucesso!\n");
    printf("Data de devolu��o: %02d/%02d/%04d\n",
           Emprestimos[total_emprestimos-1].data_devolucao.tm_mday,
           Emprestimos[total_emprestimos-1].data_devolucao.tm_mon + 1,
           Emprestimos[total_emprestimos-1].data_devolucao.tm_year + 1900);
}