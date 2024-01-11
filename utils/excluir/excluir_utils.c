#include "../utils.h"

void imprimirLinhaExcluir() {
    printf("-------------------------------\n");
}
void imprimirCabecalhoExcluir() {
    systemClear();
    imprimirLinhaExcluir();
    printf("------- EXCLUIR CONTATO -------\n");
    imprimirLinhaExcluir();
    printf("\n");
}

// Função que exclui um contato passado por parâmetro
void excluirContato(Contato** listaContatos) {
    imprimirCabecalhoExcluir();

    Contato* contatoAExcluir = (Contato*) malloc(sizeof(Contato));
    contatoAExcluir = selecionarContatoDaLista(*listaContatos);
    if (contatoAExcluir == NULL) {
        printf("\nO ID digitado não existe, cancelando a exclusão de contatos...\n");
        systemPause();
        return;
    }

    imprimirCabecalhoExcluir();
    printf("Contato selecionado:\n");
    imprimirCabecalhoLista();
    imprimirContato(contatoAExcluir);
    printf("\n\n");
    imprimirLinhaExcluir();
    printf("Deseja confirmar a exclusão?\n\n");
    printf("[0] Não\n");
    printf("[1] Sim\n");
    imprimirLinhaExcluir();
    printf("\nEscolha [0 - 1]: ");
    int confirmar;
    scanf("%d", &confirmar);
    getchar();

    if (confirmar) {
        int indexContatoParaExcluir, qtdContatos = listalen(*listaContatos);
        unsigned int i;

        for (int i=0; i < qtdContatos; i++){
            if (!strcmp((*listaContatos)[i].numero, contatoAExcluir->numero)){
                indexContatoParaExcluir = i;
                break;
            }  
        }

        for (int i = indexContatoParaExcluir; i < qtdContatos; i++) {
            (*listaContatos)[i] = (*listaContatos)[i+1];
        }

            
        *listaContatos = realloc(*listaContatos, (qtdContatos) * sizeof(Contato)); 
        if(*listaContatos == NULL){
            printf("\nErro de alocação de memória, tente novamente...\n");
            systemPause();
            return;
        }

        printf("\nExclusão concluída...\n");
    } else {
        printf("\nExclusão cancelada...\n");
    }

    systemPause();
    return;
}