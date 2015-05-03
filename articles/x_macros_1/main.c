#include <stdio.h>

   // main.c
    typedef enum
    {
      #define COLOR(id, value) id = value,
      #include "colors.xdef"
      #undef COLOR
    } colors_t;
    
    const colors_t colorValues[] =
    {
      #define COLOR(id, value) value,
      #include "colors.xdef"
      #undef COLOR
    };

    static const int  COLOR_VALUES_NUM = sizeof(colorValues)/sizeof(*colorValues);
    
    int main()
    {
      int i = 0;
      for (i = 0; i < COLOR_VALUES_NUM; ++i)
      {
        printf("0x%06X\n", colorValues[i]);
      }
      
      return 0;
    }
