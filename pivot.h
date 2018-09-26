#pragma once

#include "types.h"

void initMatPivot(prob_t*);

void afficherMatrice(prob_t*);

int selectionnerColPivot(prob_t*);

int selectionnerLignePivot(prob_t*, int);