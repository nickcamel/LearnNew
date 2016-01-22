#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "defines.h"
#include "LearnNew.h"




// Declare an array of object to learn
LearnNew obj[N_OF_OBJECTS];
char arrint[5000][5000];


// Create objects
void create_object(char*);

// Sort attributes of object according to 
// * most recently used
// * mostly used in general
void sort_recent();

// Convert char array to int, by summing char's
int c2i(char * charint);

// Number of initalized objects 
int n_obj = 0;

// Object index
int i = 0;




#endif // MAIN_H_INCLUDED
