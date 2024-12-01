#include<iostream>
#include<windows.h>
#include<conio.h> 
using namespace std;
int choose=1,old=1,temp=0;

void gotoxy(short x, short y) {
  COORD coord = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hide_cursor()//隐藏光标
{
	HANDLE h_GAME =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=false;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}
void show_cursor()//显示光标
{
	HANDLE h_GAME =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=true;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}



int keyboard_listen()//读取键盘输入-函数 
{
	int ch;
    if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真，_kbhit()不会读入缓冲区的按键数据，按键数据会保留并交由getch()读取 
    
        ch = getch();//使用bioskey()函数获取按下的键值
//		printf("%d",ch);
        switch(ch){
        	
		    case 87  ://W 
			case 119  : 
		       choose--;
		       return 0;
		       break;
		       
		    case 68  ://D
		    case 100 : 
		       choose++;
		       return 0;
		       break;
		       
		    case 83  ://S
		    case 115  : 
		       choose++;
		       return 0;
		       break;
		       
		    case 65  ://A
		    case 97  : 
		       choose--;
		       return 0;
		       break;
		    
		    
//			case 27 ://ESC
//				stop=1;
//				return input_xy;
//				break;

			case 13 ://ENTER
				return 1;
				break;
				
			default:
				cout<<"ERROR,WRONG INPUT!\r";
				return 0;
				break;
				

		}
    }
    return 2;
}

int main()
{
	hide_cursor();
	SetConsoleOutputCP(CP_UTF8);  // 设置控制台输出为 UTF-8 编码
	cout<<"正在安装paramiko"<<endl;
	system("pip install paramiko");
	system("cls");
	while(1)
	{
		hide_cursor();
		cout<<endl;
		cout<<"        _       _  _     ____    ____             \n       | |     | || |   |  _ \\  |___ \\            \n       | |     | || |_  | | | |   __) |           \n       | |___  |__   _| | |_| |  / __/            \n       |_____|    |_|   |____/  |_____|           \n                                                  \n  ____    _____   ____   __     __  _____   ____  \n / ___|  | ____| |  _ \\  \\ \\   / / | ____| |  _ \\ \n \\___ \\  |  _|   | |_) |  \\ \\ / /  |  _|   | |_) |\n  ___) | | |___  |  _ <    \\ V /   | |___  |  _ < \n |____/  |_____| |_| \\_\\    \\_/    |_____| |_| \\_\\\n                                                  \n        _____    ___     ___    _                 \n       |_   _|  / _ \\   / _ \\  | |                \n         | |   | | | | | | | | | |                \n         | |   | |_| | | |_| | | |___             \n         |_|    \\___/   \\___/  |_____|            \n                                                  \n\n";
		cout<<"   1.开启服务器"<<endl;
		cout<<"   2.关闭服务器"<<endl;
		cout<<"   3.查看服务器screen实例状态"<<endl;
		cout<<"   4.从服务器下载start.sh到.\\start\\start.sh"<<endl;
		cout<<"   5.向服务器上传.\\start\\start.sh"<<endl;
		cout<<"   6.向服务器上传.\\maps中所有文件并安装到addons"<<endl;
		cout<<"   7.在本地安装mod（自用，如需使用请调整源代码重新编译）"<<endl;
		cout<<"   8.退出程序"<<endl;
		cout<<endl;
		cout<<endl;
		switch(choose)
		{
		    case 1  :
		       gotoxy(0,19);
		       cout<<"\033[32m";
			   cout<<">>>1.开启服务器<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的
		    case 2  :
		       gotoxy(0,20);
		       cout<<"\033[32m";
			   cout<<">>>2.关闭服务器<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的
			case 3  :
		       gotoxy(0,21);
		       cout<<"\033[32m";
			   cout<<">>>3.查看服务器screen实例状态<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的
		    case 4  :
		       gotoxy(0,22);
		       cout<<"\033[32m";
			   cout<<">>>4.从服务器下载start.sh到.\\start\\start.sh<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的
		    case 5  :
		       gotoxy(0,23);
		       cout<<"\033[32m";
			   cout<<">>>5.向服务器上传.\\start\\start.sh<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的
		    case 6  :
		       gotoxy(0,24);
		       cout<<"\033[32m";
			   cout<<">>>6.向服务器上传.\\maps中所有文件并安装到addons<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的   
		    case 7  :
		       gotoxy(0,25);
		       cout<<"\033[32m";
			   cout<<">>>7.在本地安装mod（自用，如需使用请调整源代码重新编译）<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的  
			case 8  :
		       gotoxy(0,26);
		       cout<<"\033[32m";
			   cout<<">>>8.退出程序<<<"<<endl;
			   cout<<"\033[m";
		       break; // 可选的  
		    // 您可以有任意数量的 case 语句
		    default : // 可选的
		       cout<<"无法匹配choose！";
		}
		gotoxy(0,28);
		temp=keyboard_listen();
		while(temp!=1)
		{
			temp=keyboard_listen();
			
			if(temp!=2)
			{
				if(choose<=0)
				{
					choose=1;
				}
				else if(choose>=9)
				{
					choose=8;
				}
				if(choose!=old)
				{
					gotoxy(0,19);
					cout<<"   1.开启服务器                "<<endl;
					cout<<"   2.关闭服务器               "<<endl;
					cout<<"   3.查看服务器screen实例状态                                 "<<endl;
					cout<<"   4.从服务器下载start.sh到.\\start\\start.sh              "<<endl;
					cout<<"   5.向服务器上传.\\start\\start.sh           "<<endl;
					cout<<"   6.向服务器上传.\\maps中所有文件并安装到addons              "<<endl;
					cout<<"   7.在本地安装mod（自用，如需使用请调整源代码重新编译）                   "<<endl;
					cout<<"   8.退出程序             "<<endl;
					cout<<endl;
					cout<<endl;
					old=choose;
				}
				
				switch(choose)
				{
				    case 1  :
				       gotoxy(0,19);
				       cout<<"\033[32m";
					   cout<<">>>1.开启服务器<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的
				    case 2  :
				       gotoxy(0,20);
				       cout<<"\033[32m";
					   cout<<">>>2.关闭服务器<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的
					case 3  :
				       gotoxy(0,21);
				       cout<<"\033[32m";
					   cout<<">>>3.查看服务器screen实例状态<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的
				    case 4  :
				       gotoxy(0,22);
				       cout<<"\033[32m";
					   cout<<">>>4.从服务器下载start.sh到.\\start\\start.sh<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的
				    case 5  :
				       gotoxy(0,23);
				       cout<<"\033[32m";
					   cout<<">>>5.向服务器上传.\\start\\start.sh<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的
				    case 6  :
				       gotoxy(0,24);
				       cout<<"\033[32m";
					   cout<<">>>6.向服务器上传.\\maps中所有文件并安装到addons<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的   
				    case 7  :
				       gotoxy(0,25);
				       cout<<"\033[32m";
					   cout<<">>>7.在本地安装mod（自用，如需使用请调整源代码重新编译）<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的  
					case 8  :
				       gotoxy(0,26);
				       cout<<"\033[32m";
					   cout<<">>>8.退出程序<<<"<<endl;
					   cout<<"\033[m";
				       break; // 可选的  
				    // 您可以有任意数量的 case 语句
				    default : // 可选的
				       cout<<"无法匹配choose！";
				}
				gotoxy(0,28);
			}
			
		}
		
		system("cls");
		show_cursor();
		switch(choose)
		{
		    case 1  :
		       system("cd server&python server_startup.py");
		       break; // 可选的
		    case 2  :
		       system("cd server&python server_shutdown.py");
		       break; // 可选的
			case 3  :
		       system("cd server&python server_status.py");
		       break; // 可选的
		    case 4  :
		       system("cd server&python download_start_sh.py");
		       break; // 可选的
		    case 5  :
		       system("cd server&python upload_start_sh.py");
		       break; // 可选的
		    case 6  :
		       system("cd server&python remote_install_mods.py");
		       break; // 可选的   
		    case 7  :
		       system("cd server&python local_install_mods.py");
		       break; // 可选的  
			case 8  :
		       return 0;
		       break; // 可选的  
		    // 您可以有任意数量的 case 语句
		    default : // 可选的
		       cout<<"无法匹配choose！";
		}
		cout<<"命令执行完毕";
		getch();
		system("cls");
	}
}

