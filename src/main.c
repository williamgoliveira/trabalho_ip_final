#include "../include/prototypes.h"

Livro Livros[100]; 
int total_livros = 0; 
Emprestimo Emprestimos[100]; 
int total_emprestimos = 0;

int main()
{
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
    
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    carregar_Arquivos();
    menu();

    return 0;
}