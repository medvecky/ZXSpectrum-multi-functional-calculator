#include <stdio.h>
#include <conio.h>

#include "modules/system_helper.h"
#include "modules/misc_helper.h"

int main( void )
{
    setUpScreen();

    header();
  
    cgetc();

    resetDefaultScreen();

    return EXIT_SUCCESS;
}
