#include"Header.h"
int main() {
	int n;
	cout << "so luon sinh vien can nhap la : ";
	cin >> n;
	while (!cin || n < 1) {
		cout << "so luon sinh vien phai la so tu nhien >0 vui long nhap lai : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> n;
	}
	//khoi tao mang de phong them nhieu phan tu :v
	svtn* a = new svtn[n + 1000];
	nhapall(a, n);
	menu(a, n);
	xuatall(a, n);
	system("pause");
	return 69;
}