#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<limits>
using namespace std;
void dk1(int& a, int b, int c);
void dk2(int& a, int b, int c);
void dk2(float& a, float b, float c);
class sv {
protected:
	string ten;
	int ns;
	string gtinh;
	string masv;
public:
	void nhap();

};
class svtn :public sv {
private:
	float toan;
	float ly;
	float tin;
	float diemtb;
public:
	float dkn(float& d);
	friend istream& operator>>(istream& is, svtn& a) {
		float d;
		cout << "diem toan cua sinh vien " << a.ten << " la : ";
		is >> d;
		a.toan = a.dkn(d);
		cout << "diem ly cua sinh vien " << a.ten << " la : ";
		is >> d;
		a.ly = a.dkn(d);
		cout << "diem tin cua sinh vien " << a.ten << " la : ";
		is >> d;
		a.tin = a.dkn(d);
		a.diemtb = (a.toan + a.ly + a.tin) / 3;
		return is;
	}
	//nap trong toan tu xuat  :
	friend ostream& operator<<(ostream& os, svtn& a) {
		os << a.ten << setw(25) << a.ns << setw(10) << a.gtinh << setw(8)
			<< a.masv << setw(10) << a.toan << setw(10) << a.ly << setw(10) << a.tin << setw(10) << a.diemtb << endl;
		return os;
	}
	friend void xep(svtn a[], int n, int temp);
	friend void xet(int choice, svtn a[], int& n);
	friend void nhapall(svtn a[], int n);
};
//nhap tat ca thong tin sinh vien va luu lai duoi file txt
void nhapall(svtn a[], int n);
void xuatall(svtn a[], int n);
void themsv(svtn a[], int& n);
void xoa(svtn a[], int& n, int vtx);
bool tiep();
void xep(svtn a[], int n, int temp);
void xet(int choice, svtn a[], int& n);
void menu(svtn a[], int& n);