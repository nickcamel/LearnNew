#include <iostream>
#include <stdio.h>
#include <string.h>

#include "main.h"


using namespace std;

int main()
{
    // Object index
    int i = 0;

    while (true) {

        // Get object name
        char arr[N_CHAR_MAX];
		
		// Avoid processing pure enter key and space key
		do {
			cin.getline(arr, N_CHAR_MAX);
		} while (arr[0]==0 || arr[0]==32);

		// Check if object exist.
		// We dont want to create a duplicate!
		bool obj_exist = false;
		for (int k=0; k<N_CHAR_MAX; k++){
			if (strcmp(obj[k].name, arr)==0) {
				obj_exist = true;
				i = k;
				break;
			}
		}
        
		if (obj_exist==false) {
			// Name the object
			strncpy(obj[i].name, arr, N_CHAR_MAX);
		}

        // Learn new stuff about object
        obj[i].learn_new_stuff();

        // Print everything we know about object
        obj[i].print_all_knowledge();

        // Increment
        i++;
    }
    return 0;
}





