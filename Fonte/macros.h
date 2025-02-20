#define FMACROS 0 // flag para identificar se macros.h já foi incluída
// TRATAMENTO DE ERROS
#define SUCCESS 0
#define ERRO_NO_TIPO_INTEIRO -1
#define ERRO_NO_TAMANHO_STRING -2
#define	ERRO_NOME_CAMPO -3
#define ERRO_NOME_TABELA -4
#define ERRO_DE_PARAMETRO -5
#define ERRO_ABRIR_ARQUIVO -6
#define ERRO_VAZIO -7
#define ERRO_IMPRESSAO -8
#define ERRO_LEITURA_DADOS -9
#define ERRO_BUFFER_CHEIO -10
#define ERRO_ABRIR_DICIONARIO -11
#define ERRO_NO_TIPO_CHAR -12
#define ERRO_NO_TIPO_DOUBLE -13
#define ERRO_CHAVE_PRIMARIA -14
#define ERRO_CHAVE_ESTRANGEIRA -15
#define ERRO_CRIACAO_TABELA -16
#define ERRO_REMOVER_ARQUIVO -17
#define ERRO_REMOVER_ARQUIVO_OBJECT -18
#define ERRO_REMOVER_ARQUIVO_SCHEMA -19
#define ERRO_DE_ALOCACAO NULL
#define ERRO_ABRIR_ESQUEMA NULL
#define ERRO_NOME_TABELA_INVALIDO NULL
#define ERRO_ESTRUTURA_TABELA_NULA NULL
#define ERRO_INSERIR_VALOR NULL
#define ERRO_PAGINA_INVALIDA NULL
#define ERRO_DE_LEITURA NULL
#define ERRO_PARAMETRO NULL

//tratamento PK e FK
#define NPK 0
#define PK 1
#define FK 2
#define BT 3
////
#define SIZE 512                // Tamanho da página.
#define PAGES 1024              // Número de páginas.
#define TAMANHO_NOME_CAMPO 40   // Tamanho do nome dos campos de uma tabela.
#define TAMANHO_NOME_TABELA 20  // Tamanho do nome da tabela.
#define TAMANHO_NOME_ARQUIVO 20 // Tamanho do nome do arquivo.
#define TAMANHO_NOME_INDICE 40  // Tamanho do nome do arquivo de indice.
#define QTD_DB 100
#define LEN_DB_NAME 20
#define LEN_DB_NAME_IO (LEN_DB_NAME << 1)
#define DB_EXISTS 1
#define DB_NOT_EXISTS 24


// buffer.h
#define FBUFFER 1 // flag controlar os includes

// dictionary.h
#define FDICTIONARY 1 // para testar se já foi incluída

// Expressao.h
#define FEXPRESSAO 1

#define LOGICO 1
#define RELACIONAL 2
#define SINAL 3
#define ARITIMETICO 4
#define ABRE_PARENT 5
#define FECHA_PARENT 6
#define STRING 7
#define OBJETO 8
#define VALUE_NUMBER 9
#define BOOLEANO 10

// misc.h
#define FMISC 1

// sqlcommands.h
#define FSQLCOMMANDS 1   // flag para garantir a não reinclusão

// types.h
#define FTYPES 1 // flag para identificar se types.h já foi incluída

// Utility.h
#define FUTILITY 1

// /interface

// lex.l
#define YY_NO_INPUT