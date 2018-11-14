// To run in Terminal: ./compiled_name < coded_file

#define MAX_SECRET 4096
#define READ_BUFFER 256
#define KEY_SIZE 8
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double avg_word_leng (const char *secret, int secret_size)
{
    int sz = 0;

    for (int i = 0; i < secret_size; ++i)
    {
        if (secret[i] == ' ')
        {
            ++sz;
        }
    }

    return (double) secret_size / sz;
}

int may_clean (const char *secret, int secret_size)
{
    // The clean text may contain the common hungarian words
    // and with checking the avarage word length, we can reduce
    // the needed trys.

    double wordleng = avg_word_leng (secret, secret_size);

    return wordleng > 6.0 && wordleng < 9.0 && strcasestr (secret, "hogy") && strcasestr (secret, "nem") && strcasestr (secret, "az") && strcasestr (secret, "ha");

}

void exor (const char key[], int key_size, char secret[], int secret_size)
{

    int key_index = 0;

    for (int i = 0; i < secret_size; ++i)
    {

        secret[i] = secret[i] ^ key[key_index];
        key_index = (key_index + 1) % key_size;

    }

}

int exor_breaking (const char key[], int key_size, char secret[], int secret_size)
{

    exor (key, key_size, secret, secret_size);

    return may_clean (secret, secret_size);

}

int main (void)
{

    char key[KEY_SIZE];
    char secret[MAX_SECRET];
    char *p = secret;
    int read_bytes;

    // Secret file reading
    while ((read_bytes =  read (0, (void *) p, (p - secret + READ_BUFFER < MAX_SECRET) ? READ_BUFFER : secret + MAX_SECRET - p)))
    {
        p += read_bytes;
    }

    // Reseting remaining space in the secret buffer
    for (int i = 0; i < MAX_SECRET - (p - secret); ++i)
    {
        secret[p - secret + i] = '\0';
    }

    // Production of all keys
    for (int ii = '0'; ii <= '9'; ++ii)
    {
        for (int ji = '0'; ji <= '9'; ++ji)
        {
            for (int ki = '0'; ki <= '9'; ++ki)
            {
                for (int li = '0'; li <= '9'; ++li)
                {
                    for (int mi = '0'; mi <= '9'; ++mi)
                    {
                        for (int ni = '0'; ni <= '9'; ++ni)
                        {
                            for (int oi = '0'; oi <= '9'; ++oi)
                            {
                                for (int pi = '0'; pi <= '9'; ++pi)
                                {
                                    key[0] = ii;
                                    key[1] = ji;
                                    key[2] = ki;
                                    key[3] = li;
                                    key[4] = mi;
                                    key[5] = ni;
                                    key[6] = oi;
                                    key[7] = pi;

                                    printf("Tested key: [%c%c%c%c%c%c%c%c]\n", ii, ji, ki, li, mi, ni, oi, pi);

                                    if (exor_breaking (key, KEY_SIZE, secret, p - secret))
                                    {
                                        printf("Key: [%c%c%c%c%c%c%c%c]\nClean text: [%s]\n", ii, ji, ki, li, mi, ni, oi, pi, secret);
                                        return 0;
                                    }

                                    // Repeat exor to avoid a second buffer
                                    exor (key, KEY_SIZE, secret, p - secret);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
