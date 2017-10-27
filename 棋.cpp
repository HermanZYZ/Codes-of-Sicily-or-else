#include<iostream>
#include<cstdlib>
#include<windows.h> 
#include<cstring>

using namespace std;

/******************************** 
		������ʵ�ֹ��ܣ� 
1��������Ĺ��캯���Ϳ������캯��
2������������Ƿ�����һ����ʤ
3������һ�����������̵�ĳ��
4����ӡ����ȫ��
5����������ĳ�������� 
********************************/ 

class Board
{
private:
	int book[4][4];
public:
	Board();
	Board(Board &newBoard);
	~Board();
	bool judge(int k);
	void setChessPieces(int x, int y, int chess);
	void printChessBoard();
	int getBoard(int i, int j) { return book[i][j]; }
};

//�޲εĹ��캯�� 
Board::Board()
{
	int i, j;
	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			book[i][j] = -1;
}

//�������캯�� 
Board::Board(Board &newBoard)
{
	int i, j;
	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			book[i][j] = newBoard.getBoard(i, j);
}

Board::~Board()
{
	int i, j;
	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			book[i][j] = -1;
}

//����������Ƿ�����һ����ʤ
bool Board::judge(int k)
{
	if (book[1][1] == k && book[1][2] == k && book[1][3] == k) return true;
	if (book[2][1] == k && book[2][2] == k && book[2][3] == k) return true;
	if (book[3][1] == k && book[3][2] == k && book[3][3] == k) return true;

	if (book[1][1] == k && book[2][1] == k && book[3][1] == k) return true;
	if (book[1][2] == k && book[2][2] == k && book[3][2] == k) return true;
	if (book[1][3] == k && book[2][3] == k && book[3][3] == k) return true;

	if (book[1][1] == k && book[2][2] == k && book[3][3] == k) return true;
	if (book[3][1] == k && book[2][2] == k && book[1][3] == k) return true;
	return false;
}

//����һ�����������̵�ĳ��
void Board::setChessPieces(int x, int y, int chess)
{
	book[x][y] = chess;
}

//��ӡ����ȫ�� 
void Board::printChessBoard()
{ 
	system("cls"); 
	int i, j;
	cout << " ";
	if (book[1][1] == 1) cout << 'X';
	else if (book[1][1] == 0) cout << 'O';
	else cout << " ";
	cout << " |";

	cout << " ";
	if (book[1][2] == 1) cout << 'X';
	else if (book[1][2] == 0) cout << 'O';
	else cout << " ";
	cout << " |";

	cout << " ";
	if (book[1][3] == 1) cout << 'X';
	else if (book[1][3] == 0) cout << 'O';
	else cout << " ";
	cout << endl;

	for (j = 0; j <= 10; j++) cout << '-';
	cout << endl;

	cout << " ";
	if (book[2][1] == 1) cout << 'X';
	else if (book[2][1] == 0) cout << 'O';
	else cout << " ";
	cout << " |";

	cout << " ";
	if (book[2][2] == 1) cout << 'X';
	else if (book[2][2] == 0) cout << 'O';
	else cout << " ";
	cout << " |";

	cout << " ";
	if (book[2][3] == 1) cout << 'X';
	else if (book[2][3] == 0) cout << 'O';
	else cout << " ";
	cout << endl;

	for (j = 0; j <= 10; j++) cout << '-';
	cout << endl;

	cout << " ";
	if (book[3][1] == 1) cout << 'X';
	else if (book[3][1] == 0) cout << 'O';
	else cout << " ";
	cout << " |";

	cout << " ";
	if (book[3][2] == 1) cout << 'X';
	else if (book[3][2] == 0) cout << 'O';
	else cout << " ";
	cout << " |";

	cout << " ";
	if (book[3][3] == 1) cout << 'X';
	else if (book[3][3] == 0) cout << 'O';
	else cout << " ";
	cout << endl;

	cout << endl;
}

/******************************** 
		Player��ʵ�ֹ��ܣ� 
1��ʵ�־�����İ����������� 
������win,block,fork,bolck opponent's fork, 
3��
4��
 
********************************/ 

class Player
{
private:
	const string name = "pjr";
	
	bool win(Board &newBoard);
	bool block(Board &newBoard);
	bool fork(Board &newBoard);
	bool blockingFork(Board &newBoard);
	bool center(Board &newBoard);
	bool oppositeCorner(Board &newBoard);
	bool emptyCorner(Board &newBoard);
	bool emptySide(Board &newBoard);
public:
	void setChess(Board &newBoard)
	{
		if (win(newBoard) == true) return;
		else if (block(newBoard) == true) return;
		else if (fork(newBoard) == true) return;
		else if (blockingFork(newBoard) == true) return;
		else if (center(newBoard) == true) return;
		else if (oppositeCorner(newBoard) == true) return;
		else if (emptyCorner(newBoard) == true) return;
		else if (emptySide(newBoard) == true) return;
	}
	  
};

bool Player::win(Board &newBoard)
{
	//cout<<"win"<<endl; 
	int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (newBoard.getBoard(i, j) == -1)
			{
				newBoard.setChessPieces(i, j, 0);
				if (newBoard.judge(0) == true) return true;
				else newBoard.setChessPieces(i, j, -1);
			}
		}
	}
	return false;
}

bool Player::block(Board &newBoard)
{
	//cout<<"block"<<endl;
	int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (newBoard.getBoard(i, j) == -1)
			{
				newBoard.setChessPieces(i, j, 1);
				if (newBoard.judge(1) == true)
				{
					newBoard.setChessPieces(i, j, 0);
					return true;
				}
				else newBoard.setChessPieces(i, j, -1);
			}
		}
	}
	return false;
}

bool Player::fork(Board &newBoard)
{
	//cout<<"fork"<<endl;
	int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (newBoard.getBoard(i, j) == -1)
			{
				newBoard.setChessPieces(i, j, 0);

				int cnt = 0;
				Board tem(newBoard);
				for (int k = 1; k <= 3; k++)
				{
					for (int l = 1; l <= 3; l++)
					{
						if (tem.getBoard(k, l) == -1)
						{
							tem.setChessPieces(k, l, 0);
							if (tem.judge(0) == true)
								cnt++;
							tem.setChessPieces(k, l, -1);
						}
					}
				}

				if (cnt >= 2) return true;
				else newBoard.setChessPieces(i, j, -1);
			}
		}
	}
	return false;
}

bool Player::blockingFork(Board &newBoard)
{
	//cout<<"blockingFork"<<endl;
	int i, j;

	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (newBoard.getBoard(i, j) == -1)
			{
				newBoard.setChessPieces(i, j, 1);

				int cnt = 0;
				Board tem(newBoard);
				for (int k = 1; k <= 3; k++)
				{
					for (int l = 1; l <= 3; l++)
					{
						if (tem.getBoard(k, l) == -1)
						{
							tem.setChessPieces(k, l, 1);
							if (tem.judge(1) == true)
								cnt++;
							tem.setChessPieces(k, l, -1);
						}
					}
				}

				if (cnt >= 2)
				{
					newBoard.setChessPieces(i, j, 0);
					return true;
				}
				else newBoard.setChessPieces(i, j, -1);
			}
		}
	}

	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (newBoard.getBoard(i, j) == -1)
			{
				newBoard.setChessPieces(i, j, 0);

				int cnt = 0;
				Board tem(newBoard);
				for (int k = 1; k <= 3; k++)
				{
					for (int l = 1; l <= 3; l++)
					{
						if (tem.getBoard(k, l) == -1)
						{
							tem.setChessPieces(k, l, 0);
							if (tem.judge(0) == true)
								cnt++;
							tem.setChessPieces(k, l, -1);
						}
					}
				}

				if (cnt >= 1) return true;
				else newBoard.setChessPieces(i, j, -1);
			}
		}
	}

	return false;
}

bool Player::center(Board &newBoard)
{
	//cout<<"center"<<endl; 
	if (newBoard.getBoard(2, 2) == -1)
	{
		newBoard.setChessPieces(2, 2, 0);
		return true;
	}
	else return false;
}

bool Player::oppositeCorner(Board &newBoard)
{
	//cout<<"oppositeCorner"<<endl; 
	if (newBoard.getBoard(1, 1) == 1&&newBoard.getBoard(3, 3) == -1)
	{
		newBoard.setChessPieces(3, 3, 0);
		return true;
	}
	else if (newBoard.getBoard(1, 3) == 1&&newBoard.getBoard(3, 1) == -1)
	{
		newBoard.setChessPieces(3, 1, 0);
		return true;
	}
	else if (newBoard.getBoard(3, 1) == 1&&newBoard.getBoard(1, 3) == -1)
	{
		newBoard.setChessPieces(1, 3, 0);
		return true;
	}
	else if (newBoard.getBoard(3, 3) == 1&&newBoard.getBoard(1, 1) == -1)
	{
		newBoard.setChessPieces(1, 1, 0);
		return true;
	}
	return false;
}

bool Player::emptyCorner(Board &newBoard)
{
	//cout<<"emptyCorner"<<endl; 
	if (newBoard.getBoard(1, 1) == -1)
	{
		newBoard.setChessPieces(1, 1, 0);
		return true;
	}
	else if (newBoard.getBoard(1, 3) == -1)
	{
		newBoard.setChessPieces(1, 3, 0);
		return true;
	}
	else if (newBoard.getBoard(3, 1) == -1)
	{
		newBoard.setChessPieces(3, 1, 0);
		return true;
	}
	else if (newBoard.getBoard(3, 3) == -1)
	{
		newBoard.setChessPieces(3, 3, 0);
		return true;
	}
	return false;
}

bool Player::emptySide(Board &newBoard)
{
	cout<<"emptySide"<<endl; 
	if (newBoard.getBoard(1, 2) == -1)
	{
		newBoard.setChessPieces(1, 2, 0);
		return true;
	}
	else if (newBoard.getBoard(2, 1) == -1)
	{
		newBoard.setChessPieces(2, 1, 0);
		return true;
	}
	else if (newBoard.getBoard(2, 3) == -1)
	{
		newBoard.setChessPieces(2, 3, 0);
		return true;
	}
	else if (newBoard.getBoard(3, 2) == -1)
	{
		newBoard.setChessPieces(3, 2, 0);
		return true;
	}
	return false;
}


class PlayerHuman :public Player
{
private:
	string name;
public:
	void setChess(Board &newBoard,int k)
	{
		cout << "��������Ҫ���ӵ����꣺" << endl;
	line:
		int x, y;
		cin >> x >> y;

		if (x >= 1 && x <= 3 && newBoard.getBoard(x, y) == -1)
			newBoard.setChessPieces(x, y, k);
		else
		{
			cout << "����������겻�Ϸ������������룺" << endl;
			goto line;
		}
	}
	string getName(){return name;}
	friend ostream &operator<<(ostream &stream, PlayerHuman newPlayerHuman);
  	friend istream &operator>>(istream &stream, PlayerHuman &newPlayerHuman);
};

ostream &operator<<(ostream &os, PlayerHuman newPlayerHuman)
{
	os<<newPlayerHuman.name;
	return os;
}

istream &operator>>(istream &in, PlayerHuman &newPlayerHuman)
{
	in>>newPlayerHuman.name;
	return in;
}

class Game
{
private:
	void playerVsPlayer();
	void playerVsComputer(); 
	
	int res;
	int pattern;
	
public:
	void startGame();
	void process();
	void end();
	void reStartGame(); 
};

void Game::playerVsPlayer()
{
	PlayerHuman newPlayerHuman1,newPlayerHuman2;
	Board newBoard;
	
	cout<<"��˫�������Լ���������in English��"<<endl;
	
	cout<<"���1��";
	cin>>newPlayerHuman1;
	cout<<endl;
	
	cout<<"���2: ";
	cin>>newPlayerHuman2;
	cout<<endl; 
	
	if(strcmp(newPlayerHuman1.getName().c_str(),newPlayerHuman2.getName().c_str())>0) 
	{
		cout<<newPlayerHuman1<<"������ֱȽό�,����"<<newPlayerHuman1<<"�����֣�";
		Sleep(2000);
		newBoard.printChessBoard();
		int cnt = 9;
		while (cnt--)
		{
			if (cnt % 2 == 0)
			{
				cout<<newPlayerHuman1;
				newPlayerHuman1.setChess(newBoard,1);
				newBoard.printChessBoard();
				
				//Sleep(2000);//��ͣ�����ӣ�ʹ��ҿ����Լ�������һ�� 
				
				if (newBoard.judge(1) == true)
				{
					res = 1;
					break;
				}
			}
			else
			{
				cout<<newPlayerHuman2;
				newPlayerHuman2.setChess(newBoard,0);
				newBoard.printChessBoard();
				if (newBoard.judge(0) == true)
				{
					res = -1;
					break;
				}
			}
		}
		if (res != 1 && res != -1) res = 0; 
		if(res==1) cout<<newPlayerHuman1<<"��Ȼ��˾��~����Ű"<<newPlayerHuman2<<endl<<endl;
		else if(res==-1)  cout<<newPlayerHuman2<<"��Ȼ��˾��~����Ű"<<newPlayerHuman1<<endl<<endl;
		if(res==0) cout<<"�����ǻ��ѣ��¸��嶼�໥ǫ��"<<endl<<endl; 
	}
	else 
	{
		cout<<newPlayerHuman2<<"������ֱȽό�,����"<<newPlayerHuman2<<"�����֣�";
		Sleep(2000); 
		newBoard.printChessBoard();
		int cnt = 9;
		while (cnt--)
		{
			if (cnt % 2 == 0)
			{
				cout<<newPlayerHuman2;
				newPlayerHuman2.setChess(newBoard,1);
				newBoard.printChessBoard();
				
				//Sleep(2000);//��ͣ�����ӣ�ʹ��ҿ����Լ�������һ�� 
				
				if (newBoard.judge(1) == true)
				{
					res = 1;
					break;
				}
			}
			else
			{
				cout<<newPlayerHuman1;
				newPlayerHuman1.setChess(newBoard,0);
				newBoard.printChessBoard();
				if (newBoard.judge(0) == true)
				{
					res = -1;
					break;
				}
			}
		}
		if (res != 1 && res != -1) res = 0;
		if(res==1) cout<<newPlayerHuman2<<"��Ȼ��˾��~����Ű"<<newPlayerHuman1<<endl<<endl;
		else if(res==-1)  cout<<newPlayerHuman1<<"��Ȼ��˾��~����Ű"<<newPlayerHuman2<<endl<<endl;
		if(res==0) cout<<"�����ǻ��ѣ��¸��嶼�໥ǫ��"<<endl<<endl;
	}
}

void Game::playerVsComputer()
{
	Board newBoard;
	Player newPlayerComputer;
	PlayerHuman newPlayerHuman;
line:
	system("cls");	
	cout<<"��ѡ�����ֻ���֣��������Ӧ��ţ���"<<endl<<endl;
	cout<<"\t\t1,����"<<endl<<endl;
	cout<<"\t\t2,����"<<endl<<endl;

	int p;
	cin>>p;
	if(p!=1&&p!=2) 
	{
		cout<<"�������벻�Ϸ�"<<endl;
		goto line; 
	}
	
	cout<<"����������������in English����";
	cin>>newPlayerHuman;
	 
	newBoard.printChessBoard();
	int cnt = 9,k=0;
	if(p==2) k=1; 
	while (cnt--)
	{
		if (cnt % 2 == k)
		{
			cout<<newPlayerHuman;
			newPlayerHuman.setChess(newBoard,1);
			newBoard.printChessBoard();
			
			Sleep(2000);//��ͣ�����ӣ�ʹ��ҿ����Լ�������һ�� 
			
			if (newBoard.judge(1) == true)
			{
				res = 1;
				break;
			}
		}
		else
		{
			newPlayerComputer.setChess(newBoard);
			newBoard.printChessBoard();
			if (newBoard.judge(0) == true)
			{
				res = -1;
				break;
			}
		}
	}
	if (res != 1 && res != -1) res = 0;
	
	if (res==1) cout<<"��Ӵ������Ŷ��"<<newPlayerHuman<<"��������"<<endl<<endl;
	else if(res==-1) cout<<"������˼�������Ϸ򼼸�һ�ﰡ��"<<endl<<endl;
	else if(res==0) cout<<newPlayerHuman<<"���ǲ��������Ϸ��³�ƽ��~"<<endl<<endl; 
}

void Game::startGame()
{
	
	cout << "\t��ӭ����pjr�澮������Ϸ��" << endl;
	cout << endl;
	cout << "\tע�⣺��������ڴ���Ϸ��Ӱ��ѧҵ��" << endl;
	cout << endl;
	cout << endl;
	cout << "����������Ϸ��"<<endl;
	Sleep(5000); 
}

void Game::process()
{
	system("cls");
line:
	cout<<"��ѡ����Ϸģʽ�������Ӧģʽ����ţ���"<<endl<<endl;
	cout<<"\t\t1,�˻���ս"<<endl<<endl;
	cout<<"\t\t2,˫�˶���"<<endl<<endl;

	cin>>pattern;
	if(pattern==1) playerVsComputer();
	else if(pattern==2) playerVsPlayer();
	else 
	{
		cout<<"�������벻�Ϸ������������룺"<<endl;
		goto line; 
	}
}

void Game::end()
{
	cout<<"��Ҫ����һ����?�������Ӧѡ�����ţ�"<<endl<<endl;
	cout<<"\t\t1,����һ��"<<endl<<endl;
	cout<<"\t\t2,�˳���Ϸ"<<endl<<endl; 
	
	int n;
	cin>>n;
	if(n==1) this->reStartGame();
	else if(n==2) exit(0); 
}

void Game::reStartGame()
{
	Game newGame;
	newGame.process();
	newGame.end();
}

int main()
{
	Game newGame;
	newGame.startGame();
	newGame.process();
	newGame.end();
}

