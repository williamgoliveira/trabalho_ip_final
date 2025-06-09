#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct
{
    int isbn;
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    char categoria[100];
    int status;
} Livro;

typedef struct
{
    int ID_usuario;
    struct tm data_emprestimo;
    struct tm data_devolucao;
    char livro_emprestado[50];
} Emprestimo;

extern Livro Livros[100];
extern int total_livros;
extern Emprestimo Emprestimos[100];
extern int total_emprestimos;

void menu();

void registrar_Livro();

void relatorio();

void salvar_Arquivos();

void carregar_Arquivos();

void converte_String(char *str);

void buscar_Livro(Livro Livros[100] , int total_livros);

void emprestar_Livro();

void devolver_Livro();

void gerar_Multa();

void catalogo();

void relatorio_geral();

void relatorio_emprestimos();

char *compare_strings(const char *texto, const char *busca);
    
#endif