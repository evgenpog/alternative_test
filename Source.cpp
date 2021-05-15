#include <iostream>
#include <vector> 
#include <set>
using namespace std;

vector <int> cols, ocorn;
set <vector <int>> print;
int n;

void bf(vector <int> cols, vector <int> ocorn, int n) {
	if (n+1 == 7) { //помен€йте число чтобы изменить размер до какого размера необходимо строить д.ёнга
		/*for (int i = 0; i < cols.size(); i++) {
			cout << cols[i] << " ";
		}
		cout << '\n';*/
		print.insert(cols);
		return;
	}
	for (int i = 0; i < ocorn.size(); i++) {
		if (ocorn[i] == 1) {
			vector <int> cols1, ocorn1;
			cols1 = cols;
			ocorn1 = ocorn;
			if (i + 1 < ocorn.size()) {
				cols1[i]++;
				ocorn1[i + 1] = 1;
				if (i > 0) {
					if (cols1[i - 1] == cols1[i]) ocorn1[i] = 0;
				}
				bf(cols1, ocorn1, n + 1);
			}
			else{
				cols1.push_back(1);
				if (cols1[i - 1] == 1) ocorn1[i] = 0;
				ocorn1.push_back(1);
				bf(cols1, ocorn1, n + 1);
			}
		}
	}
}

int main() {
	
	cols.push_back(1);
	//если i-а€ строка в массиве равна 1, то в д.ёнга мы можем добавить	€чейку сверху на i столбец
	ocorn.push_back(1), ocorn.push_back(1);
	bf(cols, ocorn, 0);
	for (auto it = print.begin(); it != print.end(); ++it) {
		for(int i = 0; i < (*it).size(); i++){
			cout << (*it)[i] << " ";
		}
		cout << '\n';
	}
	int a;
	cin >> a;
	return 0;
}