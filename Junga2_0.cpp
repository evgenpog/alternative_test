#include <iostream>
#include <vector> 
#include <set>
#include <map>
using namespace std;

struct T {
	int x;
	int y;
}coord;
char outt[1000][50];
map <vector <int>, T> colst;
vector <int> ocornt;
vector <int> Junt;
set <map <vector <int>, T>> print;
int n;


void bf(map <vector <int>, T> cols, vector <int> Jun, vector <int> ocorn, int n) {
	/*print.insert(cols);
	if (n + 1 == 7) { //помен€йте число чтобы изменить размер до какого размера необходимо строить д.ёнга
		/*for (int i = 0; i < cols.size(); i++) {
			cout << cols[i] << " ";
		}
		cout << '\n';
		return;
	}*/
	for (int i = 0; i < Jun.size(); i++) cout << Jun[i] << " ";
	cout << " x: " << cols[Jun].x << " y: " << cols[Jun].y << "\n";	
	//outt[cols[Jun].x + 150][cols[Jun].y] = n+'0';
	if (n + 1 == 7) {
		return;
	}
	for (int i = 0; i < ocorn.size(); i++) {
		if (ocorn[i] == 1) {
			vector <int> ocorn1;
			vector <int> Jun1;
			map <vector <int>, T> cols1;
			Jun1 = Jun;
			cols1 = cols;
			ocorn1 = ocorn;
			if (i + 1 < ocorn.size()) {
				Jun1[i]++;
				cols1[Jun1].y = cols1[Jun].y + n + 1;
				cols1[Jun1].x = cols1[Jun].x*(i+1-Jun1[i]);
				ocorn1[i + 1] = 1;
				if (i > 0) {
					if (Jun1[i - 1] == Jun1[i]) ocorn1[i] = 0;
				}
				bf(cols1, Jun1, ocorn1, n + 1);
			}
			else {
				Jun1.push_back(1);
				if (Jun1[i - 1] == 1) ocorn1[i] = 0;
				cols1[Jun1].y = cols1[Jun].y + n + 1;
				cols1[Jun1].x = cols1[Jun].x*(i+1 - 1);
				ocorn1.push_back(1);
				bf(cols1, Jun1, ocorn1, n + 1);
			}
		}
	}	
}

int main() {
	coord.x = 1, coord.y = 1;
	Junt.push_back(1);
	colst[Junt] = coord;
	//если i-а€ строка в массиве равна 1, то в д.ёнга мы можем добавить	€чейку сверху на i столбец
	ocornt.push_back(1), ocornt.push_back(1);
	bf(colst, Junt, ocornt, 0);
	/*for (auto it = print.begin(); it != print.end(); ++it) {
		for (auto iter = (*it).begin(); iter != (*it).end(); ++iter) {
			for (int i = 0; i < (*iter).first.size(); i++) cout << (*iter).first[i] << " ";
			cout << " x: " << (*iter).second.x << " y: " << (*iter).second.y << "\n";
		}
		//cout << (*it)._Getpfirst << " x: " << (*it).
		/*for (int i = 0; i < (*it).size(); i++) {
			cout << (*it)[i] << " ";
		}
		cout << '\n';*/
	//}
	/*for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 50; j++) {
			//if (outt[i][j] = 0) cout << " ";
			//else 
			cout << outt[i][j];
			//cout << i;
		}
		cout << '\n';
	}*/
	int a;
	cin >> a;
	return 0;
}
