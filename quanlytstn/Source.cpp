#include"Header.h"
void dk1(int& a, int b, int c) {
	while (!cin || a != b && a != c) {
		cout << "dung nhap linh tinh , nhap lai di" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> a;
	}
}
void dk2(int& a, int b, int c) {
	while (!cin || a < b || a > c) {
		cout << " dung nhap linh tinh , nhap lai di" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> a;
	}
}
void dk2(float& a, float b, float c) {
	while (!cin || a < b || a > c) {
		cout << "vui long chon 1 trong cac lua chon ben tren , dung nhap linh tinh" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> a;
	}
}
void sv:: nhap() {
		cin.ignore();
		int t;
		string temp;
		cout << "nhap ten sinh vien : ";
		getline(cin,this->ten);
		cout << "nhap gioi tinh cua sinh vien " << this->ten<<" ";
		getline(cin,this->gtinh);
		cout << "nhap ma sinh vien " << this->ten<<" ";
		getline(cin, temp);
		while (temp.length() != 6) {
			cout << "ma sinh vien phai co 6 ky tu , nhap lai di : ";
			getline(cin, temp);
		}
		this->masv=temp;
		cout << "nhap nam sinh cua sinh vien " << this->ten << " ";
		cin >> t;
		dk2(t, 1980, 2002);
		this->ns = t;
	}
float svtn::dkn(float& d) {
		dk2(d, 0, 10);
		return d;
	}
//nhap tat ca thong tin sinh vien va luu lai duoi file txt
void nhapall(svtn a[], int n) {
	ofstream file ("D:/sv.txt");
	for (int i = 0; i < n; i++) {
		a[i].nhap();
		cin >> a[i];
		file << a[i].ten << setw(15) << a[i].ns << setw(15) << a[i].gtinh << setw(10)
			<< a[i].masv << setw(10) << a[i].toan << setw(10) << a[i].ly << setw(10) << a[i].tin << setw(5) << a[i].diemtb << endl;
	}
}
void xuatall(svtn a[], int n) {
	cout << "duoi day la danh sach sinh vien " << endl;
	cout << "ho va ten sinh vien" << setw(15) << "nam sinh" << setw(15) << "gioi tinh" << setw(15)
		<< "ma so sinh vien " << setw(10) << "diem toan" << setw(10) << "diem ly" << setw(10) << "tin dai cuong" << setw(10) <<"diem trung binh" << endl;
	for (int i = 0; i < n; i++) {
		cout << i+1 ;
		cout<< a[i];
	}
}
void themsv(svtn a[], int& n) {
	n = n + 1;
	a[n-1].nhap();
	cin >> a[n-1];
}
void xoa(svtn a[], int& n, int vtx) {
	for (int i = vtx - 1; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
bool tiep(){
	int temp;
	cout << "ban co muon lam gi nua khong ?\n1.co\t2.khong" << endl;
	cin >> temp;
	dk1(temp, 1, 2);
	if (temp == 1) {
		return true;
	}
	else {
		return false;
	}
}
void xep(svtn a[], int n,int temp) {
	if (temp == 1) {
		cout << "ban muon xap xep tang hay giam ?" << endl;
		cout << "1. tang \t 2.giam" << endl;
		int t;
		cin >> t;
		dk1(t, 1, 2);
		if (t == 1) {
			for (int i = 0; i < n; i++) {
				if (a[i].ns > a[i + 1].ns) {
					svtn b = a[i];
					a[i] = a[i + 1];
					a[i + 1] = b;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (a[i].ns < a[i + 1].ns) {
					svtn b = a[i];
					a[i] = a[i + 1];
					a[i + 1] = b;
				}
			}
		}
	}
	else{
		cout << "ban muon xap xep tang hay giam ?" << endl;
		cout << "1. tang \t 2.giam" << endl;
		int t;
		cin >> t;
		dk1(t, 1, 2);
		if (t == 1) {
			for (int i = 0; i < n; i++) {
				if (a[i].diemtb > a[i + 1].diemtb) {
					svtn b = a[i];
					a[i] = a[i + 1];
					a[i + 1] = b;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (a[i].masv < a[i + 1].masv) {
					svtn b = a[i];
					a[i] = a[i + 1];
					a[i + 1] = b;
				}
			}
		}
	}
}
void xet(int choice,svtn a[],int &n) {
	switch(choice) {
	case 1: {
		nhapall(a,n);
		break;
	}
	case 2: {
		//tao lua chon moi cho nguoi dung
		int temp;
		cout << "ban muon tim kiem sinh vien theo cach nao ?" << endl;
		cout << "1.theo ho va ten\t2.theo ma sinh vien\t3.theo so thu tu" << endl;
		cin >> temp;
		while (!cin || temp < 0 || temp>3) {
			cout << "vui long chon 1 trong cac lua chon ben tren , dung nhap linh tinh" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> temp;
		}
		switch (temp) {
		case 1: {
			cin.ignore();
			string timten;
			cout << "vui long nhap day du ho ten sinh vien can tim" << endl;
			getline(cin, timten);
				for (int i = 0; i < n; i++) {
					if (a[i].ten== timten) {
					cout << a[i];
					}
					if (i == n-1&& a[i].ten != timten) { cout << "khong co ten sv nay trong danh sach " << endl; }
				}
				break;
			}
		case 2: {
			cin.ignore();
			string timma;
			cout << "vui long nhap ma sinh vien can tim" << endl;
			getline(cin, timma);
			for (int i = 0; i < n; i++) {
				if (a[i].masv == timma) {
					cout << a[i];
				}if (i == n - 1 && a[i].masv != timma) { cout << "khong co ma sv nay trong danh sach " << endl; }
			}
			break;
			
		}
		case 3: {
			cin.ignore();
			int stt;
			cout << "vui long nhap so thu tu sinh vien can tim" << endl;
			cin >> stt;
			dk2(stt, 1, n);
			cout << a[stt];
		}break;
		}
		break;

	}
	case 3: {
		int t;
		cout << "nhap so luong sinh vien can them " << endl;
		cin >> t;
		while (!cin || t < 0) {
			cout << "luong sinh vien can them phai >0 , vui long nhap lai" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> t;
		}
		for (int i = 0; i < t; i++) {
			themsv(a, n);
		}
		break;
	}
	case 4:{
		int t;
		cout << "nhap vi tri ban muon sua thong tin sinh vien (ban nen su dung cong cu tim kiem de tim den sinh vien can sua) " << endl;
		cin >> t;
		while (!cin || t < 0) {
			cout << "stt sinh vien can sua phai >0 , vui long nhap lai : " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> t;
		}
		a[t].nhap();
		cin >> a[t];
		break;
	}
	case 5: {
		int t;
		cout << "vui long nhap vi tri sinh vien can xoa : (nen tim kiem sinh vien truoc khi chon muc nay )";
		cin >> t;
		while (!cin || t < 0) {
			cout << "stt sinh vien can sua phai >0 , vui long nhap lai : " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> t;
			}
		xoa(a, n, t);
		break;
		}
	case 6: {
		xuatall(a, n);
		break;
	}
	case 7: {
		int temp;
		cout << "ban muon xap xep danh sach sv nhu nao? " << endl;
		cout << "1.theo ma sinh vien\t2.theo diem trung binh" << endl;
		cin >> temp;
		dk1(temp, 1, 2);
		xep(a,n,temp);
	}
	}
}
void menu(svtn a[], int& n) {
	int choice;
	cout << "_____________________________________________________________" << endl;
	cout << "chao mung ban den voi ung dung quan ly thi sinh tot nghiep " << endl;
	cout << "ban can gi o chung toi ( an phim theo chi dinh ben duoi )" << endl;
	cout << "1.nhap lai toan bo thong tin sinh vien"<<setw(30)<<"2.tra cuu sinh vien" << setw(30) << "3.them sinh vien " << endl;
	cout << "4.sua thong tin sinh vien" << setw(30) << "5.xoa sinh vien" << setw(30) << "6.hien toan bo danh sach sinh vien" << endl;
	cout << "7.xap xep danh sach sinh vien" << setw(30) << "t0.de dung chuong trinh" << endl;
	cout << "_____________________________________________________________" << endl;
	cin >> choice;
	dk2(choice, 0, 7);
	xet(choice,a,n);
	if (tiep()) {
		menu(a, n);
	}
}