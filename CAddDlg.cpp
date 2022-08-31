// CAddDlg.cpp: 구현 파일
//

#include "pch.h"
#include "bookManager.h"
#include "CAddDlg.h"
#include "afxdialogex.h"
#include "CMysqlController.h"


// CAddDlg 대화 상자

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDDLG, pParent)
	, m_addName(_T(""))
	, m_addAuthor(_T(""))
	, m_addPrice(_T(""))
	, m_addOther(_T(""))
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_addName);
	DDX_Text(pDX, IDC_EDIT2, m_addAuthor);
	DDX_Text(pDX, IDC_EDIT3, m_addPrice);
	DDX_Text(pDX, IDC_EDIT4, m_addOther);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAddDlg 메시지 처리기


BOOL CAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CAddDlg::SetParentPtr(CbookManagerDlg* dlg)
{	
	this->dlgPtr = dlg;
}

void CAddDlg::OnBnClickedButton2()
{
	UpdateData(true);

	CMysqlController conn;
	CString temp;

	temp = _T("insert into TB_Book(bookname, author, price, other) VALUES('");
	temp += m_addName;
	temp += _T("', '");
	temp += m_addAuthor;
	temp += _T("', ");
	temp += m_addPrice;
	
	if(m_addOther == _T(""))
	{
		temp += _T(", NULL");
	}else
	{
		temp += _T(", '");
		temp += m_addOther;
		temp += _T("'");
	}
	temp += _T(")");
	
	if (conn.InsertQuery(LPSTR(LPCTSTR(temp))) == true)
	{
		AfxMessageBox(_T("성공"));
	}
	else
	{
		AfxMessageBox(_T(" 실패"));
	}
	
	dlgPtr->RenewListControl();
	EndDialog(IDCANCEL);
}
