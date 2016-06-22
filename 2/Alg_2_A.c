#include <stdio.h>

int arr[5];
void manager(int new,int count);

int main(){
  int new,count = 0;
  scanf("%d",&new);
  while(new != -1){
    count++;
    if(count == 1){
      printf("%d ",new);
      arr[0] = new;
    }
    else if(count == 2){
      if(arr[0] < new){
        arr[1] = new;
      }
      else{
        arr[1] = arr[0];
        arr[0] = new;
      }
      printf("%d ",arr[0]);
    }
    else if(count == 3){
      if(new < arr[0]){
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = new;
      }
      else if(new < arr[1]){
        arr[2] = arr[1];
        arr[1] = new;
      }
      else{
        arr[2] = new;
      }
      printf("%d ",arr[1]);
    }
    else if(count == 4){
      if(new < arr[0]){
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = new;
      }
      else if(new < arr[1]){
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = new;
      }
      else if(new < arr[2]){
        arr[3] = arr[2];
        arr[2] = new;
      }
      else{
        arr[3] = new;
      }
      printf("%d ",arr[1]);
    }
    else if(count == 5){
      if(new < arr[0]){
        arr[4] = arr[3];
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = new;
      }
      else if(new < arr[1]){
        arr[4] = arr[3];
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = new;
      }
      else if(new < arr[2]){
        arr[4] = arr[3];
        arr[3] = arr[2];
        arr[2] = new;
      }
      else if(new < arr[3]){
        arr[4] = arr[3];
        arr[3] = new;
      }
      else{
        arr[4] = new;
      }
      printf("%d ",arr[2]);
    }
    else{
      manager(new,count);
      printf("%d ",arr[2]);
    }
    scanf("%d",&new);
  }
  return 0;
}

void manager(int new,int count){
  int temp[6];
  int index = 0;
  if(new < arr[0]){
    temp[0] = new;
    index = 0;
    for(int i = 1;i <= 5;i++){
      temp[i] = arr[i-1];
    }
  }
  else if(new < arr[1]){
    temp[0] = arr[0];
    temp[1] = new;
    index  = 1;
    for(int i = 2;i <= 5;i++){
      temp[i] = arr[i-1];
    }
  }
  else if(new < arr[2]){
    temp[0] = arr[0];
    temp[1] = arr[1];
    temp[2] = new;
    index = 2;
    for(int i = 3;i <= 5;i++){
      temp[i] = arr[i-1];
    }
  }
  else if(new < arr[3]){
    temp[0] = arr[0];
    temp[1] = arr[1];
    temp[2] = arr[2];
    temp[3] = new;
    index = 3;
    temp[4] = arr[3];
    temp[5] = arr[4];
  }
  else if(new < arr[4]){
    temp[0] = arr[0];
    temp[1] = arr[1];
    temp[2] = arr[2];
    temp[3] = arr[3];
    temp[4] = new;
    index = 4;
    temp[5] = arr[4];

  }
  else{
    for(int i = 0;i < 5;i++){
      temp[i] = arr[i];
    }
    temp[5] = new;
    index = 5;
  }
  if(count % 2 == 0){
    if(index <= 2)
      for(int i = 0;i <= 4;i++){
        arr[i] = temp[i];
      }
    else
      for(int i = 0;i <= 4;i++){
        arr[i] = temp[i+1];
      }
  }
  else{
    if(index >= 3){
      for(int i = 0;i <= 4;i++){
        arr[i] = temp[i+1];
      }
    }
    else{
      for(int i = 0;i <= 4;i++){
        arr[i] = temp[i];
      }
    }
  }
}
