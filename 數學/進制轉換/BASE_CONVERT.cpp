#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000
char str[MAXSIZE];
int start[MAXSIZE],ans[MAXSIZE],res[MAXSIZE];
int oldBase,newBase;

int getNum(char c)
{
    if(c>='0'&&c<='9') return c-'0';
    if(c>='A'&&c<='Z') return c-'A'+10;
    return c-'a'+36;
}

char getChar(int i)
{
    if(i>=0&&i<=9)return i+'0';
    if(i>=10&&i<=35)return i-10+'A';
    return i-36+'a';
}
void change()
{
    int i;
    start[0]=strlen(str);
    for(i=1;i<=start[0];i++)
        start[i]=getNum(str[i-1]);
}
void solve()
{
    memset(res,0,sizeof(res));
    int y,i,j;
    while(start[0]>=1)
    {
        y=0;i=1;
        ans[0]=start[0];
        while(i<=start[0])
        {
            y=y*oldBase+start[i];
            ans[i++]=y/newBase;
            y%=newBase;
        }
        res[++res[0]]=y;
        i=1;
        while(i<=ans[0]&&ans[i]==0) i++;
        memset(start,0,sizeof(start));
        for(j=i;j<=ans[0];j++)
            start[++start[0]]=ans[j];
        memset(ans,0,sizeof(ans));
    }
}
void output()
{
    int i;
    printf("%d %s\n",oldBase,str);
    printf("%d ",newBase);
    for(i=res[0];i>=1;i--)
        printf("%c",getChar(res[i]));
    printf("\n\n");
}
int main()
{
    oldBase=3;
    newBase=9;
    strcpy(str,"212");
    change();
    solve();
    output();
    return 0;
}
