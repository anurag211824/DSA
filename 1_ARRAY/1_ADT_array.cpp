#include<iostream>

using namespace std;
struct myarray{
    int total_size;
    int used_size;
    int *ptr;//base address
};
void creatArray(struct myarray *a,int tsize,int usize){
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)(malloc(usize*sizeof(int)));
}
void setvalue(struct myarray *a){
    cout<<"enter the value in the marks array:";
    for(int i=0;i<a->used_size;i++){
        cin>>a->ptr[i];
    }
}
void showvalue(struct myarray *a){
    cout<<"showing the marks array:";
    for(int i=0;i<a->used_size;i++){
        cout<<a->ptr[i]<<" ";
    }
}

void setvalueAtindex(struct myarray*a,int i){
    cout<<"update the value at given index:";
    cin>>a->ptr[i];
}
void getvalueAtindex(struct myarray*a,int i){
    cout<<"the value at "<<i<<" index is:";
    cout<<a->ptr[i];
    cout<<endl;
}
int main(){
struct myarray marks;
creatArray(&marks,10,5);
setvalue(&marks);
setvalueAtindex(&marks,2);
getvalueAtindex(&marks,3);
showvalue(&marks);
return 0;
}