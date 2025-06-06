#include "../include/prototypes.h"

void catalogo(){
    
    if (total_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    
    for (int i = 0; i < total_livros; i++)
    {
        printf("\nLivro %d:\n", i+1);
        printf("ID: %d\n", Livros[i].isbn);
        printf("T�tulo: %s\n", Livros[i].titulo);
        printf("Autor: %s\n", Livros[i].autor);
        printf("Ano de Publica��o: %d\n", Livros[i].ano_publicacao);
        printf("Categoria: %s\n", Livros[i].categoria);
        if (Livros[i].status)
        {
            printf("Status: Dispon�vel\n");
        }else{printf("Status: Indispon�vel\n");}
        printf("\n");
        
    }
    
    printf("\nTotal de Livros Cadastrados: %d\n", total_livros);
    printf("\nTotal de Livros Emprestados: %d\n", total_emprestimos);
}