#include<stdio.h>
void print_sudoku();
int check_sudoku(int ,int);
int solve_sudoku(int);
int n=0;
//int a[9][9]={{2,6,0,0,4,0,1,5,0},{8,3,0,9,6,0,2,0,0},{0,4,9,2,7,0,0,6,0},{0,9,5,1,0,7,3,2,6},{0,0,0,4,3,0,7,0,5},{0,7,8,0,2,6,9,4,0},{9,0,4,6,1,8,5,0,7},{1,8,3,7,0,4,0,9,2},{7,5,6,0,9,0,4,1,0}};

int a[9][9]={{0,0,1,0,0,0,4,0,0},{8,0,6,3,0,2,5,0,1},{0,2,0,5,0,4,0,6,0},{5,0,0,0,0,0,0,0,3},{0,0,0,7,0,9,0,0,0},{6,0,0,0,0,0,0,0,4},{0,3,0,9,0,7,0,4,0},{9,0,8,2,0,1,7,0,5},{0,0,2,0,0,0,6,0,0}};
//int a[9][9]={{0,7,8,1,0,6,4,9,0},{0,0,1,2,0,4,6,0,0},{0,0,0,0,5,0,0,0,0},{4,9,0,0,0,0,0,3,7},{0,0,0,5,0,2,0,0,0},{1,6,0,0,0,0,0,4,5},{0,0,0,0,8,0,0,0,0},{0,0,9,7,0,5,3,0,0},{0,2,7,4,0,3,5,6}};
main()
{
printf("0's in sudoku are empty spaces\n ");
print_sudoku();
if(solve_sudoku(0))
{
printf("solution found after %d moves \n\n",n);
print_sudoku();
}
else
{
printf("no solution found after %d moves",n);
}
}
int solve_sudoku(int i)
{
int r,c;
if(i<0)
{
return 0;
}
else if(i>=81)
{
return -1;
}
else
{
r=i/9;
c=i%9;
if(a[r][c])
{

return check_sudoku(r,c) && solve_sudoku(i+1);
}
else
{
for(a[r][c]=9;a[r][c]>0;a[r][c]--)
{
if(solve_sudoku(i))
{
return -1;
}
}
return 0;
}
}
}
int check_sudoku(int r,int c)
{
int i;
int rr,cc;
n++;
for(i=0;i<9;i++)
{
if(i!=c && a[r][i]==a[r][c])return 0;
if(i!=r && a[i][c]==a[r][c])return 0;
rr=r/3*3+i/3;
cc=c/3*3+i%3;
if((rr!=r || cc!=c) && a[rr][cc]==a[r][c])return 0;
}
return -1;
}
void print_sudoku()
{
int i,j;
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}
}



