#include <iostream>
#include <stdio.h>
#include <string.h>

#include "LearnNew.h"

using namespace std;

LearnNew::LearnNew(){
    props = new MyProps;
	is_alive = 0;
	rec = 0;
}

LearnNew::~LearnNew(){}


void LearnNew::learn(char * newAttr, MyProps * in_thing) {

	// Create a new 'next' and learn the new attribute
	
    in_thing->next = new MyProps;

    strncpy(in_thing->attr, newAttr, N_CHAR_MAX);
	
	in_thing->rec+=P_AT_LEARNING;

}


int LearnNew::learn_new_stuff(char *ret_char, int usr_in) {
	
	// Create a pointer for iteration purpose
    LearnNew::MyProps * other;
	other = props;
	
	// Char array for user input
    char arr[N_CHAR_MAX];
	
	// Either we are using users input for learning
	// or we are learning from the object of which we are an 
	// attribute to
	if (usr_in==1) {
		cout << "attribute (or enter to print): " << endl;
		cin.getline(arr, N_CHAR_MAX);
		printf("\n");
	} else {
		strcpy(arr, ret_char);
	}
	
	// If enter key or space key was pressed, don't learn it, move on...
	if (arr[0]!=0 && arr[0]!=32) {
		
		// Move pointer to end
		while (other->next!=NULL) {
			other = other->next;
		}
		
		// We need to copy for the pointer to hold when returning.
		// "ret_char = arr" is no good, since arr will die at end of this method. 
		strcpy(ret_char, arr);
    
		// Learn the new attribute
		learn(ret_char, other);
		
		// Ok
		return 0;
	}
	
	// Nothing new was learned
	return 1;

}


void LearnNew::print_all_knowledge(int * dev) {

    LearnNew::MyProps * other;
    other = props;

    if (other!=NULL) {
        printf("\n--- %s %d---\n", name, rec);

        while (other->next!=NULL) {
            printf("%s %d\n", other->attr, other->rec);
			
			if (*dev!=1)
				other->rec+=P_AT_READING;
				
            other = other->next;

        }
    }
    printf("\n");


}
