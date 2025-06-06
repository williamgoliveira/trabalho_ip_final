#include "../include/prototypes.h"
#include <time.h>

void emprestar_Livro() {
    system("cls");
    
    if (total_livros == 0) {
        printf("Nenhum livro cadastrado para empréstimo.\n");
        return;
    }

    char livro[100], usuario[50];
    int dias;

    printf("\n<-= EMPRÉSTIMO DE LIVRO =->\n");
    getchar();
   
    // Input do livro
    printf("Digite o título do livro: ");
    fgets(livro, sizeof(livro), stdin);
    livro[strcspn(livro, "\n")] = '\0';

    // Input do usuï¿½rio
    printf("\nDigite o nome do usuário: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    // Input dos dias
    printf("Digite o prazo em dias: ");
    while(scanf("%d", &dias) != 1 || dias <= 0) {
        printf("Valor inválido! Digite novamente: ");
        while(getchar() != '\n'); // Limpa buffer
    }
    getchar();

    // Busca o livro
    int idx = -1;
    for(int i = 0; i < total_livros; i++) {
        if(compare_strings(Livros[i].titulo, livro) && Livros[i].status == 1) {
            idx = i;
            printf("Livro encontrado: %s\n", Livros[idx].titulo);

            break;
        }
    }

    if(idx == -1) {
        printf("\nLivro não encontrado ou indisponível.\n");
        return;
    }

    // Verifica limite de emprï¿½stimos
    if(total_emprestimos >= 100) {
        printf("Limite máximo de empréstimos atingido!\n");
        return;
    }

    // Atualiza status do livro
    Livros[idx].status = 0;

    // Registra o emprï¿½stimo
    time_t now = time(NULL);
    Emprestimos[total_emprestimos] = (Emprestimo){
        .data_emprestimo = *localtime(&now),
        .data_devolucao = *localtime(&(time_t){now + dias * 86400}),
    };
    strcpy(Emprestimos[total_emprestimos].livro_emprestado, Livros[idx].titulo);
    strcpy(Emprestimos[total_emprestimos].usuario, usuario);
    
    total_emprestimos++;
    salvar_Arquivos();
    
    printf("\nEmpréstimo registrado com sucesso!\n");
    printf("Data de devolução: %02d/%02d/%04d\n",
           Emprestimos[total_emprestimos-1].data_devolucao.tm_mday,
           Emprestimos[total_emprestimos-1].data_devolucao.tm_mon + 1,
           Emprestimos[total_emprestimos-1].data_devolucao.tm_year + 1900);
}