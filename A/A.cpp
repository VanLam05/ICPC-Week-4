// By DThang
#include <stdio.h>
#include <math.h>
int b[1000000] = {0};
int main()
{
    int a[100], max = 0, flag = 0, k;
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            if (i % 2 == 0)
                k = a[i + 1];
            else
                k = a[i - 1];
        }
    }
    for (int i = 0; i < 6; i++)
    {
        b[a[i]]++;
        if (b[a[i]] >= 3 && a[i] == max)
            flag = 1;
        if (a[i] != max && a[i] == max - k && b[a[i]] >= 2)
            flag = 1;
    }
    int s = a[0] * a[1] + a[2] * a[3] + a[4] * a[5];
    if (max * max == s && flag)
        printf("%d", max);
    else
        printf("0");
    return 0;
}