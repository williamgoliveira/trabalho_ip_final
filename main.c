#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct {
    int isbn;
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    char categoria[100];
    int status;
} Livro;

Livro Livros[100]; int total_livros = 0;

void menu();
void registrar_Livro();
void mostrar_Livro();
void salvar_Arquivos();
void carregar_Arquivos();
void buscar_Livro();

int main(){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    carregar_Arquivos();
    menu();
    
}

void menu(){
    
    system("cls");
    int escolha;

    while (1)
    {
        printf("\n\t----BIBLIOTECA VIRTUAL----\n");
        printf("\n1. Registrar Livro\n");
        printf("\n2. Mostrar Livros\n");
        printf("\n0. Sair\n");
    
        printf("\nInforme a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
       {
       case 1:registrar_Livro();break;
       case 2:mostrar_Livro();break; 
       case 0:salvar_Arquivos();printf("ENCERRANDO O PROGRAMA");exit(0);break;;
       default:printf("Opçãoo inválida!");
        break;
       }
        
    }
}

void carregar_Arquivos(){
    FILE *arquivo = fopen("livros.bin", "rb");
    if (arquivo == NULL) {
        total_livros = 0;
        return;
    }
    
    fread(&total_livros, sizeof(int), 1, arquivo);
    fread(Livros, sizeof(Livro), total_livros, arquivo);
    fclose(arquivo);
}

void salvar_Arquivos(){

    FILE *arquivo = fopen("livros.bin", "wb");

    fwrite(&total_livros, sizeof(int), 1, arquivo);
    fwrite(Livros, sizeof(Livro), total_livros, arquivo);
    fclose(arquivo);
    
}

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

void mostrar_Livro(){
    
    if (total_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    
    for (int i = 0; i < total_livros; i++)
    {
        printf("\nLivro %d:\n", i+1);
        printf("ID: %d\n", Livros[i].isbn);
        printf("Título: %s\n", Livros[i].titulo);
        printf("Autor: %s\n", Livros[i].autor);
        printf("Ano de Publicação: %d\n", Livros[i].ano_publicacao);
        printf("Categoria: %s\n", Livros[i].categoria);
        if (Livros[i].status)
        {
            printf("Status: Disponível\n");
        }else{printf("Status: Indisponível\n");}
        printf("\n");
        
    }
    
    printf("\nTotal de livros Cadastrados: %d\n", total_livros);

}