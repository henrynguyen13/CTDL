#include <stdio.h>

int S, n, m, count;

void TRY(int k, int last){

    for(int v = last+1; v <= m; v++){

        S += v;

        if(k == n){

        if(S == m) count++;

        }else TRY(k+1,v);

        S -= v;

    }

}

int main(int argc, char** argv){

    n = 3; m = 11; count = 0; S = 0;

    TRY(1,0);

printf("%d\n",count);

}
