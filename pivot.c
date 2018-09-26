#include "pivot.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <float.h>

/**
 * Nombre de ligne dans une matrice : nombre de contrainte.
 * Nombre de colonne matrice = nombre variable
 * @param prob
 */
void initMatPivot(prob_t* prob) {
	int nbColonne = prob->nVar + prob->nCont + 1;
	checkErrorNull(prob->cont = (double**) realloc(prob->cont, (prob->nCont + 1) * sizeof(double*)));
	prob->cont[prob->nCont] = NULL;
	for (int i = 0; i < prob->nCont + 1; ++i) {
		checkErrorNull(prob->cont[i] = (double*) realloc(prob->cont[i], nbColonne * sizeof(double)));
		prob->cont[i][nbColonne - 1] = prob->valCont[i];
	}
	for (int i = 0, j = prob->nVar; i < prob->nCont && j < (prob->nVar + prob->nCont); ++i, ++j) {
		prob->cont[i][j] = 1;
	}
	for (int j = 0; j < prob->nVar; ++j) {
		prob->cont[prob->nCont][j] = prob->fonc[j];
	}
}

/**
 * Affiche la matrice dans prob.
 * @param prob Contient la matrice pivot à afficher.
 */
void afficherMatrice(prob_t* prob) {
	for (int i = 0; i < prob->nCont + 1; ++i) {
		for (int j = 0; j < (prob->nVar + prob->nCont + 1); ++j) {
			printf("%6.2lf\t", prob->cont[i][j]);
		}
		printf("\n");
	}
}

/**
 * Permet de sélectionner la variable d'entrée hors-base pour le simplexe.
 * @param prob
 * @return L'indice de la colonne avec le coefficient le plus grand.
 */
int selectionnerColPivot(prob_t* prob) {
	int nbColonne = prob->nVar + prob->nCont + 1, j = 0;
	double max = 0;
	for (int i = 0; i < nbColonne; ++i) {
		if (prob->cont[prob->nCont][i] > max) {
			max = prob->cont[prob->nCont][i];
			j = i;
		}
	}
	return j;
}

int selectionnerLignePivot(prob_t* prob, int nColPivot) {
	int nLignePivot = 0, colonneMax = prob->nVar + prob->nCont;
	double rapport = 0, min = DBL_MAX;
	for (int i = 0; i < prob->nCont; ++i) {
		rapport = prob->cont[i][colonneMax] / prob->cont[i][nColPivot];
		if (min > rapport) {
			min = rapport;
			nLignePivot = i;
		}
	}
	return nLignePivot;
}

/**************************************/
