#include <iostream>
using namespace std;
#include <stdio.h>



double getNum();
int isDigit(char c);
void skipSpaces();
int znak();

int main()
{
    //napisac funkcje czytajace liczbe naturlana znakowo
    printf("Podaj liczbe rzeczywista ");
    double res = getNum();
    printf("Wczytano liczbe ");
    if(res > 0) putchar('+');
    printf("%lf\n", res);

    return 0;
}


int isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void skipSpaces()
{
    char c;
    while((c = getchar()) == ' ' || c == 9 || c == 13 || c == 10);
    ungetc(c, stdin); //zwraca ostatnio wczytany znak
}

int znak(){

    char c;
    if((c = getchar()) == '-') return -1;
    if(c == '+') return 1;

    ungetc(c, stdin);
    return 1;

}

double getNum()
{
    char c;
    double res = 0;
    skipSpaces();
    int z = znak();
    //dopoki wczytany znak jest znakiem cyfry
    while(isDigit(c = getchar())){
        res = res * 10 + (c - '0');
        if((c = getchar()) == '.'){
            double i = 10;
            while(isDigit(c = getchar())){
                res += (c - '0') / i;
                i *= 10;       
            }
            break;
        }
        else {
            ungetc(c, stdin);
        }
    }
    return z*res;
}

