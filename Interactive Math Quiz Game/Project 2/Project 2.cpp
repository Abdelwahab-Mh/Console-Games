#include <iostream>
#include <string>
using namespace std;
enum enLevel { Easy = 1, Med = 2, Hard = 3 , Mix=4 };
enum enType { Add = 1, Sub = 2, Mul = 3 , Div = 4 , Mix2 = 5 };
int RandomNum(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}

int ReadNumQues()
{
	int N;
	cout << "How Many Question you want to ansower ?  ";
	cin >> N;
	return N;
}

int QuesLevel(int NumLevel)
{
	int Num;
	if (NumLevel == enLevel::Mix)
	{
		NumLevel = RandomNum(1, 3);
	}
	switch (NumLevel)
	{
		case enLevel::Easy:
			Num = RandomNum(1, 20);
			break;
		case enLevel::Med:
			Num = RandomNum(1, 50);
			break;
		case enLevel::Hard:
			Num = RandomNum(1, 100);
			break;
		default :
			break;
	}
	return Num;
}

void checkResult(int result,int & Counter)
{
	int N;
	cin >> N;
	if (N == result)
	{
		cout << "Right Answer :-)" << endl;
		system("color 2F");
		Counter++;
	}
	else
	{
		cout << "Wrong Answer :-(" << endl;
		cout << "The Right Answer is: "<< result << endl;
		system("color 4F");

	}
}

int QuesType(int NumType,int NumLevel)
{
	int Num1 = QuesLevel(NumLevel);
	int Num2 = QuesLevel(NumLevel);
	int result;
	if (NumType == enType::Mix2)
	{
		NumType = RandomNum(1, 4);
	}
	switch (NumType)
	{
	case enType::Add:
		cout << Num1 << "\n" << Num2<< "+" << endl;
		cout << "---------" << endl;
		result=Num1 + Num2;
		break;
	case enType::Sub:
		cout << Num1 << "\n" << Num2 << "-" << endl;
		cout << "---------" << endl;
		result=Num1 - Num2;
		break;
	case enType::Mul:
		cout << Num1 << "\n" << Num2 << "*" << endl;
		cout << "---------" << endl;
		result=Num1 * Num2;
		break;
	case enType::Div:
		cout << Num1 << "\n" << Num2 << "/" << endl;
		cout << "---------" << endl;
		result=Num1 / Num2;
		break;
	default:
		break;
	}
	return result;
}

string SelectQuesLevel(int NumLevel)
{
	switch (NumLevel)
	{
	case 1:
		return "Easy";
	case 2:
		return "Med";
	case 3:
		return "Hard";
	case 4:
		return "Mix";
	}
}

string SelectQuesType(int NumType)
{
	switch (NumType)
	{
	case 1:
		return "Add";
	case 2:
		return "Sub";
	case 3:
		return "Mul";
	case 4:
		return "Div";
	case 5:
		return "Mix";
	}
}

void StartGame(int N)
{
	int NumQusLevel, NumQusType,Counter=0;
	char PlayAgan = 'Y';
	while(PlayAgan=='Y' || PlayAgan=='y')
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?  ";
		cin >> NumQusLevel;
		cout << "Enter Questions Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?  ";
		cin >> NumQusType;
		while (!((NumQusLevel > 0 && NumQusLevel <= 4) && (NumQusType > 0 && NumQusType <= 5)))
		{
			cout << "Invalid Number !!" << endl;
			cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?  ";
			cin >> NumQusLevel;
			cout << "Enter Questions Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?  ";
			cin >> NumQusType;
		}
		for (int i = 1; i <= N; i++)
		{
			cout << "Question [" << i << "/" << N << "]" << endl;
			checkResult(QuesType(NumQusType, NumQusLevel), Counter);
		}
		cout << "--------------------------" << endl;
		if (Counter>(N-Counter))
		{
			cout << "Final Resultls is Pass :-)" << endl;
			system("color 2F");
		}
		else
		{
			cout << "Final Resultls is Faild :-(" << endl;
			system("color 4F");
		}
		cout << "--------------------------" << endl;

		cout << "Number Of Questions: "<<N << endl;
		cout << "Questions Level    : "<< SelectQuesLevel(NumQusLevel) << endl;
		cout << "Questions Type     : " << SelectQuesType(NumQusType) << endl;
		cout << "Number Right Questions  : "<<Counter << endl;
		cout << "Number Wrong Questions  : " <<N-Counter<< endl;
		cout << "--------------------------\n" << endl;
		cout << "Do you want play agan ? Y/N ?";
		cin >> PlayAgan;
		if (PlayAgan == 'Y' || PlayAgan == 'y')
		{
			system("cls");
			Counter = 0;
		}
			

	}
}
int main()
{
	srand((unsigned)time(NULL));
	StartGame(ReadNumQues());
}