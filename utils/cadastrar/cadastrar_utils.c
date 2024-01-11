#include "../utils.h"

void imprimirLinhaCadastrar() {
    printf("---------------------------------\n");
}
void imprimirCabecalhoCadastrar() {
    systemClear();
    imprimirLinhaCadastrar();
    printf("------- CADASTRAR CONTATO -------\n");
    imprimirLinhaCadastrar();
    printf("\n");
}

int verificarSeContatoJaExiste(char* numero, Contato* listaContatos) {
    for (unsigned int i = 0; i < listalen(listaContatos); i++) {
        if (strcmp(numero, listaContatos[i].numero) == 0) {
           printf("Esse contato já existe!\n");
            return 1;
        }       
    }

    return 0;
}

int pegarNovoContato(Contato* c, Contato* listaContatos, int ehEdicao) {
    printf("Digite o DDD: ");
    scanf("%d", &c->ddd);
    getchar();
    
    printf("Digite o número: ");
    fgets(c->numero, NUMERO_LIMITE, stdin);
    c->numero[strlen(c->numero) - 1] = '\0';
    formatarNumero(c->numero);
    if (!ehEdicao && verificarSeContatoJaExiste(c->numero, listaContatos)){
        systemPause();
        return 0;
    }

    printf("Digite o nome: ");
    fgets(c->nome, STR_LIMITE, stdin);
    c->nome[strlen(c->nome) - 1] = '\0';
    
    printf("Digite o e-mail: ");
    fgets(c->email, STR_LIMITE, stdin);
    c->email[strlen(c->email) - 1] = '\0';

    return 1;
}

// Função que cadastra um novo contato e armazena na váriavel listaContatos
void cadastrarContato(Contato** listaContatos) {
    systemClear();

    imprimirCabecalhoCadastrar();
    imprimirLinhaCadastrar();
    Contato* novoContatoParaCadastrar = (Contato*) malloc(sizeof(Contato));
    int sucesso = pegarNovoContato(novoContatoParaCadastrar, *listaContatos, /*false*/ 1);
    imprimirLinhaCadastrar();

    if(!sucesso) {
        printf("\nEsse contato já existe, cancelando criação do contato...\n");
        free(novoContatoParaCadastrar);
        systemPause();
        return;
    }

    if(!strcmp(novoContatoParaCadastrar->numero, "")) {
        printf("\nNão é possível cadastrar um contato sem o número, cancelando criação do contato...\n");
        free(novoContatoParaCadastrar);
        systemPause();
        return;
    }

    int qtdContatos = listalen(*listaContatos);
    *listaContatos = realloc(*listaContatos, (qtdContatos + 2) * sizeof(Contato));
    if(*listaContatos == NULL){
        printf("\nErro de alocação de memória, tente novamente...\n");
        free(novoContatoParaCadastrar);
        systemPause();
        return;
    }
    (*listaContatos)[qtdContatos] = *novoContatoParaCadastrar;
    (*listaContatos)[qtdContatos+1] = (Contato) CONTATO_MARCADOR_FINAL;
   
    printf("\nContato cadastrado com sucesso!\n");
    imprimirCabecalhoLista();
    imprimirContato(novoContatoParaCadastrar);
    
    free(novoContatoParaCadastrar);
    systemPause();
}