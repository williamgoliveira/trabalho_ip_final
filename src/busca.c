#include "../include/prototypes.h"

void buscar_Livro(){
    system("cls");
    int escolha;

    printf("\n<-=Buscar Livros=->\n");
    printf("1. Buscar por T�TULO\n");
    printf("2. Buscar por AUTOR\n");
    
    printf("Informe a op��o desejada: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:{
        system("cls");
        char chave_titulo[100];
        char *p_titulo;
        int encontrado = 0;
        
        getchar();
        printf("Pesquisar por T�TULO: ");
        fgets(chave_titulo, sizeof(chave_titulo), stdin);
        chave_titulo[strcspn(chave_titulo, "\n")] = '\0';
        converte_String(chave_titulo);
        
        
        for (int i = 0; i < total_livros; i++)
        {
            
            char temp_titulo[100];
            strcpy(temp_titulo, Livros[i].titulo);
            converte_String(temp_titulo);
            p_titulo = strstr(temp_titulo, chave_titulo);

            if (p_titulo)
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
                }else{printf("Status: Indispon��vel\n");}

                encontrado = 1;
            }
        }
        if (!encontrado)
        {
            printf("Livro n�o encontrado!");
        }
        
        break;
    }
    
    case 2:{
        system("cls");
        getchar();
        
        char chave_autor[100];
        char *p_autor;
        int encontrado = 0;

        printf("Pesquisar por AUTOR: ");
        fgets(chave_autor, sizeof(chave_autor), stdin);
        chave_autor[strcspn(chave_autor, "\n")] = '\0';
        converte_String(chave_autor);
        
        for (int i = 0; i < total_livros; i++)
        {
            char temp_autor[100];
            strcpy(temp_autor, Livros[i].autor);
            converte_String(temp_autor);
            p_autor = strstr(temp_autor, chave_autor);

            if (p_autor)
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
                encontrado = 1;
            }
            
        }
        if (!encontrado)
        {
            printf("Autor n�o encontrado!");
        }
        break;
    }

    default:
        printf("Op��o Inv�lida!");
        break;
    }
}