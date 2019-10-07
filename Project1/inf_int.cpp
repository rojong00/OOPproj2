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
	// inf int c 생성d
	inf_int c;
	// 아랫부분(operator -)에 겹치는게 많아서 리팩토링 과정에서 Thesign_selector 함수를 따로 뺄 예정, 지금은 그냥 놔둠
	// 만약 a와 b의 thesign이 같다면 부호를 저장하고, c.Adder 호출
	if (a.thesign == b.thesign)
	{
		c.thesign = a.thesign;
		// a 와 b중 절댓값이 큰것을 앞에 호출
		if (true) // a의 절댓값이 b보다 크다면
			c.Adder(a, b);
		else if (false) // b의 절댓값이 a보다 크다면
			c.Adder(b, a);
	}
	// a와 b의 thesign이 다르다면 부호를 저장하고, Subtractor 호출
	else
	{
		if (true) // a의 절댓값이 b보다 크다면
		{
			c.thesign = a.thesign;
			c.Subtractor(a, b);
		}
		else if (false)
		{
			c.thesign = !a.thesign; // b의 절댓값이 a보다 크다면
			c.Subtractor(b, a);
		}
	}
	return c;
}

inf_int operator-(const inf_int& a, const inf_int& b)
{
	// inf int c 생성
	inf_int c;
	// a 와 b의 thesign이 같다면 부호를 저장하고, c.Subtractor 호출
	if (a.thesign == b.thesign)
	{
		if (true) // a의 절댓값이 b보다 크다면
		{
			c.thesign = a.thesign;
			c.Subtractor(a, b);
		}
		else if (false) // b의 절댓값이 a보다 크다면
		{
			c.thesign = !a.thesign;
			c.Subtractor(b, a);
		}
	}
	else
	{
		if (true) // a의 절댓값이 b보다 크다면
		{
			c.thesign = a.thesign;
			c.Adder(a, b);
		}
		else if (false) // b의 절댓값이 a보다 크다면
		{
			c.thesign = a.thesign;
			c.Adder(b, a);
		}
	}
	// a 와 b의 thesign이 다르다면 부호를 저장하고, Adder 호출

	return c;
}

void inf_int::Adder(const inf_int& a, const inf_int& b)
{
	// a가 b보다 절댓값이 크다고 가정(절댓값 비교함수 구현되면 수정 예정)
	// c에 a와 b를 더해가며 저장
	for (unsigned int idxa = 0; idxa < a.digits.size(); idxa++)
	{
		this->digits.push_back(a.digits[idxa]);
		if (idxa < b.digits.size())
			this->digits[idxa] += b.digits[idxa];
	}

	// 합산된 벡터의 index 0부터 시작해서 10보다 큰것 처리
	for (unsigned int next, counter = 0; counter < this->digits.size(); counter++)
	{
		if (this->digits[counter] >= 10)
		{
			this->digits[counter] -= 10;
			next = counter + 1; // 오버플로우 방지용
			//만약 마지막 자리가 10보다 크다면 
			if (next != this->digits.size())
				this->digits[next] += 1;
			else
				this->digits.push_back(1);
		}
	}

	// this를 이용하여 호출한 object를 직접수정하였으므로, 반환 불필요
}

void inf_int::Subtractor(const inf_int& a, const inf_int& b)
{
	//a 가 b보다 절댓값이 크다고 가정(절댓값 비교함수 구현되면 수정 예정)
	// c에 a와 b를 빼가며 저장
	for (unsigned int idxa = 0; idxa < a.digits.size(); idxa++)
	{
		this->digits.push_back(a.digits[idxa]);
		if (idxa < b.digits.size())
			this->digits[idxa] -= b.digits[idxa];
	}
	// 차산된 벡터의 index 0부터 시작하여 0보다 작은것 처리
	for (unsigned int next, counter = 0; counter < this->digits.size(); counter++)
	{
		if (this->digits[counter] < 0)
		{
			this->digits[counter] += 10;
			next = counter + 1;
			this->digits[next] -= 1;
		}
	}
	// 빼기에서는 가장 큰 자리들이 연속된 0일 수 있으니, 체크후 제거

	while (1)
	{
		if (this->digits.back() == 0)
		{
			this->digits.pop_back();
		}
		else
			break;
	}

	// this를 이용하여 호출한 object를 직접수정하였으므로, 반환 불필요
}