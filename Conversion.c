#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <stdlib.h>

int Conversion(char num[20], int t, int n)
{
int i,ii,j,k,m,x,b[30],h[30],c;
double d,r;
ii=0; 
p=0;
memset(out,0,20);
m=strlen(num);//���ַ����ĳ���
x=m; 
for(k=0,j=0;k<m;k++)//��Ҫ�ǷֶΣ���С����Ϊ���ޣ�ֻת���������� 
{ 
   if(num[k]=='.') 
   { 
      x=k; 
      break; 
   } 
}

for(j=x-1;j>=0;j--) 
{ 
   if(num[j]=='-') break; //���ŵĴ��� 
   if(num[j]=='A') r=10; 
   else if(num[j]=='B') 
      r=11; 
   else if(num[j]=='C') 
      r=12; 
   else if(num[j]=='D') 
      r=13; 
   else if(num[j]=='E') 
      r=14; 
   else if(num[j]=='F')
      r=15; 
   else 
      r=num[j]-'0';//���ַ�ת�������� 
   p=p+r*(pow ((double)t,(double)(x-j-1)));//������ 
}

if(num[x]=='.') 
{ 
   for(j=x+1;j<m;j++)
   {
      if(num[j]=='A') r=10; 
      else if(num[j]=='B') 
         r=11; 
      else if(num[j]=='C') 
         r=12; 
      else if(num[j]=='D') 
         r=13; 
      else if(num[j]=='E') 
         r=14; 
      else if(num[j]=='F') 
         r=15; 
      else 
         r=num[j]-'0';//���ַ�ת�������� 
      p=p+r*(pow ((double)t, (double)(x-j))); 
   } 
}
//g_print("%f",p);
if(n==10)//���Ҫת����ʮ����
{ 
   if(num[0]=='-') 
   {
      p=-p;
   }
   return 0;
} 
 
else //���Ҫת������������
{
   k=(int)p;
   i=0; 
   while(k)//�ж���Ҫת�������Ƿ��Ϊ0 
   { 
      h[i++]=k%n;//ȡ�࣬���н���ת��������˳������ȷֵ�෴ 
      k/=n;//ת��һλ֮�������Ӧ�ı仯 
   } 
   c=0; 
   if(p!=(int)p)//ѡ���Լ��㣬����������Ͳ��ý�����һ���ļ�����
   { 
      d=p-(int)p;//ȡС������ 
      while(d!=0) 
	  { 
         b[c]=(int)(d*n);//�㷨Ϊ��Nȡ�� 
         d=d*n-b[c]; 
         c++; 
         if(c>=10) 
            break;//��Ҫ�ǿ���С��������һ��������С����ʱ�������ѭ�����������ѭ�� 
	  } 
   }
   if(num[0]=='-')
   {   
	   out[0]='-';
	   ii++;
   }
   for(j=i-1;j>=0;j--,ii++)//�������,����10�����ֽ�����Ӧ�ı仯 
   { 
	  if(h[j]==10) out[ii]='A';
      else if(h[j]==11) out[ii]='B';
      else if(h[j]==12) out[ii]='C';
      else if(h[j]==13) out[ii]='D';
      else if(h[j]==14) out[ii]='E';
      else if(h[j]==15) out[ii]='F';
	  else if(h[j]==9)  out[ii]='9';
	  else if(h[j]==8)  out[ii]='8';
	  else if(h[j]==7)  out[ii]='7';
	  else if(h[j]==6)  out[ii]='6';
	  else if(h[j]==5)  out[ii]='5';
	  else if(h[j]==4)  out[ii]='4';
	  else if(h[j]==3)  out[ii]='3';
	  else if(h[j]==2)  out[ii]='2';
	  else if(h[j]==1)  out[ii]='1';
	  else out[ii]='0';
   } 
   if(p!=(int)p)//ѡ����������������Խ�Լ���ʱ��ͳ��������ʱ�� 
   {
      out[ii++]='.';
      for(j=0;j<c;j++)//������� 
	  { 
         if(b[j]==10) out[ii]='A';
         else if(b[j]==11) out[ii]='B';
         else if(b[j]==12) out[ii]='C';
         else if(b[j]==13) out[ii]='D';
		 else if(b[j]==14) out[ii]='E';
         else if(b[j]==15) out[ii]='F';
         else if(b[j]==9) out[ii]='9';
         else if(b[j]==8) out[ii]='8';
		 else if(b[j]==7) out[ii]='7';
         else if(b[j]==6) out[ii]='6';
         else if(b[j]==5) out[ii]='5';
         else if(b[j]==4) out[ii]='4';
		 else if(b[j]==3) out[ii]='3';
         else if(b[j]==2) out[ii]='2';
         else if(b[j]==1) out[ii]='1';
         else out[ii]='0';
		 ii++;
	  }
   }
   //puts(out);
   return 0;
} 
}
