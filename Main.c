#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.c"
#include "Layout.c"

/*
	Name: Restaurante Universitário - Universidade Federal de Viçosa - Campus Rio Parabaíba
	Author: Nilzon Alves, Vinícius Hideyuki, Natalia Camillo
	Description: Programa de gerência o cardápio do R.U da UFV-CRP - Trabalho de estruturas de Dados.
	
	Instruções: 1º-> (Funcoes.c linha 328) Alterar o caminho para salvar o arquivo txt. file = fopen("caminho");
				2º-> (Main.c) linha 102) Descomentar/Comentar a linha que determina o fechamento do console, 
					  referente ao IDE que está utilizando(DevC++ ou Falcon) Comente as duas linhas caso use outro software.
*/

int main(){
	//possibilita colocar caracteres especiais.
	setlocale(LC_ALL, "Portuguese");
	
	tela_boas_vindas(); // Configurações de Layout, - apenas estética.
	
	//variaveis básicas
	int opc = -1, opc2 = -1;

	Celula *ptrlista;
	Cardapio cardapio;
	
	inicializar(&ptrlista);
	
		
	//MENU de opções.
	while (opc != 9){		
			
		menu_principal(); // exibe o menu com opções no sistema.
		scanf("%d",&opc);//le a opção, de acordo com o menu.
		
		switch(opc){

			case 1:
				imprimir(ptrlista);
				break;
				
			case 2:
				system("cls");
				if(lendo_cardapio(&ptrlista, &cardapio) == 1){
					inserir_elemento(&ptrlista, cardapio);
				}
				system("cls");
				break;
				
			case 3:
				if(empty(ptrlista)){
					printf("Lista vazia - Impossível remover. \n");
					system("pause");
					system("cls");
					break;
				}
				printf("Qual dia da semana deseja remover ?\n");
				printf("1: Domingo\n2: Segunda-Feira\n3: Terça-Feira\n4: Quarta-Feira\n5: Quinta-Feira\n6: Sexta-Feira\n7: Sábado\n\n9: Cancelar.\n");
				scanf("%d", &opc2);
				if(opc2 == 9){		
					system("cls");
					break;
				}else{
					remover_elemento(&ptrlista, opc2);
				}				
				break;
				
			case 4:
				if(empty(ptrlista)){
					printf("Lista vazia - Impossível Movimentar um cardápio. \n");
					system("pause");
					system("cls");
					break;
				}
				transpor_dados(&ptrlista);
				system("cls");
				break;
				
			case 5:
				if(empty(ptrlista)){
					printf("Lista vazia - Impossível Salvar em Arquivo. \n");
					system("pause");
					system("cls");
					break;
				}	
							
				salvar_arquivo(ptrlista);
				break;
				
			case 9: 		
				opc2 = MessageBox(0,"Deseja finalizar o programa\nRestaurante Universitário - UFV-CRP ?","Finalizando",MB_YESNO|MB_ICONQUESTION);
				if(opc2 == 6){
					opc = 9;
					while(!empty(ptrlista)){
						remover_elemento(&ptrlista, ptrlista->info.dia_semana);
					}
					//Força o fechamento do console, usando co TASKKILL.
					//system("TASKKILL /IM ConsoleRunner.exe"); //ConsoleRunner é o nome do Console do FalconC++ 
					system("TASKKILL /IM ConsolePauser.exe"); //ConsolePauser é o nome do Console do DevC++
			 	}else if(opc2 == 7){
			 		opc = 10;				 			
					system("cls");
					
				}
				
			case 10:
				//case usado, para atribuir 10 a variavel opc, e NAO cair no default, quando clicar em NAO para sair.
				break;
				
			default: 
				printf("Código Informado inválido. \n");		
				system("pause");
				system("cls");
				break;		
		}	
	
		fflush(stdin); // evitar a inserção de CHAR em INT, e travar o laço/programa. 
	}		
	return 0;
}
