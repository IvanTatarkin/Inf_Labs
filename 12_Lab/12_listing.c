#include <stdio.h>
#include <stdlib.h>
int main(void){
    int state = 1;
    int symbol;
    int ans;
    scanf("%d", &ans);
    if (ans > 0){
        printf("%d\n", ans);
    }
    else{

        int ans1 = abs(ans);
        int q = 0;

        if (ans1 == 0){
            q = 1;
        }
        while (ans1 != 0){
            q += 1;
            ans1 = ans1 / 10;
        }
        int dop = 0;
        for (int i = 0; i < q; i++){
            dop = dop * 10 + 9;
        }
        ans = dop - abs(ans);
        printf("%d\n", ans);
    }
}
