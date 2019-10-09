/* int_int_other.cpp written by oh jong h */
#include "inf_int.h"

inf_int::inf_int()                               // constructor of inf_int without number assignment
{
  this->digits.assign(1,0);
  this->length=1;
	this->thesign=true;
}



inf_int::inf_int(long long n){                   // constructor of inf_int having arabic number argument
	if(n<0){
		this->thesign=false;
		n=-n;
	}else	this->thesign=true;

  int len=0;
  long long tmp_int_1=n, tmp_int_2=n;
  if(n==0) {
    this->digits.push_back(0);
    this->length=0;
  }else{
     do{
       tmp_int_1=(long long)(tmp_int_1/10);
       len++;
     }while(tmp_int_1>0);

     this->length=len;
     this->digits.assign(len,0);

     for(int i=0;i<len;i++){
       this->digits[i]=(tmp_int_2)%10;            // put last digit of number in digits vector
       tmp_int_2=(long long)tmp_int_2/10;
    }
  }
}



inf_int::inf_int(const char *str){               // constructor of inf_int having string argument
  string strg(str);
  int len=0;
  if(strg.front()=='-') {
    this->thesign=false;
    strg.erase(0,1);
  }else this->thesign=true;

  len=strg.length();
  this->length=len;
  this->digits.reserve(len);

  if(len>8){                                     // in case the string is too long to put in a integer, we cut it in to suitable size,
    int count=(int)len/8;                        // we set this cut standard length as 8
    if(len%8==0) count--;
    int tmp=count;
    for(int p=0;p<tmp+1;p++){
      int tmp_num_len=0;
      int tmp_num=0;
      string tmp_str=strg.substr(8*count,8);
      tmp_num_len=tmp_str.length();
      tmp_num=(int)stoi(tmp_str);
      for(int k=0;k<tmp_num_len;k++){
        this->digits.push_back(tmp_num%10);
        tmp_num=(int)tmp_num/10;
      }
      count=count-1;
    }
  }else{                                         // in case input data is short enough to put into a integer, we directly put it in
    int tmp_num_len=0;
    int tmp_num=0;
    tmp_num_len=strg.length();
    tmp_num=(int)stoi(strg);
    for(int k=0;k<tmp_num_len;k++){
      this->digits.push_back(tmp_num%10);
      tmp_num=(int)tmp_num/10;
    }
  }
}



inf_int::inf_int(const inf_int& a){              // a(b), it has a same meaning with a=b
  this->length=a.length;
	this->thesign=a.thesign;

  this->digits.reserve(a.length);
  for (int i=0;i<a.length;i++) this->digits.push_back(a.digits.at(i));
}



inf_int::~inf_int(){
	this->digits.clear();		                       // free mem alloc
}



void inf_int::Show(){                            // if vector is empty or has 0, notice it is empty
  if(this->digits.empty()||(this->digits.at(0)==0&&this->length==1)) cout<<"it's zero"<<endl;
  else {
    int len=this->digits.size();
    cout<<"num : ";
    if(this->thesign==false) cout<<"-";          // if the sign is negative, attach -. and arrage its vector element in right order and cout
    for(int i=len-1;i>=0;i--) cout<<this->digits.at(i);
  }
}
  



inf_int& inf_int::operator=(const inf_int& a)    // a=b
{
  this->digits.reserve(a.length);
  copy(a.digits.begin(),a.digits.end(),this->digits.begin());

	this->length=a.length;
	this->thesign=a.thesign;

	return *this;
}



bool operator==(const inf_int& a, const inf_int& b){
  if(a.thesign!=b.thesign) return false;
  else{
    if (a.length!=b.length) return false;
    else{
      if(a.digits==b.digits) return true;          // comparison as standard library <vector> to figure out they are same
      else return false;
    }
  }
}


bool operator!=(const inf_int& a, const inf_int& b){
	return !operator==(a, b);                       // reuse similar op
}



bool operator>(const inf_int& a, const inf_int& b){
  if(a.thesign!=b.thesign){
    if(a.thesign==true) return true;
    else return false;
  }else{                                         // if the signs of two inf_int are different, compare number
    if(a.thesign==true){                         // if the numbers are positive, bigger one is bigger
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
      return false;                              // a==b case
    }else{                                       // if the numbers are negative, smaller one is bigger
        if(a.length>b.length) return false;
        else if(a.length<b.length) return true;
        else {
          int i=a.length-1;
          do {
            if(a.digits.at(i)>b.digits.at(i)) return false;
            else if (a.digits.at(i)<b.digits.at(i)) return true;
            else i--;
          }while(i>=0);
        }
        return false;                            // a==b case
    }
  }
}



bool operator<(const inf_int& a, const inf_int& b){
  return operator>(b,a);                         // reuse similar op
}



/*
ostream& operator<<(ostream& out, const inf_int& a){
	if(a.thesign==false) out<<'-';
	for(int i=a.length-1; i>=0; i--) out<<a.digits.at(i);

	return out;
}
*/
