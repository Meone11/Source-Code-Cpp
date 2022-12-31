#include <iostream>
using namespace std;

int pangkat(int x, int y){
	if ( y == 0 ) {
		return 1;
	}else if (y == 1){
		return x;
	}else {
		return x*pangkat(x,y-1);
	}
}

int main(){
	int a, n;
	cout << "Input Angka : "; cin >> a;
	cout << "Input Pangkat : "; cin >> n;
	cout << "Hasilnya : " << pangkat(a, n) <<endl;
}