#ifndef SHARED_STRING_H
#define SHARED_STRING_H
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>

using namespace std;

typedef struct stringIdentifier_tag
{
    char *ptr;
    int occurance;
}stringIdentifier_t;

class SharedString
{
private:
    char *m_ptr;

public:
    SharedString();
    SharedString(char *value);
    ~SharedString();
    SharedString(const SharedString & value);
    void operator =(const SharedString & value);
    char* get();
    static void displayStat();

    static map<char *, stringIdentifier_t> m_stringMap;  // Stores string and its identifier in string map
};

#endif
