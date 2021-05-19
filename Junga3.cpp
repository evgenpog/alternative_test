#include <iostream>
#include <vector> 
#include <set>
#include <map>
#include <math.h>
#include <fstream>
using namespace std;

struct T {
	double x;
	int y;
}coord, tm;
struct TN {
	int X;
	int x;
	int y;
};
struct comp {
	bool operator()(struct T cr1, struct T cr2) const {
		return cr1.x < cr2.x;
	}
};
char outt[1000][50];
map <vector <int>, vector <vector <int>>> arrow;
map <vector <int>, T> colst, result;
map <T, vector <vector <int>>, comp> repeat[100];
vector <int> ocornt;
vector <int> Junt;
set <map <vector <int>, T>> print;
int n;

ofstream outf("SomeText.txt");
ofstream outf1("SomeText1.txt");
ofstream outf2("SomeText2.txt");

void bf(map <vector <int>, T> cols, vector <int> Jun, vector <int> ocorn, int n) {
	/*print.insert(cols);
	if (n + 1 == 7) { //помен€йте число чтобы изменить размер до какого размера необходимо строить д.ёнга
		/*for (int i = 0; i < cols.size(); i++) {
			cout << cols[i] << " ";
		}
		cout << '\n';
		return;
	}*/
	//for (int i = 0; i < Jun.size(); i++) cout << Jun[i] << " ";
	//cout << " x: " << cols[Jun].x << " y: " << cols[Jun].y << "\n";
	//result[Jun].x = cols[Jun].x;
	//result[Jun].y = cols[Jun].y;
	//outf << cols[Jun].x << " " << cols[Jun].y << "\n";
	//outt[cols[Jun].x + 150][cols[Jun].y] = n+'0';
	//if (n + 1 == 5 || n + 1 == 6) {
	if (auto it = result.find(Jun) == result.end()) {
		tm.x = cols[Jun].x;
		tm.y = cols[Jun].y;
		repeat[n][tm].push_back(Jun);
	}
	result[Jun].x = cols[Jun].x;
	result[Jun].y = cols[Jun].y;
	//}
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
				arrow[Jun].push_back(Jun1);
				cols1[Jun1].y = cols1[Jun].y - (n + 3);
				/*if (n + 2 == 5 || n + 2 == 6) {
					otl[Jun1].X = cols1[Jun].x;
					otl[Jun1].x = i + 1;
					otl[Jun1].y = Jun1[i];
					//for (int j = 0; j < Jun1.size(); j++) outf1 << Jun1[j] << " ";
					//outf1 << " X= " << cols1[Jun].x << " x= " << i + 1 << " y= " << Jun1[i] << "\n";
				}*/
				if ((i + 1) - (Jun1[i]) == 0) cols1[Jun1].x = cols1[Jun].x;
				else cols1[Jun1].x = cols1[Jun].x + ((i + 1) - (Jun1[i]))*sqrt(n + 1);//+sqrt(n+1));
				ocorn1[i + 1] = 1;
				if (i > 0) {
					if (Jun1[i - 1] == Jun1[i]) ocorn1[i] = 0;
				}
				bf(cols1, Jun1, ocorn1, n + 1);
			}
			else {
				Jun1.push_back(1);
				arrow[Jun].push_back(Jun1);
				if (Jun1[i - 1] == 1) ocorn1[i] = 0;
				cols1[Jun1].y = cols1[Jun].y - (n + 3);
				/*if (n + 2 == 5 || n + 2 == 6) {
					otl[Jun1].X = cols1[Jun].x;
					otl[Jun1].x = i + 1;
					otl[Jun1].y = Jun1[i];
					//for (int j = 0; j < Jun1.size(); j++) outf1 << Jun1[j] << " ";
					//outf1 << " X= " << cols1[Jun].x << " x= " << i + 1 << " y= " << Jun1[i] << "\n";
				}*/
				if ((i + 1) - (1) == 0) cols1[Jun1].x = cols1[Jun].x;
				else cols1[Jun1].x = cols1[Jun].x + ((i + 1) - (1))*sqrt(n + 1);//+ sqrt(n + 1));
				ocorn1.push_back(1);
				bf(cols1, Jun1, ocorn1, n + 1);
			}
		}
	}
}

int main() {
	coord.x = 1, coord.y = 0;
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
	for (int k = 0; k <= 6; k++) {
		/*for (auto it = repeat[k].begin(); it != repeat[k].end(); ++it) {
			if (it == repeat[k].begin()) continue;
			for (int i = 0; i < (*it).second.size(); i++) {
				//if (i == (*it).second.size() - 1) {
					auto it1 = it;
					it1++;
					if (it1 != repeat[k].end()) {
						result[(*it1).second[0]].x += sdv;
						sdv++;
					}
				//}
			}
		}*/
		//auto itrr = repeat[k].end();
		//itrr--;
		//int xpst = result[(*itrr).second[(*itrr).second.size() - 1]].x;
		double ots = 0;
		double sdv = 0;
		for (auto it = repeat[k].begin(); it != repeat[k].end(); ++it) {
			for (int i = 0; i < (*it).second.size(); i++) {
				//if ((*it).second.size() > 1 && i > 0) ots += k + 2;
				//ots += k + 2;
				//if (i == (*it).second.size() - 1) ots++;
				result[(*it).second[i]].x = ots;
				ots += k + 2;
				sdv = result[(*it).second[i]].x/2;
				//ots+=n;
				/*auto it1 = it;
				it1++;
				if (it1 != repeat[k].end()) {
					result[(*it1).second[0]].x += sdv;
					sdv++;
				}*/
				/*for (int j = 0; j < (*it).second[i].size(); j++) {
					cout << (*it).second[i][j] << " ";
				}
				cout << endl << result[(*it).second[i]].x << endl;
				result[(*it).second[i]].x += ots;
				cout << result[(*it).second[i]].x << endl;*/
			}
			//sdv++;
			//int differ = (xpst - result[(*it).second[(*it).second.size() - 1]].x) / 2;
			/*for (int i = 0; i < (*it).second.size(); i++) {
				result[(*it).second[i]].x -= ots/2;
			}*/
			/*for (int i = 0; i < (*it).second.size(); i++) {
				cout << "xpst " << xpst << "\n";
				for (int j = 0; j < (*it).second[i].size(); j++) {
					cout << (*it).second[i][j] << " ";
				}
				cout << "\n";
				cout << "x: " << (*it).first.x << " y: " << (*it).first.y << "\n";
			}
			*/
		}
		
		for (auto it = repeat[k].begin(); it != repeat[k].end(); ++it) {
			for (int i = 0; i < (*it).second.size(); i++) {
				result[(*it).second[i]].x -= sdv;
			}
		}
		/*int differ = (xpst - result[(*itrr).second[(*itrr).second.size() - 1]].x) / 2;
		cout << "xpst " << xpst << "res " << result[(*itrr).second[(*itrr).second.size() - 1]].x << endl;
		cout << differ << endl;*/
		/*int sdv = 0;
		for (auto it = repeat[k].rbegin(); it != repeat[k].rend(); it++) {
			for (int i = 0; i < (*it).second.size(); i++) {
				for (int j = 0; j < (*it).second[i].size(); j++) {
					cout << (*it).second[i][j] << " ";
				}
				cout << "\n";
				cout << sdv << endl;
				cout << "x: " << result[(*it).second[i]].x << "\n";
				//result[(*it).second[i]].x += differ / 2;
				result[(*it).second[i]].x -= sdv;
				cout << "x: " << result[(*it).second[i]].x << "\n";
				sdv++;
			}
		}*/
		/*int sdv = 0;
		for (auto it = repeat[k].begin(); it != repeat[k].end(); it++) {
			for (int i = 0; i < (*it).second.size(); i++) {
				for (int j = 0; j < (*it).second[i].size(); j++) {
					cout << (*it).second[i][j] << " ";
				}
				cout << "\n";
				cout << sdv << endl;
				cout << "x: " << result[(*it).second[i]].x << "\n";
				//result[(*it).second[i]].x += differ / 2;
				result[(*it).second[i]].x += sdv;
				cout << "x: " << result[(*it).second[i]].x << "\n";
				sdv++;
			}
		}*/
	}
	for (auto it = result.begin(); it != result.end(); ++it) {
		for (int i = 0; i < (*it).first.size(); i++) outf1 << (*it).first[i] << " ";
		outf1 << endl;
		outf1 << "x: " << (*it).second.x << " y: " << (*it).second.y << endl;///вывод на экран
		//outf << (*it).second.x << " " << (*it).second.y << endl;
	}
	for (auto it = result.begin(); it != result.end(); ++it) {
		for (int i = 0; i < (*it).first.size(); i++) {
			for (int j = 0; j < (*it).first[i]; j++) {
				outf << (*it).second.x + i << " " << (*it).second.y + j << endl;
			}
		}
	}
	for (auto it = arrow.begin(); it != arrow.end(); ++it) {
		for (int i = 0; i < (*it).second.size(); i++) {
			outf2 << result[(*it).first].x << " " << result[(*it).first].y << endl;
			outf2 << result[(*it).second[i]].x << " " << result[(*it).second[i]].y + (*it).second[i][0] << endl;
		}
	}
	/*for (auto it = otl.begin(); it != otl.end(); ++it) {
		for (int i = 0; i < (*it).first.size(); i++) outf1 << (*it).first[i] << " ";
		outf1 << endl;
		outf1 << "X= " << (*it).second.X << " x= " << (*it).second.x << " y= " << (*it).second.y << endl;///вывод на экран
	}*/
	/*for (auto it = result.begin(); it != result.end(); ++it) {
		outf << (*it).second.x << " " << (*it).second.y << endl;///вывод на экран
	}*/
	int a;
	cin >> a;
	return 0;
}
