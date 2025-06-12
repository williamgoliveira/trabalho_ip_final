#include "../include/prototypes.h"
#include <time.h>

#define MULTA_POR_DIA 2.00

void devolver_Livro(){
    system("cls");

    printf("<=-Devolução de Livro-=>\n");

    if (total_emprestimos == 0)
    {
        printf("Nenhum empréstimo cadastrado.\n");
        return;
    }

    char livro_chave[100];
    
    getchar();
    printf("Informe o nome do livro para devolução: ");
    fgets(livro_chave, sizeof(livro_chave), stdin);
    livro_chave[strcspn(livro_chave, "\n")] = '\0';

    int indice = -1;
    for(int i = 0; i < total_emprestimos; i++)
    {
        if(compare_strings(Emprestimos[i].livro_emprestado, livro_chave) && Emprestimos[i].status_emprestimo == 0)
        {
            indice = i;
            break;
        }
    }

    time_t data_atual = time(NULL);
    struct tm data_esperada_tm = Emprestimos[indice].data_devolucao;
    time_t data_esperada_t = mktime(&data_esperada_tm);

    double atraso = difftime(data_atual, data_esperada_t);

    if (indice = -1 && atraso < 0)
    {
        printf("Termo inválido ou livro não foi emprestado.\n");
    }
    
    if (atraso > 0)
    {
        int dias_atrasados = atraso/84600;
        double multa_gerada = dias_atrasados*MULTA_POR_DIA;

        printf("Livro Devolvido com %d dias de atraso\n", dias_atrasados);
        printf("Multa a ser paga: %.2f\n", multa_gerada);
    }

    else{
        printf("Livro devolvido no praso esperado!\n");
    }

    Emprestimos[indice].status_emprestimo = 1;
    total_emprestimos--;

    for (int i = 0; i < total_livros; i++)
    {
        if (compare_strings(Livros[i].titulo, livro_chave) && Livros[i].status == 0)
        {
            Livros[i].status = 1;
            break;
        }
        
    }
    
    salvar_Arquivos();
    
}