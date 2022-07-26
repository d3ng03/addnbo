#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char** argv){
    FILE *fp1, *fp2;
    uint32_t n1, n2;
    if(argc != 3) return 0;
    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    if(fp1 == NULL || fp2 == NULL) return 0;
 
    fread(&n1,sizeof(n1),1,fp1);
    fread(&n2,sizeof(n2),1,fp2);

    n1 = htonl(n1);
    n2 = htonl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,n1+n2,n1+n2);



    fclose(fp1); 
    fclose(fp2);
    return 0;
}
