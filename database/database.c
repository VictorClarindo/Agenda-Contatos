#include "../utils/utils.h"

// Função que pega os contatos salvos em disco (arquivo .txt) e armazena na váriavel listaContatos
int pegarContatos(Contato** listaContatos) {
    FILE* arquivo;
    arquivo = fopen("database/lista_contatos.csv", "r");

    if (arquivo != NULL) {
        int count = -1;
        char linhaArquivo[1024];
        Contato* temp = (Contato*) malloc(sizeof(Contato));

        while(fgets(linhaArquivo, 1023, arquivo) != NULL) {
            *temp = (Contato) CONTATO_MARCADOR_FINAL;
            sscanf(linhaArquivo, "%d,%[^,],%[^,],%[^,],\n", &temp->ddd, temp->numero, temp->nome, temp->email);

            count++;
            if (count != 0) {
                *listaContatos = realloc(*listaContatos, (count+1) * sizeof(Contato));
            }

            (*listaContatos)[count] = *temp;
        }

        free(temp);
        fclose(arquivo);
        return count;
    } 

    **listaContatos = (Contato) CONTATO_MARCADOR_FINAL;
    return 0;
}

// Função que salva em disco (arquivo .txt) todos os contatos na váriavel listaContatos
void salvarContatos(Contato* listaContatos) {
    FILE* arquivo;
    arquivo = fopen("database/lista_contatos.csv", "w");

    int listaTam = listalen(listaContatos);
    for (unsigned int i = 0; i <= listaTam; i++) {
        if (i != listaTam) {
            fprintf(arquivo, "%d,%s,%s,%s,\n", listaContatos[i].ddd, listaContatos[i].numero, 
                listaContatos[i].nome, listaContatos[i].email);
        } else {
            fprintf(arquivo, "%d,%s,%s,%s,", listaContatos[i].ddd, listaContatos[i].numero, 
                listaContatos[i].nome, listaContatos[i].email);
        }
    }

    printf("Lista de contatos salva com sucesso!\n");
    fclose(arquivo);
    return;
}