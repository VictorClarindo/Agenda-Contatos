#include "utils/utils.h"

Contato* listaContatos;

void menuPrincipal() {
    int opcaoMenuPrincipal, qtdContatos;
    opcaoMenuPrincipal = mostrarMenuPrincipal();
    qtdContatos = listalen(listaContatos);
    
    switch(opcaoMenuPrincipal) {
        case 1: 
            cadastrarContato(&listaContatos);
            break;
        case 2:
            if (qtdContatos == 0) {
                printf("\nOpção indisponível enquanto a lista de contatos estiver vazia...\n");
                systemPause();
            } else {
                editarContato(listaContatos);
            }
            break;
        case 3:
            if (qtdContatos == 0) {
                printf("\nOpção indisponível enquanto a lista de contatos estiver vazia...\n");
                systemPause();
            } else {
                excluirContato(&listaContatos);
            }
            break;
        case 4:
            if (qtdContatos == 0) {
                printf("\nOpção indisponível enquanto a lista de contatos estiver vazia...\n");
                systemPause();
            } else {
                buscarContato(listaContatos);
            }
            break;
        case 5:
            if (qtdContatos == 0) {
                printf("\nOpção indisponível enquanto a lista de contatos estiver vazia...\n");
                systemPause();
            } else {
                listarContatos(listaContatos);
            }
            break;
        case 6: 
            printf("\nEncerrando o programa...\n");
            salvarContatos(listaContatos);
            return;
        default:
            printf("\nEssa opção não existe...\n");
            systemPause();
            break;
    }

    menuPrincipal();
}

int main() {
    setlocale(LC_ALL, "portuguese");
    listaContatos = (Contato*) malloc(sizeof(Contato));
    pegarContatos(&listaContatos);

    menuPrincipal();
    
    return 0;    
}    
