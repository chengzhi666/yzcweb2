// FuncRevenueAccount.cpp : Defines the entry point for the console application.
//

//FuncRevenueAccount��һ���˵��Żݼ���ĺ������ǵ�6�µ�Ԫ���Ե�6.7�ڵ�Ԫ���Ի����е�һ��ʵ�� 
#include "stdio.h"
#include "math.h"

double FuncRevenueAccount( double amount )
{
	double rate = 1.0; // �����ۿ���
	if( amount <= 800 ) // ���˵�������800Ԫ�������ۿ�
		rate = 1.0;
	else if( amount > 800 && amount <= 1800 )
		rate = 0.9; // 9��
	else if( amount > 1800 && amount <= 4800 )
		rate = 0.8; // 8��
	else if( amount > 4800 )
		rate = 0.7; // 7��
	else if( amount <= 0 ){ // ���򣬸���һ����������ʾ��Ч
		return -1.0;
	}
	return amount * rate; // ���ؾ��Żݼ���֮����˵�
}

// ������������
void DriveroFuncRevenueAccount()
{
	printf( "���Ƕ�FuncRevenueAccount�Ĳ��ԣ��ú�����6.7�ڵ�Ԫ���Ի����е�һ������\n" );

	// --------1. ���þֲ�����---------
	int tcPassNum = 0;
	int tcFailNum = 0; // �洢ͨ����ʧ�ܵĲ�����������

	FILE* pFpFrom = NULL; // �����ļ���ָ�룬�洢���������Ļ�����Ϣ
	FILE* pFpTo = NULL; // ��¼��������ִ�н�����ļ���ָ��

	// --------2. �������ļ���׼����ȡ��������������-----------
	char* DataFileName = "TCData1.txt";
	pFpFrom = fopen( DataFileName, "r" );
	if( !pFpFrom ){
		printf( "��ȡ����ʧ�ܣ�����\n" );
		return;
	}

	// �������ļ���׼����¼��������ִ�н��
	char* DataFileTestResultName = "FuncRevenueAccountTestResult.txt";
	pFpTo = fopen( DataFileTestResultName, "w+t" );
	if( !pFpTo )
	{
		printf( "���ļ�ʧ�ܣ�����\n" );
		return;
	}
	fprintf( pFpTo, "----------�Ժ���FuncRevenueAccount�ĵ�Ԫ���Խ��-------------\n" );

	// -----------3. ִ�в�����������¼���Խ��-----------
	int TCID = 0;
	double originalAmount; // ��������������
	double expectedOutcome; // ����������Ԥ�����
	double actualOutcome; // ����������ʵ�����

	printf( "�Ժ���FuncRevenueAccountչ����Ԫ����\n" );
	while( !feof(pFpFrom) ){// ���϶�ȡÿ����������������
		fscanf( pFpFrom, "%d ", &TCID ); // �������������ID
		fscanf( pFpFrom, "%lf ", &originalAmount ); // �����������������
		fscanf( pFpFrom, "%lf ", &expectedOutcome );// �������������Ԥ�����

		actualOutcome = FuncRevenueAccount( originalAmount );// ִ�в�������
		// ���������������Ϣ
		printf( "��������%d: ����%lf, Ԥ�����%lf��ʵ�����%lf, ", TCID, originalAmount, expectedOutcome, actualOutcome );

		if( fabs(actualOutcome-expectedOutcome) < 1e-6 )// ����������ͨ�������¼ͨ������������
		{
			tcPassNum ++;
			printf( "ͨ��\n" );
			// ������������ִ�н���������ļ�
			fprintf( pFpTo, "��������%d: Pass\n", TCID );
		}
		else
		{
			tcFailNum ++;
			printf( "ʧ��\n" );
			// ������������ִ�н���������ļ�
			fprintf( pFpTo, "��������%d: Fail\n", TCID );
		}
	}
	fclose( pFpFrom );// �رղ������������ļ�

	// -----------4. ͳ�Ʋ��Խ��-----------
	printf( "��ִ��%d����������������%d��ͨ����%d��ʧ��\n", tcPassNum+tcFailNum, tcPassNum, tcFailNum );
	fprintf( pFpTo, "��ִ��%d����������������%d��ͨ����%d��ʧ��\n", tcPassNum+tcFailNum, tcPassNum, tcFailNum );

	fclose( pFpTo );// �رս����¼�ļ�
}


void main()
{
/*	double amountBefore = 0.0;
	printf( "�������˵����������������Ӧ�����㣩��\n" );
	scanf( "%lf", &amountBefore );
	printf( "������˵�ֵΪ%lf, ", amountBefore );
	double amountAfter = 0.0;
	amountAfter = FuncRevenueAccount( amountBefore );
	if( amountAfter <= 0 )
		printf( "\n�˵�����������Ч\n" );
	else
		printf( "�Żݼ������˵�ֵΪ%f\n", amountAfter );
*/
	DriveroFuncRevenueAccount();

}


/*
 * �������޸ĺ�ĺ���FuncRevenueAccount
*//*
double FuncRevenueAccount( double amount )
{
	double rate = 1.0; // �����ۿ���
	if( amount>0 && amount <= 800 ) // ���˵�������800Ԫ�������ۿ�
		rate = 1.0;
	else if( amount > 800 && amount <= 1800 )
		rate = 0.9; // 9��
	else if( amount > 2000 && amount <= 4800 )
		rate = 0.8; // 8��
	else if( amount > 4800 )
		rate = 0.7; // 7��
	else{ // ���򣬸���һ����������ʾ��Ч
		return -1000.0;
	}
	return amount * rate; // ���ؾ��Żݼ���֮����˵�
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/

