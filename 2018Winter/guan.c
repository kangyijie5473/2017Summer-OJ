#include <stdio.h>
#define N 5
void getStudentAve(int *array, int num)
{
    int sum = 0;
    for (int i = num * 5 + 0; i < (num + 1) * 5; i++)
        sum += array[i];
    printf("No.%d student average grades is %f\n", num, sum / 5.0);
    return;
}
void getClassAve(int *array, int num)
{
    int sum = 0;
    for (int i = num + 4; i < N * 5 + 5; i += 5)
        sum += array[i];
    printf("No. %d class average grades is %f\n", num, sum / (N * 1.0));
    return;
}
void getHighestStudent(int *array)
{
    int max = 0, index;
    for (int i = 5; i < N * 5 + 5; i++)
        if (array[i] > max){
            max = array[i];
            index = i;

        }
    printf("highest grade is No.%d student, No.%d class ,grade is %d\n", index / 5, index % 5 + 1, array[index]);
    return;
}
void getFangcha(int *array)
{
    int sum = 0;
    int s = 0;
    for (int i = 5; i < N * 5 + 5; i++) {
        s += array[i];
        sum += array[i] * array[i];
    
    }
    printf("fang cha %f\n", (sum / (N * 1.0 )) - (s * s / (N * N * 1.0)));
}
int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    int i, j, grade[N*5 + 5];
    for (i = 1; i <= N; i++) {
        for (j = 0; j < 5; j++) {
            printf("input NO.%d student---No.%d class grade\n", i + 1, j + 1);
            scanf("%d", &grade[i*5 + j]);
        }
    }
    getStudentAve(grade, 2);
    getClassAve(grade, 3);
    getHighestStudent(grade);
    getFangcha(grade);
    return 0;
}

