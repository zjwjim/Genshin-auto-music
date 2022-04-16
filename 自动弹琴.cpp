#include <Windows.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	bool x=false;
    int time;
    char character;
    char file[1000];

	cout<<"请输入文件名：";
	cin>>file; 
    cout<<"请输入延时：";
    cin>>time;

    FILE *fp = fopen(file, "r");
    
//	倒计时5秒
	for(int k=5;k>=0;k--)  
	{
		cout<<k<<"秒后开始运行"<<endl;
		Sleep(1000);
		system("cls");
	}
	cout<<"运行中..."<<endl;

//	开始演奏 
	while(!feof(fp))
	{
		character=fgetc(fp);
		if(character=='('||character==')') 
		{
			x=!x;
		}
		else
		{
			keybd_event((BYTE)character, 0, 0, 0);
    		keybd_event((BYTE)character, 0, KEYEVENTF_KEYUP, 0);
		}
		if(x==false&&character!='\n'&&character!='/')
        {
        	Sleep(time);
		}	
	}
	system("cls"); 
	cout<<"结束！"<<endl;
	system("pause");
	return 0;
}

        
	

