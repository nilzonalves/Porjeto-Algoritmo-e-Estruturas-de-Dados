#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

void data_hora(){
		system("color F4");
		// utilização de System Date e Time, apenas para auxilixar rapidamente o usuário em data e hora.
		printf("\t\t\t\t\t\t\t\t\t\t\t\tData Atual: "); system("\t\t\t\t\t\t\t\t\t\t\t\tDATE /t");
		printf("\t\t\t\t\t\t\t\t\t\t\t\tHora Atual: "); system("\t\t\t\t\t\t\t\t\t\t\t\tTIME /t");
		printf("\n");
}

void menu_principal(){
		data_hora(); // mostra data e hora no canto superior direito. Função em outro arquivo.
		
		printf(" _______________________________________\n");
		printf("|                 Menu                  |\n");
		printf("|                                       |\n");
		printf("|   1: Imprimir Cardápio.               |\n");
		printf("|   2: Inserir Cardápio.                |\n");
		printf("|   3: Remover Cardápio.                |\n");
		printf("|   4: Alterar Ordem dos Cardápios.     |\n");
		printf("|   5: Exportar Dados em Arquivo.       |\n");
		printf("|   9: Finalizar Programa.              |\n");
		printf("|                                       |\n");
		printf("|_______________________________________|\n");
}

void tela_boas_vindas(){

	/////////////////Organização de Interface.////////////////////
	
	//Aparece o texto informado na barra da janela do terminal.
	system("TITLE RESTAURANTE UNIVERSITÁRIO - UFV-CRP®");
	
	//cor: fundo branco, letras vermelhas.
	system("color F4");
	
	//idioma em portugues, para utilização de caractere especial.
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
	printf("\t\t|      Bem-vindo ao Sistema de Cardápio do Restaurante Universitário        |\n");
	printf("\t\t|         Universidade Federal de Viçosa - Campus RIO PARANAÍBA             |\n");
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