#ifndef _3_IN_ROW_
#define _3_IN_ROW_

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ModuleMinigames.h"


void ModuleMinigames::Iniciar_tablero(char mat[3][3]){
	int i, j;
	char con;
	con = '1';

	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			mat[i][j] = con++;
		}
	}
}

void ModuleMinigames::Tablero(const char mat[3][3]){
	int i, j;

	for (i = 0; i < 3; i++){
		printf("\n-------------\n");
		for (j = 0; j < 3; j++){
			if (j < 2){
				printf("| %c ", mat[i][j]);
			}
			else{
				printf("| %c |", mat[i][j]);
			}
		}
		if (i == 2){
			printf("\n-------------\n");
		}
	}
	printf("\n\n");
}

void ModuleMinigames::Yo_tirada(char mat[3][3]){
	int i, j, cont;
	char loc;
	printf("Para colocar tu ficha ( 'X' ) en la casilla pon el numero de dicha casilla.");
	do{
		do{
			printf("\nEn que posicion quieres poner tu ficha: ");
			fflush(stdin);//limpia variables
			scanf_s("%c", &loc);
		} while (loc < '1' || loc > '9');
		cont = 0;
		switch (loc){
		case '1':{
			i = 0;
			j = 0;
			break;
		}
		case '2':{
			i = 0;
			j = 1;
			break;
		}
		case '3':{
			i = 0;
			j = 2;
			break;
		}
		case '4':{
			i = 1;
			j = 0;
			break;
		}
		case '5':{
			i = 1;
			j = 1;
			break;
		}
		case '6':{
			i = 1;
			j = 2;
			break;
		}
		case '7':{
			i = 2;
			j = 0;
			break;
		}
		case '8':{
			i = 2;
			j = 1;
			break;
		}
		case '9':{
			i = 2;
			j = 2;
			break;
		}
		}
		if (mat[i][j] == 'X' || mat[i][j] == 'O'){
			cont = 1;
			printf("Error, ya hay una ficha colocada aqui!!");
		}
	} while (cont == 1);
	mat[i][j] = 'X';

}

void ModuleMinigames::Pc_tirada(char mat[3][3]){

	int i, j, con;

	srand(time(NULL));
	do{
		i = rand() % 3;
		j = rand() % 3;
		con = 0;

		if (mat[i][j] == 'X' || mat[i][j] == 'O'){
			con = 1;
		}
	} while (con == 1);
	mat[i][j] = 'O';
}

int Ganador(const char mat[3][3]){

	//OPTIMIZE TEST
	int h = 0;
	//Vertical lines
	for (int k = 0; k < 3; k++){
		if (mat[h][k] == mat[h + 1][k] && mat[h][k] == mat[h + 2][k]){
			if (mat[h][k] == 'X'){
				return 0; //he ganado
			}
			else{
				return 1; //he perdido
			}
		}
	}
	//Horizontal lines
	for (int k = 0; k < 3; k++){
		if (mat[k][h] == mat[k][h + 1] && mat[k][h] == mat[k][h + 2]) {
			if (mat[k][h] == 'X'){
				return 0; //he ganado
			}
			else{
				return 1; //he perdido
			}
		}
	}
	//Diagonal lines
	if (mat[0][0] == mat[1][1] && mat[h][h] == mat[2][2]){
		if (mat[0][0] == 'X'){
			return 0; //he ganado
		}
		else{
			return 1; //he perdido
		}
	}
	if (mat[0][2] == mat[1][1] && mat[0][2] == mat[2][0]){
		if (mat[0][2] == 'X'){
			return 0; //he ganado
		}
		else{
			return 1; //he perdido
		}
	}
	return 2;
}

void ModuleMinigames::funciones(char mat[3][3]){
	int i = 0, j;

	Iniciar_tablero(mat);

	do{
		system("cls");//limpia la pantalla
		Tablero(mat);
		if (i % 2 == 0){
			Yo_tirada(mat);
		}
		else{
			Pc_tirada(mat);
		}
		j = Ganador(mat);
		i++;


	} while (i < 9 && j == 2);//mientras se cumplan las 2 variables, el bucle do-while ira haciendose

	system("cls");
	Tablero(mat);

	if (j == 0){
		system("COLOR 2");//Si ganas las letras se pondran verde
		printf("Has ganado!!\n\n");
	}
	else if (j == 1){
		system("COLOR 4");//Si pierdes las letras se pondran rojas
		printf("Has perdido!!\n\n");
	}
	else{
		system("COLOR 6");//Si empatas las letras se pondran amarillas
		printf("Has empatado!!\n\n");
	}
}
*/
#endif