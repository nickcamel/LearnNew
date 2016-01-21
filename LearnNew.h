#ifndef LEARNNEW_H_INCLUDED
#define LEARNNEW_H_INCLUDED

#include "defines.h"

class LearnNew {

public:

    LearnNew();
    virtual ~LearnNew();

    int learn_new_stuff(char*, int);
    void print_all_knowledge();

    char name[N_CHAR_MAX];



    // Properties struct
    struct MyProps {
        MyProps():next(0) {}
        char attr[N_CHAR_MAX];
        struct MyProps * next;
    } * props;
	
	int is_alive;

private:
    void learn(char * newAttr, MyProps * inthing);


};

#endif // LEARNNEW_H_INCLUDED
