#include <gtk/gtk.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

void Binary_Operator()          /*˫Ŀ����*/
{
   char num[20];
   strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));/*ȡ���ı��������*/
   if(a==0)                      /*���û�е�һ��������洢Ϊ��һ����*/
   {
	   if(principle==16)
	   {
	      Conversion (num,16,10); /*�������ʮ��������ת��Ϊʮ����*/
		  a=p;
	   }
       if(principle==10)
       {
	       a=atof(num);           /*ֱ��ת���ɸ�����*/
	   }
	   if(principle==8)
	   {
	      Conversion (num,8,10);  /*������İ˽�����ת��Ϊʮ����*/
		  a=p;
	   }
	   if(principle==2)
	   {
	      Conversion (num,2,10);  /*������Ķ�������ת��Ϊʮ����*/
		  a=p;
	   }
      gtk_entry_set_text(GTK_ENTRY(entry),"");  /*����ı���*/
   }
   else        /*������е�һ��������Ӧ�洢Ϊ�ڶ�����*/
   {
       if(principle==16)
	   {
	       Conversion(num,16,10);  /*�������ʮ��������ת��Ϊʮ����*/
		   b=p;
	   }
       if(principle==10)
       {
	       b=atof(num);            /*ֱ��ת���ɸ�����*/
	   }
	   if(principle==8)
	   {
	       Conversion(num,8,10);   /*������İ˽�����ת��Ϊʮ����*/
		   b=p;
	   }
	   if(principle==2)
	   {
	       Conversion(num,2,10);   /*������Ķ�������ת��Ϊʮ����*/
		   b=p;
	   }
   }
   hasdot=0;   /*��ʾ�Ѿ�û��С����*/
}

void Right_output()
{
   char num[20];
   gcvt(a,32,num);             /*������ת�����ַ���*/
   if(principle==16)
   {
	  Conversion(num,10,16);   /*����������ʮ�����ַ�����ת����ʮ��������*/
	  gtk_entry_set_text(GTK_ENTRY(entry),out);     /*��ʾ���*/
   }
   if(principle==10)
   {  
	  //gcvt(a,32,num);             /*������ת�����ַ���*/
	  gtk_entry_set_text(GTK_ENTRY(entry),num);     /*ֱ����ʾ���*/
   }
   if(principle==8)
   {
	  Conversion(num,10,8);    /*����������ʮ�����ַ�����ת���ɰ˽�����*/
	  gtk_entry_set_text(GTK_ENTRY(entry),out);     /*��ʾ���*/
   }
   if(principle==2)
   {
	  Conversion(num,10,2);    /*����������ʮ�����ַ�����ת���ɶ�������*/
	  gtk_entry_set_text(GTK_ENTRY(entry),out);     /*��ʾ���*/
   }
   a=0;
   b=0;
   method=0;
}

float fun(int c)   /*�ݹ麯����׳�*/
{
	float d;
	if(c==0 || c==1) d=1;
	else d=fun(c-1)*c;
	return d;
} 

void output()
{
  char num[20]="0";
  strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));   /* ȡ���ı������������*/
  if(principle==16)
  {
      Conversion(num,16,10);  /*�������ʮ��������ת��Ϊʮ����*/
      b=p;
  }
  if(principle==10)
  {
      b=atof(num);            /*ֱ��ת���ɸ�����*/
  }
  if(principle==8)
  {
      Conversion(num,8,10);   /*������İ˽�����ת��Ϊʮ����*/
      b=p;
  }
  if(principle==2)
  {
      Conversion(num,2,10);   /*������Ķ�������ת��Ϊʮ����*/
      b=p;
  }
  switch(method)
  {
     case 0:
       a=a+b; Right_output(); break;
     case 1:
       a=a-b; Right_output(); break;
     case 2:
	   a=a*b; Right_output(); break;
     case 3:
	   if(b==0)
	   {
           a=0; b=0; method=0;
		   gtk_entry_set_text (GTK_ENTRY(entry),
			       g_locale_to_utf8("��������Ϊ��",-1,NULL,NULL,NULL)); /*��ʾ������Ϣ*/
	   }
       else
	   {
          a=a/b;
		  Right_output();
	   }break;
	 case 4:
       a=pow(a,b); Right_output(); break;
	 case 5:
       a=((int)a) & ((int)b); Right_output(); break;
     case 6:
       a=((int)a) | ((int)b); Right_output(); break;
     case 7:
       a=((int)a) ^ ((int)b); Right_output(); break;
     case 8:
       if(b==0)
	   {
           a=0; b=0; method=0;
		   gtk_entry_set_text (GTK_ENTRY(entry),
			       g_locale_to_utf8("��������Ϊ��",-1,NULL,NULL,NULL)); /*��ʾ������Ϣ*/
	   }
       else
	   {
          a=((int)a) % ((int)b);
		  Right_output();
	   }break;
	 case 9:
       a=sin(b); Right_output(); break;
     case 10:
       a=cos(b); Right_output(); break;
     case 11:
	   a=tan(b); Right_output(); break;
     case 12:
       a=exp(b); Right_output(); break;
	 case 13:
       a=b*b*b; Right_output(); break;
	 case 14:
       a=b*b; Right_output(); break;
     case 15:
	   if(b<=0)
	   {
           a=0; b=0; method=0;
		   gtk_entry_set_text (GTK_ENTRY(entry),
			       g_locale_to_utf8("��������Ϊ����",-1,NULL,NULL,NULL)); /*��ʾ������Ϣ*/
	   }
	   else
	   {
          a=log(b);
		  Right_output(); 
	   }break;
     case 16:
	   if(b<=0)
	   {
          a=0; b=0; method=0;
		  gtk_entry_set_text (GTK_ENTRY(entry),
			       g_locale_to_utf8("��������Ϊ����",-1,NULL,NULL,NULL)); /*��ʾ������Ϣ*/
	   }
	   else
	   {
          a=log10(b);
		  Right_output(); 
	   }break;
     case 17:
	   if(b<0)
	   {
          a=0; b=0; method=0;
		  gtk_entry_set_text (GTK_ENTRY(entry),
			       g_locale_to_utf8("����������Ч",-1,NULL,NULL,NULL)); /*��ʾ������Ϣ*/

	   }
       else
	   { 
         a=fun((int)(b));
	     Right_output();
	   }break;
	 case 18:
	   if(b==0)
	   {
           a=0; b=0; method=0;
		   gtk_entry_set_text (GTK_ENTRY(entry),
			       g_locale_to_utf8("��������Ϊ��",-1,NULL,NULL,NULL)); /*��ʾ������Ϣ*/
	   }
	   else
	   {
          a=1/b;
		  Right_output();
	   }break;
	 case 19:
       a=~((int)b); Right_output(); break;
	 case 20:
       a=floor(b); Right_output(); break;
     default: break;
  }
}

void Add(GtkWidget *widget, gpointer data)    /*�ӷ�����*/
{
   method=0;
   Binary_Operator();
}

void Sub(GtkWidget *widget,gpointer data)     /*��������*/
{
   method=1;
   Binary_Operator();
}

void Mul(GtkWidget *widget,gpointer data)     /*�˷�����*/
{
   method=2;
   Binary_Operator();
}

void Division(GtkWidget *widget,gpointer data)   /*��������*/
{
   method=3;
   Binary_Operator();
}

void Mathpowxy(GtkWidget *widget,gpointer data)  /*������*/
{
   method=4;
   Binary_Operator();
}

void And(GtkWidget *widget,gpointer data)   /*�߼���*/
{
   method=5;
   Binary_Operator();
}

void Or(GtkWidget *widget,gpointer data)    /*�߼���*/
{
   method=6;
   Binary_Operator();
}

void Xor(GtkWidget *widget,gpointer data)    /*�߼����*/
{
   method=7;
   Binary_Operator();
}

void Mod(GtkWidget *widget,gpointer data)    /*ģ����(ȡ��)*/
{
   method=8;
   Binary_Operator();
}

void Sin(GtkWidget *widget,gpointer data)    /*�����ң�������ֵ��*/
{
   method=9;
   output();
}

void Cos(GtkWidget *widget,gpointer data)    /*�����ң�������ֵ��*/
{
   method=10;
   output();
}

void Tan(GtkWidget *widget,gpointer data)    /*�����У�������ֵ��*/
{
   method=11;
   output();
}

void Exp(GtkWidget *widget,gpointer data)    /*ָ������*/
{
   method=12;
   output();
}

void Cube(GtkWidget *widget,gpointer data)    /*����*/
{
   method=13;
   output();
}

void Square(GtkWidget *widget,gpointer data)    /*ƽ��*/
{
   method=14;
   output();
}

void Log_e(GtkWidget *widget,gpointer data)    /*����Ϊe�����*/
{
   method=15;
   output();
}

void Log_10(GtkWidget *widget,gpointer data)    /*����Ϊ10�����*/
{
   method=16;
   output();
}

void Factorial(GtkWidget *widget,gpointer data)    /*�׳�*/
{
   method=17;
   output();
}

void Inverse(GtkWidget *widget,gpointer data)    /*����*/
{
   method=18;
   output();
}

void Not(GtkWidget *widget,gpointer data)    /*�߼���*/
{
   method=19;
   output();
}

void Floor(GtkWidget *widget,gpointer data)    /*ȡ��*/
{
   method=20;
   output();
}

void dot(GtkWidget *widget,gpointer data)
{                     
   if(hasdot==0) /* û��С���������һ��С���㡣*/
     {
        gtk_entry_append_text (GTK_ENTRY(entry), gtk_button_get_label(widget));
        hasdot=1;/*  ��ʾ��һ��С���㡣*/
     }
}

void Sign()
{
   char num[20];
   float c;
   strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));/*ȡ���ı�������ݡ�*/
   c=atof(num);             /*ת���ɸ�����*/
   c=-c;
   gcvt(c,32,num);          /*���ת�����ַ���*/
   gtk_entry_set_text(GTK_ENTRY(entry),num);    /*��ʾ���*/
}

void clear(GtkWidget *widget,gpointer data)
{
   gtk_entry_set_text(GTK_ENTRY(entry),"");
   hasdot=0;
   a=0;
   b=0;
   method=0;
}

void input (GtkWidget *widget, gpointer data)
{
   gtk_entry_append_text (GTK_ENTRY (entry), gtk_button_get_label(widget));
}

void input_pi (GtkWidget *widget, gpointer data)
{
   gtk_entry_set_text (GTK_ENTRY (entry), "3.1415926535897932384626433832795");
}

void addsignal()
{
/* �����17����ťʵ�����ֵ�����*/
g_signal_connect (G_OBJECT(button1), "clicked", G_CALLBACK(input_pi), NULL);
g_signal_connect (G_OBJECT(button14), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button15), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button16), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button17), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button18), "clicked", G_CALLBACK(input), NULL); /*A*/
g_signal_connect (G_OBJECT(button19), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button20), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button21), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button23), "clicked", G_CALLBACK(input), NULL); /*B*/
g_signal_connect (G_OBJECT(button24), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button25), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button26), "clicked", G_CALLBACK(input), NULL);
g_signal_connect (G_OBJECT(button28), "clicked", G_CALLBACK(input), NULL); /*C*/
g_signal_connect (G_OBJECT(button33), "clicked", G_CALLBACK(input), NULL); /*D*/
g_signal_connect (G_OBJECT(button38), "clicked", G_CALLBACK(input), NULL); /*E*/
g_signal_connect (G_OBJECT(button42), "clicked", G_CALLBACK(input), NULL); /*F*/
/*����İ�ťʵ��С���������*/
g_signal_connect (G_OBJECT(button27), "clicked", G_CALLBACK(dot), NULL);
/*����İ�ťʵ�������ŵ�����*/
g_signal_connect (G_OBJECT(button22), "clicked", G_CALLBACK(Sign), NULL);
/*����İ�ťʵ�ָ������������*/
g_signal_connect (G_OBJECT(button2), "clicked", G_CALLBACK(Sin), NULL);
g_signal_connect (G_OBJECT(button3), "clicked", G_CALLBACK(Cos), NULL);
g_signal_connect (G_OBJECT(button4), "clicked", G_CALLBACK(Tan), NULL);
g_signal_connect (G_OBJECT(button6), "clicked", G_CALLBACK(Exp), NULL);
g_signal_connect (G_OBJECT(button7), "clicked", G_CALLBACK(Mathpowxy), NULL);
g_signal_connect (G_OBJECT(button8), "clicked", G_CALLBACK(Cube), NULL);
g_signal_connect (G_OBJECT(button9), "clicked", G_CALLBACK(Square), NULL);
g_signal_connect (G_OBJECT(button10), "clicked", G_CALLBACK(Log_e), NULL);
g_signal_connect (G_OBJECT(button11), "clicked", G_CALLBACK(Log_10), NULL);
g_signal_connect (G_OBJECT(button12), "clicked", G_CALLBACK(Factorial), NULL);
g_signal_connect (G_OBJECT(button13), "clicked", G_CALLBACK(Inverse), NULL);
g_signal_connect (G_OBJECT(button32), "clicked", G_CALLBACK(Add), NULL);
g_signal_connect (G_OBJECT(button31), "clicked", G_CALLBACK(Sub), NULL);
g_signal_connect (G_OBJECT(button30), "clicked", G_CALLBACK(Mul), NULL);
g_signal_connect (G_OBJECT(button29), "clicked", G_CALLBACK(Division), NULL);
g_signal_connect (G_OBJECT(button35), "clicked", G_CALLBACK(And), NULL);
g_signal_connect (G_OBJECT(button36), "clicked", G_CALLBACK(Or), NULL);
g_signal_connect (G_OBJECT(button37), "clicked", G_CALLBACK(Mod), NULL);
g_signal_connect (G_OBJECT(button39), "clicked", G_CALLBACK(Not), NULL);
g_signal_connect (G_OBJECT(button40), "clicked", G_CALLBACK(Xor), NULL);
g_signal_connect (G_OBJECT(button41), "clicked", G_CALLBACK(Floor), NULL);
/* ����İ�ťʵ�ָ�λ����*/
g_signal_connect (G_OBJECT(button34), "clicked", G_CALLBACK(clear),NULL);
/* ����İ�ťʵ�ֽ�����*/
g_signal_connect (G_OBJECT(button5), "clicked", G_CALLBACK(output),NULL);
g_signal_connect (G_OBJECT(window),"delete_event" ,gtk_main_quit, NULL);
}



