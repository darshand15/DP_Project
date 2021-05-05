#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define typename(x) _Generic((x),                                                       \
_Bool: TYPENAME_BOOL,           unsigned char: TYPENAME_UNSIGNED_CHAR,          \
char: TYPENAME_CHAR,             signed char: TYPENAME_SIGNED_CHAR,            \
short int: TYPENAME_SHORT_INT, unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,     \
int: TYPENAME_INT, double: TYPENAME_DOUBLE                    \
/* ... */                                    \
int *: TYPENAME_POINTER_TO_INT,          \
default: TYPENAME_OTHER)


#define typename(x) _Generic((x),                                                 \
        _Bool: TYPENAME_BOOL,                  unsigned char: TYPENAME_UNSIGNED_CHAR,          \
         char: TYPENAME_CHAR,                     signed char: TYPENAME_SIGNED_CHAR,            \
    short int: TYPENAME_SHORT_INT,         unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,     \
          int: TYPENAME_INT,                     unsigned int: TYPENAME_UNSIGNED_INT,           \
     long int: TYPENAME_LONG_INT,           unsigned long int: TYPENAME_UNSIGNED_LONG_INT,      \
long long int: TYPENAME_LONG_LONG_INT, unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT, \
        float: TYPENAME_FLOAT,                         double: TYPENAME_DOUBLE,                 \
  long double: TYPENAME_LONG_DOUBLE,                   char *: TYPENAME_POINTER_TO_CHAR,        \
       void *: TYPENAME_POINTER_TO_VOID,                int *: TYPENAME_POINTER_TO_INT,         \
      default: TYPENAME_OTHER)


 enum t_typename {
        TYPENAME_BOOL,                  //0
        TYPENAME_CHAR,                  //1
        TYPENAME_POINTER_TO_CHAR,       //2
        TYPENAME_FLOAT,                 //3
        TYPENAME_POINTER_TO_FLOAT,      //4
        TYPENAME_INT,                   //5
        TYPENAME_POINTER_TO_INT,        //6
        TYPENAME_DOUBLE,                //7
        TYPENAME_POINTER_TO_DOUBLE,     //8
        TYPENAME_POINTER_TO_VOID,       //9
        TYPENAME_OTHER                  //10
    };

int main()
{
    
    // int a = 5;
    // if(typeof(5) == typeof(5))
    // {
        TYPE a;
        printf("%d", typename(a));
    // }
}