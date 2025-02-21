#define FEXPRESSAO 1

#ifndef FMACROS // garante que macros.h não seja reincluída
   #include "macros.h"
#endif

char precedArit(int id);
int operador(int id);
void *converter(char tipo,char valor[]);
void substitui(Lista *l,Lista *t);
Lista *resArit(Lista *l,Lista *t);
inf_where *opArit(Lista *l,Lista *t);
void aritPosfixa(Lista *l,Lista *t,Lista *novaExp);
column *buscaColuna(Lista *t,char *str);
Lista *relacoes(Lista *l);
char logPosfixa(Lista *l);
char opLog(Lista *l);
char precedLog(char *);
