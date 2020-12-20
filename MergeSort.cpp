// Çift Yönlü Baðlantýlý Liste Kodu
#include <iostream>
#include<stdlib.h>
using namespace std;
// listedeki veri yapýsýnýn tanýmlanmasý
typedef struct topluluk {
int bilgi;
struct topluluk *arka;
struct topluluk *on;
}BAGLISTE;
// Listenin ilk ve son elemanlarýnýn adreslerini tutan iþaretçiler
BAGLISTE *ilk=NULL, *son=NULL;
BAGLISTE *ara(int), *okuKlavye();
void yazEkrana(BAGLISTE *yazilicak);int ekle(BAGLISTE *ki);int listele(); int sil(int);
BAGLISTE *split(BAGLISTE *ilk);  
BAGLISTE *mergeSort(BAGLISTE *ilk);
BAGLISTE *merge(BAGLISTE *first, BAGLISTE *second) ; 
int main()
{
BAGLISTE *eklenecek, *ki;
int bilgi, sonuc,tmp;
char secim;
while(1){
// Ekrana Menü çýkarýlýyor
cout<<endl<<"Ekleme"<<endl<<"Listeleme"<<endl<<"Arama"<<endl<<"Silme"<<endl<<"Sýralama"<<endl;
cout<<"Cikis"<<endl<<"Seciminiz ?"<<endl;
cin>>secim;
switch(secim)
{
case 'E':
{
eklenecek=okuKlavye(); //ekleme secildi
if (eklenecek!=NULL) ekle(eklenecek);
else cout<<endl<<"Ekleme icin bellek dolu ! "<<endl;
break;
}
case 'M':{		//Sýralama seçildi
	ilk=mergeSort(ilk);
	
	break;
} 
case 'L':// listeleme seçildi
{
sonuc=listele();
if (sonuc==1) cout<<endl<<"Bos Liste ! "<<endl;

break;
}
case 'A': // Arama secildi
{
cout<<endl<<"Aranan: ";
scanf("%d",&bilgi);
ki=ara(bilgi);
if (ki==NULL) cout<<endl<<"Aranan Bulunamadi ! "<<endl;
else yazEkrana(ki);
break;
}
case 'S': // Silme secildi
{
cout<<endl<<"Silinecek: ";
scanf("%d",&bilgi);
tmp=sil(bilgi);
if (tmp==-1) {cout<<endl<<"Silindi ! "<<endl;}
else {cout<<"Silinmek istenen veri listede yok ! "<<endl;}
break;
}
case 'C':// Çýkýþ seçildi
{
cout<<"HOSCAKAL :) "<<endl;
exit(0);
}
default:cout<<"Yanlýs Secim !! "<<endl;
}
}
system("pause");
return 0;
}
// fonksiyonlar
void yazEkrana(BAGLISTE *yazilacak){
printf("bilgi: %d \n",yazilacak->bilgi);
}
int ekle(BAGLISTE *ki){
if(ilk!=NULL)
{son->arka=ki;
ki->on=son;
son=ki;
son->arka=NULL; }
else{
ilk=ki;
son=ilk;
ilk->on=NULL;
ilk->arka=NULL;
}
return 0;
}
int listele(){
BAGLISTE *p;
p = new BAGLISTE;
p=ilk;
if (p==NULL) {return 1;}
while(p!=NULL){
yazEkrana(p);
p=p->arka;
}
return 0;
}
BAGLISTE *ara(int aranan)
{
BAGLISTE *p;
p = new BAGLISTE;
p=ilk;
while(p!=NULL){
if(p->bilgi==aranan) return p;
p=p->arka;
}
return NULL;
}
int sil(int silinecek)
{
BAGLISTE *p;
p = new BAGLISTE;
p=ilk;
while(p!=NULL){
if(silinecek==p->bilgi) break;
p=p->arka;
}
if (p!=NULL)
{
if(p->on==NULL && p->arka==NULL)
{
ilk=NULL;son=NULL;
}
else if (p->on==NULL && p->arka!=NULL)
{
ilk=p->arka;
ilk->on = NULL;
}
else if (p->on!=NULL&& p->arka==NULL)
{
son=p->on;
son->arka=NULL;
}
else
{BAGLISTE *onceki, *sonraki;
onceki=p->on;
sonraki=p->arka;
onceki->arka=sonraki;
sonraki->on=onceki;
}
delete(p);
return -1;
}
else return 0;
}
BAGLISTE *okuKlavye(){
BAGLISTE *okunan;
okunan=new BAGLISTE;
if (okunan==NULL)
return NULL;
cout<<"Bilgi Giriniz"<<endl;
scanf("%d",&(okunan->bilgi));
okunan->on=NULL;
okunan->arka=NULL;
return okunan;
}



BAGLISTE *split(BAGLISTE *ilk);  
  
 
BAGLISTE *merge(BAGLISTE *first, BAGLISTE *second)  
{  
     
    if (!first)  
        return second;  
  
    
    if (!second)  
        return first;  
  
    
    if (first->bilgi < second->bilgi)  
    {  
        first->arka = merge(first->arka,second);  
        first->arka->on = first;  
        first->on = NULL;  
        return first;  
    }  
    else
    {  
        second->arka = merge(first,second->arka);  
        second->arka->on = second;  
        second->on = NULL;  
        return second;  
    }  
}  
  

BAGLISTE *mergeSort(BAGLISTE *ilk)  
{  
    if (!ilk || !ilk->arka)  
        return ilk;  
    BAGLISTE *second = split(ilk);  
  
      
    ilk = mergeSort(ilk);  
    second = mergeSort(second);  
  
    
    return merge(ilk,second);  
} 

  
BAGLISTE *split(BAGLISTE *head)  
{  
    BAGLISTE *fast = head,*slow = head;  
    while (fast->arka && fast->arka->arka)  
    {  
        fast = fast->arka->arka;  
        slow = slow->arka;  
    }  
    BAGLISTE *temp = slow->arka;  
    slow->arka = NULL;  
    return temp;  
}
