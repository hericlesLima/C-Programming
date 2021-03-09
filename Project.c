#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>

typedef struct {int codigo;	char categoria[25]; char nome[25]; int quantidade; int preco;} produtos;

typedef struct no {produtos* produto; struct no *esq; struct no *dir; struct no *pai;} No;

No *dado = NULL, *proc;

void inserirProdutos (No **dado, produtos *item);
produtos *prod_nome  ();
void mostrarPreOrdem (No *dado);
void mostrarInOrdem  (No *dado);
void mostrarPosOrdem (No *dado);
No *pesquisar        (No *dado, char *nome);
void modificar       (No *dado, char *nome);
No *minimo           (No **no);
bool eliminar(No* dado, char *nome);

int main()
{
	setlocale(LC_ALL,"Portuguese");

	char nomeprod[25], z;
	int m, v;
	int op, i, x;

	printf("\n\n\n\n\n");

	printf("\t\t\t\t\t_____________________________________________________________________________________________________\n\n\n\n");

	printf("\t\t\t\t\t\t\t   XXX     XXX  XXXXXXXXXXX  XXXX     XXX  XXXXXXXXXX    XXXXXXXXX    \n");
	printf("\t\t\t\t\t\t\t   XXX     XXX  XXXXXXXXXXX  XXXXX    XXX  XXXXXXXXXXX  XXXXXXXXXXX   \n");
	printf("\t\t\t\t\t\t\t   XXX     XXX  XXX          XXXXXX   XXX  XXX     XXX  XXX     XXX   \n");
  printf("\t\t\t\t\t\t\t   XXX     XXX  XXXXXXX      XXX XXX  XXX  XXX     XXX  XXXXXXXXXXX   \n");
	printf("\t\t\t\t\t\t\t   XXX     XXX  XXXXXXX      XXX  XXX XXX  XXX     XXX  XXXXXXXXXXX   \n");
	printf("\t\t\t\t\t\t\t    XXX   XXX   XXX          XXX   XXXXXX  XXX     XXX  XXX     XXX   \n");
	printf("\t\t\t\t\t\t\t     XXXXXXX    XXXXXXXXXXX  XXX    XXXXX  XXXXXXXXXXX  XXX     XXX   \n");
	printf("\t\t\t\t\t\t\t      XXXXX     XXXXXXXXXXX  XXX     XXXX  XXXXXXXXXX   XXX     XXX   \n");

  printf("\n\n");

	printf("\t\t\t\t\t\t\t\t\t\tXXXXXXXXXXX   XXXXXXXXXXX \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXXXXXXXXXXX  XXXXXXXXXXX \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXX      XXX  XXX         \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXX      XXX  XXXXXXX     \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXX      XXX  XXXXXXX     \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXX      XXX  XXX         \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXXXXXXXXXXX  XXXXXXXXXXX \n");
	printf("\t\t\t\t\t\t\t\t\t\tXXXXXXXXXXX   XXXXXXXXXXX \n");

	printf("\n\n");

	printf("\t\t\t\t\t\tXXXXXXXXXX  XXXXXXXXXX    XXXXXXXXX   XXXXXXXXXX   XXX     XXX  XXXXXXXXXXX   XXXXXXXXX   \n");
	printf("\t\t\t\t\t\tXXXXXXXXXXX XXXXXXXXXXX  XXXXXXXXXXX  XXXXXXXXXXX  XXX     XXX  XXXXXXXXXXX  XXXXXXXXXXX  \n");
	printf("\t\t\t\t\t\tXXX     XXX XXX     XXX  XXX     XXX  XXX     XXX  XXX     XXX      XXX      XXX     XXX  \n");
	printf("\t\t\t\t\t\tXXXXXXXXXXX XXXXXXXXXXX  XXX     XXX  XXX     XXX  XXX     XXX      XXX      XXX     XXX  \n");
	printf("\t\t\t\t\t\tXXXXXXXXXX  XXXXXXXXXX   XXX     XXX  XXX     XXX  XXX     XXX      XXX      XXX     XXX  \n");
	printf("\t\t\t\t\t\tXXX         XXX   XXX    XXX     XXX  XXX     XXX  XXX     XXX      XXX      XXX     XXX  \n");
	printf("\t\t\t\t\t\tXXX         XXX    XXX   XXXXXXXXXXX  XXXXXXXXXXX  XXXXXXXXXXX      XXX      XXXXXXXXXXX  \n");
	printf("\t\t\t\t\t\tXXX         XXX     XXX   XXXXXXXXX   XXXXXXXXXX    XXXXXXXXX       XXX       XXXXXXXXX   \n\n\n");
	printf("\t\t\t\t\t_____________________________________________________________________________________________________");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t     Designed and developed by:");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t  H�ricles Ant�nio");

	printf("\n\n\n\n\n\n\n");

	system("pause");
	system("cls");

	while(op!='0'){
		menu:

		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t                                 MARKET-MENU                                      \n");
		printf("\t\t\t\t\t\t ________________________________________ ____________________________________________  \n");
		printf("\t\t\t\t\t\t|                                        |                                            | \n");
		printf("\t\t\t\t\t\t| 1 -> Inserir um N�                     | 5 -> Pesquisar produto atrav�s do nome     | \n");
		printf("\t\t\t\t\t\t|                                        |                                            | \n");
		printf("\t\t\t\t\t\t| 2 -> Mostrar �rvore em pre-ordem       | 6 -> Modificar quantidade atrav�s do nome  | \n");
		printf("\t\t\t\t\t\t|                                        |                                            | \n");
		printf("\t\t\t\t\t\t| 3 -> Mostrar �rvore em in-ordem        | 7 -> Eliminar um n�                        | \n");
		printf("\t\t\t\t\t\t|                                        |                                            | \n");
    printf("\t\t\t\t\t\t| 4 -> Mostrar �rvore em p�s-ordem       | 0 -> Sair                                  | \n");
		printf("\t\t\t\t\t\t|________________________________________|____________________________________________| \n\n");
		printf("\t\t\t\t\t\t\t\t\t        Digite a sua op��o: ");

		fflush(stdin);
    	op = getch();
			system("cls");

		switch(op){

        case '1':

        	printf("\n\n\t\tINSERIR N�");
        	printf("\n\n\n\n\t\tQuantos produtos deseja inserir: ");
        	scanf("%d", &x);

        	fflush(stdin);
            getch();
            system("cls");

					for(i=0; i<x; i++){

							printf("\n\n\t\tInsira os dados do [%d�] produto.", i+1);
							inserirProdutos(&dado, prod_nome());
					}

			break;

      case '2':

        printf("\n\n\t\tMOSTRAR PR�-ORDEM\n\n");
				printf("\n\t\tCodigo\t\tNome\t\tCategoria\t\tQuantidade\tPreco\n");
        mostrarPreOrdem(dado);

			break;

      case '3':

      	printf("\n\n\t\tMOSTRAR IN-ORDEM\n\n");
        printf("\n\t\tCodigo\t\tNome\t\tCategoria\t\tQuantidade\tPreco\n");
        mostrarInOrdem(dado);

			break;

      case '4':

     		printf("\n\n\t\tMOSTRAR P�S-ORDEM\n\n");
		    printf("\n\t\tCodigo\t\tNome\t\tCategoria\t\tQuantidade\tPreco\n");
        mostrarPosOrdem(dado);

		 break;

     case '5':

  	 		printf("\n\n\t\tPESQUISAR PRODUTO ATRAV�S DO NOME\n");
      	printf("\n\n\t\tDigite o <NOME> do produto a pesquisar: ");
      	scanf("%s", nomeprod);
      	system("cls");

				proc = pesquisar(dado, nomeprod);
				if (proc == NULL){

					printf("\n\n\t\tO <NOME> pesquisado n�o se encontra nos registros.\n\\n\n");

				}else{

					printf("\n\n\t\tProduto pesquisado [%s].\n\n", proc->produto->nome);
					printf("\t\tC�digo: %d\n\t\tCategoria: %s\n\t\tQuantidade: %d\n\t\tPre�o: %d\n\n\n"
																										 , proc->produto->codigo
													 							 	  			   , proc->produto->categoria
													 							 	  			   , proc->produto->quantidade
													                           , proc->produto->preco);
			 }

			break;

			case '6':

			printf("\n\n\t\tMODIFICAR QUANTIDADE DE ATRAV�S DE NOME\n");
			printf("\n\n\t\tDigite o nome do produto a ser modificado: ");
      scanf("%s", nomeprod);
			modificar(dado, nomeprod);

			break;

      case '7':

        	printf("\n\n\t\tELIMINAR N�");
        	printf("\n\n\t\tDigite o nome do produto a ser eliminado: ");
          scanf("%s", nomeprod);
					eliminar(dado, nomeprod);

			break;

			case '0':

			system("cls");
			while(z!='0'){

				printf("\n\n\t\tTEM CERTEZA QUE DESEJA SAIR?\n\n\n\t\t1 -> Sim\n\n\t\t2 -> N�o\n\n\t\t");
       	printf(">>>> ");
				scanf("%c",&z);
				fflush(stdin);

				switch(z){

					case '1':{

						printf("\n*PROGRAMA ENCERRADO! ");
						sleep(2);
						exit(0);

						}
						case '2':{

						system("cls");
						return main();

						}

						default :

						system("cls");

						break;
				}
			}

	    default:

			printf("OP��O INV�LIDA.\n");
			
    	}

	getchar();

	system("pause");
	system("cls");
    }
}

produtos* prod_nome () //inser��o e armazenanto dos dados nas variaveis
{
	int arq;

	produtos *novo = (produtos*) malloc (sizeof(produtos)); //apontador para a estrutura produtos e atribui��o de espa�o na memoria

	printf("\n\n\n\t\tDigite o <CODIGO> do produto: ");
    scanf("%d", &novo->codigo);

	printf("\n\n\t\tDigite a <CATEGORIA> do produto: ");
    scanf("%s", novo->categoria);

	printf("\n\n\t\tDigite o <NOME> do produto: ");
    scanf("%s", novo->nome);

    printf("\n\n\t\tDigite a <QUANTIDADE> do produto: ");
   	scanf("%d", &novo->quantidade);

	printf("\n\n\t\tDigite o <PRE�O> do produto: ");
	scanf("%d", &novo->preco);

	FILE*produtos;
	produtos=fopen("produtos.txt","a");

	if(produtos==NULL)
	{
		printf("\n\n\t\tO ficheiro n�o pode ser criado");
	}

	printf("\n\n\t\tDeseja guardar os dados em um ficheiro?\n");


	printf("\n\t\t1 -> Sim\n");
	printf("\t\t2 -> N�o\n\n\t\t");
	printf(">>>> ");
	scanf("%d", &arq);

	switch(arq)
	{
		case 1:


    		fprintf(produtos,"\n\n\tC�digo: %d\n\n\tCategoria: %s\n\n\tNome: %s\n\n\tQuantidade: %d\n\n\tPre�o: %d\n\n", novo->codigo
									 													   			 	 	   		   , novo->categoria
																										   	   		   , novo->nome
							 														       					   		   , novo->quantidade
																	   		 	           			 		   		   , novo->preco);
			system("cls");
			printf("\n\n\t\tDADOS ARMAZENADOS COM SUCESSO.\n\n\n\n");
			fclose(produtos);

			fflush(stdin);
			getch();
			system("cls");

		break;

		case 2:

			printf("\n\n\t\t[AVISO]:OS DADOS INSERIDOS N�O FORAM GUARDADOS.\n\n\n\n");

		break;
	}

	printf("\n\n\t\t");

	return novo;
}

void inserirProdutos(No **dado, produtos *item)
{
	if(*dado == NULL) // caso a arvore esteja vazia cria uma raiz com dois ramos
	{
		(*dado) = (No*) malloc (sizeof(No));
		(*dado) -> produto = item;
		(*dado) -> esq = NULL;
		(*dado) -> dir = NULL;


	}
	else
	{
		if(strcmp (item->nome, (*dado) -> produto->nome) == 1) //caso n�o estiver vazio vazio compara o nome com a raiz.
		{

			inserirProdutos(&(*dado) -> dir, item); // envia recursivamente para a direita caso seja maior

		}
		else

			inserirProdutos(&(*dado) -> esq, item); // envia recursivamente para a esquerda caso seja menor
	}
}

void mostrarPreOrdem(No *dado)
{
    if(dado != NULL)
	{
        printf("\n\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n", dado->produto->codigo
											 	   , dado->produto->nome
											 	   , dado->produto->categoria
											 	   , dado->produto->quantidade
											 	   , dado->produto->preco);

		mostrarPreOrdem(dado->esq);
        mostrarPreOrdem(dado->dir);
    }
}

void mostrarInOrdem(No *dado)
{
    if(dado != NULL)
	{
        mostrarPreOrdem(dado->esq);
        printf("\n\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n", dado->produto->codigo
												   , dado->produto->nome
												   , dado->produto->categoria
												   , dado->produto->quantidade
												   , dado->produto->preco);
        mostrarPreOrdem(dado->dir);
    }
}

void mostrarPosOrdem(No *dado)
{
    if(dado != NULL)
	{
        mostrarPreOrdem(dado->esq);
        mostrarPreOrdem(dado->dir);
        printf("\n\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n", dado->produto->codigo
												   , dado->produto->nome
												   , dado->produto->categoria
											       , dado->produto->quantidade
											 	   , dado->produto->preco);
    }
}

No* pesquisar(No *dado, char *nome)
{
	if(dado == NULL)
	{
		return NULL;
	}
	else
	{
		No *pesq_nome = dado;

		while(pesq_nome != NULL)
		{
			if(strcmp (pesq_nome -> produto -> nome, nome) == 0)
			{
				return pesq_nome;
		    }

			if(strcmp(pesq_nome -> produto -> nome, nome) == 1)
			{
				pesq_nome = pesq_nome->esq;
			}
			else
			{
				pesq_nome = pesq_nome->dir;
			}
		}

		return NULL;
	}
}

void modificar (No *dado, char nome[])
{
	No *mod_nome = pesquisar (dado, nome);

	if (mod_nome == NULL)
	{
		printf("\n\n\t\tO produto digitado n�o existe.\n\n\n\n\n\n\n");
	}
	else
	{
		mod_nome -> produto = prod_nome();
	}
}

No *minimo(No **no)
{
	if((*no) == NULL)
	{
		return NULL;
	}

	if((*no) -> esq != NULL)
	{

		return minimo(&(*no) -> esq);

	}
	else
	{
		No *proc = *no;

		if((*no)->dir != NULL) // caso houver no a direita  nao serao perdidos
		{
			*no = (*no)->dir;
		}
		else
		{

			*no = NULL;
		}

		return proc;
	}
}

bool eliminar (No* dado, char *nome)
{
	No *elim = pesquisar (dado,nome), *Aux = elim;
	if(elim != NULL)
	{
		if(elim -> dir == NULL && elim -> esq == NULL)
		{
			free (elim);
			elim = NULL;
			return true;
		}
		else if(elim -> dir != NULL && elim -> esq == NULL)
		{
			elim = elim -> dir;
			Aux->dir = NULL;
			free(Aux); Aux = NULL;
			return true;
		}
		else if(elim -> dir == NULL && elim -> esq != NULL)
		{
			elim = elim->esq;
			Aux -> esq = NULL;
			free (Aux);
			Aux = NULL;
			return true;
		}
		else if(elim -> dir != NULL && elim -> esq != NULL)
		{
			Aux = minimo (&elim -> dir);
			Aux -> dir = elim -> dir;
			Aux -> esq = elim -> esq;

			elim -> dir = elim -> esq = NULL;
			free(elim);
			elim = Aux;
			Aux = NULL;
		}
	}
	else
	{
		printf("\n\n\t\tO produto que pretende eliminar n�o existe");
		return false;
	}
}
