
// mfc 19.03.29 v2 ipaddrDlg.cpp: 实现文件
//

// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif



#include "mfc 19.03.29 v2 ipaddr.h"
#include "mfc 19.03.29 v2 ipaddrDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cmfc190329v2ipaddrDlg 对话框



Cmfc190329v2ipaddrDlg::Cmfc190329v2ipaddrDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC190329V2IPADDR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc190329v2ipaddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cmfc190329v2ipaddrDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cmfc190329v2ipaddrDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Cmfc190329v2ipaddrDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfc190329v2ipaddrDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfc190329v2ipaddrDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfc190329v2ipaddrDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cmfc190329v2ipaddrDlg 消息处理程序

BOOL Cmfc190329v2ipaddrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cmfc190329v2ipaddrDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cmfc190329v2ipaddrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}



	CString str = (L"D:\\ipindex");
	if (!PathIsDirectory(str))
	{
		::CreateDirectory(str, NULL);//创建目录,已有的话不影响
	}
	


	CFile file1;

	TCHAR* pFileName = _T("D:\\ipindex\\index.txt");

	if (!file1.Open(pFileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
	{
		MessageBox(_T("欢迎使用!"));

		return;
	}
	DWORD len = file1.GetLength();
	len = len / 2;
	TCHAR *pContent = new TCHAR[len + 1];

	//file.Seek(0,CFile::begin);
	file1.Read(pContent, len * 2);
	pContent[len] = '\0';    // 如果文件后方还有其他字符，需要添加结束字符'\0'
	// CString str=pContent;
	//MessageBox(pContent);
	CString _name;
	_name.Format(_T("%s"), pContent);
	if (_name.IsEmpty())
	{
		MessageBox(L"记得选择网卡");
	}
	else
	{
		while (!(_name.IsEmpty()))
		{
			CString _top = _name.Left(_name.Find('\n'));
			_name = _name.Mid(_name.Find('\n') + 1);
			((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_top);
		}
	}
	file1.Close();



	


}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cmfc190329v2ipaddrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmfc190329v2ipaddrDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码



	

}


void Cmfc190329v2ipaddrDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cmfc190329v2ipaddrDlg::OnBnClickedButton1()   //保存
{
	// TODO: 在此添加控件通知处理程序代码
	//获取
	CString ipaddr = NULL;
	CString mask = NULL;
	CString gate = NULL;
	CString dns = NULL;
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(ipaddr);
	GetDlgItem(IDC_IPADDRESS2)->GetWindowText(mask);
	GetDlgItem(IDC_IPADDRESS3)->GetWindowText(gate);
	GetDlgItem(IDC_IPADDRESS4)->GetWindowText(dns);
	ipaddr.Append(L"\n");
	mask.Append(L"\n");
	gate.Append(L"\n");
	dns.Append(L"\n");

	//方案文件名
	CString name1(_T("D:\\ipindex\\"));
	CString name2 ;
	GetDlgItem(IDC_COMBO1)->GetWindowText(name2);
	name1.Append(name2);
	name1.Append(_T(".txt"));
	CString _n(L"\n");
	

	CFile life; 
	CString strline; 
	BOOL flag = life.Open(L"D:\\ipindex\\index.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);   //判断索引文件是否存在
	if (flag == FALSE) 
	{
		
		

		CFile setlife;
		setlife.Open(L"D:\\ipindex\\index.txt", CFile::modeCreate | CFile::modeWrite);    //创建索引文件
		setlife.Write(name2.GetBuffer(), name2.GetLength() * sizeof(TCHAR));    //保存方案名至索引文件
		setlife.Write(_n.GetBuffer(), _n.GetLength() * sizeof(TCHAR));
		setlife.Flush();
		setlife.Close();

		CFile file;
		file.Open(name1, CFile::modeCreate | CFile::modeWrite);               //创建方案文件
		//file.Write(str.GetBuffer(), str.GetLength() * sizeof(TCHAR));//str为CString类型   
		file.Write(ipaddr.GetBuffer(), ipaddr.GetLength() * sizeof(TCHAR));    //保存方案信息
		file.Write(mask.GetBuffer(), mask.GetLength() * sizeof(TCHAR));
		file.Write(gate.GetBuffer(), gate.GetLength() * sizeof(TCHAR));
		file.Write(dns.GetBuffer(), dns.GetLength() * sizeof(TCHAR));
		file.Flush();
		file.Close();

		MessageBox(L"方案创建保存成功！");
		
	} 
	else
	{

		
		//life.Open(L"D:\\ipindex\\index.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		life.SeekToEnd();
		life.Write(name2.GetBuffer(), name2.GetLength() * sizeof(TCHAR));    //保存方案名至索引文件
		life.Write(_n.GetBuffer(), _n.GetLength() * sizeof(TCHAR));
		life.Flush();
		life.Close();

		CFile file;
		file.Open(name1, CFile::modeCreate | CFile::modeWrite);               //创建方案文件
		//file.Write(str.GetBuffer(), str.GetLength() * sizeof(TCHAR));//str为CString类型   
		file.Write(ipaddr.GetBuffer(), ipaddr.GetLength() * sizeof(TCHAR));    //保存方案信息
		file.Write(mask.GetBuffer(), mask.GetLength() * sizeof(TCHAR));
		file.Write(gate.GetBuffer(), gate.GetLength() * sizeof(TCHAR));
		file.Write(dns.GetBuffer(), dns.GetLength() * sizeof(TCHAR));
		file.Flush();
		file.Close();

		MessageBox(L"保存方案成功！");
	}
	UpdateData(TRUE); 
	
	
}


void Cmfc190329v2ipaddrDlg::OnBnClickedButton2()    //修改ip
{
	// TODO: 在此添加控件通知处理程序代码
	CString ipaddr = NULL;
	CString mask = NULL;
	CString gate = NULL;
	CString dns = NULL;
	CString _net = NULL;
	CString _typeip("\" static ");
	CString _typedns("\" source=static addr=");
	CString _space(" ");
	CString _cmdip("/c netsh interface ip set address \"");
	CString _cmddns("/c netsh interface ip set dns \"");


	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(ipaddr);
	GetDlgItem(IDC_IPADDRESS2)->GetWindowText(mask);
	GetDlgItem(IDC_IPADDRESS3)->GetWindowText(gate);
	GetDlgItem(IDC_IPADDRESS4)->GetWindowText(dns);
	GetDlgItem(IDC_COMBO2)->GetWindowText(_net);

	if (dns=="0.0.0.0")  //check dns
	{
		dns = gate;
	}

	//set ip
	_cmdip.Append(_net);
	_cmdip.Append(_typeip);
	_cmdip.Append(_space);
	_cmdip.Append(ipaddr);
	_cmdip.Append(_space);
	_cmdip.Append(mask);
	_cmdip.Append(_space);
	_cmdip.Append(gate);


	//set dns
	_cmddns.Append(_net);
	_cmddns.Append(_typedns);
	_cmddns.Append(dns);



	SHELLEXECUTEINFO shelldns;
	memset(&shelldns, 0, sizeof(shelldns));
	shelldns.cbSize = sizeof(shelldns);
	shelldns.hwnd = NULL;
	shelldns.lpVerb = _T("runas");
	shelldns.lpFile = _T("C:\\\\Windows\\\\System32\\\\cmd.exe"); // 修改dns
	shelldns.lpParameters = (_cmddns);
	shelldns.nShow = SW_HIDE;
	shelldns.fMask = SEE_MASK_NOCLOSEPROCESS;
	BOOL setdns = ShellExecuteEx(&shelldns);
	


	SHELLEXECUTEINFO shellip;      
	memset(&shellip, 0, sizeof(shellip));
	shellip.cbSize = sizeof(shellip);
	shellip.hwnd = NULL;
	shellip.lpVerb = _T("runas");
	shellip.lpFile = _T("C:\\\\Windows\\\\System32\\\\cmd.exe"); // 修改ip
	shellip.lpParameters = (_cmdip);
	shellip.nShow = SW_HIDE;
	shellip.fMask = SEE_MASK_NOCLOSEPROCESS;
	BOOL setip = ShellExecuteEx(&shellip);
	



}


void Cmfc190329v2ipaddrDlg::OnBnClickedButton3()
{



	















	// TODO: 在此添加控件通知处理程序代码



	CString ipaddr = NULL;
	CString mask = NULL;
	CString gate = NULL;
	CString dns = NULL;
	CString text = NULL;
	GetDlgItem(IDC_COMBO1)->GetWindowText(text);
	//if (text.Find('\n'))
	//{
	//	text = text.Left(text.Find('\n'));
	//}
	
	CString path(_T("D:\\ipindex\\"));
	path.Append(text);
	path.Append(_T(".txt"));

	CIPAddressCtrl m_ip;

	DWORD m_dwPos = 0;
	CString strline;//定义一个变量用于接收读取的一行内容 
	CStdioFile file;//定义一个CStdioFile类的对象 file 


	CFile file1;




	if (!file1.Open(path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
	{
		MessageBox(_T("打开方案失败!"));
	}
	DWORD len = file1.GetLength();
	len = len / 2;
	TCHAR *pContent = new TCHAR[len+1];

	//file.Seek(0,CFile::begin);
	file1.Read(pContent,len*2);
	pContent[len] = '\0';    // 如果文件后方还有其他字符，需要添加结束字符'\0'
	// CString str=pContent;
	//MessageBox(pContent);

	CString allip;
	allip.Format(_T("%s"), pContent);

	CString newip = allip.Left(allip.Find('\n'));
	CString noip = allip.Mid(allip.Find('\n')+1);
	CString newmask = noip.Left(noip.Find('\n'));
	CString nomask = noip.Mid(noip.Find('\n')+1);
	CString newgate = nomask.Left(nomask.Find('\n'));
	CString nogate = nomask.Mid(nomask.Find('\n') + 1);
	CString newdns = nogate.Left(nogate.Find('\n'));



	SetDlgItemText(IDC_IPADDRESS1, newip);
	SetDlgItemText(IDC_IPADDRESS2, newmask);
	SetDlgItemText(IDC_IPADDRESS3, newgate);
	SetDlgItemText(IDC_IPADDRESS4, newdns);


	//m_ip.SetWindowText(pContent);

	file1.Close();






	//BOOL flag = file.Open(path, CFile::modeRead);//open函数需要传两个参数，前一个是文件路径，后一个是文件的打开模式 

	//if (flag == TRUE)
	//{
	//	file.Seek(m_dwPos, CFile::begin);
	//	if (file.ReadString(strline) != FALSE)
	//	{
	//		m_dwPos = file.GetPosition();//获取当前文件指针    记录读到哪一行

	//		m_ip.SetWindowText(strline);
	//		//UpdateData(FALSE);
	//	}
	//	file.Close();
	//}
}
