#include <stdio.h>
#include<stdlib.h>
int *insert(int *arr,int new,int length);

int main(){
    int new,count = 0;
    int *arr;
    while(scanf("%d",&new) != EOF){
      count++;
      int *new_arr;
      if(count == 1){
        new_arr = (int*)malloc(sizeof(int));
        new_arr[0] = new;
      }
      else{
        new_arr = insert(arr,new,count - 1);
      }
      free(arr);
      arr = new_arr;
      printf("%d ",arr[(count+1)/2-1]);
    }
    return 0;
}

int *insert(int *arr,int new,int length){
  int *new_arr = (int*)malloc(sizeof(int)*(length+1));
  if(new <= arr[0]){
    new_arr[0] = new;
    for(int i = 0;i < length;i++){
      new_arr[i+1] = arr[i];
    }
    return new_arr;
  }
  else if(new <= arr[length-1]){
    for(int i = 0;i < length-1;i++){
      if(new > arr[i] && new <= arr[i+1]){
        new_arr[i] = arr[i];
        new_arr[i+1] = new;
        for(int j = i+1;j < length;j++){
          new_arr[j+1] = arr[j];
        }
        return new_arr;
      }
      else{
        new_arr[i] = arr[i];
      }
    }
  }
  else{
    for(int i = 0;i < length;i++){
      new_arr[i] = arr[i];
    }
    new_arr[length] = new;
    return new_arr;
  }
  return new_arr;
}
