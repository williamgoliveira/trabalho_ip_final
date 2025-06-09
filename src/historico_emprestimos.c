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
            printf("%s\n", Emprestimos[i].livro_emprestado);
            printf("Emprestado: %d/%d/%d\n", emp_dia, emp_mes, emp_ano);
            printf("Devolução: %d/%d/%d\n", dev_dia, dev_ano, dev_mes);
        }
    }

    if (flag == 0)
    {
        printf("Nenhum empréstimo foi feito por essa pessoa.");
    }
}