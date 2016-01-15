#ifndef LEARNNEW_H_INCLUDED
#define LEARNNEW_H_INCLUDED

class LearnNew {

public:

    LearnNew();
    virtual ~LearnNew();

    void learn_new_stuff();
    void print_all_knowledge();

    char name[32];

private:

    // Properties struct
    struct MyProps {
        MyProps():next(0) {}
        char attr[32];
        struct MyProps * next;
    } * props;


    void learn(char * newAttr, MyProps * inthing);


};

#endif // LEARNNEW_H_INCLUDED
