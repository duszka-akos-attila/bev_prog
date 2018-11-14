#include <stdio.h>
#include <unistd.h>

int
main (void)
{
  int i, egy_e;
  unsigned char b;
    //> futatt ++ karakter ++ crtl d
    //> kiirja a karakter kódját
  
  while (read (0, (void *) &b, sizeof (unsigned char)))
    {
      for (i = 0; i < 8; ++i)
	{
	  egy_e = b & 0x80;
      //>
	  //printf("%d", egy_e >> 7);
	  if ((egy_e >> 7) == 1)
	    printf ("1");
	  else
	    printf ("0");
	  b <<= 1;
	}
    }
}
