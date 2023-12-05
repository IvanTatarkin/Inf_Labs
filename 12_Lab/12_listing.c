#include <stdio.h>
#include <string.h>
int main(void){
    int state = 1;
    int symbol;
    int ans = 0;
    while ((symbol = getchar()) != EOF){
        switch (state) {
            case 1:
                if (symbol == '-'){
                    state = 2;
                }
                else if (symbol == '+'){
                    state = 1;
                }
                else if (symbol == '0'){
                    ans = ans * 10;
                }
                else if (symbol == '1'){
                    ans = ans * 10 + 1;
                }
                else if (symbol == '2'){
                    ans = ans * 10 + 2;
                }
                else if (symbol == '3'){
                    ans = ans * 10 + 3;
                }
                else if (symbol == '4'){
                    ans = ans * 10 + 4;
                }
                else if (symbol == '5'){
                    ans = ans * 10 + 5;
                }
                else if (symbol == '6'){
                    ans = ans * 10 + 6;
                }
                else if (symbol == '7'){
                    ans = ans * 10 + 7;
                }
                else if (symbol == '8'){
                    ans = ans * 10 + 8;
                }
                else if (symbol == '9'){
                    ans = ans * 10 + 9;
                }
                break;
            case 2:
                if (symbol == '0'){
                    ans = ans * 10 + 9;
                }
                else if (symbol == '1'){
                    ans = ans * 10 + 8;
                }
                else if (symbol == '2'){
                    ans = ans * 10 + 7;
                }
                else if (symbol == '3'){
                    ans = ans * 10 + 6;
                }
                else if (symbol == '4'){
                    ans = ans * 10 + 5;
                }
                else if (symbol == '5'){
                    ans = ans * 10 + 4;
                }
                else if (symbol == '6'){
                    ans = ans * 10 + 3;
                }
                else if (symbol == '7'){
                    ans = ans * 10 + 2;
                }
                else if (symbol == '8'){
                    ans = ans * 10 + 1;
                }
                else if (symbol == '9'){
                    ans = ans * 10;
                }
                break;
        default:
            break;
        }
    }
    printf("%d\n", ans);
}