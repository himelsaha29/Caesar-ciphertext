#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * @author HimelSaha
 */


void encrypt(char [], int);

int main(int argc, char *argv[])
{
    int x = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc == 2)
    {
        x = atoi(argv[1]);                              // converting string to integer
    }
    int flag = 0;

    char *arg = argv[1];                                // making sure the key provided is a number
    for (int i = 0; i < strlen(arg); i++)
    {

        if (!(arg[i] >= 48 && arg[i] <= 57))
        {
            flag = 1;
        }
    }

    if (flag)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    char plain[5000];
    printf("plaintext: ");
    fgets(plain, 5000, stdin);                          // getting user input
    encrypt(plain, x);                                  // passing the plaintext and the key to 'encrypt' function
    return 0;

}

void encrypt(char *txt, int k)
{
    for (int i = 0; i < strlen(txt); i++)
    {
        int keyOrigin = k;
        
        if ((txt[i] >= 65 && txt[i] <= 90))             // if the character is a capital letter
        {
            int key = keyOrigin;


            // if the ASCII value of the character + key is greater than 90(Z), key is added to the ASCII value of the character
            // (key value decremented at the same time) until key value is 0. When the ASCII value of the character is 90(Z) 
            // and key value is not 0, the ASCII value is set to 65(A) and the rest of the operation is performed as before
            
            if ((txt[i] + k) > 90) 
            {
                while (key != 0)
                {
                    if (txt[i] == 90)
                    {
                      txt[i] =  65;
                      key--;
                    }
                    int remaining = 90 - txt[i];
                    if (key >= remaining)
                    {
                        txt[i] = (txt[i] + remaining);
                        key -= remaining;
                    }
                    else {
                        txt[i] += key;
                        key = 0;
                    }

                }
            }
            
            // if the ASCII value of the character + key is not greater than 90, the key is simply added to the ASCII value
            // of the character
            else
            {
                txt[i] = txt[i] + key;
            }

        }
        else if ((txt[i] >= 97 && txt[i] <= 122))       // if the character is a not capital letter
        {
                int key = keyOrigin;
                
                // if the ASCII value of the character + key is greater than 122(z), key is added to the ASCII value of the character
                // (key value decremented at the same time) until key value is 0. When the ASCII value of the character is 122(z) 
                // and key value is not 0, the ASCII value is set to 97(a) and the rest of the operation is performed as before
                if ((txt[i] + k) > 122)
                {

                  while (key != 0)
                  {
                      if (txt[i] == 122)
                      {
                        txt[i] =  97;
                        key--;
                      }
                      int remaining = 122 - txt[i];
                      if (key >= remaining)
                      {
                          txt[i] = (txt[i] + remaining);
                          key -= remaining;
                      }
                      else {
                          txt[i] += key;
                          key = 0;
                      }

                  }
                }
                
                // if the ASCII value of the character + key is not greater than 122, the key is simply added to the ASCII value
                // of the character
                else
                {
                   txt[i] = txt[i] + key;
                }
        }
        else
        {
            continue;
        }
    }

    // print the ciphertext converted from the plaintext using the provided key
    printf("ciphertext: %s\n", txt);
}

