/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Ian Saud Soares - matricula: 0050011104
* Pilhas
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "pilhas.h"
void calcular(Pilha *num, Pilha*op)
{
	int a,b;
	char opera;
	int resultado;
	a=pilha_pop(num);
	b=pilha_pop(num);
	opera=pilha_pop(op);
	if (opera=='+')
	{
		resultado=b+a;
		pilha_push(num,resultado);
	}
	if (opera=='-')
	{
		pilha_push(num,b-a);
	}
	if (opera=='*')
	{
		pilha_push(num,b*a);
	}	
	if (opera=='/')
	{
		pilha_push(num,b/a);
	}	
}
int converte(char c)
{
    int i;
    int num=toDigit(c);
		for(i=0;i<10;i++)
	{
		if(num==i)
			return i;
	}

}
int main()
{
	char exp[20];
	char operador;
	char aux;
	int i;
	int tamanho;
	Pilha *num;
	Pilha *op;
	num=pilha_cria();
	op=pilha_cria();
	do
	{
	puts("Ola, meu nome eh Ian");
	printf("Entre com a expressao para que eu resolva: ");
	scanf("%s", exp);
	fflush(stdin);
	tamanho=strlen(exp);	
	for (i=0;i<tamanho;i++)
	{
			if (isdigit(exp[i]))
			{
				
				aux=converte(exp[i]);
				pilha_push(num,aux);
			}  
			else
			{
				if (exp[i]=='(')
				{}
				else
				{
					if (exp[i]==')')
					{
						calcular(num, op);
					}
					else
					{
						pilha_push(op,exp[i]);
					}
				}
			}										
	}
	printf("Obrigado, o resultado da sua expressão e: %d\n", pilha_pop(num));
	puts("Desejar continuar (s/n)");
	scanf("%c", &operador);
	fflush(stdin);
	}while(operador=='s');
	puts("FIM!!!");
	return 0;
}


              



