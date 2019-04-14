#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int ret_code = 0;
    for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
        ret_code = putchar(c);
 
    /* �����Ƿ�ִ� EOF �� */
    if (ret_code == EOF)
       if (ferror(stdout)) 
       {
          fprintf(stderr,"putchar() failed in file %s at line # %d\n", __FILE__,__LINE__-6);
          perror("putchar()");
          exit(EXIT_FAILURE);
       }
    putchar('\n');
 
    // putchar ����ֵ�����ڲ���
    int r = 0x1070;
    printf("\n0x%x\n", r);
    r = putchar(r);
    printf("\n0x%x\n", r);
}

