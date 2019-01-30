#include "shared_string.h"
#include <assert.h> 

// Static member initialization
map<char *, stringIdentifier_t> SharedString::m_stringMap;

/***********************************************************************************
@name               : SharedString

@description        : Creates a blank string and no memory is allocated to it.

@returns            : nothing
***********************************************************************************/
SharedString::SharedString()
{
    printf("Constructor-0 called\n");
    m_ptr = nullptr;
}


/***********************************************************************************
@name               : SharedString

@param  value       : String for which memory is to be allocated

@description        : Allocates new memory to a string if this string is not already
                      present in the system. If present, reference count is updated
                      and the same address is provided to it.

@returns            : nothing
***********************************************************************************/
SharedString::SharedString(char *value)
{
    printf("Constructor-1 called\n");
    m_ptr = nullptr;
    auto it = m_stringMap.find(value);

    if (it != m_stringMap.end())
    {
        //Found in map, don't allocate new memory
        printf("Found in map! Not allocating new memory\n");
        stringIdentifier_t *string_identifier = &(it->second);
        m_ptr = string_identifier->ptr;
        string_identifier->occurance++;
    }
    else
    {
        printf("NOT Found in map. Doing fresh allocation\n");
        stringIdentifier_t string_identifier;
        int len = strlen(value);
        m_ptr = (char *)malloc(sizeof(char) * (len + 1));
        memset(m_ptr, 0, sizeof(m_ptr));
        if (m_ptr)
        {
            string_identifier.ptr = m_ptr;
            string_identifier.occurance = 1;
            memcpy(m_ptr, value, len);
            m_stringMap[value] = string_identifier;
        }
        else
        {
            printf("ERROR: Malloc failure\n");
        }
    }
}

/***********************************************************************************
@name               : ~SharedString

@param  value       : String for which memory is to be allocated

@description        : De-allocates memory for the string if there is only 1 reference
                      to it. If more than 1 reference is present, then memory is not
                      freed, only reference count is reduced by 1.

@returns            : nothing
***********************************************************************************/
SharedString::~SharedString()
{
    printf("Destructor called\n");
    for (auto it = m_stringMap.begin(); it != m_stringMap.end(); it++)
    {
        if (strncmp(it->first, m_ptr, strlen(it->first)) == 0)
        {
            if (it->second.occurance == 1)
            {
                printf("Freeing memory for [%s]...", it->second.ptr);
                free(it->second.ptr);
                m_stringMap.erase(it);
                printf(" [DONE]\n");
            }
            else
            {
                it->second.occurance--;
                printf("Reducing reference count for [%s] to: %d\n", it->first, it->second.occurance);
            }

            break;
        }
    }
}


/***********************************************************************************
@name               : SharedString

@param  value       : String which is to be copied to create a new shared string

@description        : Copy constructor. Uses the same memory provided in the value 
                      of parameter and updates the reference count.

@returns            : nothing
***********************************************************************************/
SharedString::SharedString(const SharedString & value)
{
    printf("Copy constructor called!\n");
    m_ptr = value.m_ptr;
    bool found = false;

    printf("searching [%s]...\n", m_ptr);

    /* Update reference count */
    for (auto it = m_stringMap.begin(); it != m_stringMap.end(); it++)
    {
        if (strncmp(it->first, value.m_ptr, strlen(it->first)) == 0)
        {
            it->second.occurance++;
            found = true;
        }
    }

    if (!found)
    {
        printf("String does not exist!\n");
        assert(0);
    }
}

/***********************************************************************************
@name               : operator =

@param  rhs         : String which is to be copied to create a new shared string

@description        : Assignment operator. Uses the same memory provided in the rhs
                      of parameter and updates the reference count.

@returns            : nothing
***********************************************************************************/
void SharedString::operator =(const SharedString & rhs)
{
    printf("Assignment operator called!\n");
    m_ptr = rhs.m_ptr;
    bool found = false;

    /* Update reference count */
    for (auto it = m_stringMap.begin(); it != m_stringMap.end(); it++)
    {
        if (strcmp(it->first, rhs.m_ptr) == 0)
        {
            it->second.occurance++;
            found = true;
        }
    }

    if (!found)
    {
        printf("String does not exist!\n");
        assert(0);
    }

}

/* Get the address */
char* SharedString::get()
{
    return m_ptr;
}

/***********************************************************************************
@name               : displayStat

@param  rhs         : String which is to be copied to create a new shared string

@description        : Display statistics of which string has how many references. 
                      This is a static function and does not require any object for calling

@returns            : nothing
***********************************************************************************/
void SharedString::displayStat()
{
    for (auto it = SharedString::m_stringMap.begin(); it != SharedString::m_stringMap.end(); it++)
    {
        printf("%s: %d\n", it->second.ptr, it->second.occurance);
    }
}