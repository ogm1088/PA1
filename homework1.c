#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Set the size of the data size to 12000 (maximum)
#define ROW 1000
#define DIM 12
int ReadFromFile(int **Array, FILE *inFile);

int main(int argc, char *argv[]){

    if(argc==1 || argc < 13 || argc > 14){
        puts("Too few or too many data input");
        exit(1);
    }

    //store the q points into an array
    int *q =(int*)malloc(sizeof(int)*DIM);
    if(!q){
        puts("Cannot allocate memory");
        exit(1);
    }
    for(int i = 0; i < DIM; i++){
        q[i] = atoi(argv[i+2]);
    } 
    
    //open the data file
    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        puts("Unable to open the file");
        exit(1);
    }

    //Allocate memory for the 2D array
    int **data_array = (int**)malloc(ROW * sizeof(int*));
    for(int i=0;i<ROW;i++){
        data_array[i] =(int*)malloc(DIM * sizeof(int));
    }
    if(!data_array){
        puts("Cannot allocate memory");
        exit(1);
    }

    //Load data into a 2D array
    for(int i=0; i<ROW;i++){
        for(int j=0;j<DIM;j++){
            data_array[i][j]= ReadFromFile(data_array, fp);
            printf("%d ",data_array[i][j]);
        }
        printf("\n");
    }

    free(q);
   for(int i=0;i<ROW;i++){
        free(data_array[i]);
    }    
    free(data_array);
    //Close file
    fclose(fp);

    return 0;
}

int ReadFromFile(int **Array, FILE *inFile)
{
int value;
fscanf(inFile,"%i,", &value);

return (value);
}