#include <stdlib.h>
#include <string.h>

char chosen[10];
int gameOn = 1;

int matrix[6*7] = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 0, 1, 1, 0,
  0, 0, 0, 1, 0, 0, 0,
  1, 1, 0, 0, 1, 1, 0,
  0, 0, 0, 1, 1, 1, 0,
  3, 1, 0, 0, 0, 1, 2
};
#define Y ((int)(positionX*(positionX/7)/positionX))
int positionX = matrix[5]; 
int positionY = Y;//y passa a ser uma ref

void viewArray(int (*matrix)) {
    for (int i = 0; i < 6*7; i++){
            if (matrix[i] == 1) {
              printf("■ ");
            } else if (matrix[i] == 0) {
              printf("□ ");
            } else if (matrix[i] == 2) {
              printf("☑ ");
            } else if (matrix[i] == 3) {
              printf("X ");
            } else {
              printf("%d ", matrix[i]);
            }
        printf("\n");
    }
}

int main() {
  printf("\nThe Maze!!\n\nCommands:\nForward - 'up'\nBackward - 'down'\nRight - 'right'\nLeft - 'left'\n\n");
  viewArray(matrix);

  while(gameOn = 1) {
    printf("\nChoose where you want to go: ");
    scanf("%s", chosen);

    if (strcmp(chosen, "up") == 0 && positionX > 0 && matrix[Y] > 0) {
            matrix[positionX] = 0;
            positionX--;
            matrix[positionX] = 3;
        } else if (strcmp(chosen, "down") == 0 && positionX < 5 && matrix[positionX + 1][positionY] == 0) {
            matrix[positionX] = 0;
            positionX++;
            matrix[positionX] = 3;
        } else if (strcmp(chosen, "left") == 0 && positionY > 0 && matrix[positionX][positionY - 1] == 0) {
            matrix[positionX] = 0;
            positionY--;
            matrix[positionX] = 3;
        } else if (strcmp(chosen, "right") == 0 && positionY < 6 && matrix[positionX][positionY + 1] == 0) {
            matrix[positionX] = 0;
            positionY++;
            matrix[positionX] = 3;
        } else if (strcmp(chosen, "down") == 0 && positionX < 5 && matrix[positionX + 1][positionY] == 2) {
            matrix[positionX] = 0;
            positionX++;
            matrix[positionX] = 3;
            break;
        }
    
    printf("\n");
    viewArray(matrix);
  }

  printf("\nCongratulations you have reached the end of the maze!!");
}
