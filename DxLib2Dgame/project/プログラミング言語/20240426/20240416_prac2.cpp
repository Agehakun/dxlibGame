#include<stdio.h>
int main(void)
{
    //�ϐ��錾
    int a = 10;//�����^
    long b = 12345678;//�{���x
    float c = 10.5f;//���������_
    double d = 3.14159265358979;//�{���������_
    //Char�^�i�����^�j

    //�����̕\��
    printf("a=%f,b=%d\n",(float) (a)+c, b);
    printf("c=%f,d=%f\n", c, d);
    return 0;
}



