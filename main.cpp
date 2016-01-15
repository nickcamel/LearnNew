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
		
		// TODO: Look in to this below.
		// It works, but it looks kind of wierd.
		// The idea is to ignore pure enter key, i.e we do not
		// want to process the input if only enter key was pressed.
		// We cant just use cin >> arr since we want to include white spaces.
		cin.getline(arr, N_CHAR_MAX);
		while (arr[0]==0)
			cin.getline(arr, N_CHAR_MAX);
		
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





