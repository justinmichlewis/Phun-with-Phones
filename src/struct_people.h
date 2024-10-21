#ifndef PEOPLE_H
#define PEOPLE_H

struct People
{
    char name[10];
    char number[9];
    int id;
};

struct People peopleMale[10] = {
    {"Justin", "5551662", 1},
    {"Bill", "5557485", 2},
    {"Sage", "5556869", 3},
    {"Brad", "5557833", 4},
    {"James", "5551122", 5},
    {"Alex", "5553344", 6},
    {"Bob", "5555566", 7},
    {"Charlie", "5557788", 8},
    {"Dennis", "5559900", 9},
    {"Evan", "5552233", 10},
};

struct People peopleFemale[10] = {
    {"Emily", "5551662", 1},
    {"Sophia", "5557485", 2},
    {"Olivia", "5556869", 3},
    {"Ava", "5557833", 4},
    {"Isabella", "5551122", 5},
    {"Mia", "5553344", 6},
    {"Amelia", "5555566", 7},
    {"Harper", "5557788", 8},
    {"Evelyn", "5559900", 9},
    {"Abigail", "5552233", 10},
};

struct People peopleMaleFemale[10] = {
    {"Emily", "5551662", 1},
    {"Sophia", "5557485", 2},
    {"Olivia", "5556869", 3},
    {"Ava", "5557833", 4},
    {"James", "5551122", 5},
    {"Mia", "5553344", 6},
    {"Alex", "5555566", 7},
    {"Harper", "5557788", 8},
    {"Evelyn", "5559900", 9},
    {"Evan", "5552233", 10},
};

#endif