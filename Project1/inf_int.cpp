#include "inf_int.h"

// 
// to be filled by students
//
// example :
//

inf_int::inf_int() // �ϴ� �ʿ��ؼ� �����پ�, ���� �����Ϸ�� ������
{
	this->length = 1;
	this->thesign = true;
}

 inf_int operator+(const inf_int& a, const inf_int& b)
 {
	 // inf int c ����d
	 inf_int c;
	 // ���� a�� b�� thesign�� ���ٸ� ��ȣ�� �����ϰ�, c.Adder ȣ��
	 c.Adder(a, b);
	 // a�� b�� thesign�� �ٸ��ٸ� ��ȣ�� �����ϰ�, Subtractor ȣ��

	 return c;
 }

 inf_int operator-(const inf_int& a, const inf_int& b)
 {
	 // inf int c ����
	 inf_int c;
	 // a �� b�� thesign�� ���ٸ� ��ȣ�� �����ϰ�, c.Subtractor ȣ��
	 // a �� b�� thesign�� �ٸ��ٸ� ��ȣ�� �����ϰ�, Adder ȣ��

	 return c;
 }

 void inf_int::Adder(const inf_int& a, const inf_int& b)
 {
	 // a�� b���� ������ ũ�ٰ� ����(���� ���Լ� �����Ǹ� ���� ����)
	 // c�� a�� b�� ���ذ��� ����
	 for (unsigned int idxa = 0; idxa < a.digits.size(); idxa++)
	 {
		 this->digits.push_back(a.digits[idxa]);
		 if (idxa < b.digits.size())
			 this->digits[idxa] += b.digits[idxa];
	 }

	 // �ջ�� ������ index 0���� �����ؼ� 10���� ū�� ó��
	 for (unsigned int next, counter = 0; counter < this->digits.size(); counter++)
	 {
		 if (this->digits[counter] >= 10)
		 {
			 this->digits[counter] -= 10;
			 next = counter + 1; // �����÷ο� ������
			 //���� ������ �ڸ��� 10���� ũ�ٸ� 
			 if (next != this->digits.size())
				 this->digits[next] += 1;
			 else
				 this->digits.push_back(1);
		 }
	 }
 }

 void inf_int::Subtractor(const inf_int& a, const inf_int& b)
 {
	 //a �� b���� ������ ũ�ٰ� ����(���� ���Լ� �����Ǹ� ���� ����)
	 // c�� a�� b�� ������ ����
	 // ����� ������ index 0���� �����Ͽ� 0���� ������ ó��
	 // �ᱣ��, ��ȣ, ���� ó���Ͽ� ��ȯ
 }