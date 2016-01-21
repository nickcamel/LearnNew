#include <iostream>
#include <stdio.h>
#include <string.h>

#include "main.h"


using namespace std;

int main()
{
    // Object index
    //int i = 0;

    while (true) {

        // Get object name
        char arr[N_CHAR_MAX];
		
		// Avoid processing pure enter key and space key
		do {
			cin.getline(arr, N_CHAR_MAX);
		} while (arr[0]==0 || arr[0]==32);

		// Check if object exist.
		// We dont want to create a duplicate!
		create_object(arr);
		
        // Learn new stuff about object
        char attr_tmp[N_CHAR_MAX];
		
		if (obj[i].learn_new_stuff(attr_tmp, 1)==0) {
			//i = next_i;
			create_object(attr_tmp);
			
			obj[i].learn_new_stuff(arr, 0);
			
			// Browse to make a connection
			//printf("->dev-> new stuff : %s\n", attr_tmp);
		} else {
			// We didnt learn anything new
			obj[i].print_all_knowledge();
			//printf("->dev-> what else is new?\n");
		}
		
		
		
		

        // Print everything we know about object
        //;

        // Increment
        //i++;
    }
    return 0;
}


bool create_object(char * arr) {
	
	bool obj_exist = false;
	
	
	//error! here we need to follow each attr pointer
	//also need a clever way of making closer/longer bonds!
	
	for (int k=0; k<N_OF_OBJECTS; k++){
		if (strcmp(obj[k].name, arr)==0) {
			obj_exist = true;
			i = k;
			break;
		}
	}
	
	if (obj_exist==false) {
		// Find empty object
		for (int k=0; k<N_OF_OBJECTS; k++){
			if (obj[k].is_alive==0) {
				i = k;
				break;
			}
		}
		
		// Name the object
		strncpy(obj[i].name, arr, N_CHAR_MAX);
		obj[i].is_alive = 1;
	}
	
	return obj_exist;
}


