struct ship
{
	int x;		//координаты первой палубы
	int y;
	int xd;		// смещение для следующих палуб
	int yd;
	int col;	// количество палуб
};
	bool SeaMap[10][10];	// поле

void print();
void printBorder();
void printBody();

void initSea();
void initShip(int col, int num);
ship randShip(int col);

void SetShip(ship X);
ship shipSetRotate(ship X, int gradus);

bool CheckSea(ship S);
bool CheckVector(ship S);


