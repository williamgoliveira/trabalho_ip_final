#include "../include/prototypes.h"

void relatorio_geral()
{
    if (total_livros == 0)
    {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int emprestados = 0, disponiveis = 0;
    printf("\n");

    for (int i = 0; i < total_livros; i++)
    {
        if (Livros[i].status == 0)
        {
            printf("\n%s (EMPRESTADO)\n", Livros[i].titulo);
            emprestados += 1;
        }
        else
        {
            printf("\n%s (DISPONÍVEL)\n", Livros[i].titulo);
            disponiveis += 1;
        }
    }

    printf("\nLivros emprestados: %d\n\nLivros disponíveis: %d\n\nTotal de livros: %d\n", emprestados, disponiveis, total_livros);
}