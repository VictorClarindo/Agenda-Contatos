#ifndef _UTILS
#define _UTILS

#ifdef WIN32
#define IS_WINDOWS 1
#elif _WIN32
#define IS_WINDOWS 1
#else
#define IS_WINDOWS 0
#endif 

#define STR_LIMITE 52
#define NUMERO_LIMITE 15

typedef struct {
    int ddd;
    char numero[NUMERO_LIMITE + 1], nome[STR_LIMITE + 1], email[STR_LIMITE + 1];
} Contato;

#define CONTATO_MARCADOR_FINAL {0, "", "", ""}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#include "../database/database.h"
#include "buscar/buscar_utils.h"
#include "cadastrar/cadastrar_utils.h"
#include "editar/editar_utils.h"
#include "excluir/excluir_utils.h"
#include "listar/listar_utils.h"

void systemPause();

void systemClear();

int listalen(Contato* listaContatos);

int mostrarMenuPrincipal();

void imprimirCabecalhoLista();

char* formatarParaImprimir(char* num);

void imprimirContato(Contato *c);

void imprimirContatoIdentificado(Contato *c, int i);

Contato* selecionarContatoDaLista(Contato *contatos);

void formatarNumero(char* numero);
#endif