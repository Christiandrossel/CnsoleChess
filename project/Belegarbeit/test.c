#include <stdio.h>
#include<windows.h>
#include<string.h>


char Feld[8][8];

struct eingabe {
	char b1;
	int z1;
	char b2;
	int z2;
}black,white;

char schachbrett() {
	int i, j;
	int z = 8;
    char b = 'a';
	

	printf(" ");
	for (i = 0; i < 8; i++) {
		printf(" %c  ", b++);
	}
	printf("\n");
				
		for (i = 0; i < 8; i++) {
			printf("+-------------------------------+\n");
			  for (j = 0; j < 8; j++) {
				printf("| %c ", Feld[i][j]);			//i ist die Spalte j die Zeile
				
			}printf("|%d\n",z--);
		}
		printf("+-------------------------------+\n");
		return 0;
	}
void figuren() {
	
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			Feld[i][j] = '\0';
		}
	}

	Feld[0][0] = 'T', Feld[1][0] = 'B';
	Feld[0][1] = 'S', Feld[1][1] = 'B';
	Feld[0][2] = 'L', Feld[1][2] = 'B';
	Feld[0][3] = 'K', Feld[1][3] = 'B';
	Feld[0][4] = 'D', Feld[1][4] = 'B';
	Feld[0][5] = 'L', Feld[1][5] = 'B';
	Feld[0][6] = 'S', Feld[1][6] = 'B';
	Feld[0][7] = 'T', Feld[1][7] = 'B';

	Feld[7][0] = 't', Feld[6][0] = 'b';
	Feld[7][1] = 's', Feld[6][1] = 'b';
	Feld[7][2] = 'l', Feld[6][2] = 'b';
	Feld[7][3] = 'k', Feld[6][3] = 'b';
	Feld[7][4] = 'd', Feld[6][4] = 'b';
	Feld[7][5] = 'l', Feld[6][5] = 'b';
	Feld[7][6] = 's', Feld[6][6] = 'b';
	Feld[7][7] = 't', Feld[6][7] = 'b';
}

char Konvertierung() {
	

}

int Eingabe() {
	int vx,vy,nx,ny;
	int i, j;
	//wer ist drann...
	//Zug eingabe
	printf("Geben sie ihren Zug an: ");
	scanf("%d%d%d%d", &vx,&vy,&nx,&ny);

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (Feld[i][j] == Feld[vx][vy]) {
				Feld[nx][ny] = Feld[i][j];
				Feld[i][j] = 0;

			
			}
		}
	}
	
	//strcpy(quelle, ziel)

//Speichert Figur bevor löschen
	/*figur = Feld[delX][delY];
	printf("%c", figur);*/
//lösche Figur im erst gewählten Feld
	//Feld[delX][delY] = 0;
//setzte Figur in das Zweite gewählte Feld
	//Feld[makeX][makeY] = figur;


	//Überprüfe Zug.
		//konvertierung der Buchstaben
	
		
	return 0;
}

int speichern() {
	FILE *fp;
	int i, j;
	fp = fopen("Schachbrett.txt", "w");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			fprintf(fp, " %d ", Feld[i][j]);
		}fprintf(fp, "\n");
	}
	return 0;
}

void main() {
	int b, d, i, j, delX, delY, makeX, makeY;
	char a, c, figur;
	char Feld[8][8];
	//Wir brauchen ein Schachbrett
	figuren();
	schachbrett();
	Eingabe();
	//Anweisung das der DAU Eingabe

	//Zug eingabe
	
	//strcpy(quelle, ziel)

	
//while(Eingabe(&Feld[8][8],&delx,&dely,&makex,&makey,&figur)==0);{
		
		
	
	//überprüfung gültiger spielzug
	//Ausführen der Eingabe
	//Abspeichern in ein txt dokument
		//speichern(&Feld[8][8]);



}