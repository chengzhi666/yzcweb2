package com.ch.test;

import java.util.Scanner;

public class FuncRevenue {
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
			return -1000.0;
		}
		return amount * rate; // ���ؾ��Żݼ���֮����˵�
	}
	
	public static void main(String[] args) {
		FuncRevenue f =new FuncRevenue();
		 Scanner scan = new Scanner(System.in);
		double amountBefore = 0.0;
		System.out.println( "�������˵����������������Ӧ�����㣩��" );
		 amountBefore=scan.nextDouble();  
		System.out.println( "������˵�ֵΪ:"+amountBefore );
		double amountAfter = 0.0;
		amountAfter = f.FuncRevenueAccount( amountBefore );
		if( amountAfter <= 0 )
			System.out.println( "�˵�����������Ч" );
		else
			System.out.println( "�Żݼ������˵�ֵΪ"+amountAfter );
	}
}
