#include<iostream>

using namespace std;
void generate(int n,string &str1,string &str2){
	for(int i=0;i<n;i++){
		if(i%2==0){
			str1+='1';
			str2+='0';
		}
		else{
			str1+='0';
			str2+='1';
		}
	}
}
int diff(string &str,string &str1,string &str2){
	int count1=0;
	int count2=0;
	int n=str.size();
	for(int i=0;i<n;i++){
		if(str1[i]!=str[i])
		count1++;
		if(str2[i]!=str[i])
		count2++;
	}
	return min(count1,count2);
}
int makeBeautiful(string str) {
	int n=str.size();
	string str1="";
	string str2="";
	generate(n,str1,str2);
	int res=diff(str,str1,str2);
	return res;
}

int main(){
string str;
cin>>str;
int res=makeBeautiful(str);
cout<<res;
return 0;
}