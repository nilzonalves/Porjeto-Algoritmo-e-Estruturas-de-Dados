#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

void data_hora(){
		system("color F4");
		// utiliza��o de System Date e Time, apenas para auxilixar rapidamente o usu�rio em data e hora.
		printf("\t\t\t\t\t\t\t\t\t\t\t\tData Atual: "); system("\t\t\t\t\t\t\t\t\t\t\t\tDATE /t");
		printf("\t\t\t\t\t\t\t\t\t\t\t\tHora Atual: "); system("\t\t\t\t\t\t\t\t\t\t\t\tTIME /t");
		printf("\n");
}

void menu_principal(){
		data_hora(); // mostra data e hora no canto superior direito. Fun��o em outro arquivo.
		
		printf(" _______________________________________\n");
		printf("|                 Menu                  |\n");
		printf("|                                       |\n");
		printf("|   1: Imprimir Card�pio.               |\n");
		printf("|   2: Inserir Card�pio.                |\n");
		printf("|   3: Remover Card�pio.                |\n");
		printf("|   4: Alterar Ordem dos Card�pios.     |\n");
		printf("|   5: Exportar Dados em Arquivo.       |\n");
		printf("|   9: Finalizar Programa.              |\n");
		printf("|                                       |\n");
		printf("|_______________________________________|\n");
}

void tela_boas_vindas(){

	/////////////////Organiza��o de Interface.////////////////////
	
	//Aparece o texto informado na barra da janela do terminal.
	system("TITLE RESTAURANTE UNIVERSIT�RIO - UFV-CRP�");
	
	//cor: fundo branco, letras vermelhas.
	system("color F4");
	
	//idioma em portugues, para utiliza��o de caractere especial.
	setlocale(LC_ALL, "Portuguese"); 
	
	//tela de boas vindas
	printf("\t\t ___________________________________________________________________________\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|      Bem-vindo ao Sistema de Card�pio do Restaurante Universit�rio        |\n");
	printf("\t\t|         Universidade Federal de Vi�osa - Campus RIO PARANA�BA             |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|                                                                           |\n");
	printf("\t\t|___________________________________________________________________________|\n");

	system("pause");
	system("cls");
		
}