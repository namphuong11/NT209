#include <iostream>
int bitAnd(int x, int y)
{
	int res; // bien ket qua
	res= ~(~x|~y); // dinh luat Morgan ~(x.y)= ~x+~y
	return res;
}

int negative(int x)
{
    //Xor voi so lon nhat tuong duong 32 bit 1 de lay so bu 1
    x=x ^ 4294967295;
    //Cong so bu 1 voi 1 de ra duoc so bu 2 tuc la so am can tim
    x +=1;
    return x;
}

int getByte(int x, int n) {
    // Di chuyen byte can lay ve bên phai de nó tro thanh byte thap nhat
    int shiftedValue = x >> (n << 3);
    // Lay byte thap nhat cua gia tri da di chuyen
    int result = shiftedValue & 0xFF;
    return result;
}

int setByte(int x, int n)
{
    // Tinh toan gia tri cua byte moi voi tat ca bit la 1
    int byteValue = 0xFF;
    // Dich bit sang vi tri thich hop
    byteValue <<= (n<<3);
    // Bat byte thu n cua x bang cach su dung toan tu |
    return x | byteValue;
}

int mulpw2(unsigned int x, int n) {
    //2^n nhung n am nen ta se lay gia tri cua x dich phai ( phep chia ) cho so doi cua n
    x=x >> negative(n);
    return x;
}

int isEqual(int x, int y) {
    // Su dung toan tu XOR (^) de kiem tra su khac biet giua x va y
    // Neu x va y khac nhau, ket qua cua XOR se la 1, nguoc lai la 0
    // O day ta phu dinh lai toan tu XOR de ra duoc ket qua theo yeu cau
	x=!(x ^ y);
    return x;
}

int is16x(int x) {
    return x;
}

int isPositive(int x) {
    x= !((x>>31) & 1);
    return x;
}

int isGE2n(int x, int n) {
    return x;
}

int main()
{
    int score = 0;
    // 1.1
    printf("1.1 bitAnd");
    if (bitAnd(3, -9) == (3 & -9) && bitAnd(1, 8) == (1 & 8))
    {
        printf("\tPass.");
        score += 1;
    }
    else
        printf("\tFailed.");

    //1.2
    printf("\n1.2 negative");
    if (negative(0) == 0 && negative(9) == -9 && negative(-5) == 5)
    {
        printf("\tPass.");
        score += 1;
    }
    else
        printf("\tFailed.");

    //1.3
    printf("\n1.3 getByte");
    if (getByte(8, 0) == 8 && getByte(0x11223344, 1) == 0x33)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    //1.4
    printf("\n1.4 setByte");
    if (setByte(10, 0) == 255 && setByte(0, 1) == 65280 && setByte(0x5501, 2) == 0xFF5501)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    //1.5
    printf("\n1.5 mulpw2");
    if (mulpw2(10, -1) == 5 && mulpw2(15, -2) == 3 && mulpw2(50, -2) == 12)
    {
        if (mulpw2(10, 1) == 20 && mulpw2(5, 4) == 80)
        {
            printf("\tAdvanced Pass.");
            score += 4;
        }
        else
        {
            printf("\tPass.");
            score += 3;
        }
    }
    else
        printf("\tFailed.");

    /*
    //2.1
    printf("\n2.1 isEqual");
    if (isEqual(2,2)==1 && isEqual(5,-1)==0 && isEqual(0,16)==0 && isEqual(-4,-4)==1)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    //2.2
    printf("\n2.2 is16x");
    if (is16x(16) == 1 && is16x(23) == 0 && is16x(0) == 1)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    //2.3
    printf("\n2.3 isPositive");
    if (isPositive(16) == 1 && isPositive(0) == 0 && isPositive(-8) == 0)
    {
        printf("\tPass.");
        score += 3;
    }
    else
        printf("\tFailed.");

    //2.4
    printf("\n2.4 isGE2n");
    if (isGE2n(12, 4) == 0 && isGE2n(8, 3) == 1 && isGE2n(15, 2) == 1)
    {
        printf("\tPass.");
        score += 3;
    }
    else
        printf("\tFailed.");*/

    printf("\n------\nYour score: %.1f", (float)score / 2);
    return 0;
}
