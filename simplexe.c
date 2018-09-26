#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "probleme.h"
#include "pivot.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Erreur, nombre d'agument insuffisnat.\n");
		exit(EXIT_FAILURE);
	}
	char nomFichier[20];
	int nColPivot, nLignePivot;
	double** matrice = NULL;
	prob_t probleme = {0, 0, 0, NULL, NULL, NULL, NULL};

	strcpy(nomFichier, argv[1]);

	if (!lireProbleme(nomFichier, &probleme)) {
		afficherProbleme(probleme);
		matrice = initMatPivot(&probleme);
		afficherMatrice(&probleme, matrice);
		nColPivot = selectionnerColPivot(&probleme, matrice);
		nLignePivot = selectionnerLignePivot(&probleme, matrice, nColPivot);
		diviserLignePivot(&probleme, matrice, nLignePivot, nColPivot);
		printf("\n\n");
		afficherMatrice(&probleme, matrice);
		miseAZeroColPivot(&probleme, matrice, nLignePivot, nColPivot);
		printf("\n\n");
		afficherMatrice(&probleme, matrice);
		libererMatrice(&probleme, &matrice);
	} else {
		printf("Probleme lecture Probleme\n");
		return EXIT_FAILURE;
	}
	libererMemoireProbleme(probleme);

	return EXIT_SUCCESS;
}
