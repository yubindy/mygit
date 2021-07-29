#include <stdio.h>

#include <termios.h>

 

int main(){

 

     struct termios new_setting,init_setting;

     char pwd[16];
     tcgetattr(0,&init_setting);
     new_setting=init_setting;
     new_setting.c_lflag&=~ECHO;
     tcsetattr(0,TCSANOW,&new_setting);
     printf("please enter password: \n");  
    scanf("%s",pwd);
     printf("you enter %s\n",pwd);
     tcsetattr(0,TCSANOW,&init_setting);
     return 0;

}