#include <stdio.h>

int verify(FILE *fp, int ch, int i)
{
if(i==1)
    return 0;
else
    printf("Caracter actual: %c", ch);
    fseek(fp, -2, SEEK_CUR);
    verify(fp, ch, i);
    return 0;
}
int exists(const char *fname)
{
	FILE *file;
	if ((file=fopen(fname, "r")))
	
		fclose(file);
		return 1;
	
}
int main(int argc, char** argv)
{
FILE *fp = fopen(argv[1], "r");
int ch = getc(fp);
int i=0;
if (exists(argv[1])==1)
    printf("El archivo existe y es el siguiente:\n");
fseek(fp, 0, SEEK_SET);
while (ch != EOF)
{
    ch = getc(fp);
    putchar(ch);
}
fseek(fp, 0, SEEK_END);
while(i!=1)
{
i=(int)ftell(fp);
ch = getc(fp);
putchar(ch);
fseek(fp, -2, SEEK_CUR);
}
printf("\n");
verify(fp, ch, i);
return 0;
}

