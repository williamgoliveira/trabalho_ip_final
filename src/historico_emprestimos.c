#include "../include/prototypes.h"

void relatorio_emprestimos()
{
    int ID, flag = 0;
    printf("Digite a ID de um usuário: ");
    scanf("%d", &ID);
    
    for (int i = 0; i < total_emprestimos; i++)
    {
        if (ID == Emprestimos[i].ID_usuario)
        {
            int emp_dia = Emprestimos[i].data_emprestimo.tm_mday,
            emp_mes = Emprestimos[i].data_emprestimo.tm_mon,
            emp_ano = Emprestimos[i].data_emprestimo.tm_year;

            int dev_dia = Emprestimos[i].data_devolucao.tm_mday,
            dev_mes = Emprestimos[i].data_devolucao.tm_mon,
            dev_ano = Emprestimos[i].data_devolucao.tm_year;

            flag = 1;
            printf("\nLivro: %s\n\n", Emprestimos[i].livro_emprestado);
            printf("Emprestado: %02d/%02d/%04d\n\n", emp_dia, emp_mes + 1, emp_ano + 1900);
            printf("Devolução: %02d/%02d/%04d\n\n", dev_dia, dev_mes + 1, dev_ano + 1900);
            printf("\n____________________________\n");
        }
    }

    if (flag == 0)
    {
        printf("Nenhum empréstimo foi feito por essa pessoa.");
    }
}