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

map <vector <int>, vector <vector <int>>> arrow;
map <vector <int>, set <vector <int>>> way1;
map <vector <int>, int> way;
map <vector <int>, T> colst, result;
map <T, vector <vector <int>>, comp> repeat[100];
vector <int> Jadn[100];
vector <int> ocornt;
vector <int> Junt;
set <map <vector <int>, T>> print;
int N;

ofstream outf("SomeText.txt");
ofstream outf1("SomeText1.txt");
ofstream outf2("SomeText2.txt");
ofstream outf3("N.txt");
ofstream outf4("Jadn.txt");
ifstream inf("output.txt");

void bf(map <vector <int>, T> cols, vector <int> Jun, vector <int> ocorn, int n) {
	if (auto it = result.find(Jun) == result.end()) {
		tm.x = cols[Jun].x;
		tm.y = cols[Jun].y;
		repeat[n][tm].push_back(Jun);
	}
	result[Jun].x = cols[Jun].x;
	result[Jun].y = cols[Jun].y;
	if (n + 1 == N) {
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
				way1[Jun].insert(Jun1);
				cols1[Jun1].y = cols1[Jun].y - (n + 3);
				if ((i + 1) - (Jun1[i]) == 0) cols1[Jun1].x = cols1[Jun].x;
				else cols1[Jun1].x = cols1[Jun].x + ((i + 1) - (Jun1[i]));//+sqrt(n+1));
				ocorn1[i + 1] = 1;
				if (i > 0) {
					if (Jun1[i - 1] == Jun1[i]) ocorn1[i] = 0;
				}
				bf(cols1, Jun1, ocorn1, n + 1);
			}
			else {
				Jun1.push_back(1);
				arrow[Jun].push_back(Jun1);
				way1[Jun].insert(Jun1);
				if (Jun1[i - 1] == 1) ocorn1[i] = 0;
				cols1[Jun1].y = cols1[Jun].y - (n + 3);
				if ((i + 1) - (1) == 0) cols1[Jun1].x = cols1[Jun].x;
				else cols1[Jun1].x = cols1[Jun].x + ((i + 1) - (1));//+ sqrt(n + 1));
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
	way[Junt] = 1;
	cin >> N;
	outf3 << N << endl;
	ocornt.push_back(1), ocornt.push_back(1);
	bf(colst, Junt, ocornt, 0);
	for (auto it = way1.begin(); it != way1.end(); ++it) {
		for (auto iter = (*it).second.begin(); iter != (*it).second.end(); iter++) {
			way[(*iter)] += way[(*it).first];
		}
	}
	for (int k = 0; k < N; k++) {
		double ots = 0;
		double sdv = 0;
		for (auto it = repeat[k].begin(); it != repeat[k].end(); ++it) {
			for (int i = 0; i < (*it).second.size(); i++) {
				result[(*it).second[i]].x = ots;
				ots += k + 2;
				sdv = result[(*it).second[i]].x / 2;
			}
		}
		for (auto it = repeat[k].begin(); it != repeat[k].end(); ++it) {
			for (int i = 0; i < (*it).second.size(); i++) {
				result[(*it).second[i]].x -= sdv;
			}
		}
		int sum = 0, elem;
		while (sum != k + 1) {
			inf >> elem;
			sum += elem;
			Jadn[k].push_back(elem);
		}
	}
	int opred = 0;
	for (auto it = result.begin(); it != result.end(); ++it) {
		for (int i = 0; i < (*it).first.size(); i++) {
			for (int j = 0; j < (*it).first[i]; j++) {
				outf << (*it).second.x + i << " " << (*it).second.y + j << " |" << way[(*it).first] << endl;
				if ((*it).first == Jadn[opred]) {
					outf4 << (*it).second.x + i << " " << (*it).second.y + j <<  endl;
				}
			}
		}
		if ((*it).first == Jadn[opred]) opred++;
	}
	for (auto it = arrow.begin(); it != arrow.end(); ++it) {
		for (int i = 0; i < (*it).second.size(); i++) {
			outf2 << result[(*it).first].x << " " << result[(*it).first].y << endl;
			outf2 << result[(*it).second[i]].x << " " << result[(*it).second[i]].y + (*it).second[i][0] << endl;
		}
	}
	return 0;
}