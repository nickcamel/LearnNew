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
	sigIntHandler.sa_handler = handle_ui;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;	
	sigaction(SIGINT, &sigIntHandler, NULL);
	
	// Get initial time
	gettimeofday(&tic, NULL);
	
	// We may implement a self searching algorithm soon so that we don't depend ENTIRELY on user.
	// e.g through 
	// wget --user-agent=Mozilla/5.0 -O srch -e robots=off "http://www.google.com/search?hl=en&q=foo"
		
	while ( true ) {
		
		// This is our main loop.
		// It is interrupted by pressing 'ctrl+c'.
		// It will every once in a while be creative and do something with
		// the objects it has stored. Say every T_CREATIVE_SEC seconds and if
		// number of object are greater than T_CREATIVE_N
		
		// 1. We need to start 'forgetting'. Removing points
		// 2. We need to start making connections.
		//    sun->fire. fire->burns. sun->burns?
		
		// Get current time
		gettimeofday(&toc, NULL);
		
		// Check condition
		if ( ( ((toc.tv_sec-tic.tv_sec)%T_CREATIVE_SEC)>=T_CREATIVE_SEC ) && 
				( n_obj>T_CREATIVE_N ) )  {
			
			// do something here
			
			// If condition is true, set new initial time
			gettimeofday(&tic, NULL);
			
			
			
		}
		
	
	}   
	
	
    return 0;
}

void handle_ui(int s) {
	
	// Erase "^C"
	cout << "\b\b";
	
	
	
	if (n_obj<N_OF_OBJECTS-1) {
		
		
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
    } else {
		// Cannot create more objects just print
		printf("\n\n");
		if (n_obj>0) {
			// Every once in while, print everything
			// but here we dont add points since it's for dev
			for (int k=0; k<n_obj; k++) {
				int dev = 1;
				obj[k].print_all_knowledge(&dev);
			}
		}
		
		printf("\nOut of memory!\n");
		printf("Max number of objects reached\n");
		printf("Allowed %d  Created %d\n", N_OF_OBJECTS, n_obj);
		if (n_obj<N_OF_OBJECTS) {
			printf("Yes, I know there are less objects than allowed, \nbut creating a new object will also create it's attribute\nNo point in arguing about that you maybe only want to ADD an attribute, \nI'm not handling it. Just edit defines.h\n");
			printf("Yes, your session will get lost!\n");
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