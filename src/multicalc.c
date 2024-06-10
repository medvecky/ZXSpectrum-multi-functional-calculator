#include <stdio.h>
#include <conio.h>

int main( void )
{
  bordercolor( BLACK );
  textcolor( GREEN );
  textbackground( BLACK );
  clrscr();

  gotoxy( 10, 10 );
  puts( "Hello world" );

  gotoxy( 7, 11 );
  puts( "Spectrum is cool!" );
  
  cgetc();

  bordercolor( WHITE );
  textcolor( BLACK );
  textbackground( WHITE );
  clrscr();

  return 0;
}
