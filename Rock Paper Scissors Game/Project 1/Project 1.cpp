#include <iostream>
#include <string>
using namespace std;
enum enChoose { Stone = 1, Paper = 2 ,Scissors = 3 };
int PrintRandomNum(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
void ResultComputer(int ChooseOfComputer)
{
	if (ChooseOfComputer == enChoose::Stone)
	{
		cout << "Computer Choose: Stone" << endl;
	}
	else if (ChooseOfComputer == enChoose::Paper)
	{
		cout << "Computer Choose: Paper" << endl;
	}
	else if (ChooseOfComputer == enChoose::Scissors)
	{
		cout << "Computer Choose: Scissors" << endl;
	}
}
void ResultPlayer(int ChooseOfPlayer)
{
	if (ChooseOfPlayer ==enChoose::Stone)
	{
		cout << "Player Choose: Stone" << endl;
	}
	else if (ChooseOfPlayer == enChoose::Paper)
	{
		cout << "Player Choose: Paper" << endl;
	}
	else if (ChooseOfPlayer == enChoose::Scissors)
	{
		cout << "Player Choose: Scissors" << endl;
	}
}

int ReadRoundNum(string S)
{
	int Num;
	cout << S << endl;
	cin >> Num;
	return Num;
}

void CheckWin(int ChooseOfPlayer,int ChooseOfComputer,int &CountPlayer,int &CountComputer,int &CountDrow)
{
	if (ChooseOfPlayer == ChooseOfComputer)
	{
		cout << "Round Winner: [No Winner]" << endl;
		CountDrow++;
		system("color 6");
	}
	else if (ChooseOfPlayer==enChoose::Paper && ChooseOfComputer==enChoose::Stone)
	{
		cout << "Round Winner: [Player Winner]" << endl;
		CountPlayer++;
		system("color 2");
	}
	else if (ChooseOfPlayer == enChoose::Paper && ChooseOfComputer == enChoose::Scissors)
	{
		cout << "Round Winner: [Computer Winner]" << endl;
		CountComputer++;
		system("color 4");
		cout << "\a";
	}
	else if (ChooseOfPlayer == enChoose::Stone && ChooseOfComputer == enChoose::Scissors)
	{
		cout << "Round Winner: [Player Winner]" << endl;
		CountPlayer++;
		system("color 2");
	}
	else if (ChooseOfPlayer == enChoose::Stone && ChooseOfComputer == enChoose::Paper)
	{
		cout << "Round Winner: [Computer Winner]" << endl;
		CountComputer++;
		system("color 4");
		cout << "\a";
	}
	else if (ChooseOfPlayer == enChoose::Scissors && ChooseOfComputer == enChoose::Paper)
	{
		cout << "Round Winner: [Player Winner]" << endl;
		CountPlayer++;
		system("color 2");
	}
	else if (ChooseOfPlayer == enChoose::Scissors && ChooseOfComputer == enChoose::Stone)
	{
		cout << "Round Winner: [Computer Winner]" << endl;
		CountComputer++;
		system("color 4");
		cout << "\a";
	}
}

void Game(int NumOfRound)
{
	int ChoosePlyar , ChooseComputer,CountPlayer=0,CountComputer=0, CountDrow=0;
	for (int i=1;i<=NumOfRound;i++)
	{
		cout << "Round [" << i << "]" << "begin"<<endl;
		cout << "Your Choos: [1]:Stone [2]:Paper [3]:Scissors ?";
		cin >> ChoosePlyar;
		while (ChoosePlyar < 1 || ChoosePlyar > 3)
		{
			cout << "Invalid choice, enter 1-3: ";
			cin >> ChoosePlyar;
		}

		cout << "_____________Round [" << i << "]" << endl;
		ResultPlayer(ChoosePlyar);
		ChooseComputer = PrintRandomNum(1, 3);
		ResultComputer(ChooseComputer);
		CheckWin(ChoosePlyar, ChooseComputer, CountPlayer, CountComputer, CountDrow);
		cout << "______________________" << endl;
    }
	cout << "_________[Game Results]__________" << endl;
	cout << "Game Round            :"<< NumOfRound << endl;
	cout << "Player Won            :"<< CountPlayer << endl;
	cout << "Computer Won          :"<< CountComputer << endl;
	cout << "Drow Times            :"<< CountDrow << endl;
	if (CountPlayer> CountComputer)
	{
		cout << "Game Winner: [Player Winner]" << endl;
		system("color 2");
	}
	else if (CountPlayer < CountComputer)
	{
		cout << "Game Winner: [Computer Winner]" << endl;
		system("color 4");
		cout << "\a";
	}else
	{ 
		cout << "Round Winner: [No Winner]" << endl;
		system("color 6");
	}
	cout << "_________________________________" << endl;
	cout << "Do You want to play agan ? Y/N ?";
	char Cont;
	cin >> Cont;
	if (Cont == 'Y' || Cont == 'y')
	{
		system("color 0");
		system("cls");
		Game(ReadRoundNum("Please Enter Number Of Round: "));
	}
	else if (Cont == 'N' || Cont == 'n')
	{}
}
int main()
{
	srand((unsigned)time(NULL));
	Game(ReadRoundNum("Please Enter Number Of Round: "));
}