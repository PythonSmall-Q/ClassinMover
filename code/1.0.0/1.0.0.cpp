#include <iostream>
#include <Windows.h>
#include <set>
#include <vector>
using namespace std;
struct window{
	HWND WindowHwnd;
	string title;
	string type;
	void put(string tl,string tp,HWND wh) {
		WindowHwnd=wh;
		title=tl;
		type=tp;
	}
	bool operator<(const window&a) {
		return title < a.title;
	}
	bool search(string s) {
		if(s.size()==0)return true;
		if(title.find(s)!=-1)return true;
		return false;
	}
}tmp;
vector<window>win;
set<string>ss;
string se;
BOOL CALLBACK EnumChildProc(_In_ HWND   hwnd, _In_ LPARAM lParam) {
	char szTitle[MAX_PATH] = {0};
	char szClass[MAX_PATH] = {0};
	int nMaxCount = MAX_PATH;
	LPSTR lpClassName = szClass;
	LPSTR lpWindowName = szTitle;
	GetWindowTextA(hwnd, lpWindowName, nMaxCount);
	GetClassNameA(hwnd, lpClassName, nMaxCount);
	string l=lpWindowName,r=lpClassName;
	if(ss.count(l))return TRUE;
	ss.insert(l);
	if(l.size()==0)return TRUE;
	tmp.put(l,r,hwnd);
	if(tmp.search(se))win.push_back(tmp);
	return TRUE;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	char szTitle[MAX_PATH] = {0};
	char szClass[MAX_PATH] = {0};
	int nMaxCount = MAX_PATH;
	LPSTR lpClassName = szClass;
	LPSTR lpWindowName = szTitle;
	GetWindowTextA(hwnd, lpWindowName, nMaxCount);
	GetClassNameA(hwnd, lpClassName, nMaxCount);
	string l=lpWindowName,r=lpClassName;
	if(ss.count(l))return TRUE;
	ss.insert(l);
	if(l.size()==0)return TRUE;
	tmp.put(l,r,hwnd);
	if(tmp.search(se))win.push_back(tmp);
	EnumChildWindows(hwnd, EnumChildProc, lParam);
	return TRUE;
}
int x,y;
void geti(){
	x=GetSystemMetrics(SM_CXSCREEN);
	y=GetSystemMetrics(SM_CYSCREEN);
}
bool search(string s) {
	geti();
	se=s;
	ss.clear();
	win.clear();
	EnumWindows(EnumWindowsProc, 0);
	HWND h;
	if(win.size()==1)h=win[0].WindowHwnd;
	else return 0;
	SetWindowPos(h,HWND_NOTOPMOST,0,0,x,y-50,SWP_NOSENDCHANGING);
	SetWindowPos(h,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	SetWindowLong(h,GWL_STYLE,GetWindowLong(h,GWL_STYLE) | WS_SIZEBOX | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_CAPTION);
	return 1;
}
int main() {
	cout<<"Classin Mover Verson 1.0.0";
	if(search("Classroom_"))
		cout<<"Succeed, wish you use this application again!";
	else
		cout<<"Error, please check if you have opened a classroom or you have opened more than one classroom";
	return 0;
}
