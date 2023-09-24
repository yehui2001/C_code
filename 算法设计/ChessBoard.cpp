#include<iostream>
#include<math.h>
using namespace std;
#define N 100
int tile = 1;
int Board[N][N];
/*
(tag-row)
tr:棋盘左上角方格的行号
tc:棋盘左上角方格的列号
dr:特殊方格所在的行号
dc:特殊方格所在的列号
size:待插方格的宽度 size = 2^k,棋盘规格为2^k * 2^k

四种骨牌放置情况:
                0 1    1 0   1 1  1 1
                1 1    1 1   0 1  1 0
*/

//算法思想：利用分治思想，将原问题先拆解成4个小问题，但其中有三个棋盘与带有特殊方格的棋盘不同
//为了保证我们处理的是相同的子问题，我们需要插入特殊方格，并使新插入的方格构成一张L型骨牌
//所以要求当我们的特殊方格不在该棋盘时，在该棋盘靠近十字分割线的位置插入一张骨牌           
//分析代码流程：运行后，可以看到在最大十字分割线的三个方向上有一张骨牌
//但其实根据递归的顺序，它们并不是最早放上去的，最早放上去的其实是判断分割后左上角棋盘无特殊方格，而在其棋盘右下角放置的2，依次递归，进行到size==1结束一轮
//
void ChessBoard(int tr,int tc,int dr,int dc, int size){
    int s;
    if(size == 1)   return;                 //子棋盘1x1，无法插入L型骨牌
    int t = tile++;                         //L型骨牌号，位于一个递归函数中的tile是一样的，这很合理，因为它们构成一张骨牌
    s = size/2;                             //分割棋盘

    //覆盖左上角子棋盘
    if(dr < tr + s && dc < tc + s)          //特殊方格位于此棋盘中(特殊方格行号小于横轴行号，列号小于竖轴列号)
        ChessBoard(tr,tc,dr,dc,s);          //继续分割
    else{
        Board[tr + s - 1][tc + s - 1] = t;  //用tile覆盖右下角，为什么? 因为我们放置L型骨牌时，都会将新加入的骨牌贴近中轴线交汇处放置，以形成L型骨牌。保证每次递归放入的骨牌都能够组成L型
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);  //在新加入对角线位置的特殊方格基础上，再进行分割
    }
    
    //覆盖右上角子棋盘
    if(dr < tr + s && dc >= tc + s)         //特殊方格位于此棋盘中，tc + s 位于右半边
        ChessBoard(tr,tc+s,dr,dc,s);        //继续分割
    else{
        Board[tr + s - 1][tc + s] = t;      //覆盖左下角
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    
    //覆盖左下角子棋盘
    if(dr >= tr + s && dc < tc + s)         //特殊方格位于此棋盘中
        ChessBoard(tr+s,tc,dr,dc,s);        //继续分割
    else{
        Board[tr + s][tc + s - 1] = t;      //覆盖右上角
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    //覆盖右下角子棋盘
    if(dr >= tr + s && dc >= tc + s)        //特殊方格位于此棋盘中
        ChessBoard(tr+s,tc+s,dr,dc,s);      //继续分割
    else{
        Board[tr + s][tc + s] = t;          //覆盖左上角
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

void Print(int A[100][100],int k){
    int i,j;
    for(i = 0; i < pow(2,k);i++){
        for(j = 0; j < pow(2,k); j++){
            if(j==pow(2,k)/2) cout <<"|";
            cout << A[i][j] <<"\t";
        }
        if(i==pow(2,k)/2-1) cout << "\n" << "------------------------------------------------------------------------------------------------------------------------------------" <<endl;
        cout<< "\n" << endl;
    }
}

int main(){
    //int Board[2][5] = 0;
    int k = 4;
    int size = pow(2,k);
    ChessBoard(0,0,2,5,size);
    Print(Board,k);
    return 0;
}