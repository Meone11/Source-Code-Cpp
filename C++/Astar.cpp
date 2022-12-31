// A C++ Program to implement A* Search Algorithm
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int> > pPair;

#define ROW 9
#define COL 10

struct cell {
	int parent_i, parent_j;
	// f = g + h
	double f, g, h;
};

bool isValid(int row, int col)
{
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isUnBlocked(int grid[][COL], int row, int col)
{
	if (grid[row][col] == 1)
		return (true);
	else
		return (false);
}

bool isDestination(int row, int col, Pair dest)
{
	if (row == dest.first && col == dest.second)
		return (true);
	else
		return (false);
}

double calculateHValue(int row, int col, Pair dest)
{
	// Return using the distance formula
	return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}

void tracePath(cell cellDetails[][COL], Pair dest)
{
    cout << "\nJalur Rute Anda Adalah : ";
	// printf("\nThe Path is ");
	int row = dest.first;
	int col = dest.second;

	stack<Pair> Path;

	while (!(cellDetails[row][col].parent_i == row
			&& cellDetails[row][col].parent_j == col)) {
		Path.push(make_pair(row, col));
		int temp_row = cellDetails[row][col].parent_i;
		int temp_col = cellDetails[row][col].parent_j;
		row = temp_row;
		col = temp_col;
	}

	Path.push(make_pair(row, col));
	while (!Path.empty()) {
		pair<int, int> p = Path.top();
		Path.pop();
        cout << "-> (" << p.first << "," << p.second << ")";
		// printf("-> (%d,%d) ", p.first, p.second);
	}

	return;
}

void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
	// Jika sumber kelebihan atau out of range
	if (isValid(src.first, src.second) == false) {
		printf("Sumber awal invalid\n");
		return;
	}

	// Jika tujuan out of range
	if (isValid(dest.first, dest.second) == false) {
		printf("Tujuan invalid\n");
		return;
	}

	// Jika Tujua atau Sumber awal yang di blokir
	if (isUnBlocked(grid, src.first, src.second) == false || isUnBlocked(grid, dest.first, dest.second) == false) {
		printf("Sumber atau Tujuan Di Blok\n");
		return;
	}

	// Jika tujuan sama dengan sumber awal
	if (isDestination(src.first, src.second, dest) == true) {
		printf("Kita sudah Berada di tujuan anda\n");
		return;
	}

	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));

	cell cellDetails[ROW][COL];

	int i, j;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			cellDetails[i][j].f = FLT_MAX;
			cellDetails[i][j].g = FLT_MAX;
			cellDetails[i][j].h = FLT_MAX;
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}

	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;

	set<pPair> openList;

	openList.insert(make_pair(0.0, make_pair(i, j)));

	bool foundDest = false;

	while (!openList.empty()) {
		pPair p = *openList.begin();

		openList.erase(openList.begin());

		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;

		double gNew, hNew, fNew;

		if (isValid(i - 1, j) == true) {

			if (isDestination(i - 1, j, dest) == true) {

				cellDetails[i - 1][j].parent_i = i;
				cellDetails[i - 1][j].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i - 1][j] == false && isUnBlocked(grid, i - 1, j) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i - 1, j, dest);
				fNew = gNew + hNew;

				if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i - 1, j)));

					cellDetails[i - 1][j].f = fNew;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
				}
			}
		}

		if (isValid(i + 1, j) == true) {

			if (isDestination(i + 1, j, dest) == true) {

				cellDetails[i + 1][j].parent_i = i;
				cellDetails[i + 1][j].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i + 1][j] == false && isUnBlocked(grid, i + 1, j) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i + 1, j, dest);
				fNew = gNew + hNew;

				if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i + 1, j)));

					cellDetails[i + 1][j].f = fNew;
					cellDetails[i + 1][j].g = gNew;
					cellDetails[i + 1][j].h = hNew;
					cellDetails[i + 1][j].parent_i = i;
					cellDetails[i + 1][j].parent_j = j;
				}
			}
		}

		if (isValid(i, j + 1) == true) {

			if (isDestination(i, j + 1, dest) == true) {

				cellDetails[i][j + 1].parent_i = i;
				cellDetails[i][j + 1].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i][j + 1] == false && isUnBlocked(grid, i, j + 1) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j + 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i, j + 1)));

					cellDetails[i][j + 1].f = fNew;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
				}
			}
		}

		if (isValid(i, j - 1) == true) {

			if (isDestination(i, j - 1, dest) == true) {

				cellDetails[i][j - 1].parent_i = i;
				cellDetails[i][j - 1].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i][j - 1] == false && isUnBlocked(grid, i, j - 1) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j - 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i, j - 1)));

					cellDetails[i][j - 1].f = fNew;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;
				}
			}
		}

		if (isValid(i - 1, j + 1) == true) {

			if (isDestination(i - 1, j + 1, dest) == true) {

				cellDetails[i - 1][j + 1].parent_i = i;
				cellDetails[i - 1][j + 1].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i - 1][j + 1] == false && isUnBlocked(grid, i - 1, j + 1) == true) {
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i - 1, j + 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i - 1][j + 1].f == FLT_MAX || cellDetails[i - 1][j + 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i - 1, j + 1)));
					cellDetails[i - 1][j + 1].f = fNew;
					cellDetails[i - 1][j + 1].g = gNew;
					cellDetails[i - 1][j + 1].h = hNew;
					cellDetails[i - 1][j + 1].parent_i = i;
					cellDetails[i - 1][j + 1].parent_j = j;
				}
			}
		}

		if (isValid(i - 1, j - 1) == true) {

			if (isDestination(i - 1, j - 1, dest) == true) {
				cellDetails[i - 1][j - 1].parent_i = i;
				cellDetails[i - 1][j - 1].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i - 1][j - 1] == false && isUnBlocked(grid, i - 1, j - 1) == true) {
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i - 1, j - 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i - 1][j - 1].f == FLT_MAX || cellDetails[i - 1][j - 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i - 1, j - 1)));
					cellDetails[i - 1][j - 1].f = fNew;
					cellDetails[i - 1][j - 1].g = gNew;
					cellDetails[i - 1][j - 1].h = hNew;
					cellDetails[i - 1][j - 1].parent_i = i;
					cellDetails[i - 1][j - 1].parent_j = j;
				}
			}
		}

		if (isValid(i + 1, j + 1) == true) {
			if (isDestination(i + 1, j + 1, dest) == true) {
				cellDetails[i + 1][j + 1].parent_i = i;
				cellDetails[i + 1][j + 1].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i + 1][j + 1] == false && isUnBlocked(grid, i + 1, j + 1) == true) {
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i + 1, j + 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i + 1][j + 1].f == FLT_MAX || cellDetails[i + 1][j + 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i + 1, j + 1)));

					cellDetails[i + 1][j + 1].f = fNew;
					cellDetails[i + 1][j + 1].g = gNew;
					cellDetails[i + 1][j + 1].h = hNew;
					cellDetails[i + 1][j + 1].parent_i = i;
					cellDetails[i + 1][j + 1].parent_j = j;
				}
			}
		}

		// Only process this cell if this is a valid one
		if (isValid(i + 1, j - 1) == true) {

			if (isDestination(i + 1, j - 1, dest) == true) {
				cellDetails[i + 1][j - 1].parent_i = i;
				cellDetails[i + 1][j - 1].parent_j = j;
				cout << "Tujuan Anda di Temukan : " <<endl;
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i + 1][j - 1] == false && isUnBlocked(grid, i + 1, j - 1) == true) {
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i + 1, j - 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i + 1][j - 1].f == FLT_MAX || cellDetails[i + 1][j - 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i + 1, j - 1)));

					cellDetails[i + 1][j - 1].f = fNew;
					cellDetails[i + 1][j - 1].g = gNew;
					cellDetails[i + 1][j - 1].h = hNew;
					cellDetails[i + 1][j - 1].parent_i = i;
					cellDetails[i + 1][j - 1].parent_j = j;
				}
			}
		}
	}

	if (foundDest == false)
		printf("Tujuan Anda tidak ditemukan!\n");

	return;
}

// Driver program to test above function
int main()
{
	// int row, column;
	// cout << " Masukan Row Pada Matriks : "; cin >> row;
	// cout << " Masukan Column Pada Matriks : "; cin >> column;
	int grid[ROW][COL];
	
	cout << "Masukan Nilai Matriks hanya dengan 0 dan 1\n 0 : Jalan di blokir\n 1 : Jalan bisa di lewati\n";
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			cin >> grid[i][j];
		}
	}

	int startRow, startCol, tujuanRow, tujuanCol;
	cout << "Masukan Titik Awal Anda berada sesuai dengan row matriks : "; cin >> startRow;
	cout << "Masukan Titik Awal Anda berada sesuai dengan column matriks : "; cin >> startCol;

	Pair src = make_pair(startRow, startCol);

	cout << "Masukan Tujuan Anda berada sesuai dengan row matriks : "; cin >> tujuanRow;
	cout << "Masukan Tujuan Anda berada sesuai dengan column matriks : "; cin >> tujuanCol;

	Pair dest = make_pair(tujuanRow, tujuanCol);

	aStarSearch(grid, src, dest);

	return (0);
}
