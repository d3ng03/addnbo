#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(){
    FILE *fp1, *fp2;
    uint32_t n1, n2;

    fp1 = fopen("thousand.bin", "rb");
    fp2 = fopen("five-hundred.bin", "rb");

    if(fp1 == NULL || fp2 == NULL) return 0;
 
    //fscanf(fp1, "%d", &n1);
    //fscanf(fp2,"%d",&n2);
    
    fread(&n1,sizeof(n1),1,fp1);
    fread(&n2,sizeof(n2),1,fp2);

    n1 = htonl(n1);
    n2 = htonl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,n1+n2,n1+n2);



    fclose(fp1); 
    fclose(fp2);
    return 0;
}
