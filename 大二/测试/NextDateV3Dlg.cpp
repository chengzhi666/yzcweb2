// NextDateV3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "NextDateV3.h"
#include "NextDateV3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNextDateV3Dlg dialog

CNextDateV3Dlg::CNextDateV3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNextDateV3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNextDateV3Dlg)
	m_nYear = 0;
	m_nMonth = 0;
	m_nDay = 0;
	m_strTomorrow = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNextDateV3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNextDateV3Dlg)
	DDX_Control(pDX, IDC_EDIT7, m_ctrlTomorrow);
	DDX_Control(pDX, IDC_EDIT3, m_ctrlDay);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlMonth);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlYear);
	DDX_Text(pDX, IDC_EDIT1, m_nYear);
	DDV_MinMaxInt(pDX, m_nYear, 1800, 2050);
	DDX_Text(pDX, IDC_EDIT2, m_nMonth);
	DDV_MinMaxInt(pDX, m_nMonth, 1, 12);
	DDX_Text(pDX, IDC_EDIT3, m_nDay);
	DDV_MinMaxInt(pDX, m_nDay, 1, 31);
	DDX_Text(pDX, IDC_EDIT7, m_strTomorrow);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNextDateV3Dlg, CDialog)
	//{{AFX_MSG_MAP(CNextDateV3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_COMPUTE, OnBtnCompute)
	ON_BN_CLICKED(IDC_BTN_CLEAR, OnBtnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNextDateV3Dlg message handlers

BOOL CNextDateV3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// ��֤��ʼ��ʾ��ʱ�����κ�����
	m_ctrlYear.SetWindowText( "" );
	m_ctrlMonth.SetWindowText( "" );
	m_ctrlDay.SetWindowText( "" );
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNextDateV3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNextDateV3Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNextDateV3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// Judge whether the given year is a leap year
bool isLeapYear( const int& year )
{
	bool isLeap = false;
	if( (year%4==0 && year%100!=0) || year%400==0 )
		isLeap = true;
	return isLeap;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//
//         ������NextDate�ĵ��������ӣ��Ǽ��ɰ汾��
//
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
typedef struct MyDate{
	int month;
	int day;
	int year;
}MyDATE;
int lastDayOfMonth( const int& year, const int& month );
bool GetDate( const int& year, const int& month, const int& day, MyDate& date );
bool ValidDate( const MyDate& date );
MyDate IncrementDate( const MyDate& date );
CString PrintDate( const MyDate& date );

void NextDate3( const int& year, const int& month, const int& day, CString& strTomorrow )
{
	MyDate today, tomorrow;

	if( !GetDate( year, month, day, today ) )// ��ȡ��������ڣ���������Ч�Լ���
		return;

	tomorrow = IncrementDate( today );
	// ���ǵ�2012-12-31��next date�����ޣ���˶Լ����Ľ�������ٴμ���
	if( ValidDate( tomorrow ) )
		strTomorrow = PrintDate( tomorrow );
	else
		strTomorrow = "Reach the last day of the year 2012.\n";
}

// �ú�������ָ��ָ����ݺ�ָ���·ݵ���ĩ����
int lastDayOfMonth( const int& year, const int& month )
{
	int nLastDayOfMonth;
	if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 )
		nLastDayOfMonth = 31;// ��ÿ����31�죬����ĩ����Ϊ31
	else if( month == 2 )// ��Ϊ2��
	{
		if( isLeapYear( year ) )
			nLastDayOfMonth = 29;// ��Ϊ���꣬����ĩ����Ϊ29��
		else
			nLastDayOfMonth = 28;// ��Ϊ��ͨ��ݣ�����ĩ����Ϊ28��
	}
	else
		nLastDayOfMonth = 30;// ��ÿ����30�죬����ĩ����Ϊ30��
	return nLastDayOfMonth;
}

// �ú������ڻ�ȡָ�����ڣ����жϸ������Ƿ���Ч
bool GetDate( const int& year, const int& month, const int& day, MyDate& aDate )
{
	aDate.year = year;// �����봫��aDate
	aDate.month = month;
	aDate.day = day;
	if( !ValidDate( aDate ) )// ������Ч���ڣ���Ҫ����������
		return false;
	else
		return true;
}

// �����ڽ�����Ч��У��
bool ValidDate( const MyDate& aDate )
{
	bool bMonthOK = false;
	if( aDate.month>0 && aDate.month<=12 )// ���·���[1,12]֮�䣬���·���Ч
		bMonthOK = true;

	bool bDayOK = false; 
	if( bMonthOK )// ���·���Чʱ����������1����ĩ����֮�䣨����ĩ���ڣ�����������Ч
	{
		if( aDate.day>0 && aDate.day<=lastDayOfMonth( aDate.year, aDate.month ) ) 
			bDayOK = true;
	}

	bool bYearOK = false;
	if( aDate.year>=1800 && aDate.year<=2050 )// �������[1800,2050]֮��ʱ�������Ч
		bYearOK = true;

	bool bValid = false;
	if( bMonthOK && bDayOK && bYearOK )// ��ݡ��·ݺ����ھ���Ч����������Ч
		bValid = true;
//	else// �������������ʾ
//		AfxMessageBox( "Possible invalid input of MM DD YYYY.\n" );
	return bValid;
}

// �����һ�������
MyDate IncrementDate( const MyDate& date )
{
	MyDate tomorrow;
	tomorrow.month = date.month;// initialization
	tomorrow.day = date.day;
	tomorrow.year = date.year;

	if( date.day<lastDayOfMonth( date.year, date.month ) )
		tomorrow.day = date.day + 1;// ��������ĩ���ڣ������ڼ�1
	else// ������ĩ������
	{
		tomorrow.day = 1;
		if( date.month == 12 )
		{// ����12�£�����������ĩ���ڣ���Ҫ�����ں��·ݸ�λ����ݼ�1
			tomorrow.month = 1;
			tomorrow.year = date.year + 1;
		}
		else// ������ĩ���ڣ���������ĩ���ڣ���������Ҫ��λ���·ݼ�1
			tomorrow.month = date.month + 1;
	}
	return tomorrow;
}
// ��ӡ����
CString PrintDate( const MyDate& aDate )
{
	CString str = "";
	str.Format( "Day is:%d-%d-%d\n", aDate.year, aDate.month, aDate.day );
	return str;
}

// ���ݽ�������ڼ�����������ڲ����������
void CNextDateV3Dlg::OnBtnCompute() 
{
	UpdateData();// ��������

	// ������һ������ڣ�����������༭��
	NextDate3( m_nYear, m_nMonth, m_nDay, m_strTomorrow );
	m_ctrlTomorrow.SetWindowText( m_strTomorrow );	
	
}

// ��������������
void CNextDateV3Dlg::OnBtnClear() 
{
	m_nYear = 0;
	m_nMonth = 0;
	m_nDay = 0;
	m_ctrlYear.SetWindowText( "" );
	m_ctrlMonth.SetWindowText( "" );
	m_ctrlDay.SetWindowText( "" ); 
	m_strTomorrow = "";
	m_ctrlTomorrow.SetWindowText( m_strTomorrow );
	
}
