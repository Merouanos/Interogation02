#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char phrase[51], p[101], max;
int l, i, indice, j;
bool verified;

int main()
{
    do
    {

        printf("Please give me a phrase :\n ");
        gets(phrase);
        l = strlen(phrase);
        if (l > 50)
            verified = false;
        else
            verified = true;
        i = 0;
        while (i < l && verified)
            if (phrase[i] < 'a' || phrase[i] > 'z')
                verified = false;
            else
                i++;
    } while (!verified);

    p[0] = phrase[0];
    p[1] = '1';
    p[2] = '\0';
    i = 1;
    indice = 0;
    verified = true;
    max = '1';
    while (i < l && max <= '9')
    {

        j = 0;
        verified = false;
        while (p[j] != '\0' && max <= '9' && !verified)
        {
            if (p[j] == phrase[i])
            {
                p[j + 1]++;
                verified = true;
                if (max <= p[j + 1])
                {
                    max = p[j + 1];
                    indice = i;
                }
            }
            else
                j = j + 2;
        }
        if (!verified)
        {
            p[j] = phrase[i];
            p[j + 1] = '1';
            p[j + 2] = '\0';
        }

        i++;
    }
    if (max <= '9')
    {
        printf("The p phrase is : \n");
        puts(p);
        printf("The most repeated word is %c and it's repeated %c times with an index of : %d ", phrase[indice], max, indice);
    }
    else
        printf("errur");
}
