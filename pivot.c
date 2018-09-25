/*A completer*/
#include <stdlib.h>
#include <stdio.h>
#include "pivot.h"

/**
 * Nombre de ligne dans une matrice : nombre de contrainte.
 * Nombre de colonne matrice = nombre variable
 * @param prob
 */
void initMatPivot(prob_t* prob) {
	int nbColonne = prob->nVar + prob->nCont + 1;
	if ((prob->cont = (double**) realloc(prob->cont, (prob->nCont + 1) * sizeof(double*))) == NULL) {
		fprintf(stderr, "Erreur allocation mémoire (code 1)\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < prob->nCont + 1; ++i) {
		if ((prob->cont[i] = (double*) realloc(prob->cont[i], nbColonne * sizeof(double))) == NULL) {
			fprintf(stderr, "Erreur allocation mémoire (code 2)\n");
			exit(EXIT_FAILURE);
		}
		prob->cont[i][nbColonne - 1] = prob->valCont[i];
	}
	for (int i = 0, j = prob->nVar; i < prob->nCont && j < (prob->nVar + prob->nCont); ++i, ++j) {
		prob->cont[i][j] = 1;
	}
	for (int j = 0; j < prob->nVar; ++j) {
		prob->cont[prob->nCont][j] = prob->fonc[j];
	}
}

void afficherMatrice(prob_t* prob) {
	for (int i = 0; i < prob->nCont + 1; ++i) {
		for (int j = 0; j < (prob->nVar + prob->nCont + 1); ++j) {
			printf("%6.2lf\t", prob->cont[i][j]);
		}
		printf("\n");
	}
}

/**************************************/
