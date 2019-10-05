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
	 // 만약 a와 b의 thesign이 같다면 부호를 저장하고, Adder 호출
	 // a와 b의 thesign이 다르다면 부호를 저장하고, Subtractor 호출
 }

 inf_int operator-(const inf_int& a, const inf_int& b)
 {
	 // a 와 b의 thesign이 같다면 부호를 저장하고, Subtractor 호출
	 // a 와 b의 thesign이 다르다면 부호를 저장하고, Adder 호출
 }

 void Adder(const inf_int& a, const inf_int& b)
 {
	 // a 가 b보다 절댓값이 크다고 가정(절댓값 비교함수 구현되면 수정 예정)
	 // a 의 길이가 n이라면 n+1로 맞추어 새 배열 c 선언, 0으로 초기화 (initializer 구현시 수정 예정)
	 // c에 a 와 b를 더해가며 저장
	 // 합산된 배열의 index 0부터 시작해서 10보다 큰것 처리
	 // 결괏값, 부호, 길이 처리해서 반환
 }

 void Subtractor(const inf_int& a, const inf_int& b)
 {
	 //a 가 b보다 절댓값이 크다고 가정(절댓값 비교함수 구현되면 수정 예정)
	 // a 의 길이가 n이라면 n로 맞추어 새 배열 c 선언, 0으로 초기화
	 // c에 a와 b를 빼가며 저장
	 // 차산된 배열의 index 0부터 시작하여 0보다 작은것 처리
	 // 결괏값, 부호, 길이 처리하여 반환
 }