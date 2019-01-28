#include "header.h"

/* Global String Map */
StrMap_t gStrMap;
//gStrMap.totalAllocs = 0;
//gStrMap.totalRequests = 0;

SharedString::SharedString()
{
}

SharedString::SharedString(const char *val)
{
    bool allocMem = true;
    char *ptr = NULL;
    gStrMap.totalRequests++;
    //cout<<"Creating SharedString\n";

    /* Check if this string already exists in StrMap */
    vector<char *>::iterator it = gStrMap.vStrPtr.begin();
    while (it != gStrMap.vStrPtr.end())
    {
        if (strcmp(*it, val) == 0)
        {
            allocMem = false;
            ptr = *it;
            break;
        }
        it++;
    }

    if (allocMem)
    {
        cout<<"Allocating new memory\n";
        m_Len = strlen(val);
        m_ptr = new char [m_Len];
        strcpy(m_ptr, val);
        gStrMap.vStrPtr.push_back(m_ptr);
        gStrMap.totalAllocs++;
    }
    else
    {
        cout<<"Not allocating fresh memory\n";
        m_ptr = ptr;
    }
}

SharedString::~SharedString()
{
    //cout<<"Destroying SharedString\n";
}

char * SharedString::operator =(char *rhs)
{
    bool allocMem = true;
    char *ptr = NULL;
    gStrMap.totalRequests++;
    //cout<<"Creating SharedString\n";

    /* Check if this string already exists in StrMap */
    vector<char *>::iterator it = gStrMap.vStrPtr.begin();
    while (it != gStrMap.vStrPtr.end())
    {
        if (strcmp(*it, rhs) == 0)
        {
            allocMem = false;
            ptr = *it;
            break;
        }
        it++;
    }

    if (allocMem)
    {
        cout<<"Allocating new memory\n";
        m_Len = strlen(rhs);
        m_ptr = new char [m_Len];
        strcpy(m_ptr, rhs);
        gStrMap.vStrPtr.push_back(m_ptr);
        gStrMap.totalAllocs++;
    }
    else
    {
        cout<<"Not allocating fresh memory\n";
        m_ptr = ptr;
    }


    //m_ptr = rhs;
    return m_ptr;
}

void SharedString::Display()
{
    cout<<m_ptr<<endl;
}

void End()
{
    printf("\n\nSUMMARY:\n");
    printf("Total allocation requests : %d\n", gStrMap.totalRequests);
    printf("Total allocations done    : %d\n", gStrMap.totalAllocs);
    printf("\n\n");

}
