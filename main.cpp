#include <iostream>
#include <stdio.h>
#include <string.h>

#include "main.h"


using namespace std;

int main()
{
    while (n_obj<N_OF_OBJECTS) {
		// We need a main loop in here where cpu is being creative
		// E.g it combines or generates 3 new object with links
		// Afterwards if we approve, it stores, else disregards
		
		// main_loop_here()
		
		// When ready for user input
		// go to here
		
        // Get object name
        char arr[N_CHAR_MAX];
		
		// Avoid processing pure enter key and space key
		cout << "object: " << endl;
		do {
			cin.getline(arr, N_CHAR_MAX);
		} while (arr[0]==0 || arr[0]==32);

		// Check if object exist.
		// We dont want to create a duplicate!
		create_object(arr);
		
        // Learn new stuff about object.
		// Here we add an attribute to current object.
		// Thereafter we create a new object using the attribute and it's
		// attribute will be the original object. So an attribute to an object
		// goes both ways.
		// Obj A w. attr B ==> Obj B w. attr A
        char attr_tmp[N_CHAR_MAX];
				
		if (obj[i].learn_new_stuff(attr_tmp, 1)==0) {
			
			create_object(attr_tmp);
			
			obj[i].learn_new_stuff(arr, 0);
			
			
		} else {
			// We didnt learn anything new
			// Just print the object
			obj[i].print_all_knowledge();
			
		}
		
		
    }
	
	cout << "Out of memory!" << endl;
	printf("Max number of objects exceeded\n");
	printf("Allowed %d  Created %d\n", N_OF_OBJECTS, n_obj);
    return 0;
}


void create_object(char * arr) {
	
	bool obj_exist = false;
	
	//need a clever way of making closer/longer bonds!
	
	// Check if object 'arr' already exist
	for (int k=0; k<N_OF_OBJECTS; k++){
		if (strcmp(obj[k].name, arr)==0) {
			// It does exist. Mark 'i' to current object and break out
			obj_exist = true;
			i = k;
			break;
		}
	}
	
	// If object 'arr' does not exist, find an
	// uninitialized object
	if (obj_exist==false) {
		
		for (int k=0; k<N_OF_OBJECTS; k++){
			if (obj[k].is_alive==0) {
				// An empty object was found. Mark 'i' and break out
				i = k;
				break;
			}
		}
		
		// Name the object
		strncpy(obj[i].name, arr, N_CHAR_MAX);
		
		// Mark it alive
		obj[i].is_alive = 1;
		
		// N of objects
		n_obj++;
	}
	
	
}


