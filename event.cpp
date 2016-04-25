#include "event.h"

char * Trans(Event &e, char *s);

int TestMain(){
    char input[100], tmp[100];
    char *p;
    Event e;

    for(int i = 0; i < 3; i ++){
        gets(input);
        Trans(e, input);
    }

    cout << e;

    return 0;
}

char * Trans(Event &e, char *s){
    int i;
    char *p;
    s = s+1;
    p = strtok(s, " ");
    i = TransInt(p);
    p = strtok(NULL, "=");

    switch(i){
        case 1:{
            e.name = p;
            break;
        }
        case 2:{
            e.description = p;
            break;
        }
        case 3:{
            e.location = p;
            break;
        }
        default:{
            break;
        }
    }

    return p;
}

ostream& operator<<(ostream &os, const Event &e){

    os << setw(10) << setiosflags(ios::left) << "Event" << " : " << e.name << endl;
    os << setw(10) << setiosflags(ios::left) << "Des" << " : " << e.description << endl;
    os << setw(10) << setiosflags(ios::left) << "Location" << " : " << e.location << endl;

    return os;
}

int TransInt(char *s){
    int i, j, flag, sign;

    i = j = flag = sign = 0;
    while(*s != 0){
        if(*s == '*'){
            if(flag == 0){
                flag = 1;
                if(sign == 1){
                    i = -i;
                    sign = 0;
                }
            } else{
                if(sign == 1){
                    j = -j;
                    sign = 0;
                }
                i *= j;
                j = 0;
            }
        } else if(*s >= '0' && *s <= '9'){
            if(flag == 0){
                i = i*10 + *s-'0';
            } else{
                j = j*10 + *s-'0';
            }
        } else if(*s == '-'){
            if(sign == 0){
                sign = 1;
            }
        }else{
            return _ERROR;
        }

        s ++;
    }

    if(flag == 1){
        if(sign == 1){
            j = -j;
            sign = 0;
        }
        i *= j;
    } else{
        if(sign == 1){
            i = -i;
        }
    }

    return i;
}
