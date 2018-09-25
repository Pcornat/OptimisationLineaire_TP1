#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "probleme.h"
#include "simplexe.h"
#include "pivot.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Erreur, nombre d'agument insuffisnat.\n");
		exit(EXIT_FAILURE);
	}
	char nomFichier[20];
	prob_t probleme = {0, 0, 0, NULL, NULL, NULL, NULL};

	strcpy(nomFichier, argv[1]);

	if (!lireProbleme(nomFichier, &probleme))
	{
		afficherProbleme(probleme);
		initMatPivot(&probleme);
		afficherMatrice(&probleme);
	}
	else
	{
		printf("Probleme lecture Probleme\n");
		return -1;
	}

	libererMemoireProbleme(probleme);

	return 0;
}