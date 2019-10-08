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
  string strg(str);
  int len=0;
  len=strg.length();
  if(strg.front()=='-') {
    this->thesign=false;
    strg.erase(0,1);
  }else this->thesign=true;

  this->length=len;
  this->digits.reserve(len);

  if(len>8){
    int count=(int)len/8;
    int tmp=count;
    for(int p=0;p<tmp+1;p++){
      int tmp_num_len=0;
      unsigned int tmp_num=0;
      string tmp_str=strg.substr(8*count,8);
      tmp_num_len=tmp_str.length();
      tmp_num=(unsigned int)stoi(tmp_str);
      for(int k=0;k<tmp_num_len;k++){
        this->digits.push_back(tmp_num%10);
        tmp_num=(int)tmp_num/10;
      }
      count=count-1;
    }
  }else{
    int tmp_num_len=0;
    unsigned int tmp_num=0;
    tmp_num_len=strg.length();
    tmp_num=(unsigned int)stoi(strg);
    for(int k=0;k<tmp_num_len;k++){
      this->digits.push_back(tmp_num%10);
      tmp_num=(int)tmp_num/10;
    }
  }
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
  	for(int i=len-1;i>=0;i--) cout<<this->digits.at(i);
    cout<<'\n';
}


inf_int& inf_int::operator=(const inf_int& a)
{
  this->digits.reserve(a.length);
  copy(a.digits.begin(),a.digits.end(),this->digits.begin());

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
    if(a.thesign==true){
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
    }else{
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
        return false; //a==b case
      }
    }
}





bool operator<(const inf_int& a, const inf_int& b){
  return operator>(b,a);
}
