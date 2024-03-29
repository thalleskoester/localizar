//
// Created by THALLES on 19/11/2019.
//

#ifndef LOCALIZA_FLAGS_H
#define LOCALIZA_FLAGS_H

#include "helpers.h"

//#define FLAG_DEBUG 0
#define FLAG_HELP 1
#define FLAG_CASE 2
#define FLAG_COUNT 3
#define FLAG_NUMB 4
#define FLAG_OUT 5

typedef int (*VecFlagsFunc)(dString);

void initFlags(Flags *flags, Option *option, VecFlagsFunc *func,
               int flagsCount);

void displayFlagHelp(dString scriptName, int exitCode);

void displayFlagCount(Targets target);

void checkFlagsExistence(Flags *flags, Option *option, int argc,
                         dStringVector argv);

void updateFlagStatus(Flags *flags, unsigned int id, int status);

int getFlagStatus(Flags flags, int id);

int flagDebug(dString arg);

int flagHelp(dString arg);

int flagCaseSensitive(dString arg);

int flagCount(dString arg);

int flagLineNumber(dString arg);

int flagOutput(dString arg);

#endif // LOCALIZA_FLAGS_H
