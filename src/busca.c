#include "../include/prototypes.h"

void buscar_Livro(Livro Livros[100], int total_livros)
{
    system("cls");
    int opcao;
    char termo[100];
    int encontrados = 0;
    
    
    printf("\nEscolha o tipo de busca:\n");
    printf("1 - Buscar por t?tulo\n");
    printf("2 - Buscar por autor\n");
    printf("Op??o: ");
    scanf("%d", &opcao);
    getchar();
     
    printf("Digite o termo de busca: ");
    fgets(termo, 100, stdin);
    termo[strcspn(termo, "\n")] = '\0';
    
    printf("\nResultados da busca:\n");
    
    for (int i = 0; i <  total_livros ; i++)
    {
        int match = 0;
        
        if (opcao == 1)
        {
            if (compare_strings(Livros[i].titulo, termo) != NULL)
            {
                match = 1;
            }
        } 
        else if (opcao == 2)
        {
            if (compare_strings(Livros[i].autor, termo) != NULL)
            {
                match = 1;
            }
        }
        
        if (match)
        {
            printf("\nLivro %d:\n", i+1);
            printf("T?tulo: %s\n", Livros[i].titulo);
            printf("Autor: %s\n", Livros[i].autor);
            printf("ISBN: %d\n", Livros[i].isbn);
            printf("G?nero: %s\n", Livros[i].categoria);
            printf("Ano de Publi??o: %d\n", Livros[i].ano_publicacao);

            if (Livros[i].status)
            {
                printf("Status: Dispon?vel\n");
            }
            else
            {
                printf("Status: Indispon?vel\n");
            }
            encontrados++;
        }
    }
    
    if (encontrados == 0)
    {
        printf("Nenhum livro encontrado com o termo \"%s\".\n", termo);
    } 
    else
    {
        printf("\nTotal de livros encontrados: %d\n", encontrados);
    }
}