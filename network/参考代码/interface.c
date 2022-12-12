#include <stdio.h>
#include <gtk/gtk.h>
#include "forward.h"
#include "readPcap.h"
#include "readRoute.h"

static GtkWidget *pcapFile;
static GtkWidget *routeFile;
GtkWidget *file;

char fileRoute[1024];
char filePcap[1024];

char * copyStr(char *dest, const gchar *src)
{
	if(src == NULL){
		return NULL;	
	}
	char *strDest = dest;
	while((*dest++ = *src++) != '\0');
	return strDest;
}

//点击不同的按钮触发不同的效果
void on_button_clicked(GtkWidget *button,gpointer data)
{
	if((int)data == 1){
		gtk_entry_set_text(GTK_ENTRY(pcapFile),"");  
        	gtk_entry_set_text(GTK_ENTRY(routeFile),"");  
	} else if ((int)data == 2){
		const gchar *pcapName = gtk_entry_get_text(GTK_ENTRY(pcapFile));
		const gchar *routeName = gtk_entry_get_text(GTK_ENTRY(routeFile));
		g_print("读数据:%s\n",pcapName);
		g_print("file-name:%s\n",pcapName);
		g_print("route-file-name:%s\n",routeName);

		g_print("拷贝字符串\n");
		copyStr(fileRoute, routeName);
		copyStr(filePcap, pcapName);

	
		printf("fileRoute:%s,filePcap:%s\n",fileRoute,filePcap);	

		read_Route(fileRoute);
		read_pcap(filePcap);
	}
}

void file_OK(GtkWidget *w, gpointer *data)
{
	gtk_entry_set_text(GTK_ENTRY(data), gtk_file_selection_get_filename(GTK_FILE_SELECTION(file)));
	
	gtk_widget_destroy(file);
}

//查找文件
void select_file(GtkWidget *w, gpointer *data)
{
	file = gtk_file_selection_new("File selection");
	
	g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(file) -> ok_button), "clicked", G_CALLBACK(file_OK), data);
	g_signal_connect_swapped(G_OBJECT(GTK_FILE_SELECTION(file) -> cancel_button), "clicked", G_CALLBACK(gtk_widget_destroy), NULL);
	
	gtk_widget_show(file);	
}

int main(int argc, char *argv[])
{
	GtkWidget *window;

	GtkWidget *table;

	GtkWidget *label;
	
	GtkWidget *button;

	GtkWidget *sep;
	

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    	g_signal_connect(GTK_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window),"模拟IPv4转发软件");
    	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

	table = gtk_table_new(4,8,TRUE);
	gtk_container_add(GTK_CONTAINER(window),table);
	
	//
	label = gtk_label_new("选择文件，完成分组转发");
	gtk_table_attach_defaults(GTK_TABLE(table),label,3,5,0,1);
	
	//pcap文件路径选择
	label = gtk_label_new("pcap文件路径:");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,2,1,2);
	
	pcapFile = gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table),pcapFile,2,6,1,2);
	button = gtk_button_new_with_label("选择文件");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(select_file),pcapFile);
	gtk_table_attach_defaults(GTK_TABLE(table),button,6,7,1,2);

	/**********  存储路由表的文件路径选择*******/
	label = gtk_label_new("路由表文件路径:");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,2,2,3);
	
	routeFile = gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table),routeFile,2,6,2,3);
	button = gtk_button_new_with_label("选择文件");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(select_file),routeFile);
	gtk_table_attach_defaults(GTK_TABLE(table),button,6,7,2,3);

	button = gtk_button_new_with_label("清空");  
    	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),(gpointer)1);  
    	gtk_table_attach_defaults(GTK_TABLE(table),button,1,3,3,4);  
    	gtk_widget_show(button);  
  
    	button = gtk_button_new_with_label("确认");  
    	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),(gpointer)2);  
    	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window);  
    	gtk_table_attach_defaults(GTK_TABLE(table),button,5,7,3,4);  
    	gtk_widget_show(button);  

	
/*
	box = gtk_vbox_new(FALSE,0);  
   	gtk_container_add(GTK_CONTAINER(window),box);  
    	box1 = gtk_hbox_new(FALSE,0);  
    	gtk_box_pack_start(GTK_BOX(box),box1,FALSE,FALSE,5);  
    	box2 = gtk_hbox_new(FALSE,0);  
    	gtk_box_pack_start(GTK_BOX(box),box2,FALSE,FALSE,5);  
    	sep = gtk_hseparator_new();//分割线  
    	gtk_box_pack_start(GTK_BOX(box),sep,FALSE,FALSE,5);  
    	box3 = gtk_hbox_new(FALSE,0);  
    	gtk_box_pack_start(GTK_BOX(box),box3,TRUE,TRUE,5);

	label1 = gtk_label_new("pcap文件路径：");  
    	pcapFile = gtk_entry_new();  
    	gtk_box_pack_start(GTK_BOX(box1),label1,FALSE,FALSE,5);  
    	gtk_box_pack_start(GTK_BOX(box1),pcapFile,FALSE,FALSE,5);  
  
    	label2 = gtk_label_new("路由表文件：");  
    	routeFile = gtk_entry_new();  
    	gtk_box_pack_start(GTK_BOX(box2),label2,FALSE,FALSE,5);  
    	gtk_box_pack_start(GTK_BOX(box2),routeFile,FALSE,FALSE,5); 

	button = gtk_button_new_with_label("清空");  
    	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),(gpointer)1);  
    	gtk_box_pack_start(GTK_BOX(box3),button,TRUE,TRUE,10);  
    	gtk_widget_show(button);  
  
    	button = gtk_button_new_with_label("确认");  
    	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),(gpointer)2);  
    	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window);  
    	gtk_box_pack_start(GTK_BOX(box3),button,TRUE,TRUE,5);  
    	gtk_widget_show(button); 
*/

	gtk_widget_show_all(window);  
   	gtk_main();  
    	return FALSE; 
}
