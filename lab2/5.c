#include<stdio.h>
#include<fcntl.h>
int main(){
 while(1){
   int fd1 = creat("file1",0744);
   int fd2 = creat("file2",0744);
   int fd3 = creat("file3",0744);
   int fd4 = creat("file4",0744);
   int fd5 = creat("file5",0744); 
 }
  return 1;
}
