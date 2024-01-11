#include "../utils.h"

void imprimirLinhaEditar() {
    printf("-------------------------------\n");
}
void imprimirCabecalhoEditar() {
    systemClear();
    imprimirLinhaEditar();
    printf("------- EDITAR CONTATO -------\n");
    imprimirLinhaEditar();
    printf("\n");
}

// Função que edita o contato selecionado a partir da função buscarContato()
void editarContato(Contato* listaContatos) {
    systemClear();
    imprimirCabecalhoEditar();

    Contato* contato = (Contato*) malloc(sizeof(Contato));
    contato = selecionarContatoDaLista(listaContatos);
    if (contato == NULL) {
        printf("\nO ID digitado não existe, cancelando a edição de contatos...\n");
        systemPause();
        return;
    }

    imprimirCabecalhoEditar();
    printf("Informações atuais do contato:\n");
    imprimirCabecalhoLista();
    imprimirContato(contato);

    printf("\n\n");

    imprimirLinhaEditar();
    printf("Preencha os novos dados do contato:\n");
    printf("NOTE: Digite \"-1\" no DDD e deixe vazio nos outros campos caso não deseje editar\n\n");
    Contato* novoContato = (Contato*) malloc(sizeof(Contato));
    pegarNovoContato(novoContato, listaContatos, /*true*/ 1);
    imprimirLinhaEditar();

    if (novoContato->ddd == -1) novoContato->ddd = contato->ddd;
    if (!strcmp(novoContato->numero, "")) strcpy(novoContato->numero, contato->numero);
    if (!strcmp(novoContato->nome, "")) strcpy(novoContato->nome, contato->nome);
    if (!strcmp(novoContato->email, "")) strcpy(novoContato->email, contato->email);

    imprimirCabecalhoEditar();
    printf("\nInformações atualizadas do contato:\n");
    imprimirCabecalhoLista();
    imprimirContato(novoContato);

    int confirmarEdicao;
    printf("\n\n");
    imprimirLinhaEditar();
    printf("Deseja confirmar a edição?\n\n");
    printf("[0] Não\n");
    printf("[1] Sim\n");
    imprimirLinhaEditar();
    printf("\nEscolha [0 - 1]: ");
    scanf("%d", &confirmarEdicao);
    getchar();

    if (confirmarEdicao) {
        contato->ddd = novoContato->ddd;
        strcpy(contato->numero, novoContato->numero);
        strcpy(contato->nome, novoContato->nome);
        strcpy(contato->email, novoContato->email);
        printf("\nEdição concluída com sucesso...\n");
    } else {
        printf("\nEdição revertida com sucesso...\n");
    }

    free(novoContato);
    systemPause();
    return;
}