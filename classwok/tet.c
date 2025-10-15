#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
static _Bool T_Piece[3][3] = {
    {
        0,0,0
    },
    {
        1,1,1
    },
    {
        0,1,0
    }
};
_Bool ** RotatePiece(_Bool** piece,int rotation){
    for(int i = 0 ; i < rotation ; i ++){
        _Bool cornTemp = piece[0][0];
        piece[0][0] = piece[0][2];
        piece[0][2] = piece[2][2];
        piece[2][2] = piece[2][0];
        piece[2][0] = cornTemp;
        _Bool sideTemp = piece[0][1];
        piece[0][1] = piece[2][1];
        piece[2][1] = piece[1][2];
        piece[1][2] = piece[1][0];
        piece[1][0] = piece[0][0];
    }
}
_Bool ** MakeNewPiece(_Bool pieceType[3][3]){
    _Bool ** newPiece = malloc(sizeof(_Bool*)*3);
    for(int i = 0 ; i < 3 ; i++){
        newPiece[i] = malloc(sizeof(_Bool)*3);
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%p\n=========\n",&newPiece[i][j]);
            newPiece[i][j] =  pieceType[i][j];
            printf("%d\n",pieceType[i][j]);
        }
    }
    return (_Bool**)newPiece;
}
void DisplayPiece(_Bool**piece){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d",piece[i][j]);
        }
        printf("\n");
    }
}
void main(){
    _Bool ** curPiece = MakeNewPiece(T_Piece);
    DisplayPiece(curPiece);
    RotatePiece(curPiece,1);
    DisplayPiece(curPiece);
}
