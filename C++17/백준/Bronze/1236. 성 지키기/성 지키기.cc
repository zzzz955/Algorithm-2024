#include<iostream>
std::string s[50];int r[50],c[50],n,m,i,j,a=1e9,x=0,y=0;
int main() {std::cin>>n>>m;for(i=0;i<n;i++){std::cin>>s[i];for(j=0;j<m;j++){if(s[i][j]=='X'){r[i]=1;c[j]=1;}}}for(i=0;i<n;i++)if(!r[i])x++;for(i=0;i<m;i++)if(!c[i])y++;printf("%d",std::max(x,y));}