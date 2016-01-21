#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "defines.h"
#include "LearnNew.h"




// Declare an array of object to learn
LearnNew obj[N_OF_OBJECTS];

// Create objects
void create_object(char*);

// Sort attributes of object according to 
// * most recently used
// * mostly used in general
void sort_recent();

// Number of initalized objects
int n_obj = 0;

// Object index
int i = 0;




#endif // MAIN_H_INCLUDED
