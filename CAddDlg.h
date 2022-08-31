#pragma once
#include "bookManagerDlg.h"


// CAddDlg 대화 상자

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAddDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_addName;
	CString m_addAuthor;
	CString m_addPrice;
	CString m_addOther;
	virtual BOOL OnInitDialog();
	void SetParentPtr(CbookManagerDlg* dlg);
	CbookManagerDlg* dlgPtr;
	afx_msg void OnBnClickedButton2();
};
