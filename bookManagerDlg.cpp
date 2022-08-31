
// bookManagerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "bookManager.h"
#include "bookManagerDlg.h"
#include "afxdialogex.h"

#include "CAddDlg.h"
#include "CMysqlController.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CbookManagerDlg 대화 상자



CbookManagerDlg::CbookManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOOKMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbookManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CbookManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONADD, &CbookManagerDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTONRENEW, &CbookManagerDlg::OnBnClickedButtonrenew)

	ON_BN_CLICKED(IDC_BUTTONDELETE, &CbookManagerDlg::OnBnClickedButtondelete)
END_MESSAGE_MAP()


// CbookManagerDlg 메시지 처리기

BOOL CbookManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_list.SetExtendedStyle(
		LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 40);
	m_list.InsertColumn(1, _T("책이름"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(2, _T("저자"), LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, _T("가격"), LVCFMT_CENTER, 100);
	m_list.InsertColumn(4, _T("기타"), LVCFMT_CENTER, 100);

	CFont font;
	LOGFONT logfont;
	::ZeroMemory(&logfont, sizeof(logfont));
	logfont.lfHeight = 22;
	font.CreateFontIndirect(&logfont);
	GetDlgItem(IDC_STATICTITLE)->SetFont(&font);;
	font.Detach();



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CbookManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CbookManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CbookManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbookManagerDlg::OnBnClickedButtonadd()
{
	CAddDlg child;
	child.SetParentPtr(this);
	
	child.DoModal();

}


void CbookManagerDlg::OnBnClickedButtonrenew()
{
	RenewListControl();
}

void CbookManagerDlg::RenewListControl()
{
	CMysqlController conn;
	//CString result;
	vector<Datarow*> row;

	m_list.DeleteAllItems();

	if (conn.SelectQuery("select * from TB_Book", row) == true)
	{

	}
	for (size_t i = 0; i < row.size(); i++)
	{
		m_list.InsertItem(i, row.at(i)->getID());
		m_list.SetItem(i, 1, LVIF_TEXT, row.at(i)->getBookname(), NULL, NULL, NULL, NULL);
		m_list.SetItem(i, 2, LVIF_TEXT, row.at(i)->getAuthor(), NULL, NULL, NULL, NULL);
		m_list.SetItem(i, 3, LVIF_TEXT, row.at(i)->getPrice(), NULL, NULL, NULL, NULL);
		m_list.SetItem(i, 4, LVIF_TEXT, row.at(i)->getOther(), NULL, NULL, NULL, NULL);

	}


	for (size_t i = 0; i < row.size(); i++)
	{
		delete row.at(i);
	}

}




void CbookManagerDlg::OnBnClickedButtondelete()
{

	UpdateData(true);

	int clickindex = m_list.GetSelectionMark();
	CMysqlController conn;
	CString temp;

	temp = _T("delete from TB_Book where id=");

	CString idNum = m_list.GetItemText(clickindex, 0);
	temp += idNum;

	if (conn.InsertQuery(LPSTR(LPCTSTR(temp))) == true)
	{
		AfxMessageBox(_T("성공"));

		RenewListControl();
	}
	else
	{
		AfxMessageBox(_T(" 실패"));
	}

	UpdateData(false);

}