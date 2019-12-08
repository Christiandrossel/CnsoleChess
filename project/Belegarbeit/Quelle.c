#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>


char Feld[8][8] = { 0 };
enum Spielerfarbe { schwarz = 1, weiss }farbe;

struct undo {
	char figur;
	char vx;
	char vy;
	char nx;
	char ny;
	int farbe;

}undo[500];


char schachbrett() {
	int i, j;
	int z1 = 8;
	int z2 = 8;
	char b = 'a';


	printf("   ");
	for (i = 8; i > 0; i--) {
		printf(" %c  ", b++);
	}
	printf("\n");

	for (i = 7; i >= 0; i--) {
		printf("  +-------------------------------+\n");
		printf(" %d", z1--);
		for (j = 7; j >= 0; j--) {
			printf("| %c ", Feld[j][i]);			//j ist die Spalte i die Zeile

		}printf("|%d\n", z2--);
	}
	printf("  +-------------------------------+\n");
	b = 'a';
	printf("   ");
	for (i = 8; i > 0; i--) {
		printf(" %c  ", b++);
	}
	printf("\n");
	return 0;
}

void figuren() {

	Feld[0][0] = 'T', Feld[0][1] = 'B';
	Feld[1][0] = 'S', Feld[1][1] = 'B';
	Feld[2][0] = 'L', Feld[2][1] = 'B';
	Feld[3][0] = 'K', Feld[3][1] = 'B';
	Feld[4][0] = 'D', Feld[4][1] = 'B';
	Feld[5][0] = 'L', Feld[5][1] = 'B';
	Feld[6][0] = 'S', Feld[6][1] = 'B';
	Feld[7][0] = 'T', Feld[7][1] = 'B';

	Feld[0][7] = 't', Feld[0][6] = 'b';
	Feld[1][7] = 's', Feld[1][6] = 'b';
	Feld[2][7] = 'l', Feld[2][6] = 'b';
	Feld[3][7] = 'k', Feld[3][6] = 'b';
	Feld[4][7] = 'd', Feld[4][6] = 'b';
	Feld[5][7] = 'l', Feld[5][6] = 'b';
	Feld[6][7] = 's', Feld[6][6] = 'b';
	Feld[7][7] = 't', Feld[7][6] = 'b';
}

int konvertierebst(char *xvar) {
	int vx;
	int hilf1 = (char)xvar;
	switch (hilf1) {
	case 97: vx = 7; return vx;
	case 98: vx = 6; return vx;
	case 99: vx = 5; return vx;
	case 100: vx = 4; return vx;
	case 101: vx = 3; return vx;
	case 102: vx = 2; return vx;
	case 103: vx = 1; return vx;
	case 104: vx = 0; return vx;
	}
}

int konvertierez(char *yvar) {

	int vy;
	int hilf1 = (char)yvar;
	printf("hilf %d\n", hilf1);
	switch (hilf1) {
	case 56: vy = 7; return vy;
	case 55: vy = 6; return vy;
	case 54: vy = 5; return vy;
	case 53: vy = 4; return vy;
	case 52: vy = 3; return vy;
	case 51: vy = 2; return vy;
	case 50: vy = 1; return vy;
	case 49: vy = 0; return vy;
	}
}


int Eingabe(char var, char vcx, char vcy, char ncx, char ncy, int laufnr) { //von x und nach x als char Wert also a,b,c usw.
	int i, j;
	int vx, nx, vy, ny, wert;
	int z = 6;
	char figur;
	int regel = 0;
	printf("Wert nach übergabe -> vx: %c   vy: %c   nx: %c   ny: %c  farbe: %d\n", vcx, vcy, ncx, ncy, farbe);

	vx = konvertierebst(vcx);				//vx ist die Spalte
	vy = konvertierez(vcy);					//vy ist die Zeile
	nx = konvertierebst(ncx);
	ny = konvertierez(ncy);
	printf("Werte nach Konvertierung -> vx: %d   vy: %d   nx: %d   ny: %d\n", vx, vy, nx, ny);

	if ((vx >= 0) && (vx < 8) && (vy >= 0) && (vy < 8) && (nx >= 0) && (nx < 8) && (ny >= 0) && (ny < 8)) {
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (Feld[j][i] == Feld[vx][vy]) {
					figur = Feld[vx][vy];

					printf("figur %c\n", figur);
					if (var == 'e') {
						undo[laufnr].figur = Feld[nx][ny]; printf("Gespeicherte Figur: %c\n", undo[laufnr].figur);
						regel = Regel(figur, vx, vy, nx, ny);
						printf("regel: %d\n", regel);
						if (regel == 0) {
							printf("*****Der Zug entspricht nicht den Regeln*****\n");
							return -1;
						}
					}

					if (farbe == schwarz) {
						wert = islower(figur);	//Liefert 1 zurück wenn großer Buchstabe
					}
					else
						if (farbe == weiss) {
							wert = isupper(figur);
						}
					printf("wert %d\n", wert);
					if (wert) {		//Untersuche ob richtiger stein genommen wurde
						printf("Figur hat jetzt den Wert: %c\n Das Feld hat den Wert: %c\n", figur, Feld[j][i]);
						//Untersuche je nach Farbe ob ein Spielstein an Stelle steht
						if ((farbe == weiss) && (isupper(Feld[nx][ny]) != 0)) {
							printf("*******Ein Spielstein ist im Weg*******\n");
							printf("weiss");
							return -1;
						}
						if ((farbe == schwarz) && (islower(Feld[nx][ny]) != 0)) {
							printf("*******Ein Spielstein ist im Weg*******\n");
							printf("schwarz rückgabewert: %d\n", islower(Feld[nx][ny]));
							return -1;

						}

						printf("der wert ist: %d\n", wert);
						Feld[nx][ny] = figur;
						printf("Feld nachxy: %c\n", Feld[nx][ny]);
						Feld[vx][vy] = 0;
						printf("Feld vonxy: %c\n\n", Feld[j][i]);

						if (var == 'u') {							//Wenn UNDO FKT dann stelle Geschlagene Figur wieder her
							Feld[vx][vy] = undo[laufnr].figur;
						}

						if (farbe == schwarz) {
							farbe = weiss;
						}
						else {
							farbe = schwarz;
						}
						goto ausgabe;
					}
					else
					{
						printf("\n\n*****Falsche Spielfigur oder leeres Feld*****\n\n");
						return -1;
					}

				}

			}
		}
	}
	else
	{
		printf("\n\n*****ZUG EINGABE IST FALSCH*****\n\n");
		return -1;
	}
ausgabe:
	schachbrett();
	return 1;
}
//Spielmenue
int menue() {
	int wert;
	printf("\n     Spielmenu   \n\n");
	printf("1. Spielstand Laden\n");
	printf("2. Spielstand Speichern\n");
	printf("3. Zur\201ck zum Spiel\n");
	printf("4. Spiel beenden\n");
	printf("Ihre Eingabe: ");
	scanf("%d", &wert);

	switch (wert) {
	case 1: if (load("Schachbrett.txt") == 1) {
		printf("Spiel wurde erfolgreich geladen\n");
		return 1;
	}
	case 2: if (save("Schachbrett.txt") == 1) {
		printf("Spiel wurde erfolgreich gespeichert\n");
		return 1;
	}
	case 3: break;
	case 4: printf("\n\nSpiel wurde beendet!\n\n"); exit(4);
	}
	return 0;
}

//Lade Spielstand
int load(char name[]) {
	FILE *fp;
	int i, j;

	fp = fopen(name, "r");
	if (fp == 0) {													//Prüft ob Datei geöffnet
		printf("Fehler beim öffnen der Datei\n");
		return -1;
	}
	if (feof(fp) != 0) {											//Prüft ob Datei Zeiger am Ende steht, wenn ja 
		rewind(fp);													//setzte Lesezeigerposition am Anfang
	}
	for (i = 7; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {

			if (fscanf(fp, "%c", &Feld[j][i]) == EOF) {
				printf("Fehler beim einlesen\n");
				return -1;
			}fscanf(fp, "\n");
		}
	}
	fscanf(fp, "%d", &farbe);
	fclose(fp);
	return 1;
}

//Speichere Spielstand
int save(char name[]) {
	FILE *fp;
	int i, j;

	fp = fopen(name, "w");
	if (fp == 0) {
		printf("Fehler beim öffnen der öffnen der Datei\n");
		return -1;
	}
	for (i = 7; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			if (fprintf(fp, "%c", Feld[j][i]) == EOF) {
				printf("Fehler beim Schreiben\n");
				return -1;
			}
		}fprintf(fp, "\n");
	}
	fprintf(fp, "%d", farbe);
	fclose(fp);
	return 1;
}

//Spielregeln
int Regel(char figur, int vx, int vy, int nx, int ny) {
	int i, j, k;
	int ret = 0;
	printf("figur in der funktion: %c\n", figur);
	printf("Werte in der FKT Regel: vx: %d   vy: %d   nx: %d   ny: %d\n", vx, vy, nx, ny);
	//Bauer
	if (figur == 'b') {
		if ((vy == 6) && (vx == nx)) {
			printf("vy: %d", vy);
			if ((ny == 5) || (ny == 4)) {
				printf("ny: %d", ny);
				return 1;
			}
		}
		if ((ny == (vy - 1)) && (vx == nx)) {
			return 1;
		}
		if (isupper(Feld[vx - 1][vy - 1])) {
			return 1;
		}
		if (isupper(Feld[vx + 1][vy - 1])) {
			return 1;
		}
	}


	if (figur == 'B') {
		if ((vy == 1) && (vx == nx)) {
			if ((ny == 2) || (ny == 3)) {
				return 1;
			}
		}
		if ((ny == (vy + 1)) && (vx == nx)) {
			return 1;
		}
		if (islower(Feld[vx + 1][vy + 1])) {
			return 1;
		}
		if (islower(Feld[vx - 1][vy + 1])) {
			return 1;
		}
	}


	//Turm
	if ((figur == 't') || (figur == 'T')) {
		if ((vy != ny) && (vx == nx)) {
			if (vy < ny) {
				i = vy + 1;
				for (i; i < ny; i++) {
					ret = isalpha(Feld[vx][i]);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
			if (vy > ny) {
				i = vy - 1;
				for (i; i > ny; i--) {
					ret = isalpha(Feld[vx][i]);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
		}
		if ((vy == ny) && (vx != nx)) {
			if (vx > nx) {
				i = vx - 1;
				for (i; i > nx; i--) {
					ret = isalpha(Feld[i][vy]);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
			if (vx < nx) {
				i = vx + 1;
				for (i; i < nx; i++) {
					ret = isalpha(Feld[vx][i]);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
		}
	}


	//Läufer
	if ((figur == 'l') || (figur == 'L')) {
		if ((vx < nx) && (vy < ny)) {					//Wenn der läufer sich nach links hoch bewegt
			i = nx - vx;
			if (((vx + i) == nx) && ((vy + i) == ny)) {
				j = vx + 1; k = vy + 1;
				for (j, k; j < nx, k < ny; j++, k++) {
					ret = isalpha(Feld[j][k]);
					printf("L ret: %d  ", ret);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
		}
		if ((vx > nx) && (vy>ny)) {						//Wenn der Läufer sich nach rechts unten bewegt
			i = vx - nx;
			if ((vx == (nx + i)) && (vy == (ny + i))) {
				j = vx - 1; k = vy - 1;
				for (j, k; j > nx, k > ny; j--, k--) {
					ret = isalpha(Feld[j][k]);
					printf("L ret: %d  ", ret);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
		}
		if ((vx > nx) && (vy<ny)) {						//Wenn der Läufer sich nach rechts oben bewegt
			i = vx - nx;
			if ((vx == (nx + i)) && ((vy + i) == ny)) {
				j = vx - 1; k = vy + 1;
				for (j, k; j > nx, k < ny; j--, k++) {
					ret = isalpha(Feld[j][k]);
					printf("L ret: %d  ", ret);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
		}
		if ((vx < nx) && (vy>ny)) {						//Wenn der Läufer sich nach links unten bewegt
			i = nx - vx;
			if (((vx + i) == nx) && (vy == (ny + i))) {
				j = vx + 1; k = vy - 1;
				for (j, k; j < nx, k > ny; j++, k--) {
					ret = isalpha(Feld[j][k]);
					printf("L ret: %d  ", ret);
					if (ret) {
						printf("*******Fehler: Spielfigur im Weg*******\n");
						return 0;
					}
				}
				return 1;
			}
		}
	}


	//Springer
	if ((figur == 's') || (figur == 'S')) {
		if ((nx == (vx + 2)) && (ny == (vy + 1)) || ((nx == (vx + 1)) && (ny == (vy + 2)))) {//+2 in eine Richtung && +1 in die andere Richtung
			return 1;
		}
		if ((nx == (vx - 2)) && (ny == (vy - 1)) || ((nx == (vx - 1)) && (ny == (vy - 2)))) { //-2 in die eine Richtung && -1 in die andere Richtung
			return 1;
		}
		if ((nx == (vx + 2)) && (ny == (vy - 1)) || ((nx == (vx + 1)) && (ny == (vy - 2)))) {  // +2 -1 || +1 -2
			return 1;
		}
		if ((nx == (vx - 2)) && (ny == (vy + 1)) || ((nx == (vx - 1)) && (ny == (vy + 2)))) {// -2 +1 || -1 +2
			return 1;
		}
	}

	//Dame: Sie darf sich wie Turm oder wie Läufer bewegen.
	if ((figur == 'd') || (figur == 'D')) {
		if ((vy != ny) && (vx == nx)) {					//Wie Turm
			return 1;
		}
		if ((vy == ny) && (vx != nx)) {
			return 1;
		}

		//Wie Läufer
		if ((vx < nx) && (vy < ny)) {					//Wenn der läufer sich nach rechts hoch bewegt
			i = nx - vx;
			if (((vx + i) == nx) && ((vy + i) == ny)) {
				return 1;
			}
		}
		if ((vx > nx) && (vy>ny)) {						//Wenn der Läufer sich nach links oben bewegt
			i = vx - nx;
			if ((vx == (nx + i)) && (vy == (ny + i))) {
				return 1;
			}
		}
		if ((vx > nx) && (vy<ny)) {						//Wenn der Läufer sich nach rechts oben bewegt
			i = vx - nx;
			if ((vx == (nx + i)) && ((vy + i) == ny)) {
				return 1;
			}
		}
		if ((vx < nx) && (vy>ny)) {						//Wenn der Läufer sich nach links unten bewegt
			i = nx - vx;
			if (((vx + i) == nx) && (vy == (ny + i))) {
				return 1;
			}
		}
	}

	//Der König
	if ((figur == 'k') || (figur == 'K')) {
		if ((nx == (vx + 1)) && (vy == ny)) {
			return 1;
		}

		if ((nx == (vx - 1)) && (vy == ny)) { //gerade
			return 1;
		}
		if ((vx == nx) && ((vy + 1) == ny)) {
			return 1;
		}

		if ((vx == nx) && ((vy - 1) == ny)) {
			return 1;
		}

		if (((vx + 1) == nx) && ((vy + 1) == ny)) {
			return 1;
		}

		if (((vx - 1) == nx) && ((vy - 1) == ny)) { //Schräg
			return 1;
		}
		if (((vx + 1) == nx) && ((vy - 1) == ny)) {
			return 1;
		}

		if (((vx - 1) == nx) && ((vy + 1) == ny)) { //Schräg
			return 1;
		}
	}

	return 0;
}



void main() {
	int matt = 1, anz;			//m für Schachmatt und anz für Anzahl der Eingaben
	char vx, nx, vy, ny;			// von x, nach x
	char puffer;				//Puffer um die Entertaste im eingabebereich zu puffern
								//int vy, ny;				//von y, nach y
	int i, laufnr = 0;				//Laufnummer
	int eingabe, ret;			//Returnwerte
	char farbenname[10] = { "test" };
	printf("THE ULTIMATIVE CHESS ANDVENTURE\n\n");

	figuren();
	schachbrett();
	farbe = weiss;

	do {
	start:
		if (farbe == weiss) {
			strcpy(farbenname, "wei\341er");
		}
		if (farbe == schwarz) {
			strcpy(farbenname, "schwarzer");
		}

		fflush(stdin);
		printf("1. Spieler: schwarz (Kleinbuchstaben)\n");
		printf("2. Spieler: wei\341 (Gro\341buchstaben)\n");
		printf("%s Spieler ist drann\n", farbenname);

		printf("Geben sie ihren Zug an (Bsp.: a2a4) : ");
		anz = 0; vx = 0; vy = 0; nx = 0; ny = 0; puffer = 0;
		anz = scanf("%c%c%c%c%c", &vx, &vy, &nx, &ny, &puffer);
		fflush(stdin);
		if (anz == 5) {
			if (vx == 'm')
				if (vy == 'e')
					if (nx == 'n')
						if (ny == '\201') {
							menue();
							schachbrett();
							goto start;
						}
			if (vx == 'u')
				if (vy == 'n')
					if (nx == 'd')
						if (ny == 'o') {   //UNDO Fkt.
							if (laufnr > 0) {
								laufnr--;
								for (i = 0; i <= laufnr; i++) {
									vx = undo[laufnr].vx;
									vy = undo[laufnr].vy;
									nx = undo[laufnr].nx;
									ny = undo[laufnr].ny;
									farbe = undo[laufnr].farbe;
								}
								printf("laufnr: %d  undo.vx: %c   undo.vy: %c  undo.nx: %c   undo.ny: %c  farbe: %d\n", laufnr, (undo + 0)->vx, (undo + 0)->vy, (undo + 0)->nx, (undo + 0)->ny, (undo + 0)->farbe);
								printf("Werte von Undo auf -> vx: %c   vy: %c   nx: %c   ny: %c\n", vx, vy, nx, ny);
								Eingabe('u', vx, vy, nx, ny, laufnr);
								Feld[vx][vy] = undo[laufnr].figur;
								farbe = undo[laufnr].farbe;
								goto start;
							}
							else
								printf("\nKein Zug abgespeichert\n\n"); goto start;

						}

			//scanf("%d%c%d%c", &vy, &nx, &ny, &puffer);
			for (i = 0; i <= laufnr; i++) {
				undo[laufnr].nx = vx;
				undo[laufnr].ny = vy;
				undo[laufnr].vx = nx;
				undo[laufnr].vy = ny;
				undo[laufnr].farbe = farbe;
			}

			printf("laufnr: %d  undo.vx: %c   undo.vy: %c  undo.nx: %c   undo.ny: %c  farbe: %d\n", laufnr, (undo + 0)->vx, (undo + 0)->vy, (undo + 0)->nx, (undo + 0)->ny, (undo + 0)->farbe);
			ret = Eingabe('e', vx, vy, nx, ny, laufnr);
			printf("ret: %d\n", ret);			//Nur wenn die Eingabe stimmt dann laufnummer +1
			if (ret == 1) {
				laufnr++;
			}

		}
		else {
			printf("\n\n*****Falsche Eingabe*****\n\n");
			//goto start;
		}
	} while (matt);									//solange nicht Schachmatt


	return 1;
}




