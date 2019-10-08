#include "inf_int.h"


inf_int operator+(const inf_int& a, const inf_int& b)
{
	// inf int c ����d
	inf_int c;
	// c�� ����ִ� �ʱ갪 0 ���ֱ�
	c.digits.pop_back();

	// �Ʒ��κ�(operator -)�� ��ġ�°� ���Ƽ� �����丵 �������� Thesign_selector �Լ��� ���� �� ����, ������ �׳� ����
	// ���� a�� b�� thesign�� ���ٸ� ��ȣ�� �����ϰ�, c.Adder ȣ��
	if (a.thesign == b.thesign)
	{
		c.thesign = a.thesign;
		// a �� b�� ������ ū���� �տ� ȣ��
		if (true) // a�� ������ b���� ũ�ٸ�
			c.Adder(a, b);
		else if (false) // b�� ������ a���� ũ�ٸ�
			c.Adder(b, a);
	}
	// a�� b�� thesign�� �ٸ��ٸ� ��ȣ�� �����ϰ�, Subtractor ȣ��
	else
	{
		if (true) // a�� ������ b���� ũ�ٸ�
		{
			c.thesign = a.thesign;
			c.Subtractor(a, b);
		}
		else if (false)
		{
			c.thesign = !a.thesign; // b�� ������ a���� ũ�ٸ�
			c.Subtractor(b, a);
		}
	}
	return c;
}

inf_int operator-(const inf_int& a, const inf_int& b)
{
	// inf int c ����
	inf_int c;
	// a �� b�� thesign�� ���ٸ� ��ȣ�� �����ϰ�, c.Subtractor ȣ��
	if (a.thesign == b.thesign)
	{
		if (true) // a�� ������ b���� ũ�ٸ�
		{
			c.thesign = a.thesign;
			c.Subtractor(a, b);
		}
		else if (false) // b�� ������ a���� ũ�ٸ�
		{
			c.thesign = !a.thesign;
			c.Subtractor(b, a);
		}
	}
	else
	{
		if (true) // a�� ������ b���� ũ�ٸ�
		{
			c.thesign = a.thesign;
			c.Adder(a, b);
		}
		else if (false) // b�� ������ a���� ũ�ٸ�
		{
			c.thesign = a.thesign;
			c.Adder(b, a);
		}
	}
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

	// this�� �̿��Ͽ� ȣ���� object�� ���������Ͽ����Ƿ�, ��ȯ ���ʿ�
}

void inf_int::Subtractor(const inf_int& a, const inf_int& b)
{
	//a �� b���� ������ ũ�ٰ� ����(���� ���Լ� �����Ǹ� ���� ����)
	// c�� a�� b�� ������ ����
	for (unsigned int idxa = 0; idxa < a.digits.size(); idxa++)
	{
		this->digits.push_back(a.digits[idxa]);
		if (idxa < b.digits.size())
			this->digits[idxa] -= b.digits[idxa];
	}
	// ����� ������ index 0���� �����Ͽ� 0���� ������ ó��
	for (unsigned int next, counter = 0; counter < this->digits.size(); counter++)
	{
		if (this->digits[counter] < 0)
		{
			this->digits[counter] += 10;
			next = counter + 1;
			this->digits[next] -= 1;
		}
	}
	// ���⿡���� ���� ū �ڸ����� ���ӵ� 0�� �� ������, üũ�� ����

	while (1)
	{
		if (this->digits.back() == 0)
		{
			this->digits.pop_back();
		}
		else
			break;
	}

	// this�� �̿��Ͽ� ȣ���� object�� ���������Ͽ����Ƿ�, ��ȯ ���ʿ�
}

bool inf_int::Abstract_compair(const inf_int a, const inf_int b)
{
	// a�� b�� ������ ��.
	// �տ�(a)�� ���ų� ũ�� true, �ڿ�(b)�� ũ�� false ��ȯ

	// a ���̰� b ���̺��� ��� true ��ȯ
	if (a.length > b.length)
		return true;
	// b ���̰� a ���̺��� ��� false ��ȯ
	else if (a.length < b.length)
		return false;

	// a ���̿� b ���̰� ������
	else if (a.length == b.length)
	{
		for (int i = a.length - 1; i >= 0; i--)
		{
			// ū ���ں��� �����ؼ� �������� ����, ���� ���� ū ���ڰ� ŭ
			if (a.digits[i] > b.digits[i])
				return true;
			else if (a.digits[i] < b.digits[i])
				return false;
		}
		// �� ���� ������ ũ�� true ��ȯ
		return true;
	}
}