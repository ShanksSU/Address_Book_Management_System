#include <iostream>
using namespace std;

void menuprint() {
	cout << "*****************************" << endl;
	cout << "******* " << "1. �K�[�p���H" << " *******" << endl;
	cout << "******* " << "2. ����p���H" << " *******" << endl;
	cout << "******* " << "3. �R���p���H" << " *******" << endl;
	cout << "******* " << "4. �d���p���H" << " *******" << endl;
	cout << "******* " << "5. �ק��p���H" << " *******" << endl;
	cout << "******* " << "6. �M���p���H" << " *******" << endl;
	cout << "******* " << "0. �����q�T��" << " *******" << endl;
	cout << "*****************************" << endl;
}

//�p���H���c��
struct person {
	string m_name;
	string m_sex;
	int m_age;
	int m_number;
	string m_addr;
};

//�q�T�����c��
#define MAX 1000
struct address_book {
	struct person personArray[MAX];
	int personsize;
};

//1. �K�[�p���H
void addperson(address_book* abs) {
	if (abs->personsize > MAX) {
		cout << "�H�Ƥw���L�k�A�K�[�p���H" << endl;
		return;
	} else {
		//�W��
		string name;
		cout << "�п�J�p���H�W�١G" << endl;
		cin >> name;
		abs->personArray[abs->personsize].m_name = name;

		//�ʧO
		string sex;
		cout << "�п�J�p���H�ʧO(�k|�k)�G" << endl;
		cin >> sex;
		abs->personArray[abs->personsize].m_sex = sex;

		//�~��
		int age;
		cout << "�п�J�p���H�~�֡G" << endl;
		cin >> age;
		abs->personArray[abs->personsize].m_age = age;

		//�q�ܸ��X
		int number;
		cout << "�п�J�p���H�q�ܡG" << endl;
		cin >> number;
		abs->personArray[abs->personsize].m_number = number;
	
		//�a�}
		string addr;
		cout << "�п�J�p���H�a�}�G" << endl;
		cin >> addr;
		abs->personArray[abs->personsize].m_addr = addr;
		abs->personsize++;
		cout << "�K�[���\" << endl;
		system("PAUSE");
		system("cls");
	}
}

//2. ����p���H
void showperson(address_book *abs) {
	if (abs->personsize == NULL) {
		cout << "�q�T���S�H��" << endl;
	} else {
		for (int i = 0; i < abs->personsize; i++) {
			cout << "�m�W�G" << abs->personArray[i].m_name << endl;
			cout << "�ʧO�G" << abs->personArray[i].m_sex << endl;
			cout << "�~�֡G" << abs->personArray[i].m_age << endl;
			cout << "�q�ܡG" << abs->personArray[i].m_number << endl;
			cout << "�a�}�G" << abs->personArray[i].m_addr << endl;
			cout << "====================================" << endl;
		}
	}
	system("PAUSE");
	system("cls");
}

//3. �R���p���H
void delperson(address_book* abs, string delname) {
	int peo = 0;
	for (int i = 0; i < abs->personsize; i++) {
		if (abs->personArray[i].m_name == delname) {
			cout << "�w�R���p���H" << endl;
			abs->personArray[i] = abs->personArray[i + 1];
			abs->personsize--;
			peo++;
		}
	}

	if (abs->personsize == NULL) {
		cout << "�q�T���S�H��" << endl;
	}else if (peo == 0) {
		cout << "�d�L�p���H" << endl;
	}
	system("PAUSE");
	system("cls");
}

//4. �d���p���H
void inquireperson(address_book* abs, string inquirename) {
	int peo = 0;
	for (int i = 0; i < abs->personsize; i++) {
		if (abs->personArray[i].m_name == inquirename) {
			cout << "�w�d���p���H" << endl;
			cout << "�m�W�G" << abs->personArray[i].m_name << endl;
			cout << "�ʧO�G" << abs->personArray[i].m_sex << endl;
			cout << "�~�֡G" << abs->personArray[i].m_age << endl;
			cout << "�q�ܡG" << abs->personArray[i].m_number << endl;
			cout << "�a�}�G" << abs->personArray[i].m_addr << endl;
			peo = 1;
		}
	}

	if (abs->personsize == NULL) {
		cout << "�q�T���S�H��" << endl;
	}else if (peo == 0) {
		cout << "�d�L�p���H" << endl;
	}
	system("PAUSE");
	system("cls");
}

//5. �ק��p���H
void editperson(address_book* abs, string editname) {
	int peo = 0;
	for (int i = 0; i < abs->personsize; i++) {
		if (abs->personArray[i].m_name == editname) {
			//�W��
			string name;
			cout << "�п�J�p���H�W�١G" << endl;
			cin >> name;
			abs->personArray[i].m_name = name;

			//�ʧO
			string sex;
			cout << "�п�J�p���H�ʧO(�k|�k)�G" << endl;
			cin >> sex;
			abs->personArray[i].m_sex = sex;

			//�~��
			int age;
			cout << "�п�J�p���H�~�֡G" << endl;
			cin >> age;
			abs->personArray[i].m_age = age;

			//�q�ܸ��X
			int number;
			cout << "�п�J�p���H�q�ܡG" << endl;
			cin >> number;
			abs->personArray[i].m_number = number;

			//�a�}
			string addr;
			cout << "�п�J�p���H�a�}�G" << endl;
			cin >> addr;
			abs->personArray[i].m_addr = addr;
		}
	}

	if (abs->personsize == NULL) {
		cout << "�q�T���S�H��" << endl;
	} else if (peo == 0) {
		cout << "�d�L�p���H" << endl;
	}
	system("PAUSE");
	system("cls");
}

//6. �M���p���H
void delallperson(address_book *abs) {
	abs->personsize = 0;
	cout << "�w�R���Ҧ��p���H" << endl;
	system("PAUSE");
	system("cls");
}


int main() {
	int select = 0;

	address_book abs;
	abs.personsize = 0;

	while (true) {
		menuprint();
		cout << "�п�J�N���G";
		cin >> select;
		switch (select) {

		case 1://�K�[�p���H
			addperson(&abs);
			break;

		case 2://����p���H
			showperson(&abs);
			break;

		case 3://�R���p���H
		{
			string delname;
			cout << "�п�J�n�R�����p���H�m�W" << endl;
			cin >> delname;
			delperson(&abs, delname);
			break;
		}
		case 4://�d���p���H
		{
			string inquirename;
			cout << "�п�J�n�d�ߤ��p���H�m�W" << endl;
			cin >> inquirename;
			inquireperson(&abs, inquirename);
			break;
		}
		case 5://�ק��p���H
		{
			string editname;
			cout << "�п�J�n�ק蠟�p���H�m�W" << endl;
			cin >> editname;
			editperson(&abs, editname);
			break;
		}
		case 6://�M���p���H
		{
			string check;
			cout << "�u���n�M�Ŷ�?(Y/N)�G";
			cin >> check;
			if (check == "y") {
				delallperson(&abs);
			}
			break;
		}
		case 0://�����q�T��
			cout << "�w��U���ϥ�" << endl;
			return 0;
			break;

		default:
			cout << "�u�r! �X���F" << endl;
			system("PAUSE");
			system("cls");
			break;
		}
	}

	return 0;
}

/*
����
�k
18
098178
�x�n

����
�k
15
09877777
�x�F

�Ѥ�
�k
22
09871515
�x�_

*/