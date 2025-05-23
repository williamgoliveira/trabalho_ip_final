#include "../include/prototypes.h"

void registrar_Livro(){
    system("cls");
    Livro livro;

    printf("\n<-=CADASTRO DE LIVROS=->\n");

    printf("\nInforme o ISBN(ID) do livro: ");
    scanf("%d", &livro.isbn);
    getchar();

    printf("Informe o NOME do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

    printf("Informe o AUTOR do livro: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);
    livro.autor[strcspn(livro.autor, "\n")] = '\0';

    printf("Informe o ano de publicação do livro: ");
    scanf("%d", &livro.ano_publicacao);
    getchar();

    printf("Informe a CATEGORIA do livro: ");
    fgets(livro.categoria, sizeof(livro.categoria), stdin);
    livro.categoria[strcspn(livro.categoria, "\n")] = '\0';

    livro.status = 1;

    Livros[total_livros] = livro;
    total_livros++;

    printf("\nLivro Cadastrado com sucesso!\n");
    salvar_Arquivos();
}