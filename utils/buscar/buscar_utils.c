#include "../utils.h"

void imprimirLinhaBuscar() {
    printf("------------------------------\n");
}

void imprimirCabecalhoBuscar() {
    systemClear();
    imprimirLinhaBuscar();
    printf("------- BUSCAR CONTATO -------\n");
    imprimirLinhaBuscar();
    printf("\n");
}

void imprimirNaoEncontrado() {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~/NENHUM CONTATO ENCONTRADO/~~~~~~~~~~~~~~~~~~~~~~");
}

void buscarDdd(Contato *contatos) {
    int dddBusca;
    printf("\nDDD a ser buscado: ");
    scanf("%d", &dddBusca);
    getchar();

    imprimirCabecalhoBuscar();
    //Repetindo a formatação da agenda
    imprimirCabecalhoLista();
    int i, qtdEncontrados = 0, qtdContatos = listalen(contatos);
    //printf("qtdContatos = %d\n", qtdContatos);
    systemPause();
    for (i = 0; i < qtdContatos; i++) {
        if (dddBusca == contatos[i].ddd) {
            qtdEncontrados++;
            imprimirContato(&contatos[i]);
        }
    }
    if (qtdEncontrados == 0) {
        imprimirNaoEncontrado();
    }
        
    printf("\n");
    return;  
}

void buscarNumero(Contato *contatos) { 
    char numeroBusca[NUMERO_LIMITE];
    printf("\nNúmero a ser buscado: ");
    scanf("%s", numeroBusca);
    getchar();

    int i, qtdEncontrados = 0, qtdContatos = listalen(contatos);
    imprimirCabecalhoBuscar();
    imprimirCabecalhoLista();
    for (i = 0; i < qtdContatos; i++){
        if (!strcmp(contatos[i].numero, numeroBusca)){
            qtdEncontrados++;
            imprimirContato(&contatos[i]);
        }
    }
    if (qtdEncontrados == 0) {
        imprimirNaoEncontrado();
    }
        
    printf("\n");
    return;   
}

void buscarEmail(Contato *contatos) { 
    char emailBusca[STR_LIMITE];

    printf("\nE-mail a ser buscado: ");  
    scanf("%s", emailBusca);
    getchar();

    int i, qtdEncontrados = 0, qtdContatos = listalen(contatos);
    imprimirCabecalhoBuscar();
    imprimirCabecalhoLista();
    for (i = 0; i < qtdContatos; i++){
        if (!strcmp(contatos[i].email, emailBusca)){
            qtdEncontrados++;
            imprimirContato(&contatos[i]);
        }
    }
    if (qtdEncontrados == 0) {
        imprimirNaoEncontrado();
    }
        
    printf("\n");
    return;   
}

void buscarNome(Contato *contatos) { 
    char nomeBusca[STR_LIMITE];
    printf("\nNome a ser buscado: ");
    fgets(nomeBusca, STR_LIMITE, stdin);
    nomeBusca[strlen(nomeBusca) - 1] = '\0';

    int i, qtdEncontrados = 0, qtdContatos = listalen(contatos);
    imprimirCabecalhoBuscar();
    imprimirCabecalhoLista();
    for (i = 0; i < qtdContatos; i++){
        if (strstr(contatos[i].nome, nomeBusca) != NULL){
            qtdEncontrados++;
            imprimirContato(&contatos[i]);
        }
    }
    if (qtdEncontrados == 0) {
        imprimirNaoEncontrado();
    }
        
    printf("\n");
    return;   
}

// Função que busca um contato passado por parâmetro
void buscarContato(Contato* listaContatos) {
    int opcao;

    imprimirCabecalhoBuscar();
    imprimirLinhaBuscar();
    printf("Buscar contato por:\n\n");
    printf("[1] Nome\n");
    printf("[2] DDD\n");
    printf("[3] Número\n");
    printf("[4] E-mail\n");
    imprimirLinhaBuscar();
    printf("\nEscolha [1 - 4]: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 1:
            buscarNome(listaContatos);
            break;
        case 2: 
            buscarDdd(listaContatos);
            break;
        case 3:
            buscarNumero(listaContatos);
            break;
        case 4:
            buscarEmail(listaContatos);
            break;
        default:
            printf("\nEssa opção não existe, cancelando busca por contatos...\n");
            break;
    }

    systemPause();
    return;
}