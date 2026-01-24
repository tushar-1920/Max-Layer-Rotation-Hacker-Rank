#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int row, col, rot;
    int i, j, current;
    int rIndex, cIndex;
    int min1, min2, frameNumber;
    int horRot, verRot, currentRot;
    int rotmat[300][300];

    scanf("%d %d %d", &row, &col, &rot);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &current);
            min1 = fmin(i, j);
            min2 = fmin(col - 1 - j, row - 1 - i);
            frameNumber = fmin(min1, min2);

            horRot = col - 1 - 2 * frameNumber;
            verRot = row - 1 - 2 * frameNumber;

            currentRot = rot % (2 * (horRot + verRot));

            rIndex = i;
            cIndex = j;

            while (currentRot != 0) {
                if (rIndex == frameNumber && cIndex > frameNumber) {
                    cIndex--;
                } else if (cIndex == frameNumber && rIndex < (row - 1 - frameNumber)) {
                    rIndex++;
                } else if (rIndex == (row - 1 - frameNumber) && cIndex < (col - 1 - frameNumber)) {
                    cIndex++;
                } else if (cIndex == (col - 1 - frameNumber) && rIndex > frameNumber) {
                    rIndex--;
                }
                currentRot--;
            }

            rotmat[rIndex][cIndex] = current;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", rotmat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
