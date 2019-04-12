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

//- ////////////////////////// FUNÇÕES BÁSICAS //////////////////////////

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

//- ////////////////////////// FUNÇÕES UTILIZADAS //////////////////////////

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


/////////////////////////// PRIMEIRA FUNÇÃO DO MENU /////////////////////

void imprimir(Celula *lista){
	if(empty(lista)){
		printf("Não há cardápio para exibir.\n");
		system("pause");
		system("cls");
		return;
	}

	Celula *aux;
	aux = lista->next;	
	
	char semanas[7][15] = {"Domingo","Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sábado"};

	char seta = 187;// caractere que representa uma SETA para direita (apenas estética). 
	do{
		printf("\n|%s|\n", semanas[aux->info.dia_semana-1]);
		
		printf("\tAlmoço: \n");
		printf("%c Salada: %s \n", seta, aux->info.salada_1);
		printf("%c Prato Principal: %s \n", seta, aux->info.prato_principal_1);
		printf("%c Opção Vegetariana: %s \n", seta, aux->info.opc_vegetariana_1);
		printf("%c Guarnição: %s \n", seta, aux->info.guarnicao_1);
		printf("%c Sobremesa: %s \n", seta, aux->info.sobremesa_1);
		
		if(aux->info.dia_semana != 1 && aux->info.dia_semana != 7){
			printf("\n \tJantar: \n");
			printf("%c Salada: %s \n", seta, aux->info.salada_2);
			printf("%c Prato Principal: %s \n", seta, aux->info.prato_principal_2);
			printf("%c Opção Vegetariana: %s \n", seta, aux->info.opc_vegetariana_2);
			printf("%c Guarnição: %s \n", seta, aux->info.guarnicao_2);
			printf("%c Sobremesa: %s \n", seta, aux->info.sobremesa_2);
		}		
		
		printf("-------------------------------\n");
		aux = aux->next;
		
	}while (aux != lista->next);

	printf("\n");
	system("pause");
	system("cls");
}

/////////////////////////// SEGUNDA FUNÇÃO DO MENU /////////////////////

// Função utilizada para LER o cardápio digitado pelo usuário.
int lendo_cardapio(Celula **lista, Cardapio *cardapio){	
	
	printf("Esse cardápio é para qual dia da semana ?\n\n");
	printf("1: Domingo\n2: Segunda Feira.\n3: Terça Feira\n4: Quarta Feira.\n5: Quinta Feira.\n6: Sexta Feira.\n7: Sábado.\n\n9: Cancelar.\n");
	scanf("%d", &cardapio->dia_semana);	
	Celula *no;
	
	no = pesquisa(*lista, cardapio->dia_semana);
	
	if(no != NULL){
		printf("Dia da semana já esta presente no sistema. \n");
		system("pause");
		return 0;
	}
	
	if(cardapio->dia_semana == 9){		
		return 0;
		system("cls");
	}else{
		
		fflush(stdin);
		printf("ALMOÇO: Informe a salada: \n");
		gets(cardapio->salada_1);
		printf("ALMOÇO: Informe o prato principal: \n");
		gets(cardapio->prato_principal_1);
		printf("ALMOÇO: Informe a opção vegetariana: \n");
		gets(cardapio->opc_vegetariana_1);
		printf("ALMOÇO: Informe a guarnição: \n");
		gets(cardapio->guarnicao_1);
		printf("ALMOÇO: Informe a sobremesa: \n");
		gets(cardapio->sobremesa_1);

		if(cardapio->dia_semana != 1 && cardapio->dia_semana != 7){
			
			printf("JANTAR: Informe a salada: \n");
			gets(cardapio->salada_2);
			printf("JANTAR: Informe o prato principal: \n");
			gets(cardapio->prato_principal_2);
			printf("JANTAR: Informe a opção vegetariana: \n");
			gets(cardapio->opc_vegetariana_2);
			printf("JANTAR: Informe a guarnição: \n");
			gets(cardapio->guarnicao_2);
			printf("JANTAR: Informe a sobremesa: \n");
			gets(cardapio->sobremesa_2);
		}	
	}	
	return 1;
}

//Função utilizada para fazer a atribuição dos valores informado pelo usuário, na Struct cardápio.
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
		printf("Erro na criação do nó. \n");
	}
}

/////////////////////////// TERCEIRA FUNÇÃO DO MENU /////////////////////

int remover_elemento(Celula **lista, int elem){
	
	Celula *aux, *aux2;
	Celula *no;
	aux2 = *lista;
	
		//no PRIMEIRO IF, *no recebe o nó retornado da função pesquisa, cujo o elemento (elem) é igual/se foi encontrado.
		//ou seja, *no contém a estrutura do elem informado pelo usuário.
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
	system("Cardápio removido com sucesso. \n");
	system("pause");
	system("cls");
	return 1;
}

/////////////////////////// QUARTA FUNÇÃO DO MENU /////////////////////

int transpor_dados(Celula **lista){
	
    Celula *aux,*ant,*ant2, *no;
    
    ant = (*lista);
    aux = (*lista)->next;
    ant2 = (*lista);
    
    int x;
    
    printf("Qual dia deseja alternar pra frente?\n \n");
    printf("1: Domingo\n2: Segunda-Feira\n3: Terça-Feira\n4: Quarta-Feira\n5: Quinta-Feira\n6: Sexta-Feira\n7: Sábado\n\n9: Cancelar\n");
	scanf("%d", &x);				
    
    if(x == 9){	
    	system("cls");
    	return 0;
	}
    //verificando se a lista tem apenas 1(UM) elemento.
   if(aux->next == aux){
    	printf("Não foi possível realizar a transposicao!\n");
    	printf("So há um cardápio no registro!\n");
    	return 0;
	}
	
	//verificando se a lista tem 2 (DOIS) elementos.
	if((*lista)->next->next == (*lista)){
		(*lista) = aux;
		return 1;
	}	
	
    no = pesquisa(*lista, x); // novo NÓ recebe o elemento que deseja transpor para frente. 
	aux = no->next;// Inicializando o AUX para ter valores de ANT e ANT2.
	
	//percorre a lista até achar o NÓ desejado.
	while(aux != no){
		ant2 = ant;
		ant = aux;
		aux = aux->next;
	}
	
	//movimentações da transposição
	ant->next = aux->next;
	aux->next = ant;
	ant2->next = aux;
	
	//definindo o ponteiro LISTA novamente no ULTIMO elemento da lista. SE, o ANT estiver na ultima posição
	if(*lista == ant){
		*lista = aux;
		return 1;
	}
	
	//definindo o ponteiro LISTA novamente no ULTIMO elemento da lista. SE, o AUX estiver na ultima posição
	if((*lista) == aux){
		(*lista) = ant;
	}
	

	return 1;  
}

/////////////////////////// QUINTA FUNÇÃO DO MENU /////////////////////

void salvar_arquivo(Celula *cardapio){
	//vetor de dia da semana, para imprimir por extenso a semana no arquivo.
	char semanas[7][15] = {"Domingo","Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sábado"};
	
	//criação do ponteiro para criar o arquivo texto.
	FILE* file;
	file = fopen("C:\\Users\\Nilzon Alves\\Desktop\\trabalho\\Cardapio.txt", "w");
	
	Celula *no;
	
	int opc;
	system("cls");
	
	printf("Cardápio de qual dia da semana deseja Salvar em Arquivo ?\n");
	printf("1: Domingo\n2: Segunda-Feira\n3: Terça-Feira\n4: Quarta-Feira\n5: Quinta-Feira\n6: Sexta-Feira\n7: Sábado\n\n9: Cancelar\n"); 
	scanf("%d", &opc);
	
	if(opc == 9){
		system("cls");
		return;
	}
	
	no = pesquisa(cardapio, opc); // a função pesquisa, retorna o NÓ com o dia da semana pesquisado.
	
	if(no == NULL){
		printf("\aO dia da semana informado, não há cardápio para ser salvo. \n");
		system("pause");
		system("cls");
		return;
	}
	
	char dateStr[9];
	
	// pega a data atual
	_strdate( dateStr);
	
	//armazena os dias corretamente, pois a formatação retornada, nao é no formato BR.
	char dia[2]={dateStr[3],dateStr[4]}; //INDICE 3 e 4 e nao o 0 e 1, porque a data, está no formato americano. 
	char mes[3]={dateStr[0],dateStr[1]};
	char ano[2]={dateStr[6],dateStr[7]};
	
	// Armazenando a DATA ATUAL no topo do arquivo gerado. 
	fprintf(file, "Cardápio oferecido na Data: %s/%s/20%s\n\n",dia,mes,ano);	
	
	int indice = no->info.dia_semana; //pega o dia da semana que ESTA EM TIPO INTEIRO. Armazena em INDICE, para poder ser usada no vetor na linha abaixo.
	fprintf(file, "\n Almoço: \n");
	fprintf(file, "Dia da semana: %s \n", semanas[indice-1]);
	fprintf(file, "Salada: %s \n", no->info.salada_1);
	fprintf(file, "Prato Principal: %s \n", no->info.prato_principal_1);
	fprintf(file, "Opção Vegetariana: %s \n", no->info.opc_vegetariana_1);
	fprintf(file, "Guarnição: %s \n", no->info.guarnicao_1);
	fprintf(file, "Sobremesa: %s \n", no->info.sobremesa_1);

	if(indice != 1 && indice != 7){
		fprintf(file, "\n Jantar: \n");
		fprintf(file, "Dia da semana: %s \n", semanas[indice-1]);
		fprintf(file, "Salada: %s \n", no->info.salada_2);
		fprintf(file, "Prato Principal: %s \n", no->info.prato_principal_2);
		fprintf(file, "Opção Vegetariana: %s \n", no->info.opc_vegetariana_2);
		fprintf(file, "Guarnição: %s \n", no->info.guarnicao_2);
		fprintf(file, "Sobremesa: %s \n", no->info.sobremesa_2);
	}		
				
	printf("Aquivo gerado.\n");
	system("pause");
	system("cls");
		
	fclose(file);
}
