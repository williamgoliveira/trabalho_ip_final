#include "../include/prototypes.h"

void menu(){
    system("cls");
    int escolha;

    while (1)
    {
        printf("\n\033[1;4m      L I B R A   T E C H      \033[0m\n");
        printf("\n-----------------------------");
        printf("\n\n1. Registrar Livro\n");
        printf("\n2. Mostrar Catálogo\n");
        printf("\n3. Buscar Livros\n");
        printf("\n4. Emprestar Livro\n");
        printf("\n5. Relatório\n");
        printf("\n6. Histórico de Empréstimos\n");
        printf("\n0. Sair\n");
        printf("\n-----------------------------");
        
        printf("\nInforme a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
       {
       case 1:registrar_Livro();break;
       case 2:catalogo();break;
       case 3:buscar_Livro(Livros , total_livros);break;
       case 4:emprestar_Livro();break;
       case 5:relatorio_geral();break;
       case 6:relatorio_emprestimos();break;
       case 0:salvar_Arquivos();printf("ENCERRANDO O PROGRAMA");exit(0);break;
       default:printf("Opção inválida!");
        break;
       }
    
    }
}