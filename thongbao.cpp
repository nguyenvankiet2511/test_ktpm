//thêm dòng mới
#include<iostream>
#include<string>
using  namespace std;
//1
void init_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]="; cin >> arr[i];
	}
}
void display(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void check_del(int arr_n[], int &n, int k)
{
	n = n - 1;
	for (int i = k; i < n; i++)
	{
		arr_n[i] = arr_n[i + 1];
	}
}
int min2so(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else return b;
}
int ucln2so(int a, int b)
{
	int min = min2so(a, b);
	while(min>=1)
	{
		if ((a % min == 0) && (b % min == 0))
		{
			return min;
			break;
		}
		--min;
	}
}
void BCNN_arr(int arr[], int n)
{
	int max = INT_MIN;
	int min = INT_MAX;
	int i = 0;
	while (i<n)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	cout << "phan tu lon nhat trong mang la: " << max << endl;
	cout << "phan tu nho nhat trong mang la: " << min << endl;
	cout << "BCNN cua phan tu lon nhat va nho nhat la: " << (min*max) / ucln2so(min, max) << endl;
	
}
//2
int cau2(string chuoi, char kytu)
{
	int i = 0;
	int dem = 0;
	while (i < chuoi.length())
	{
		if (chuoi[i] == kytu)
		{
			dem++;
		}
		i++;
	}
	return dem;
}
//3
void cau3()
{
	int a, b;
	cout << "nhap toa do cua x: "; cin >> a >> b;
	while (a < 0 || b < 0 || a>5 || b>5)
	{
		cout << "loi gia tri, nhap lai\n";
		cout << "nhap toa do cua x: "; cin >> a >> b;
	}
	for (int i = 5; i >= 0; i--)
	{
		for (int j = 0; j <= 5; j++)
		{
			if (a == i && b == j)
			{
				cout << "x";
			}
			else cout << " ";
		}
		cout << endl;
	}
}
int main()
{
	int lc;
	bool check = true;
	while (check)
	{
		cout << "  ===menu===\n";
		cout << "1.cau 1\n";
		cout << "2.cau 2\n";
		cout << "3.cau 3\n";
		cout << "nhap ki tu bat ky de thoat chuong trinh\n";
		cout << endl;
		cout << "nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			const int MAX = 100;
			int arr[MAX];
			int m;
			cout << "nhap so phan tu cua mang: "; cin >> m;
			while (m<2 || m>MAX)
			{
				cout << "loi gia tri, nhap lai\n";
				cout << "nhap so phan tu cua mang: "; cin >> m;
			}
			init_arr(arr, m);
			cout << "mang sau khi tao la: \n";
			display(arr, m);
			BCNN_arr(arr, m);
			int k;
			cout << "nhap vao vi tri can xoa: "; cin >> k;
			while (k<0 || k>(MAX-1))
			{
				cout << "loi gia tri, nhap lai\n";
				cout << "nhap vao vi tri can xoa: "; cin >> k;
			}
			cout << "mang sau khi xoa tai vi tri " << k << " la: \n";
			check_del(arr, m, k);
			display(arr, m);
			break;
		}
		case 2:
		{
			string chuoi;
			cout << "nhap vao mang ki tu: ";
			cin.ignore();
			getline(cin, chuoi);
			char kytu;
			cout << "nhap vao ki tu can tim: "; cin >> kytu;
			int dem = cau2(chuoi, kytu);
			cout << "so lan xuat hien cua ky tu " << kytu << " la: " << dem << endl;
			break;
		}
		case 3:
		{
			cau3();
			break;
		}
		default: check = false;
		}
	}
	system("pause");
	return 0;
}