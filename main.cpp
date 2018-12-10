#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
const int SIZE = 100;
// Fungsi untuk membandingkan dua nlai, untuk mencari nilai yang paling besar
bool comp(pair<int, double> a, pair<int, double> b){
        return a.second > b.second;
}

int main(){
    //Membaca berkas yang akan dilakukan pengecekan
    ifstream BacaData1("DataTugas2.csv");
    //Menulis kedalam berkas
    ofstream TulisData1("TebakanTugas2.csv");
    string nomor, pemasukan, hutang;
    //Nilai yang berisi Nomor dan Hasil
    vector< pair<int,double> > mData;
    //Deskripsi Variable yang digunakan
    int j = 1;
    double n, p, h, DataY, DataN, DataM, Hasil;
    double HitungPRendah, HitungPSedang, HitungPTinggi;
    double HitungHRendah, HitungHSedang, HitungHTinggi;
    double HKecilPKecil, HKecilPSedang, HKecilPTinggi, HSedangPKecil, HSedangPSedang, HSedangPTinggi, HTinggiPKecil, HTinggiPSedang, HTinggiPTinggi;
    srand (time(NULL));
    int i = 0;
    TulisData1<<"Daftar Index yang Mendapatkan BLT"<<endl;

    getline(BacaData1,nomor,',');
    getline(BacaData1,pemasukan,',');
    getline(BacaData1,hutang,'\n');

    //Melakukan perulangan selama masih ada data yang bisa dibaca
    while(BacaData1.good()){
        //Melakukan pengindikasian untuk tiap row yang ada pada berkas
        getline(BacaData1,nomor,',');
        getline(BacaData1,pemasukan,',');
        getline(BacaData1,hutang,'\n');
        //Mengubah data string pada berkas menjadi double supaya dapat dilakukan perhitungan
        stringstream nomor1(nomor), pemasukan1(pemasukan), hutang1(hutang);
        nomor1 >> n; pemasukan1 >> p; hutang1 >> h;

        //Hitung Nilai Pendapatan rendah
        if (p<=0.25){
            HitungPRendah = 1;
        }
        else if ((p>0.25) && (p<=0.6)){
            HitungPRendah = ((0.6-p)/(0.6-0.25));
        }
        else{
            HitungPRendah = 0;
        }
        //Hitung Nilai Pendapatan Sedang
        if ((p>=0.5) && (p<0.8)){
            HitungPSedang = ((p-0.5)/(0.8-0.5));
        }
        else if ((p>=0.8) && (p<=1.2)){
            HitungPSedang = 1;
        }
        else if ((p>1.2) && (p<=1.5)){
            HitungPSedang = ((1.5-p)/(1.5-1.2));
        }
        else{
            HitungPSedang = 0;
        }
        //Hitung Nilai Pendapatan Tinggi
        if ((p>=1.4) && (p<1.75)){
            HitungPTinggi = ((p-1.4)/(1.75-1.4));
        }
        else if (p>=1.75){
            HitungPTinggi = 1;
        }
        else{
            HitungPTinggi = 0;
        }

        //Hitung Nilai Hutang Kecil
        if (h<=10){
            HitungHRendah = 1;
        }
        else if ((h>10) && (h<=30)){
            HitungHRendah = ((30-h)/(30-10));
        }
        else{
            HitungHRendah = 0;
        }
        //Hitung Nilai Hutang Sedang
        if ((h>=25) && (h<48)){
            HitungHSedang = ((h-25)/(48-25));
        }
        else if ((h>=48) && (h<=52)){
            HitungHSedang = 1;
        }
        else if ((h>52) && (h<=75)){
            HitungHSedang = ((75-h)/(75-52));
        }
        else{
            HitungHSedang = 0;
        }
        //Hitung Nilai hutang Tinggi
        if ((h>=70) && (h<90)){
            HitungHTinggi = ((h-70)/(90-70));
        }
        else if (h>=90){
            HitungHTinggi = 1;
        }
        else{
            HitungHTinggi = 0;
        }

        //Mencari nilai terkecil antara pendapatan rendah dengan hutang rendah
        if (HitungPRendah<HitungHRendah){
            HKecilPKecil = HitungPRendah;
        }
        else{
            HKecilPKecil = HitungHRendah;
        }
        //Mencari nilai terkecil antara pendapatan sedang dengan hutang rendah
        if (HitungPSedang<HitungHRendah){
            HKecilPSedang = HitungPSedang;
        }
        else{
            HKecilPSedang = HitungHRendah;
        }
        //Mencari nilai terkecil antara pendapatan tinggi dengan hutang rendah
        if (HitungPTinggi<HitungHRendah){
            HKecilPTinggi = HitungPTinggi;
        }
        else{
            HKecilPTinggi = HitungHRendah;
        }
        //Mencari nilai terkecil antara pendapatan rendah dengan hutang sedang
        if (HitungPRendah<HitungHSedang){
            HSedangPKecil = HitungPRendah;
        }
        else{
            HSedangPKecil = HitungHSedang;
        }
        //Mencari nilai terkecil antara pendapatan sedang dengan hutang sedang
        if (HitungPSedang<HitungHSedang){
            HSedangPSedang = HitungPSedang;
        }
        else{
            HSedangPSedang = HitungHSedang;
        }
        //Mencari nilai terkecil antara pendapatan tinggi dengan hutang sedang
        if (HitungPTinggi<HitungHSedang){
            HSedangPTinggi = HitungPTinggi;
        }
        else{
            HSedangPTinggi = HitungHSedang;
        }
        //Mencari nilai terkecil antara pendapatan rendah dengan hutang besar
        if (HitungPRendah<HitungHTinggi){
            HTinggiPKecil = HitungPRendah;
        }
        else{
            HTinggiPKecil = HitungHTinggi;
        }
        //Mencari nilai terkecil antara pendapatan sedang dengan hutang besar
        if (HitungPSedang<HitungHTinggi){
            HTinggiPSedang = HitungPSedang;
        }
        else{
            HTinggiPSedang = HitungHTinggi;
        }
        //Mencari nilai terkecil antara pendapatan tinggi dengan hutang tinggi
        if (HitungPTinggi<HitungHTinggi){
            HTinggiPTinggi = HitungPTinggi;
        }
        else{
            HTinggiPTinggi = HitungHTinggi;
        }

        //Mencari nilai terbesar diantara nilai dengan status maybe
        if (HKecilPKecil>HSedangPSedang){
            if (HKecilPKecil>HTinggiPTinggi){
                DataM = HKecilPKecil;
            }
            else{
                DataM = HTinggiPTinggi;
            }
        }
        else{
            if (HSedangPSedang>HTinggiPTinggi){
                DataM = HSedangPSedang;
            }
            else{
                DataM = HTinggiPTinggi;
            }
        }
        //Mencari nilai terbesar diantara nilai dengan status no
        if (HKecilPSedang>HKecilPTinggi){
            if (HKecilPSedang>HSedangPTinggi){
                DataN = HKecilPSedang;
            }
            else{
                DataN = HSedangPTinggi;
            }
        }
        else{
            if (HKecilPTinggi>HSedangPTinggi){
                DataN = HKecilPTinggi;
            }
            else{
                DataN = HSedangPTinggi;
            }
        }
        //Mencari nilai terbesar diantara nilai dengan status yes
        if (HSedangPKecil>HTinggiPKecil){
            if (HSedangPKecil>HTinggiPSedang){
                DataY = HSedangPKecil;
            }
            else{
                DataY = HTinggiPSedang;
            }
        }
        else{
            if (HTinggiPKecil>HTinggiPSedang){
                DataY = HTinggiPKecil;
            }
            else{
                DataY = HTinggiPSedang;
            }
        }

        //Menghitung nilai defuzzyfication menggunakan metode sugeno dengan height method
        Hasil = (((30*DataN)+(60*DataM)+(80*DataY))/(DataN+DataM+DataY));
        mData.push_back(make_pair(i+1, Hasil));
        i++;
    }
    //Melakukan shorting dari data yang sudah ditambahkan kedalam vector
    sort(mData.begin(), mData.end(), comp);
    //Memilih 20 data dengan nilai acceptance paling besar dan layak menerima blt
    cout<<"Index"<<"   "<<"Nilai Acceptance"<<endl;
    while(j <= 20){
        cout<<mData[j].first<<"        "<<mData[j].second<<endl;
        TulisData1<<mData[j].first<<endl;
        j++;
    }
    BacaData1.close();
    TulisData1.close();
}
