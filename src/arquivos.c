#include "../include/prototypes.h"

void carregar_Arquivos(){
    FILE *arquivo = fopen("bin_files/livros.bin", "rb");
    FILE *p = fopen("bin_files/emprestimos.bin", "rb");
    if (arquivo == NULL) {
        total_livros = 0;
        return;
    }

    if (p == NULL)
    {
        total_emprestimos = 0;
        return;
    }
    
    fread(&total_livros, sizeof(int), 1, arquivo);
    fread(Livros, sizeof(Livro), total_livros, arquivo);
    fclose(arquivo);
    
    fread(&total_emprestimos, sizeof(int), 1, p);
    fread(Emprestimos, sizeof(Emprestimo), total_emprestimos, p);
    fclose(p);
}

void salvar_Arquivos(){

    FILE *arquivo = fopen("bin_files/livros.bin", "wb");
    FILE *p = fopen("bin_files/emprestimos.bin", "wb");

    fwrite(&total_livros, sizeof(int), 1, arquivo);
    fwrite(Livros, sizeof(Livro), total_livros, arquivo);
    fclose(arquivo);

    fwrite(&total_emprestimos, sizeof(int), 1, p);
    fwrite(Emprestimos, sizeof(Emprestimos), total_emprestimos, p);
    fclose(p);
    
}