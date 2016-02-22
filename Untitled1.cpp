#include <conio.h>

int main() {
   cprintf( "Ejemplo de \"textbackground\" y \"textcolor\"\r\n\r\n" );
   textbackground( BLUE );
   textcolor( LIGHTRED );
   cprintf( "Este mensaje tiene otro color de fondo y de texto.\r\n" );
   textbackground( WHITE );
   cprintf( "Este mensaje tiene un color de fondo distinto.\r\n" );
   normvideo();
   cprintf( "Pulsa una tecla para continuar...\r\n" );
   getch();

   return 0;
}
