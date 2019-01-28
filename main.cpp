#include "header.h"

int main(int argc, char *argv[])
{
    int i = 1;
    //SharedString s[argc-1];
    while (i < argc)
    {
        char *val = new char [strlen(argv[i])];
        strcpy(val, argv[i]);
        cout<<"Creating "<<val<<endl;
        SharedString s[i];
        s[i] = val;
        s[i].Display();
        i++;
    }

    End();
    return 0;
}
