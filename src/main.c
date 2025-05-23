#include "../include/prototypes.h"

Livro Livros[100]; int total_livros = 0; Emprestimo Emprestimos[100]; int total_emprestimos = 0;

int main(){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    carregar_Arquivos();
    menu();

    return 0;
    
}

/*void emprestar_Livro(){
    system("cls");
    Emprestimo emprestimo;
    char chave_livro[100];
    int encontrado;
    
    printf("\n<-=EMPRESTIMO DE LIVRO=->\n");
    getchar();

    printf("Digite o nome do livro: ");
    fgets(chave_livro, sizeof(chave_livro), stdin);
    chave_livro[strcspn(chave_livro, "\n")] = '\0';
    
    char chave_busca[100];
    strcpy(chave_busca, chave_livro);
    converte_String(chave_busca);
    char *p_livro;
    
    for (int i = 0; i < total_livros; i++)
    {
            
        char temp_titulo[100];
        strcpy(temp_titulo, Livros[i].titulo);
        converte_String(temp_titulo);
        p_livro = strstr(temp_titulo, chave_busca);

        if (p_livro && Livros[i].status == 1)
        {
            printf("\nDigite o usu�rio: ");
            fgets(emprestimo.usuario, sizeof(emprestimo.usuario), stdin);
            emprestimo.usuario[strcspn(emprestimo.usuario, "\n")] = '\0';

            printf("Digite a data de empr�stimo(DD MM AAAA): ");
            scanf("%d %d %d", &emprestimo.data_emprestimo.tm_mday, &emprestimo.data_emprestimo.tm_mon, &emprestimo.data_emprestimo.tm_year);
            emprestimo.data_emprestimo.tm_mon--;
            emprestimo.data_emprestimo.tm_year -= 1900;

            printf("Digite a data de devolu��o(DD MM AAAA): ");
            scanf("%d %d %d", &emprestimo.data_devolucao.tm_mday, &emprestimo.data_devolucao.tm_mon, &emprestimo.data_devolucao.tm_year);
            emprestimo.data_devolucao.tm_mon--;
            emprestimo.data_devolucao.tm_year -= 1900;

            encontrado = 1;
            strcpy(emprestimo.livro_emprestado, Livros[i].titulo);
            Livros[i].status = 0;
            Emprestimos [total_emprestimos] = emprestimo;
            total_emprestimos++;
            break;
        }else{printf("\nLivro n�o encontrado ou Indispon�vel\n");}
    }
    
}
*/