#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

typedef struct StrMap_tag
{
    vector<char *> vStrPtr;
    size_t totalAllocs;
    size_t totalRequests;
}StrMap_t;

class SharedString
{
    private:
        char *m_ptr;
        int m_Len;
    public:
        SharedString(const char *);
        SharedString();
        ~SharedString();
        char * operator =(char *);
        void Display();
};

void End();
