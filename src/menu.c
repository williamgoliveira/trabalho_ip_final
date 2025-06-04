#include "../include/prototypes.h"

void menu(){
    system("cls");
    int escolha;

    while (1)
    {
        printf("\n\t----BIBLIOTECA VIRTUAL----\n");
        printf("\n1. Registrar Livro\n");
        printf("\n2. Mostrar Livros\n");
        printf("\n3. Buscar Livros\n");
        printf("\n4. Emprestar Livro\n");
        printf("\n0. Sair\n");
    
        printf("\nInforme a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
       {
       case 1:registrar_Livro();break;
       case 2:relatorio();break;
       case 3:buscar_Livro(Livros , total_livros);break;
       case 4:emprestar_Livro();break;
       case 0:salvar_Arquivos();printf("ENCERRANDO O PROGRAMA");exit(0);break;
       default:printf("Opção inválida!");
        break;
       }
    
    }
}