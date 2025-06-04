 #include <stdio.h>
 #include <string.h>
 
  struct livro{
     
    char titulo[100];
    char autor[100];
    int ano;
    int disponivel;
};
 
 int main () {
     
struct livro livro1;

strcpy(livro1.titulo, "Dom Casmurro");
strcpy(livro1.autor, "Machado de Assis");
livro1.ano = 1899;
livro1.disponivel = 1;

FILE *arquivo = fopen("livros.bin", "ab");

if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
}

fwrite(&livro1, sizeof(struct livro), 1, arquivo);

fclose(arquivo);

printf("Livro gravado com sucesso!\n\n");

arquivo = fopen("livros.bin", "rb");
if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para leitura!\n");
    return 1;
}

 struct livro temp;
    printf("=== Lista de Livros Salvos ===\n");
    while (fread(&temp, sizeof(struct livro), 1, arquivo) == 1) {
        printf("\nTitulo:     %s\n", temp.titulo);
        printf("Autor:      %s\n", temp.autor);
        printf("Ano:        %d\n", temp.ano);
        printf("Disponivel: %s\n", temp.disponivel ? "Sim" : "Não");
    }

    fclose(arquivo);
return 0; 
}