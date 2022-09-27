#pragma warning(disable:6031)
#pragma warning(disable:4996)
#include<stdio.h> 
void ShowImage(unsigned char high, unsigned char low, FILE* f);

int main()
{
    char high, low;
    scanf(" %c%c", &high, &low);
    FILE* f = fopen("HZK16.DAT", "rb");
    if (f)
    {
        ShowImage(high, low, f);
        fclose(f);
    }
    return 0;
}

void ShowImage(unsigned char high, unsigned char low, FILE* f)
{
    int i, j;
    unsigned char buffer[32];       //�洢һ���������õ�32���ֽ�
    long int offset;
    offset = ((high - 0xa1) * 94 + low - 0xa1) * 32;     //�������ƫ�Ƶ�ַ
    fseek(f, offset, 0);             //����ƫ��Ѱ�ҵ�������ģ�ĵ�һ���ֽ�
    for (i = 0; i < 32; ++i) {       //������ȡ32���ֽ�
        buffer[i] = fgetc(f);
    }

    for (i = 0; i < 32; ++i) {       //��32���ֽ�˳���ӡ
        for (j = 0; j < 8; ++j) {
            if (buffer[i] & 0x80) {
                printf("��");
            }
            else {
                printf("��");
            }
            buffer[i] <<= 1;
        }
        if (i % 2) {
            printf("\n");           //���i%2==1˵�����ֽ��ǿ�����Ǹ��ֽڣ���ʾ���Ҫ����
        }
    }
}