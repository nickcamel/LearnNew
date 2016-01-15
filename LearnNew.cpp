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

    strncpy(in_thing->attr, newAttr, 32);

}


void LearnNew::learn_new_stuff() {

    LearnNew::MyProps * other;
    char arr[32];
    char *tmp;

    other = props;

    for (int k=0; k<2; k++) {
        cin.getline(arr, 32);
        tmp = arr;
        learn(tmp, other);

        other = other->next;

    }


}


void LearnNew::print_all_knowledge() {

    LearnNew::MyProps * other;
    other = props;

    if (other!=NULL) {
        printf("\n%s\n", name);

        while (other->next!=NULL) {
            printf("%s\n", other->attr);
            other = other->next;

        }
    }
    printf("\n");


}
