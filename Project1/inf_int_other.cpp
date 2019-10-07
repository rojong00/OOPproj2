#include "inf_int.h"

inf_int::inf_int()
{
  this->digits.assign(1,0);
  this->length=1;
	this->thesign=true;
}



inf_int::inf_int(int n){
  this->digits.assign(1,0);
	if(n<0){
		this->thesign=false;
		n=-n;
	}else	this->thesign=true;

  int len=0, tmp_int_1=n, tmp_int_2=n;
  do{
    tmp_int_1=(int)(tmp_int_1/10);
    len++;
  }while(tmp_int_1>0);

  this->length=len;
  this->digits.assign(len,0);

  for(int i=0;i<len;i++){
    this->digits[i]=(tmp_int_2)%10;
    tmp_int_2=(int)tmp_int_2/10;
  }
}



inf_int::inf_int(const char *str){
  //this->digits.assign(1,0);
  string strg(str);
  int len=0;
  len=strg.length();
  if(strg.front()=='-') {
    this->thesign=false;
    strg.erase(0,1);
  }else {
    this->thesign=true;
  }

  this->length=len;

  //this->digits.assign(len,0);
  this->digits.reserve(len);
  //cout<<"length of num : "<<len<<endl;

  if(len>8){
    int count=(int)len/8;
    //cout<<"count : "<<count<<endl;
    int tmp=count;
    for(int p=0;p<tmp+1;p++){
      int tmp_num_len=0, tmp_num=0;
      string tmp_str=strg.substr(8*count,8);
      //if(tmp_str.length()!=8) tmp_str.shrink_to_fit();
      tmp_num_len=tmp_str.length();
      //cout<<tmp_num_len<<endl;
      tmp_num=stoi(tmp_str);
      for(int k=0;k<tmp_num_len;k++){
        //unsigned int tmp_2=tmp_num%10;
        //cout<<"tmp_num : "<<tmp_num<<endl;
        this->digits.push_back(tmp_num%10);
        //this->digits.push_back(tmp_2);
        //this->digits[8*p+k]=(unsigned int)tmp_num%10;
        //cout<<this->digits[8*p+k];
        tmp_num=(int)tmp_num/10;
      }
      //cout<<"vector size : "<<this->digits.size()<<endl;
      count=count-1;
    }
  }
  //cout<<'\n'<<"finish"<<endl;
}

/*
inf_int::inf_int(const inf_int& c){
  int len=c.length;
  this->thesign=c.thesign;
  this->digits.assign(len,0);
  this->digits=c.digits;
}
*/


void inf_int::show(){
  	int len=this->digits.size();
    cout<<"num :";
  	for(int i=0;i<len;i++) cout<<this->digits[i];
    cout<<'\n';
}


inf_int& inf_int::operator=(const inf_int& a)
{
  this->digits.reserve(a.length);
  copy(a.digits.begin(),a.digits.end(),this->digits.begin());
  //for(int i=0;i<a.length;i++) this->digits[i]=a.digits[i];

	this->length=a.length;
	this->thesign=a.thesign;

	return *this;
}



bool operator==(const inf_int& a, const inf_int& b){
  int len_a=a.length, len_b=b.length, count=0;
  if (len_a!=len_b) {return false;
  }else{
    if(a.digits==b.digits) return true;
    else return false;
  }
}



bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}



bool operator>(const inf_int& a, const inf_int& b){
  if(a.thesign!=b.thesign){
    if(a.thesign==true) return true;
    else return false;
  }else{
    if(a.length>b.length) return true;
    else if(a.length<b.length) return false;
    else {
      int i=a.length-1;
      do {
        if(a.digits.at(i)>b.digits.at(i)) return true;
        else if (a.digits.at(i)<b.digits.at(i)) return false;
        else i--;
      }while(i>=0);
    }
    return false; //a==b case
  }
}



bool operator<(const inf_int& a, const inf_int& b){
  return operator>(b,a);

}

/*
inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if(a.thesign==b.thesign){	// 이항의 부호가 같을 경우 + 연산자로 연산
		for(i=0; i<a.length; i++){
			c.Add(a.digits[i], i+1);
		}
		for(i=0; i<b.length; i++){
			c.Add(b.digits[i], i+1);
		}

		c.thesign=a.thesign;

		return c;
	}else{	// 이항의 부호가 다를 경우 - 연산자로 연산
		c=b;
		c.thesign=a.thesign;

		return a-c;
	}
}

inf_int operator-(const inf_int& a, const inf_int& b)
{
	// to be filled
}

inf_int operator*(const inf_int& a, const inf_int& b)
{
    // to be filled
}


ostream& operator<<(ostream& out, const inf_int& a)
{
	int i;

	if(a.thesign==false){
		out<<'-';
	}
	for(i=a.length-1; i>=0; i--){
		out<<a.digits[i];
	}
	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a의 index 자리수에 n을 더한다. 0<=n<=9, ex) a가 391일때, Add(a, 2, 2)의 결과는 411
{
	if(this->length<index){
		this->digits=(char*)realloc(this->digits, index+1);

		if(this->digits==NULL){		// 할당 실패 예외처리
			cout<<"Memory reallocation failed, the program will terminate."<<endl;

			exit(0);
		}

		this->length=index;					// 길이 지정
		this->digits[this->length]='\0';	// 널문자 삽입
	}

	if(this->digits[index-1]<'0'){	// 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
		this->digits[index-1]='0';
	}

	this->digits[index-1]+=num-'0';	// 값 연산


	if(this->digits[index-1]>'9'){	// 자리올림이 발생할 경우
		this->digits[index-1]-=10;	// 현재 자릿수에서 (아스키값) 10을 빼고
		Add('1', index+1);			// 윗자리에 1을 더한다
	}
}
*/
