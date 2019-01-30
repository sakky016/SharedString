#include"shared_string.h"

/* Tester main */
int main()
{
    printf("\nObject creation for s1 [abc]\n");
    SharedString s1("abc");

    printf("\nObject creation for s2 [abc]\n");
    SharedString s2("abc");

    printf("\nObject creation for s3 [def]\n");
    SharedString s3("def");

    printf("\nObject creation for s4 [ghi]\n");
    SharedString s4("ghi");
    
    printf("\nObject creation for s5 [def]\n");
    SharedString s5("def");
    
    printf("\nObject creation for s6 by copying\n");
    SharedString s6 = s5;
    
    printf("\nObject creation for s7 by assignment\n");
    SharedString s7;
    s7 = s5;

    printf("\n");
    printf("s1: %s, address: 0x%p\n", s1.get(), s1.get());
    printf("s2: %s, address: 0x%p\n", s2.get(), s2.get());
    printf("s3: %s, address: 0x%p\n", s3.get(), s3.get());
    printf("s4: %s, address: 0x%p\n", s4.get(), s4.get());
    printf("s5: %s, address: 0x%p\n", s5.get(), s5.get());
    printf("s6: %s, address: 0x%p\n", s6.get(), s6.get());
    printf("s7: %s, address: 0x%p\n", s7.get(), s7.get());

    printf("\n--------------------------------------------\n");
    printf("Displaying Stats:\n");
    printf("--------------------------------------------\n");
    SharedString::displayStat();
    printf("--------------------------------------------\n");

    // Call destructors explicitly;
    printf("\n--------------------------------------------\n");
    printf("Destructor calls:\n");
    printf("--------------------------------------------\n");
    s1.~SharedString();
    s2.~SharedString();
    s3.~SharedString();
    s4.~SharedString();
    s5.~SharedString();
    s6.~SharedString();
    s7.~SharedString();
    printf("--------------------------------------------\n");

    getchar();
    return 0;
}