#include <stdio.h>
#include <math.h>

void moveDisk(char fromPeg, char toPeg, int disk) {
    printf("Move disk %d from %c to %c\n", disk, fromPeg, toPeg);
}

void towersOfHanoiIterative(int n, char src, char aux, char dest) {
    int i, moves = (int)pow(2, n) - 1;
    char s = src, a = aux, d = dest;
    if (n % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }
    for (i = 1; i <= moves; i++) {
        int disk = (i & -i);
        int disk_no = (int)(log2(disk)) + 1;
        if (i % 3 == 1) moveDisk(s, d, disk_no);
        else if (i % 3 == 2) moveDisk(s, a, disk_no);
        else moveDisk(a, d, disk_no);
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towersOfHanoiIterative(n, 'A', 'B', 'C');
    return 0;
}
