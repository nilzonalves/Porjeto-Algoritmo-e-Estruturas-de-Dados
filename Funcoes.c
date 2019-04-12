#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

//- ////////////////////////// ESTRUTURAS UTILIZADAS //////////////////////////

typedef struct sCardapio{
	int dia_semana;
	char salada_1[50];
	char prato_principal_1[50];
	char opc_vegetariana_1[50];
	char guarnicao_1[50];
	char sobremesa_1[20];
	
	char salada_2[50];
	char prato_principal_2[50];
	char opc_vegetariana_2[50];
	char guarnicao_2[50];
	char sobremesa_2[20];
}Cardapio;

typedef struct sCelula{
	Cardapio info;   
	struct sCelula* next;
}Celula;

//- ////////////////////////// FUN��ES B�SICAS //////////////////////////

void inicializar(Celula **ptrlista){
	*ptrlista = NULL;
	
}

Celula* getnode(){
	return (Celula*)malloc(sizeof(Celula));
}

void freenode(Celula* no){
	free(no);
}

int empty(Celula* lista){
	if(lista == NULL){
		return 1;
	}else{
		return 0;
	}
}

//- ////////////////////////// FUN��ES UTILIZADAS //////////////////////////

Celula* pesquisa(Celula *lista, int elem){
	Celula *aux,*aux2;
	
	if(!empty(lista)){
		aux = lista;
		aux2 = lista;
		do{
			if(aux->info.dia_semana == elem){
				return aux;
				//printf("Dia da Semana: %d\n", aux->info.dia_semana);	
			}
			aux = aux->next;
			
		}while(aux2 != aux);	
	}
	return NULL;
}


/////////////////////////// PRIMEIRA FUN��O DO MENU /////////////////////

void imprimir(Celula *lista){
	if(empty(lista)){
		printf("N�o h� card�pio para exibir.\n");
		system("pause");
		system("cls");
		return;
	}

	Celula *aux;
	aux = lista->next;	
	
	char semanas[7][15] = {"Domingo","Segunda-Feira", "Ter�a-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "S�bado"};

	char seta = 187;// caractere que representa uma SETA para direita (apenas est�tica). 
	do{
		printf("\n|%s|\n", semanas[aux->info.dia_semana-1]);
		
		printf("\tAlmo�o: \n");
		printf("%c Salada: %s \n", seta, aux->info.salada_1);
		printf("%c Prato Principal: %s \n", seta, aux->info.prato_principal_1);
		printf("%c Op��o Vegetariana: %s \n", seta, aux->info.opc_vegetariana_1);
		printf("%c Guarni��o: %s \n", seta, aux->info.guarnicao_1);
		printf("%c Sobremesa: %s \n", seta, aux->info.sobremesa_1);
		
		if(aux->info.dia_semana != 1 && aux->info.dia_semana != 7){
			printf("\n \tJantar: \n");
			printf("%c Salada: %s \n", seta, aux->info.salada_2);
			printf("%c Prato Principal: %s \n", seta, aux->info.prato_principal_2);
			printf("%c Op��o Vegetariana: %s \n", seta, aux->info.opc_vegetariana_2);
			printf("%c Guarni��o: %s \n", seta, aux->info.guarnicao_2);
			printf("%c Sobremesa: %s \n", seta, aux->info.sobremesa_2);
		}		
		
		printf("-------------------------------\n");
		aux = aux->next;
		
	}while (aux != lista->next);

	printf("\n");
	system("pause");
	system("cls");
}

/////////////////////////// SEGUNDA FUN��O DO MENU /////////////////////

// Fun��o utilizada para LER o card�pio digitado pelo usu�rio.
int lendo_cardapio(Celula **lista, Cardapio *cardapio){	
	
	printf("Esse card�pio � para qual dia da semana ?\n\n");
	printf("1: Domingo\n2: Segunda Feira.\n3: Ter�a Feira\n4: Quarta Feira.\n5: Quinta Feira.\n6: Sexta Feira.\n7: S�bado.\n\n9: Cancelar.\n");
	scanf("%d", &cardapio->dia_semana);	
	Celula *no;
	
	no = pesquisa(*lista, cardapio->dia_semana);
	
	if(no != NULL){
		printf("Dia da semana j� esta presente no sistema. \n");
		system("pause");
		return 0;
	}
	
	if(cardapio->dia_semana == 9){		
		return 0;
		system("cls");
	}else{
		
		fflush(stdin);
		printf("ALMO�O: Informe a salada: \n");
		gets(cardapio->salada_1);
		printf("ALMO�O: Informe o prato principal: \n");
		gets(cardapio->prato_principal_1);
		printf("ALMO�O: Informe a op��o vegetariana: \n");
		gets(cardapio->opc_vegetariana_1);
		printf("ALMO�O: Informe a guarni��o: \n");
		gets(cardapio->guarnicao_1);
		printf("ALMO�O: Informe a sobremesa: \n");
		gets(cardapio->sobremesa_1);

		if(cardapio->dia_semana != 1 && cardapio->dia_semana != 7){
			
			printf("JANTAR: Informe a salada: \n");
			gets(cardapio->salada_2);
			printf("JANTAR: Informe o prato principal: \n");
			gets(cardapio->prato_principal_2);
			printf("JANTAR: Informe a op��o vegetariana: \n");
			gets(cardapio->opc_vegetariana_2);
			printf("JANTAR: Informe a guarni��o: \n");
			gets(cardapio->guarnicao_2);
			printf("JANTAR: Informe a sobremesa: \n");
			gets(cardapio->sobremesa_2);
		}	
	}	
	return 1;
}

//Fun��o utilizada para fazer a atribui��o dos valores informado pelo usu�rio, na Struct card�pio.
void atribuir_cardapio(Cardapio card, Celula *no){
	no->info.dia_semana = card.dia_semana;
	strcpy(no->info.salada_1, card.salada_1);
	strcpy(no->info.prato_principal_1, card.prato_principal_1);
	strcpy(no->info.opc_vegetariana_1, card.opc_vegetariana_1);
	strcpy(no->info.guarnicao_1, card.guarnicao_1);
	strcpy(no->info.sobremesa_1, card.sobremesa_1);	
		
	no->info.dia_semana = card.dia_semana;
	strcpy(no->info.salada_2, card.salada_2);
	strcpy(no->info.prato_principal_2, card.prato_principal_2);
	strcpy(no->info.opc_vegetariana_2, card.opc_vegetariana_2);
	strcpy(no->info.guarnicao_2, card.guarnicao_2);
	strcpy(no->info.sobremesa_2, card.sobremesa_2);
	
}

void inserir_elemento (Celula **lista, Cardapio elem){
	
	Celula *no;
	
	no = getnode();
	
	atribuir_cardapio(elem, no);
	
	if(no != NULL){
		
		if(empty(*lista)){
			*lista = no;
			no->next = no;
		}else{
			no->next = (*lista)->next;
			(*lista)->next = no;
			(*lista)= no;
		}
	}else{
		printf("Erro na cria��o do n�. \n");
	}
}

/////////////////////////// TERCEIRA FUN��O DO MENU /////////////////////

int remover_elemento(Celula **lista, int elem){
	
	Celula *aux, *aux2;
	Celula *no;
	aux2 = *lista;
	
		//no PRIMEIRO IF, *no recebe o n� retornado da fun��o pesquisa, cujo o elemento (elem) � igual/se foi encontrado.
		//ou seja, *no cont�m a estrutura do elem informado pelo usu�rio.
		if((no = pesquisa(*lista, elem)) != NULL){
			aux = *lista;
			if(aux == no){
				//if para remover o elemento, caso ele seja o UNICO da lista.
				if(no->next == no){
					*lista = NULL;
					freenode(no);
					system("cls");
					return 1; 
				}
				
				while(aux2->next != no){
					aux2 = aux2->next;					
				}
				(*lista) = aux2;
				aux2->next = aux->next;
				freenode(aux);
				system("cls");
				return 1;
			}else{
				while(aux->next != no){
					aux = aux->next;
				}
				system("cls");
				aux->next = no->next;
				freenode(no);
				return 1;
			}
		
		}
	system("Card�pio removido com sucesso. \n");
	system("pause");
	system("cls");
	return 1;
}

/////////////////////////// QUARTA FUN��O DO MENU /////////////////////

int transpor_dados(Celula **lista){
	
    Celula *aux,*ant,*ant2, *no;
    
    ant = (*lista);
    aux = (*lista)->next;
    ant2 = (*lista);
    
    int x;
    
    printf("Qual dia deseja alternar pra frente?\n \n");
    printf("1: Domingo\n2: Segunda-Feira\n3: Ter�a-Feira\n4: Quarta-Feira\n5: Quinta-Feira\n6: Sexta-Feira\n7: S�bado\n\n9: Cancelar\n");
	scanf("%d", &x);				
    
    if(x == 9){	
    	system("cls");
    	return 0;
	}
    //verificando se a lista tem apenas 1(UM) elemento.
   if(aux->next == aux){
    	printf("N�o foi poss�vel realizar a transposicao!\n");
    	printf("So h� um card�pio no registro!\n");
    	return 0;
	}
	
	//verificando se a lista tem 2 (DOIS) elementos.
	if((*lista)->next->next == (*lista)){
		(*lista) = aux;
		return 1;
	}	
	
    no = pesquisa(*lista, x); // novo N� recebe o elemento que deseja transpor para frente. 
	aux = no->next;// Inicializando o AUX para ter valores de ANT e ANT2.
	
	//percorre a lista at� achar o N� desejado.
	while(aux != no){
		ant2 = ant;
		ant = aux;
		aux = aux->next;
	}
	
	//movimenta��es da transposi��o
	ant->next = aux->next;
	aux->next = ant;
	ant2->next = aux;
	
	//definindo o ponteiro LISTA novamente no ULTIMO elemento da lista. SE, o ANT estiver na ultima posi��o
	if(*lista == ant){
		*lista = aux;
		return 1;
	}
	
	//definindo o ponteiro LISTA novamente no ULTIMO elemento da lista. SE, o AUX estiver na ultima posi��o
	if((*lista) == aux){
		(*lista) = ant;
	}
	

	return 1;  
}

/////////////////////////// QUINTA FUN��O DO MENU /////////////////////

void salvar_arquivo(Celula *cardapio){
	//vetor de dia da semana, para imprimir por extenso a semana no arquivo.
	char semanas[7][15] = {"Domingo","Segunda-Feira", "Ter�a-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "S�bado"};
	
	//cria��o do ponteiro para criar o arquivo texto.
	FILE* file;
	file = fopen("C:\\Users\\Nilzon Alves\\Desktop\\trabalho\\Cardapio.txt", "w");
	
	Celula *no;
	
	int opc;
	system("cls");
	
	printf("Card�pio de qual dia da semana deseja Salvar em Arquivo ?\n");
	printf("1: Domingo\n2: Segunda-Feira\n3: Ter�a-Feira\n4: Quarta-Feira\n5: Quinta-Feira\n6: Sexta-Feira\n7: S�bado\n\n9: Cancelar\n"); 
	scanf("%d", &opc);
	
	if(opc == 9){
		system("cls");
		return;
	}
	
	no = pesquisa(cardapio, opc); // a fun��o pesquisa, retorna o N� com o dia da semana pesquisado.
	
	if(no == NULL){
		printf("\aO dia da semana informado, n�o h� card�pio para ser salvo. \n");
		system("pause");
		system("cls");
		return;
	}
	
	char dateStr[9];
	
	// pega a data atual
	_strdate( dateStr);
	
	//armazena os dias corretamente, pois a formata��o retornada, nao � no formato BR.
	char dia[2]={dateStr[3],dateStr[4]}; //INDICE 3 e 4 e nao o 0 e 1, porque a data, est� no formato americano. 
	char mes[3]={dateStr[0],dateStr[1]};
	char ano[2]={dateStr[6],dateStr[7]};
	
	// Armazenando a DATA ATUAL no topo do arquivo gerado. 
	fprintf(file, "Card�pio oferecido na Data: %s/%s/20%s\n\n",dia,mes,ano);	
	
	int indice = no->info.dia_semana; //pega o dia da semana que ESTA EM TIPO INTEIRO. Armazena em INDICE, para poder ser usada no vetor na linha abaixo.
	fprintf(file, "\n Almo�o: \n");
	fprintf(file, "Dia da semana: %s \n", semanas[indice-1]);
	fprintf(file, "Salada: %s \n", no->info.salada_1);
	fprintf(file, "Prato Principal: %s \n", no->info.prato_principal_1);
	fprintf(file, "Op��o Vegetariana: %s \n", no->info.opc_vegetariana_1);
	fprintf(file, "Guarni��o: %s \n", no->info.guarnicao_1);
	fprintf(file, "Sobremesa: %s \n", no->info.sobremesa_1);

	if(indice != 1 && indice != 7){
		fprintf(file, "\n Jantar: \n");
		fprintf(file, "Dia da semana: %s \n", semanas[indice-1]);
		fprintf(file, "Salada: %s \n", no->info.salada_2);
		fprintf(file, "Prato Principal: %s \n", no->info.prato_principal_2);
		fprintf(file, "Op��o Vegetariana: %s \n", no->info.opc_vegetariana_2);
		fprintf(file, "Guarni��o: %s \n", no->info.guarnicao_2);
		fprintf(file, "Sobremesa: %s \n", no->info.sobremesa_2);
	}		
				
	printf("Aquivo gerado.\n");
	system("pause");
	system("cls");
		
	fclose(file);
}
