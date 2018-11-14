#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define KEY_MAX 100
#define BUFFER_SIZE 256

int main (int argc, char **argv)
{

  char key[KEY_MAX];
  char buffer[BUFFER_SIZE];

  int key_index = 0;
  int read_bytes = 0;

  int key_size = strlen (argv[1]);
  strncpy (key, argv[1], KEY_MAX);

  while ((read_bytes = read (0, (void *) buffer, BUFFER_SIZE)))
    {

      for (int i = 0; i < read_bytes; ++i)
	{

	  buffer[i] = buffer[i] ^ key[key_index];
	  key_index = (key_index + 1) % key_size;

	}

      write (1, buffer, read_bytes);

    }
}
