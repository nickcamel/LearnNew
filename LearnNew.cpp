#include <iostream>
#include <stdio.h>
#include <string.h>

#include "LearnNew.h"

using namespace std;

LearnNew::LearnNew(){
    props = new MyProps;
}

LearnNew::~LearnNew(){}


void LearnNew::learn(char * newAttr, MyProps * in_thing) {

	// Create a new 'next' and learn the new attribute
	
    in_thing->next = new MyProps;

    strncpy(in_thing->attr, newAttr, N_CHAR_MAX);

}


int LearnNew::learn_new_stuff(char *ret_char) {
	
	// Create a pointer for iteration purpose
    LearnNew::MyProps * other;
	
	// Char array for user input
    char arr[N_CHAR_MAX];
	
	
    other = props;

	cin.getline(arr, N_CHAR_MAX);
	
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


void LearnNew::print_all_knowledge() {

    LearnNew::MyProps * other;
    other = props;

    if (other!=NULL) {
        printf("\n--- %s ---\n", name);

        while (other->next!=NULL) {
            printf("%s\n", other->attr);
            other = other->next;

        }
    }
    printf("\n");


}
