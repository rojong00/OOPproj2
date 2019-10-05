#include "inf_int.h"

// 
// to be filled by students
//
// example :
//
 bool operator==(const inf_int& a , const inf_int& b)
 {
     // we assume 0 is always positive.
     if ( (strcmp(a.digits , b.digits)==0) && a.thesign==b.thesign )
         return true;
     return false;
 }

 inf_int operator+(const inf_int& a, const inf_int& b)
 {
	 // ���� a�� b�� thesign�� ���ٸ� ��ȣ�� �����ϰ�, Adder ȣ��
	 // a�� b�� thesign�� �ٸ��ٸ� ��ȣ�� �����ϰ�, Subtractor ȣ��
 }

 inf_int operator-(const inf_int& a, const inf_int& b)
 {
	 // a �� b�� thesign�� ���ٸ� ��ȣ�� �����ϰ�, Subtractor ȣ��
	 // a �� b�� thesign�� �ٸ��ٸ� ��ȣ�� �����ϰ�, Adder ȣ��
 }

 void Adder(const inf_int& a, const inf_int& b)
 {
	 // a �� b���� ������ ũ�ٰ� ����(���� ���Լ� �����Ǹ� ���� ����)
	 // a �� ���̰� n�̶�� n+1�� ���߾� �� �迭 c ����, 0���� �ʱ�ȭ (initializer ������ ���� ����)
	 // c�� a �� b�� ���ذ��� ����
	 // �ջ�� �迭�� index 0���� �����ؼ� 10���� ū�� ó��
	 // �ᱣ��, ��ȣ, ���� ó���ؼ� ��ȯ
 }

 void Subtractor(const inf_int& a, const inf_int& b)
 {
	 //a �� b���� ������ ũ�ٰ� ����(���� ���Լ� �����Ǹ� ���� ����)
	 // a �� ���̰� n�̶�� n�� ���߾� �� �迭 c ����, 0���� �ʱ�ȭ
	 // c�� a�� b�� ������ ����
	 // ����� �迭�� index 0���� �����Ͽ� 0���� ������ ó��
	 // �ᱣ��, ��ȣ, ���� ó���Ͽ� ��ȯ
 }