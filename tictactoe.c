#include<stdio.h>
#include<conio.h>     // getch()
#include<stdlib.h>    // system()

char arr[10] = {'o','1','2','3','4','5','6','7','8','9'};
void ShowBoard();
int checkForWin();

int main()
{
    int player = 1;
    int i;
    int choice;
    char mark;  // x or o

do{
    ShowBoard();
    player = (player % 2) ? 1:2 ; 
    printf("Player %d turn : ",player);
    scanf("%d",&choice);
    mark = (player == 1) ? 'X' : 'O' ;

    if( choice == 1 )
        arr[1] = mark;
    else if( choice == 2 ) 
        arr[2] = mark;
    else if(choice == 3 )
        arr[3] = mark;
    else if( choice == 4 )
        arr[4] = mark;
    else if( choice == 5 )
        arr[5] = mark;
    else if( choice == 6 )
        arr[6] = mark;
    else if( choice == 7 )
        arr[7] = mark;
    else if( choice == 8 )
        arr[8] = mark;
    else if( choice == 9 )
        arr[9] = mark;

    else    // if player entered the value other than (1-9)
    {
        printf("Invalid Value \n");
        player -- ;
    }

    i = checkForWin();  
    player++;
   

} while (i == -1);

ShowBoard();
if (i == 1)
{  
    player++;
    player = (player % 2) ? 1:2 ; 
    printf("Congratulations !! Player %d is winner\n ", player);
}
else
{
    printf("Ohh Sorry !! Game is Draw\n");
}
  
    return 0;
}  

void ShowBoard()
{
    system("cls"); 
    printf("!! Tic Tac Toe !!\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[1],arr[2],arr[3]);
    printf("     |     |     \n");
    printf("-----|-----|-----\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[4],arr[5],arr[6]);
    printf("     |     |     \n");
    printf("-----|-----|-----\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[7],arr[8],arr[9]);
    printf("     |     |     \n");
}  

int checkForWin()
{
    // For Rows 
    if(arr[1] == arr[2] && arr[2] == arr[3])
    return 1;

    else if(arr[4] == arr[5] && arr[5] == arr[6])
    return 1;

    else if(arr[7] == arr[8] && arr[8] == arr[9])
    return 1;

    // For Columns 
    else if(arr[1] == arr[4] && arr[4] == arr[7])
    return 1;

    else if(arr[2] == arr[5] && arr[5] == arr[8])
    return 1;

    else if(arr[3] == arr[6] && arr[6] == arr[9])
    return 1; 

    // For Diagonals 
    else if(arr[1] == arr[5] && arr[5] == arr[9])
    return 1;

    else if(arr[3] == arr[5] && arr[5] == arr[7])
    return 1;

    // If game is draw
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5'
    && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
    return 0;

    else 
    return -1 ;
}  