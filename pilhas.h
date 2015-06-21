/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Ian Saud Soares - matricula: 0050011104
* Pilhas
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define toDigit(c) (c-'0')

struct lista {
    int info;
    struct lista * prox;
};

typedef struct lista Lista;

struct pilha{
    Lista* prim;
};
typedef struct pilha Pilha;

//CRIAR//
Pilha *pilha_cria(void)
{
      Pilha *a = (Pilha*)malloc(sizeof(Pilha));
      a->prim=NULL; /*Vazia*/
	  return a;
}
//VAZIA
int pilha_vazia(Pilha* a){
    if(a->prim!=NULL)
        return 0;
    else
        return 1;
}
//PUSH//
void pilha_push  (Pilha *a, int chave)
{
	  Lista *b = (Lista*)malloc(sizeof(Lista));
	  b->info=chave;
	  b->prox=a->prim;
	  a->prim=b;
}
//POP//
int pilha_pop  (Pilha *a)
{
	  int chave;
	  Lista *c;
	  if (pilha_vazia(a))
	  {
	  	puts("Pilha Vazia");
	  	exit(1);
	  	
	  } 
	  c=a->prim;
	  chave=c->info;
	  a->prim=c->prox;
	  free(c);
	  return chave;
}
//FREE WHILLY//
void pilha_free (Pilha *a)
{
	Lista *d=a->prim;
	while (d!=NULL)
	{
		Lista *c=d->prox;
		free(d);
		d=c;
	}
	free(a);
}



              



