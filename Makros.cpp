#include "Makros.h"

char* stradd(const char* strA, const char* strB)
{
        if(strA == NULL)
                strA = "";
        if(strB == NULL)
                strB = "";
        char* buff = new char[strlen(strA) + strlen(strB)];
        strcat(buff,strA);
        strcat(buff,strB);
        return buff;
}

char * substr(const char* str, unsigned int start, unsigned int end)
{
        if(str == 0 || strlen(str) < start || strlen(str) < end || start > end)
                return NULL;

        char *buff = new char[end-start];
        for(unsigned int iup = start, isub = 0; iup < end; iup++, isub++)
        {
                buff[isub] = str[iup];
        }

        return buff;
}

