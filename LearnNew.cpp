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

    in_thing->next = new MyProps;

    strncpy(in_thing->attr, newAttr, N_CHAR_MAX);

}


void LearnNew::learn_new_stuff() {

	// Create a pointer for iteration purpose
    LearnNew::MyProps * other;
	
	// Char array for user input
    char arr[N_CHAR_MAX];
	
	// Char pointer for assigning attribute to object
    char *tmp;

	
    other = props;

	while (other->next!=NULL) {
		other = other->next;
	}
	
    //for (int k=0; k<2; k++) {
        cin.getline(arr, N_CHAR_MAX);
        tmp = arr;
        learn(tmp, other);

     //   other = other->next;

    //}


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
