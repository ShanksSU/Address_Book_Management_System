#include <iostream>
using namespace std;

void menuprint() {
	cout << "*****************************" << endl;
	cout << "******* " << "1. 添加聯絡人" << " *******" << endl;
	cout << "******* " << "2. 顯示聯絡人" << " *******" << endl;
	cout << "******* " << "3. 刪除聯絡人" << " *******" << endl;
	cout << "******* " << "4. 查找聯絡人" << " *******" << endl;
	cout << "******* " << "5. 修改聯絡人" << " *******" << endl;
	cout << "******* " << "6. 清空聯絡人" << " *******" << endl;
	cout << "******* " << "0. 關閉通訊錄" << " *******" << endl;
	cout << "*****************************" << endl;
}

//聯絡人結構體
struct person {
	string m_name;
	string m_sex;
	int m_age;
	int m_number;
	string m_addr;
};

//通訊錄結構體
#define MAX 1000
struct address_book {
	struct person personArray[MAX];
	int personsize;
};

//1. 添加聯絡人
void addperson(address_book* abs) {
	if (abs->personsize > MAX) {
		cout << "人數已滿無法再添加聯絡人" << endl;
		return;
	} else {
		//名稱
		string name;
		cout << "請輸入聯絡人名稱：" << endl;
		cin >> name;
		abs->personArray[abs->personsize].m_name = name;

		//性別
		string sex;
		cout << "請輸入聯絡人性別(男|女)：" << endl;
		cin >> sex;
		abs->personArray[abs->personsize].m_sex = sex;

		//年齡
		int age;
		cout << "請輸入聯絡人年齡：" << endl;
		cin >> age;
		abs->personArray[abs->personsize].m_age = age;

		//電話號碼
		int number;
		cout << "請輸入聯絡人電話：" << endl;
		cin >> number;
		abs->personArray[abs->personsize].m_number = number;
	
		//地址
		string addr;
		cout << "請輸入聯絡人地址：" << endl;
		cin >> addr;
		abs->personArray[abs->personsize].m_addr = addr;
		abs->personsize++;
		cout << "添加成功" << endl;
		system("PAUSE");
		system("cls");
	}
}

//2. 顯示聯絡人
void showperson(address_book *abs) {
	if (abs->personsize == NULL) {
		cout << "通訊錄沒人喔" << endl;
	} else {
		for (int i = 0; i < abs->personsize; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << endl;
			cout << "性別：" << abs->personArray[i].m_sex << endl;
			cout << "年齡：" << abs->personArray[i].m_age << endl;
			cout << "電話：" << abs->personArray[i].m_number << endl;
			cout << "地址：" << abs->personArray[i].m_addr << endl;
			cout << "====================================" << endl;
		}
	}
	system("PAUSE");
	system("cls");
}

//3. 刪除聯絡人
void delperson(address_book* abs, string delname) {
	int peo = 0;
	for (int i = 0; i < abs->personsize; i++) {
		if (abs->personArray[i].m_name == delname) {
			cout << "已刪除聯絡人" << endl;
			abs->personArray[i] = abs->personArray[i + 1];
			abs->personsize--;
			peo++;
		}
	}

	if (abs->personsize == NULL) {
		cout << "通訊錄沒人喔" << endl;
	}else if (peo == 0) {
		cout << "查無聯絡人" << endl;
	}
	system("PAUSE");
	system("cls");
}

//4. 查找聯絡人
void inquireperson(address_book* abs, string inquirename) {
	int peo = 0;
	for (int i = 0; i < abs->personsize; i++) {
		if (abs->personArray[i].m_name == inquirename) {
			cout << "已查詢聯絡人" << endl;
			cout << "姓名：" << abs->personArray[i].m_name << endl;
			cout << "性別：" << abs->personArray[i].m_sex << endl;
			cout << "年齡：" << abs->personArray[i].m_age << endl;
			cout << "電話：" << abs->personArray[i].m_number << endl;
			cout << "地址：" << abs->personArray[i].m_addr << endl;
			peo = 1;
		}
	}

	if (abs->personsize == NULL) {
		cout << "通訊錄沒人喔" << endl;
	}else if (peo == 0) {
		cout << "查無聯絡人" << endl;
	}
	system("PAUSE");
	system("cls");
}

//5. 修改聯絡人
void editperson(address_book* abs, string editname) {
	int peo = 0;
	for (int i = 0; i < abs->personsize; i++) {
		if (abs->personArray[i].m_name == editname) {
			//名稱
			string name;
			cout << "請輸入聯絡人名稱：" << endl;
			cin >> name;
			abs->personArray[i].m_name = name;

			//性別
			string sex;
			cout << "請輸入聯絡人性別(男|女)：" << endl;
			cin >> sex;
			abs->personArray[i].m_sex = sex;

			//年齡
			int age;
			cout << "請輸入聯絡人年齡：" << endl;
			cin >> age;
			abs->personArray[i].m_age = age;

			//電話號碼
			int number;
			cout << "請輸入聯絡人電話：" << endl;
			cin >> number;
			abs->personArray[i].m_number = number;

			//地址
			string addr;
			cout << "請輸入聯絡人地址：" << endl;
			cin >> addr;
			abs->personArray[i].m_addr = addr;
		}
	}

	if (abs->personsize == NULL) {
		cout << "通訊錄沒人喔" << endl;
	} else if (peo == 0) {
		cout << "查無聯絡人" << endl;
	}
	system("PAUSE");
	system("cls");
}

//6. 清空聯絡人
void delallperson(address_book *abs) {
	abs->personsize = 0;
	cout << "已刪除所有聯絡人" << endl;
	system("PAUSE");
	system("cls");
}


int main() {
	int select = 0;

	address_book abs;
	abs.personsize = 0;

	while (true) {
		menuprint();
		cout << "請輸入代號：";
		cin >> select;
		switch (select) {

		case 1://添加聯絡人
			addperson(&abs);
			break;

		case 2://顯示聯絡人
			showperson(&abs);
			break;

		case 3://刪除聯絡人
		{
			string delname;
			cout << "請輸入要刪除之聯絡人姓名" << endl;
			cin >> delname;
			delperson(&abs, delname);
			break;
		}
		case 4://查找聯絡人
		{
			string inquirename;
			cout << "請輸入要查詢之聯絡人姓名" << endl;
			cin >> inquirename;
			inquireperson(&abs, inquirename);
			break;
		}
		case 5://修改聯絡人
		{
			string editname;
			cout << "請輸入要修改之聯絡人姓名" << endl;
			cin >> editname;
			editperson(&abs, editname);
			break;
		}
		case 6://清空聯絡人
		{
			string check;
			cout << "真的要清空嗎?(Y/N)：";
			cin >> check;
			if (check == "y") {
				delallperson(&abs);
			}
			break;
		}
		case 0://關閉通訊錄
			cout << "歡迎下次使用" << endl;
			return 0;
			break;

		default:
			cout << "哎呀! 出錯了" << endl;
			system("PAUSE");
			system("cls");
			break;
		}
	}

	return 0;
}

/*
阿貓
女
18
098178
台南

阿花
男
15
09877777
台東

老王
男
22
09871515
台北

*/