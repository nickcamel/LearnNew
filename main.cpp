#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>


#include "main.h"


using namespace std;

int main()
{
	sort_recent();
	return 1;
    while (n_obj<N_OF_OBJECTS) {
		// We need a main loop in here where cpu is being creative
		// E.g it combines or generates 3 new object with links
		// Afterwards if we approve, it stores, else disregards
		printf("nobj %d\n", n_obj);
		if (n_obj>3) {
			// main_loop_here()
			// Go to drawing conclusions
			sort_recent();
		}
		
		
		// When ready for user input
		// go to here
		
        // Get object name
        char arr[N_CHAR_MAX];
		
		// Avoid processing pure enter key and space key
		cout << "object: " << endl;
		do {
			cin.getline(arr, N_CHAR_MAX);
		} while (arr[0]==0 || arr[0]==32);


		
		printf("\n");
		//cout << "devtest"<<endl;
		strcpy(arrint[c2i(arr)], arr);
		//cout << arrint[c2i(arr)] <<endl;
		//cout << "devtest end"<<endl;
		//printf("\n");
		
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
			obj[i].rec+=P_AT_LEARNING;
			
		} else {
			// We didnt learn anything new
			// Just print the object
			obj[i].print_all_knowledge();
			obj[i].rec+=P_AT_READING;
			
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
		obj[i].rec+=P_AT_CREATION;		
		// N of objects
		n_obj++;
	}
	
	
}


void sort_recent() {
	LearnNew tmpobj[6];
	int recarr[6];
	int rectmp[6];
	
	n_obj = 6;
	int objrec[6] = {9, 8, 2, 1, 6, 7};
	int ind[6] = {0, 1, 2, 3, 4, 5};
	
	for (int k=0; k<6;k++) {
		recarr[k] = objrec[k];
		rectmp[k] = objrec[k];
		printf("init %d, %d, %d\n", recarr[k], rectmp[k], objrec[k]);
	}
	
	
	for (int k=0; k<6;k++) {
		
		printf("just print %d, %d, %d\n", recarr[k], rectmp[k], objrec[k]);
	}
	printf(" \n");
	for (int kk=0; kk<n_obj-1;kk++) {
		for (int k=0; k<n_obj-1;k++) {
			int t1 = rectmp[k];
			
			for (int j=k+1; j<n_obj;j++) {
				int t2 = rectmp[j];
				
				if (t1>t2) {
					rectmp[k] = t2;
					rectmp[j] = t1;
					
					printf("k %d , j %d , t1 %d , t2 %d\n", k, j, t1, t2);
					k++;
				}
				
				
			}
		}
	}
	for (int k=0; k<6;k++) {
		
		printf("post just print %d, %d, %d\n", recarr[k], rectmp[k], objrec[k]);
	}
	
}


int c2i(char * charint) {
	int ci = 0;
	for (unsigned int k = 0; k<strlen(charint); k++) {
		ci += (int) charint[k];
	}
	
	return ci;
}