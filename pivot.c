/*A completer*/
#include "pivot.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Nombre de ligne dans une matrice : nombre de contrainte.
 * Nombre de colonne matrice = nombre variable
 * @param prob
 */
void initMatPivot(prob_t *prob)
{
	double **mat = NULL;
	int nbColonne = prob->nVar + prob->nCont + 1;
	for (int i = 0; i < prob->nCont + 1; ++i)
	{
		if ((prob->cont[i] = (double *)realloc(prob->cont[i], nbColonne * sizeof(double))) == NULL)
		{
			fprintf(stderr, "Erreur allocation mémoire (code 1)\n");
			exit(EXIT_FAILURE);
		}
		//prob->cont[i][nbColonne - 1] = prob->cont[i][prob->nCont];
	}
}

void afficherMatrice(prob_t *prob)
{
	for (int i = 0; i < prob->nCont + 1; ++i)
	{
		for (int j = 0; j < (prob->nVar + prob->nCont + 1); ++j)
		{
			printf("%6.2lf\t", prob->cont[i][j]);
		}
		printf("\n");
	}
}

/**************************************/
