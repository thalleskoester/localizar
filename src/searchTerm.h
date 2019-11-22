//
// Created by Thalles on 21/11/2019.
//

#ifndef LOCALIZA_SEARCHTERM_H
#define LOCALIZA_SEARCHTERM_H

#include "helpers/structs.h"
#include "helpers/dstring.h"

void initSearchTerm(SearchTerm *searchTerm);

void addSearchTerm(SearchTerm *searchTerm, dString term);

int splitCount(dString term);

#endif //LOCALIZA_SEARCHTERM_H
