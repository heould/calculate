#include <stdlib.h>
#include <gtk/gtk.h>
#include <math.h>
#include "myhead.h"
#include "show_Hex_window.c"
#include "show_Dec_window.c"
#include "show_Oct_window.c"
#include "show_Bin_window.c"
#include "Signal_Process.c"
#include "Conversion.c"

void on_clicked(GtkWidget *widget, gpointer data)
{

      if(GTK_TOGGLE_BUTTON(widget)->active)
	  {
		  if((char *)data=="Hex")
		  {
             show_Hex_window();
             principle=16;
		  }	 
		  if((char *)data=="Dec")
		  {
             show_Dec_window();
			 principle=10;
		  }
		  if((char *)data=="Oct")
		  {
             show_Oct_window();
			 principle=8;
		  }
		  if((char *)data=="Bin")
		  {
             show_Bin_window();
			 principle=2;
		  }
	  }   
}

int main (int argc, char *argv[])
{
a=0;
b=0;
hasdot=0;
gtk_set_locale(); 
gtk_rc_add_default_file("./gtkrc.zh_CN");   
gtk_init (&argc,&argv);      /* �������ڡ�*/
method=0;                    /*���㷽����*/
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), 
		g_locale_to_utf8("�ҵļ�����",-1,NULL,NULL,NULL));

vbox = gtk_vbox_new (FALSE, 0); /*����һ����ֱ��*/
gtk_container_add (GTK_CONTAINER (window), vbox);
gtk_widget_show (vbox);
table1 = gtk_table_new (2,4,FALSE);       /*����һ��2��4�еı��1*/
gtk_box_pack_start (GTK_BOX (vbox), table1, TRUE, FALSE, 0);
gtk_widget_show (table1);
table2= gtk_table_new (5,9,FALSE);       /*����һ��5��9�еı��*/
gtk_box_pack_start (GTK_BOX (vbox), table2, TRUE, FALSE, 0);
gtk_widget_show (table2);
entry = gtk_entry_new ( );                 /*���������������ı���*/
gtk_table_attach (GTK_TABLE (table1), entry, 0, 4, 0, 1,
            (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
            (GtkAttachOptions) (0),0,0);
gtk_widget_show (entry);

button1 = gtk_button_new_with_mnemonic("pi");       /*pi*/
gtk_table_attach (GTK_TABLE (table2), button1, 0, 1, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button1,40,30);
 
button2 = gtk_button_new_with_mnemonic("sin");        /*sin*/
gtk_table_attach (GTK_TABLE (table2), button2, 0, 1, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button3 = gtk_button_new_with_mnemonic("cos");        /*cos*/
gtk_table_attach (GTK_TABLE (table2), button3, 0, 1, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button4 = gtk_button_new_with_mnemonic("tan");        /*tan*/
gtk_table_attach (GTK_TABLE (table2), button4, 0, 1, 3, 4,
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
 
button5 = gtk_button_new_with_mnemonic("=");        /*===*/
gtk_widget_show (button5);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button5, 0, 3, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
 
button6 = gtk_button_new_with_mnemonic("Exp");      /*Exp*/
gtk_table_attach (GTK_TABLE (table2), button6, 1, 2, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button6,40,30);

button7 = gtk_button_new_with_mnemonic("x^y");        /*x^y*/
gtk_widget_show (button7);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button7, 1, 2, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
  
button8 = gtk_button_new_with_mnemonic("x^3");        /*x^3*/
gtk_widget_show (button8);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button8, 1, 2, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button9 = gtk_button_new_with_mnemonic("x^2");      /*x^2*/
gtk_widget_show (button9);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button9, 1, 2, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
  
button10 = gtk_button_new_with_mnemonic("ln");       /*ln*/
gtk_widget_show (button10);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button10, 2, 3, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button10,40,30);
    
button11 = gtk_button_new_with_mnemonic("log");       /*log*/
gtk_widget_show (button11);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button11, 2, 3, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
 
button12 = gtk_button_new_with_mnemonic("n!");        /*n!*/
gtk_widget_show (button12);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button12, 2, 3, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button13 = gtk_button_new_with_mnemonic("1/x ");        /*1/x*/
gtk_widget_show (button13);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button13, 2, 3, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button14 = gtk_button_new_with_label("7");        /*���ְ�ť7*/
gtk_table_attach (GTK_TABLE (table2), button14, 3, 4, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button14,40,30);

button15 = gtk_button_new_with_mnemonic("4");        /*���ְ�ť4*/
gtk_table_attach (GTK_TABLE (table2), button15, 3, 4, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
 
button16 = gtk_button_new_with_mnemonic("1");        /*���ְ�ť1*/
gtk_widget_show (button16);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button16, 3, 4, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button17 = gtk_button_new_with_mnemonic("0");        /*���ְ�ť0*/
gtk_widget_show (button17);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button17, 3, 4, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
  
button18 = gtk_button_new_with_mnemonic("A");        /*���ְ�ťA*/
gtk_table_attach (GTK_TABLE (table2), button18, 3, 4, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button19 = gtk_button_new_with_mnemonic("8");      /*���ְ�ť8*/
gtk_table_attach (GTK_TABLE (table2), button19, 4, 5, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button19,40,30);

button20 = gtk_button_new_with_mnemonic("5");       /*���ְ�ť5*/
gtk_table_attach (GTK_TABLE (table2), button20, 4, 5, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button21 = gtk_button_new_with_mnemonic("2");       /*���ְ�ť2*/
gtk_table_attach (GTK_TABLE (table2), button21, 4, 5, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button22 = gtk_button_new_with_mnemonic("+/-");     /*+/-*/
gtk_widget_show (button22);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button22, 4, 5, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button23 = gtk_button_new_with_mnemonic("B");       /*���ְ�ťB*/
gtk_table_attach (GTK_TABLE (table2), button23, 4, 5, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button24 = gtk_button_new_with_mnemonic("9");       /*���ְ�ť9*/
gtk_table_attach (GTK_TABLE (table2), button24, 5, 6, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button24,40,30);

button25 = gtk_button_new_with_mnemonic("6");       /*���ְ�ť6*/
gtk_table_attach (GTK_TABLE (table2), button25, 5, 6, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button26 = gtk_button_new_with_mnemonic("3");       /*���ְ�ť3*/
gtk_table_attach (GTK_TABLE (table2), button26, 5, 6, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button27 = gtk_button_new_with_mnemonic(".");     /*С����*/
gtk_widget_show (button27);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button27, 5, 6, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button28 = gtk_button_new_with_mnemonic("C");       /*���ְ�ťC*/
gtk_table_attach(GTK_TABLE (table2), button28, 5, 6, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button29 = gtk_button_new_with_mnemonic("/");       /*����*/
gtk_widget_show (button29);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button29, 6, 7, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button29,40,30);

button30 = gtk_button_new_with_mnemonic("*");      /*�˷�*/
gtk_widget_show (button30);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button30, 6, 7, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button31 = gtk_button_new_with_mnemonic("-");      /*����*/
gtk_widget_show (button31);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button31, 6, 7, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button32 = gtk_button_new_with_mnemonic("+");      /*�ӷ�*/
gtk_widget_show (button32);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button32, 6, 7, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button33 = gtk_button_new_with_mnemonic("D");   /*D*/
gtk_table_attach (GTK_TABLE(table2), button33, 6, 7, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button34 = gtk_button_new_with_mnemonic("CR");   /*CR*/
gtk_widget_show (button34);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button34, 7, 9, 0, 1, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);
gtk_widget_set_size_request (button34,80,30);

button35 = gtk_button_new_with_mnemonic("And");   /*And*/
gtk_widget_show (button35);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button35, 7, 8, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button36 = gtk_button_new_with_mnemonic("Or");   /*Or*/
gtk_widget_show (button36);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button36, 7, 8, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button37 = gtk_button_new_with_mnemonic("Mod");   /*Mod*/
gtk_widget_show (button37);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button37, 7, 8, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button38 = gtk_button_new_with_mnemonic("E");   /*E*/
gtk_table_attach (GTK_TABLE(table2), button38, 7, 8, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button39 = gtk_button_new_with_mnemonic("Not");    /*Not*/
gtk_widget_show (button39);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button39, 8, 9, 1, 2, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button40 = gtk_button_new_with_mnemonic("Xor");   /*Xor*/
gtk_widget_show (button40);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button40, 8, 9, 2, 3, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button41 = gtk_button_new_with_mnemonic("Int");   /*Int*/
gtk_widget_show (button41);/*����ʾ������*/
gtk_table_attach (GTK_TABLE (table2), button41, 8, 9, 3, 4, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

button42 = gtk_button_new_with_mnemonic("F");   /*F*/
gtk_table_attach (GTK_TABLE(table2), button42, 8, 9, 4, 5, 
            (GtkAttachOptions) (GTK_FILL),
            (GtkAttachOptions) (0), 0, 0);

/*�����Ǵ����ĸ���ѡ��ť������"ʮ����"��ť����ΪĬ��ѡ��*/
radio = gtk_radio_button_new_with_label (NULL,
      g_locale_to_utf8("ʮ������",-1,NULL,NULL,NULL));
g_signal_connect(GTK_OBJECT(radio),"clicked",
                G_CALLBACK(on_clicked),"Hex");
gtk_table_attach (GTK_TABLE (table1), radio, 0, 1, 1, 2,
            (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
            (GtkAttachOptions) (0),0,0);
gtk_widget_show (radio);
group = gtk_radio_button_group (GTK_RADIO_BUTTON(radio));
radio = gtk_radio_button_new_with_label (group,
      g_locale_to_utf8("ʮ����",-1,NULL,NULL,NULL));
g_signal_connect(GTK_OBJECT(radio),"clicked",
                G_CALLBACK(on_clicked),"Dec");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio),TRUE);/*ʮ����radio����ΪĬ��ѡ��״̬*/
gtk_table_attach (GTK_TABLE (table1), radio, 1, 2, 1, 2,
            (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
            (GtkAttachOptions) (0),0,0);
gtk_widget_show (radio);
group = gtk_radio_button_group (GTK_RADIO_BUTTON(radio));
radio = gtk_radio_button_new_with_label (group,
       g_locale_to_utf8("�˽���",-1,NULL,NULL,NULL));
g_signal_connect(GTK_OBJECT(radio),"clicked",
                G_CALLBACK(on_clicked),"Oct");
gtk_table_attach (GTK_TABLE (table1), radio, 2, 3, 1, 2,
            (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
            (GtkAttachOptions) (0),0,0);
gtk_widget_show (radio);
group = gtk_radio_button_group (GTK_RADIO_BUTTON(radio));
radio = gtk_radio_button_new_with_label (group,
      g_locale_to_utf8("������",-1,NULL,NULL,NULL));
g_signal_connect(GTK_OBJECT(radio),"clicked",
                G_CALLBACK(on_clicked),"Bin");
gtk_table_attach (GTK_TABLE (table1), radio, 3, 4, 1, 2,
            (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
            (GtkAttachOptions) (0),0,0);
gtk_widget_show (radio);
addsignal ();                 /*����¼���*/
gtk_widget_show (window);
gtk_main ();
return 0;
}
