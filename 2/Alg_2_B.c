#include <stdio.h>
#include <stdlib.h>

int main(){
  int length;
  scanf("%d",&length);
  int *data1 = (int*)malloc(sizeof(int) * length);
  int *data2 = (int*)malloc(sizeof(int) * length);
  for(int i = 0;i < length;i++)
    scanf("%d",&data1[i]);
  for(int i = 0;i < length;i++)
    scanf("%d",&data2[i]);
  if(data1[0] > data2[0]){
    int *temp = data1;
    data1 = data2;
    data2 = temp;
  }
  int count = 0,count2 = 0,stop = 0;
  for(int i = 0;i < length;i++){
    count++;
    if(count == length){
      printf("%d",data1[i]);
      break;
    }
    if(i != length - 1){
      while(data2[count2] < data1[i+1]){
        count++;
        if(count == length){
          printf("%d",data2[count2]);
          stop = 1;
        }
        count2++;
      }
    }
    else{
      printf("%d",data2[count2 + length - count]);
      break;
    }
    if(stop == 1)break;
  }
  free(data1);
  free(data2);
  return 0;
}
