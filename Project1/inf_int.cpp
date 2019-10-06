#include "inf_int.h"

// 
// to be filled by students
//
// example :
//

inf_int::inf_int() // 일단 필요해서 가져다씀, 추후 구현완료시 수정함
{
	this->length = 1;
	this->thesign = true;
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