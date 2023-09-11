#include <stdio.h>
#include <string.h>
int main() {
    int n;
    char arr[101] = { 0 };
    int flag[3] = { 1 };
    int flag_cnt[3] = { 0 };
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", arr);
        int i = 0;
        for (i = 0; i < strlen(arr); i++)
        {
            if (!(arr[i] >= '0' && arr[i] <= '9' && arr[i] >= 'A' && arr[i] <= 'z'))
            {
                flag[0] = 0;
                break;
            }
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                flag_cnt[0] = 1;
            }
            if (arr[i] >= 'A' && arr[i] <= 'Z')
            {
                flag_cnt[1] = 1;
            }
            if (arr[i] >= 'a' && arr[i] <= 'z')
            {
                flag_cnt[2] = 1;
            }
        }
        if ((flag_cnt[0] + flag_cnt[1] + flag_cnt[2]) < 2)
        {
            flag[2] = 0;
        }
        if (arr[0] >= '0' && arr[0] <= '9')
        {
            flag[1] = 0;
        }
        if (flag[0] && flag[1] && flag[2] && strlen(arr) >= 8)
        {
            printf("YES");
        }
        else {
            printf("NO");
        }
    }
    return 0;
}