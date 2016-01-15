#include <iostream>
#include <stdio.h>
#include <string.h>

#include "main.h"
#include "LearnNew.h"

using namespace std;

int main()
{
    LearnNew obj[30];
    int i = 0;

    while (true) {

        // Get object name
        char arr[32];
        cin.getline(arr, 32);
        strncpy(obj[i].name, arr, 32);

        // Learn new stuff about object
        obj[i].learn_new_stuff();

        // Print everything we know about object
        obj[i].print_all_knowledge();

        // Increment
        i++;
    }
    return 0;
}





