#include <stdio.h>
int main(void)
{
    int data[7];
    int datarec[7], c, c1, c2, c3, i;
    printf("Enter 4 bits of data one by one:\n");
    scanf("%d", &data[6]);
    scanf("%d", &data[5]);
    scanf("%d", &data[4]);
    scanf("%d", &data[2]);
    data[0] = data[2] ^ data[4] ^ data[6];
    data[1] = data[2] ^ data[5] ^ data[6];
    data[3] = data[4] ^ data[5] ^ data[6];
    printf("Encoded data is:");
    for (i = 0; i < 7; i++)
        printf("%d", data[i]);
    printf("\nEnter the recvied data one by one: \n");
    for (i = 0; i < 7; i++)
        scanf("%d", &datarec[i]);

    c1 = datarec[6] ^ datarec[4] ^ datarec[2] ^ datarec[0];
    c2 = datarec[5] ^ datarec[4] ^ datarec[1] ^ datarec[0];
    c3 = datarec[3] ^ datarec[2] ^ datarec[1] ^ datarec[0];
    c = c3 * 4 + c2 * 2 + c1;
    printf("\nThe error is in the %d bit", c);
    if (c == 0)
    {
        printf("\nNo error while transmission of data: \n");
    }
    else
    {
        printf("\nError on position %d", c);
        printf("\nData sent:\n");
        for (i = 0; i < 7; i++)
            printf("%d", datarec[i]);
        printf("\nCorrect message is:\n");
        if (datarec[7 - c] == 0)
            datarec[7 - c] = 1;
        else
            datarec[7 - c] = 0;
        for (i = 0; i < 7; i++)
            printf("%d", datarec[i]);
    }
    return 0;
}