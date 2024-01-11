#include "utils.h"

void systemPause() {
    if (IS_WINDOWS) {
        system("pause");
    } else {
        system("read -p \"\nPressione a tecla enter para continuar...\" saindo");
    }

    return;
}

void systemClear() {
    if (IS_WINDOWS) {
        system("cls");
    } else {
        system("clear");
    }

    return;
}

char* formatarParaImprimir(char* num);

int listalen(Contato* listaContatos) {
    int count = 0;
    while (listaContatos[count].ddd != 0 && listaContatos[count].numero[0] != '\0' && 
        listaContatos[count].nome[0] != '\0' && listaContatos[count].email[0] != '\0') {
        count++;
    }

    return count;
}

int mostrarMenuPrincipal() {
    systemClear();
    printf("------------------------------\n");
    printf("----- AGENDA DE CONTATOS -----\n");
    printf("------------------------------\n");
    printf("[1] Cadastrar contato\n");
    printf("[2] Editar contato\n");
    printf("[3] Excluir contato\n");
    printf("[4] Buscar contato\n");
    printf("[5] Listar contatos\n"); 
    printf("[6] Sair\n");
    printf("------------------------------\n\n");

    printf("Escolha [1 - 6]:  ");
    int opcao;
    scanf("%d", &opcao); 
    getchar();   

    return opcao;
}

void imprimirCabecalhoLista() {
    printf("\nNOME\t\t\t\t\t\t| DDD\t| TELEFONE\t| EMAIL\n"
        "------------------------------------------------|-------|---------------|------------------------------\n");
}

void imprimirContato(Contato *c) {
    if (strlen(c->nome) < 8){
        printf("%s\t\t\t\t\t\t| %d\t| %s\t| %s\n", c->nome, c->ddd, formatarParaImprimir(c->numero), c->email);
    } else if (strlen(c->nome) >= 8 && strlen(c->nome) < 16) {
        printf("%s\t\t\t\t\t| %d\t| %s\t| %s\n", c->nome, c->ddd, formatarParaImprimir(c->numero), c->email);
    } else if (strlen(c->nome) >= 16 && strlen(c->nome) < 24) {
        printf("%s\t\t\t\t| %d\t| %s\t| %s\n", c->nome, c->ddd, formatarParaImprimir(c->numero), c->email);
    } else if (strlen(c->nome) >= 24 && strlen(c->nome) < 32) {
        printf("%s\t\t\t| %d\t| %s\t| %s\n", c->nome, c->ddd, formatarParaImprimir(c->numero), c->email);
    } else if (strlen(c->nome) >= 32 && strlen(c->nome) < 40) {
        printf("%s\t\t| %d\t| %s\t| %s\n", c->nome, c->ddd, formatarParaImprimir(c->numero), c->email);
    }       

    return;
}

void imprimirCabecalhoListaIdentificada() {
    printf("\nID   | NOME\t\t\t\t\t\t| DDD\t| TELEFONE\t| EMAIL\n"
    "-----|--------------------------------------------------|-------|---------------|---------------\n");
}

void imprimirContatoIdentificado(Contato *c, int i) {
    if (strlen(c->nome) <= 8){
        printf("%d    | %s\t\t\t\t\t\t| %d\t| %s\t| %s\n", (i+1), c->nome, c->ddd, c->numero, c->email);
    } else if (strlen(c->nome) > 8 && strlen(c->nome) <= 16) {
        printf("%d    | %s\t\t\t\t\t| %d\t| %s\t| %s\n", (i+1), c->nome, c->ddd, c->numero, c->email);
    } else if (strlen(c->nome) > 16 && strlen(c->nome) <= 24) {
        printf("%d    | %s\t\t\t\t| %d\t| %s\t| %s\n", (i+1), c->nome, c->ddd, c->numero, c->email);
    } else if (strlen(c->nome) > 24 && strlen(c->nome) <= 32) {
        printf("%d    | %s\t\t\t| %d\t| %s\t| %s\n", (i+1), c->nome, c->ddd, c->numero, c->email);
    } else if (strlen(c->nome) > 32 && strlen(c->nome) <= 40) {
        printf("%d    | %s\t\t| %d\t| %s\t| %s\n", (i+1), c->nome, c->ddd, c->numero, c->email);
    }       

    return;
}

Contato* selecionarContatoDaLista(Contato *contatos) {
    unsigned int qtdContatos = listalen(contatos);

    printf("\nSelecione o contato desejado para a operação:\n");
    imprimirCabecalhoListaIdentificada();
    for (unsigned int i = 0; i < qtdContatos; i++) {
        imprimirContatoIdentificado(&contatos[i], i);
    }

    int idContato;
    printf("\nDigite o ID do contato desejado: ");
    scanf("%d", &idContato);
    idContato -= 1;

    if (idContato >= 0 && idContato < qtdContatos) {
        return &contatos[idContato];
    } else {
        return NULL;
    }    
}

char numeroFormatado[NUMERO_LIMITE + 1];
void formatarNumero(char* numero) {
    int i, j = 0;

    for (i = 0; numero[i] != '\0'; i++) {
        if (isdigit(numero[i])) {
            numeroFormatado[j++] = numero[i];
        }
    }

    numeroFormatado[j] = '\0';
    strcpy(numero, numeroFormatado);
    return;
}

char numeroComTraco[NUMERO_LIMITE + 2];
char* formatarParaImprimir(char* num){
    int i, j = 0;
    if(strlen(num) == 9){
        for(i = 0; i < strlen(num) + 3; i++){
            if(i == 5){
                numeroComTraco[5] = '-';
            }
            else{numeroComTraco[i] = num[j]; j++;}
            
        }
    }

    else if(strlen(num) == 8){
        for(i = 0; i < strlen(num) + 3; i++){
            if(i == 4){
                numeroComTraco[4] = '-';
            }
            else{
                numeroComTraco[i] = num[j];
                j++;
            }
        }
    }
    else{
        return num;
    }
    numeroComTraco[i] = '\0';
    return numeroComTraco;
}