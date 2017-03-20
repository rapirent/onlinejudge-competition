#include <cstdio>
#include <iostream>

using namespace std;

int solution[8][100]={0};
int count=0;
int test[3][17] = {0};

void search(int x)
{
    if(x==8) {
        count++;
        return;
    }
    for(int y = 0;y<8;y++) {
        if(!test[0][y] && !test[1][x+y] && !test[2][x-y+8]) {
            solution[x][count] = y;
            test[0][y] = test[1][x+y] = test[2][x-y+8] = 1;
            search(x+1);
            test[0][y] = test[1][x+y] = test[2][x-y+8] = 0;
        }
    }
}


int main(void)
{
    search(0);
    int repeat;
    scanf("%d",&repeat);
    while(repeat-->0) {
        int weight[8][8] = {0};
        for(int x = 0;x<8;x++) {
            for(int y = 0; y<8;y++) {
                scanf("%d",&weight[x][y]);
            }
        }
        int sum = 0;
        for(int count_trav = 0; count_trav < count ; count_trav++) {
            int tmp = 0;
            for(int x = 0;x<8;x++) {
                tmp += weight[x][ solution[x][count_trav] ];
            }
            if(tmp>sum) {
                sum = tmp;
            }
        }
        printf("%5d\n",sum);
    }    
}
