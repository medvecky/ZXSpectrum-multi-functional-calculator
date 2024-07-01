#include <conio.h>

#include "system_helper.h"

void setUpScreen( void )
{
#ifdef __CPM__
    cls();
#else
    clrscr();
#endif
}

#ifdef __CPM__

void cls()
{
  gotoyx( 0, 0 );
  printf( "\x1BJ" );
}

void gotoyx( int row, int col ) 
{
  printf ( "\x1BY%c%c", ' ' + row, ' ' + col );
}

#endif