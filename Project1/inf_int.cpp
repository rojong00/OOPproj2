#include "inf_int.h"

inf_int::inf_int()
{
	this->digits.assign(1, 0);
	this->length = 1;
	this->thesign = true;
}



inf_int::inf_int(int n) {
	this->digits.assign(1, 0);
	if (n < 0) {
		this->thesign = false;
		n = -n;
	}
	else	this->thesign = true;

	int len = 0, tmp_int_1 = n, tmp_int_2 = n;
	do {
		tmp_int_1 = (int)(tmp_int_1 / 10);
		len++;
	} while (tmp_int_1 > 0);

	this->length = len;
	this->digits.assign(len, 0);

	for (int i = 0; i < len; i++) {
		this->digits[i] = (tmp_int_2) % 10;
		tmp_int_2 = (int)tmp_int_2 / 10;
	}
}



inf_int::inf_int(const char* str) {
	this->digits.assign(1, 0);
	string strg(str);
	int len = 0;
	len = strg.length();
	if (strg.front() == '-') {
		this->thesign = false;
		strg.erase(0, 1);
	}
	else {
		this->thesign = true;
	}

	this->length = len;
	this->digits.assign(len, 0);
	cout << "length : " << this->digits.size() << endl;

	if (len > 8) {
		int count = (int)len / 8;
		int tmp = count;
		for (int p = 0; p < tmp + 1; p++) {
			int tmp_num_len = 0, tmp_num = 0;
			string tmp_str = strg.substr(8 * count, 8);
			tmp_num_len = tmp_str.length();
			tmp_num = stoi(tmp_str);
			for (int k = 0; k < tmp_num_len; k++) {
				this->digits[8 * p + k] = tmp_num % 10;
				tmp_num = (int)tmp_num / 10;
			}
			count = count - 1;
		}
	}
}
/*
if(count2!=0){
  for(p=0;p<++count;p++){
	int tmp_num_len=0, tmp_num=0;
	string tmp_str=strg.substr(9*count,9);
	tmp_num_len=tmp_str.length();
	tmp_num=stoi(tmp_str);
	for(int k=0;k<tmp_num_len;k++){
	  this->digits[9*p+k]=tmp_num%10;
	  tmp_num=(int)tmp_num/10;
	}
	count--;
  }
}else {}
for(int i=count;i>0;i--){
  string sub=strg.substr(0,9);
  for(int k=0;k<9;k++){
	this->digits[]
  }
}
}
cout<<stoi(str)<<endl;
//cout<<atoi(*str)<<"hihi"<<endl;
for(int i=0;i<len;i++) this->digits[i]=(int)strg.at(len-1-i);
//cout<<"digits : "<<this->digits[0]<<this->digits[1]<<endl;
*/




inf_int::inf_int(const inf_int& c) {
	int len = c.length;
	this->thesign = c.thesign;
	this->digits.assign(len, 0);
	this->digits = c.digits;
}



void inf_int::show() {
	int len = this->digits.size();
	cout << "num :";
	for (int i = 0; i < len; i++) cout << this->digits[i];
	cout << '\n';
}


inf_int& inf_int::operator=(const inf_int& a)
{
	this->digits.assign(a.length, 0);
	for (int i = 0; i < a.length; i++) this->digits[i] = a.digits[i];

	this->length = a.length;
	this->thesign = a.thesign;

	return *this;
}



bool operator==(const inf_int& a, const inf_int& b) {
	int len_a = a.length, len_b = b.length, count = 0;
	if (len_a != len_b) {
		return false;
	}
	else {
		if (a.digits == b.digits) return true;
		else return false;
	}
}



bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}



bool operator>(const inf_int& a, const inf_int& b) {
	if (a.thesign != b.thesign) {
		if (a.thesign == true) return true;
		else return false;
	}
	else {
		if (a.length > b.length) return true;
		else if (a.length < b.length) return false;
		else {
			for (int i = a.length; i > 0; i--) {
				if (a.digits[i] > b.digits[i]) return true;
				else if (a.digits[i] < b.digits[i]) return false;
			}
		}
		return false; //a==b case
	}
}



bool operator<(const inf_int& a, const inf_int& b) {
	if (a.thesign != b.thesign) {
		if (b.thesign == true) return true;
		else return false;
	}
	else {
		if (a.length < b.length) return true;
		else if (a.length > b.length) return false;
		else {
			for (int i = a.length; i > 0; i--) {
				if (a.digits[i] < b.digits[i]) return true;
				else if (a.digits[i] > b.digits[i]) return false;
			}
		}
		return false; //a==b case
	}
}

inf_int operator+(const inf_int& a, const inf_int& b)
{
	// inf int c ����d
	inf_int c;
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