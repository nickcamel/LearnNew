#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <algorithm>
#include <signal.h>
#include <unistd.h>

#include "main.h"


using namespace std;


int main()
{
	// http://stackoverflow.com/questions/1641182/how-can-i-catch-a-ctrl-c-event-c
	// this works well.. but need to investigate when returning from handler...?
	sigIntHandler.sa_handler = handle_ui;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;	
	sigaction(SIGINT, &sigIntHandler, NULL);
	
	
	gettimeofday(&tic, NULL);
	
	while ( true ) {
		gettimeofday(&toc, NULL);
		
		
		if ( ( (toc.tv_sec-tic.tv_sec) >= 1 ) && ( (toc.tv_sec-tic.tv_sec) < 2) )
			printf("time has passed 1\n");
		if ( (toc.tv_sec-tic.tv_sec >= 2 ) && (toc.tv_sec-tic.tv_sec < 3) )
			printf("time has passed 2\n");
		if ( (toc.tv_sec-tic.tv_sec >= 3 ) && (toc.tv_sec-tic.tv_sec < 4) )
			printf("time has passed 3\n");
		if ( (toc.tv_sec-tic.tv_sec >= 4 ) && (toc.tv_sec-tic.tv_sec < 5) )
			printf("time has passed 4\n");
		if ( ( (toc.tv_sec-tic.tv_sec) >= 5 ) && ( (toc.tv_sec-tic.tv_sec) < 6 ) )
			printf("time has passed 5\n");
	
		if (toc.tv_sec-tic.tv_sec > 5) {
			
			gettimeofday(&tic, NULL);
			
			
			if (n_obj>=N_OF_OBJECTS) {
				
				printf("Out of memory!\n");
				printf("Max number of objects exceeded\n");
				printf("Allowed %d  Created %d\n", N_OF_OBJECTS, n_obj);
				break;
			}
		}
		
	
	}   
	
	
    return 0;
}

void handle_ui(int s) {
	
	// Erase "^C"
	cout << "\b\b";
	
	if (n_obj<N_OF_OBJECTS) {
		// We need a main loop in here where cpu is being creative
		// E.g it combines or generates 3 new object with links
		// Afterwards if we approve, it stores, else disregards
		
		if (n_obj>3) {
			// main_loop_here()
			// Go to drawing conclusions
			
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
		
		// Create the inputted object
		create_object(arr);
		
        // Learn new stuff about object.
		// Here we add an attribute to current object.
		// Thereafter we create a new object using the attribute and it's
		// attribute will be the original object. So an attribute to an object
		// goes both ways.
		// Obj A w. attr B ==> Obj B w. attr A
        char attr_tmp[N_CHAR_MAX];
				
		if (obj[i].learn_new_stuff(attr_tmp, 1)==0) {
			
			// add learning points
			obj[i].rec+=P_AT_LEARNING;
			create_object(attr_tmp);
			
			obj[i].learn_new_stuff(arr, 0);
			// add learning points
			obj[i].rec+=P_AT_LEARNING;
			
		} else {
			// We didnt learn anything new
			// User just wants to read
			//int dev = 0;
			//obj[i].print_all_knowledge(&dev);
			obj[i].rec+=P_AT_READING;
			
		}
		
		if (n_obj>1)
			sort_recent();
		
		// DEV
		if (n_obj>0) {
			// Every once in while, print everything
			// but here we dont add points since it's for dev
			for (int k=0; k<n_obj; k++) {
				int dev = 1;
				obj[k].print_all_knowledge(&dev);
			}
		}
    }
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
		// add creation points
		obj[i].rec+=P_AT_CREATION;		
		// N of objects
		n_obj++;
	}
	
	
}


void sort_recent() {
	//In this method we sort our object according to their priority
	
	/*
	printf("name prio pre \n");
	for (int k=0; k<n_obj;k++) {
		printf("%6s %d\n", obj[k].name, obj[k].rec);
	}
	*/
	
	// Sort descending
	for (int kk=n_obj-1; kk>0;kk--) {
		for (int k=n_obj-1; k>0;k--) {
			int t1 = obj[k].rec;
			
			for (int j=k-1; j>=0;j--) {
				int t2 = obj[j].rec;
				
				if (t1>t2) {
					LearnNew ttmp = obj[k];
					obj[k] = obj[j];
					obj[j] = ttmp;
					
					k--;
				}
				
				
			}
		}
	}
	
	// Sort ascending
	/*
	for (int kk=0; kk<n_obj-1;kk++) {
		for (int k=0; k<n_obj-1;k++) {
			int t1 = obj[k].rec;
			
			for (int j=k+1; j<n_obj;j++) {
				int t2 = obj[j].rec;
				
				if (t1>t2) {
					LearnNew ttmp = obj[k];
					obj[k] = obj[j];
					obj[j] = ttmp;
					
					k++;
				}
				
				
			}
		}
	}
	*/
	
	/*
	printf("name prio post \n");
	for (int k=0; k<n_obj;k++) {
		printf("%6s %6d\n", obj[k].name, obj[k].rec);
	}
	*/
	
}


int c2i(char * charint) {
	int ci = 0;
	for (unsigned int k = 0; k<strlen(charint); k++) {
		ci += (int) charint[k];
	}
	
	return ci;
}