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
    unsigned char buffer[32];       //存储一个汉字所用的32个字节
    long int offset;
    offset = ((high - 0xa1) * 94 + low - 0xa1) * 32;     //计算绝对偏移地址
    fseek(f, offset, 0);             //根据偏移寻找到该字字模的第一个字节
    for (i = 0; i < 32; ++i) {       //连续读取32个字节
        buffer[i] = fgetc(f);
    }

    for (i = 0; i < 32; ++i) {       //将32个字节顺序打印
        for (j = 0; j < 8; ++j) {
            if (buffer[i] & 0x80) {
                printf("■");
            }
            else {
                printf("□");
            }
            buffer[i] <<= 1;
        }
        if (i % 2) {
            printf("\n");           //如果i%2==1说明该字节是靠后的那个字节，显示完后要换行
        }
    }
}