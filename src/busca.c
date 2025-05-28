#include "../include/prototypes.h"

char *compare_string(const char *texto, const char *busca);

void buscar_Livro(Livro livros[], int n){
    
    system("cls");
    int opcao;
    char termo[100];
    int encontrados = 0;
    
    
    printf("\nEscolha o tipo de busca:\n");
    printf("1 - Buscar por título\n");
    printf("2 - Buscar por autor\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    getchar(); 
    
    printf("Digite o termo de busca: ");
    fgets(termo, 100, stdin);
    termo[strcspn(termo, "\n")] = '\0'; 
    
    printf("\nResultados da busca:\n");
    
    for (int i = 0; i < n; i++) {
        int match = 0;
        
        if (opcao == 1) {
            // Busca por título (case insensitive)
            if (compare_string(livros[i].titulo, termo) != NULL) {
                match = 1;
            }
        } else if (opcao == 2) {
            // Busca por autor (case insensitive)
            if (compare_string(livros[i].autor, termo) != NULL) {
                match = 1;
            }
        }
        
        if (match) {
            printf("\nLivro %d:\n", i+1);
            printf("Título: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("ISBN: %d\n", livros[i].isbn);
            printf("Gênero: %s\n", livros[i].categoria);
            printf("Ano de Publicação: %d\n", livros[i].ano_publicacao);
            printf("Status:%s\n" , livros[i].status );
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("Nenhum livro encontrado com o termo \"%s\".\n", termo);
    } else {
        printf("\nTotal de livros encontrados: %d\n", encontrados);
    }
}

char *compare_string(const char *texto, const char *busca) {
    if (!busca || !*busca) return (char *)texto; 

    for (; *texto; texto++) {
        if (tolower((unsigned char)*texto) == tolower((unsigned char)*busca)) {
            const char *t = texto, *b = busca;
            while (*t && *b && tolower((unsigned char)*t) == tolower((unsigned char)*b)) {
                t++;
                b++;
            }
            if (!*b) return (char *)texto; 
        }
    }
    return NULL; 
}