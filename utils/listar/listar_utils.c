#include "../utils.h"

// Função que lista todos os contatos armazenados na váriavel listaContatos
// Função utilizada para ordenar de maneira ascendente os contatos no vetor listaOrdenada
void troca_proximo(int i, Contato aux, Contato* listaOrdenada) {
    aux.ddd = listaOrdenada[i].ddd;
    strcpy(aux.numero, listaOrdenada[i].numero);
    strcpy(aux.nome, listaOrdenada[i].nome);
    strcpy(aux.email,listaOrdenada[i].email);

    listaOrdenada[i].ddd = listaOrdenada[i+1].ddd;
    strcpy(listaOrdenada[i].numero, listaOrdenada[i+1].numero);
    strcpy(listaOrdenada[i].nome, listaOrdenada[i+1].nome);
    strcpy(listaOrdenada[i].email,listaOrdenada[i+1].email);
    
    listaOrdenada[i+1].ddd = aux.ddd;
    strcpy(listaOrdenada[i+1].numero, aux.numero);
    strcpy(listaOrdenada[i+1].nome, aux.nome);
    strcpy(listaOrdenada[i+1].email,aux.email);
}

// Função utilizada para ordenar de maneira descendente os contatos no vetor listaOrdenada
void troca_anterior(int i, Contato aux, Contato* listaOrdenada) {
    aux.ddd = listaOrdenada[i].ddd;
    strcpy(aux.numero, listaOrdenada[i].numero);
    strcpy(aux.nome, listaOrdenada[i].nome);
    strcpy(aux.email,listaOrdenada[i].email);
    
    listaOrdenada[i].ddd = listaOrdenada[i-1].ddd;
    strcpy(listaOrdenada[i].numero, listaOrdenada[i-1].numero);
    strcpy(listaOrdenada[i].nome, listaOrdenada[i-1].nome);
    strcpy(listaOrdenada[i].email,listaOrdenada[i-1].email);

    listaOrdenada[i-1].ddd = aux.ddd;
    strcpy(listaOrdenada[i-1].numero, aux.numero);
    strcpy(listaOrdenada[i-1].nome, aux.nome);
    strcpy(listaOrdenada[i-1].email,aux.email);
}

// Função utilizada para trocar dois contatos quaisquer no vetor listaOrdenada
void troca_simples(int i,int j, Contato aux, Contato* listaOrdenada) {
    aux.ddd = listaOrdenada[i].ddd;
    strcpy(aux.numero, listaOrdenada[i].numero);
    strcpy(aux.nome, listaOrdenada[i].nome);
    strcpy(aux.email,listaOrdenada[i].email);
    
    listaOrdenada[i].ddd = listaOrdenada[j].ddd;
    strcpy(listaOrdenada[i].numero, listaOrdenada[j].numero);
    strcpy(listaOrdenada[i].nome, listaOrdenada[j].nome);
    strcpy(listaOrdenada[i].email,listaOrdenada[j].email);

    listaOrdenada[j].ddd = aux.ddd;
    strcpy(listaOrdenada[j].numero, aux.numero);
    strcpy(listaOrdenada[j].nome, aux.nome);
    strcpy(listaOrdenada[j].email,aux.email);
}

void imprimirLinhaListar() {
    printf("-------------------------------\n");
}

void imprimirCabecalhoListar() {
    systemClear();
    imprimirLinhaListar();
    printf("------- LISTAR CONTATOS -------\n");
    imprimirLinhaListar();
    printf("\n");
}

// Função que lista todos os contatos armazenados na váriavel listaContatos
void listarContatos(Contato* listaContatos) {
    imprimirCabecalhoListar();

    unsigned int i, j;
    int selecao_ordem, selecao, qtdContatos = listalen(listaContatos);
    Contato* listaOrdenada;
    Contato aux;
    listaOrdenada = (Contato*) malloc(qtdContatos * sizeof(Contato));
    for (i = 0; i < qtdContatos; i++) {
        listaOrdenada[i].ddd = listaContatos[i].ddd;
        strcpy(listaOrdenada[i].numero, listaContatos[i].numero);
        strcpy(listaOrdenada[i].nome, listaContatos[i].nome);
        strcpy(listaOrdenada[i].email, listaContatos[i].email);
    }


    imprimirLinhaListar();
    printf("Tipo de ordenação desejada:\n\n");
    printf("[1] Ascendente/Crescente\n");
    printf("[2] Descendente/Decrescente\n");
    imprimirLinhaListar();
    printf("\nEscolha [1 - 2]: ");
    scanf("%d", &selecao_ordem);
    getchar();

    if (selecao_ordem == 1) {
        imprimirCabecalhoListar(); 
        imprimirLinhaListar();
        printf("Campo ordenado:\n\n");
        printf("[1] Nome\n");
        printf("[2] DDD\n");
        printf("[3] Número\n");
        printf("[4] E-mail\n");
        printf("[5] Ordem de criação\n");
        imprimirLinhaListar();
        printf("\nEscolha [1 - 5]: ");
        scanf("%d", &selecao);
        getchar();

        switch(selecao) {
            case 1:
                for(j = qtdContatos-1; j > 0; j--){
                    for(i = 0;i < j;i++){
                        if (strcasecmp(listaOrdenada[i].nome, listaOrdenada[i+1].nome) > 0) {
                            troca_proximo(i, aux, listaOrdenada);
                        }
                    }      
                }
                break;
            case 2:
                for(j = qtdContatos-1; j > 0; j--){
                    for(i = 0; i < j; i++){
                        if (listaOrdenada[i].ddd > listaOrdenada[i+1].ddd) {
                            troca_proximo(i, aux, listaOrdenada);
                        }
                    }      
                }
                break;
            case 3:
                for (j = qtdContatos-1; j > 0;j--) {
                    for(i = 0;i < j;i++){
                        if (strcasecmp(listaOrdenada[i].numero, listaOrdenada[i+1].numero) > 0) {
                            troca_proximo(i,aux, listaOrdenada);
                        }
                    }      
                }
                break;
            case 4:
                for (j = qtdContatos-1; j > 0; j--) {
                    for (i = 0;i < j;i++) {
                        if (strcasecmp(listaOrdenada[i].email, listaOrdenada[i+1].email) > 0) {
                            troca_proximo(i, aux, listaOrdenada);
                        }
                    }      
                }
                break;
            case 5:
                for(j = qtdContatos-1,i=0;j>i;j--,i++){
                    troca_simples(i,j,aux,listaOrdenada);
                }
                break;
            default:
                printf("\nEssa opção não existe, cancelando listagem dos contatos...\n");
                systemPause();
                return;
                break;
        }
    } else if (selecao_ordem == 2) {
        imprimirCabecalhoListar(); 
        imprimirLinhaListar();
        printf("Campo ordenado:\n\n");
        printf("[1] Nome\n");
        printf("[2] DDD\n");
        printf("[3] Número\n");
        printf("[4] E-mail\n");
        printf("[5] Ordem de criação\n");
        imprimirLinhaListar();
        printf("\nEscolha [1 - 5]: ");
        scanf("%d", &selecao);
        getchar();

        switch(selecao){
            case 1:
                for(j = 0; j < qtdContatos ;j++){
                    for(i = j;i > 0;i--){
                        if(strcmp(listaOrdenada[i].nome,listaOrdenada[i-1].nome) > 0){
                            troca_anterior(i,aux,listaOrdenada);
                        }
                    }      
                }
                break;
            case 2:
                for(j = 0; j < qtdContatos ;j++){
                    for(i = j; i > 0; i--){
                        if(listaOrdenada[i].ddd > listaOrdenada[i+1].ddd){
                            troca_anterior(i,aux,listaOrdenada);
                        }
                    }      
                }
                break;
            case 3:
                for(j = 0; j < qtdContatos ;j++){
                    for(i = j; i > 0; i--){
                        if(strcasecmp(listaOrdenada[i].numero,listaOrdenada[i-1].numero) > 0){
                            troca_anterior(i,aux,listaOrdenada);
                        }
                    }      
                }
                break;
            case 4:
                for(j = 0; j < qtdContatos; j++){
                    for(i = j;i > 0;i--){
                        if(strcasecmp(listaOrdenada[i].email,listaOrdenada[i-1].email) > 0){
                            troca_anterior(i,aux,listaOrdenada);
                        }
                    }      
                }
                break;
            case 5:
                listaOrdenada = listaContatos;
                break;
            default:
                printf("\nEssa opção não existe, cancelando listagem dos contatos...\n");
                systemPause();
                return;
                break;
        }
    } else {
        printf("\nEssa opção não existe, cancelando listagem doscontatos...\n");
        systemPause();
        return;
    }

    imprimirCabecalhoListar();
    imprimirCabecalhoLista();
    for(i = 0; i < qtdContatos; i++){
        imprimirContato(&listaOrdenada[i]);
    }

    systemPause();
    return;
}
