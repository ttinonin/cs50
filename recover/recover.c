#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if(argc != 2){
        printf("Usage: ./recover [key]\n");
        return 1;
    }
    int16_t buffer;
    while(fread(&buffer, sizeof(buffer), 1, file)){
        if(buffer[0]=='0xff' && buffer[1] == '0xd8' && buffer[2]=='0xff'){
            continue;
        }
        else{
            break;
        }
    }
}