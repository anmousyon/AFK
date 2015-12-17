#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
string counterbName[800];
string countergName[800];
string championName[130];
string skillName[800];
string champName;
string role[130];


void fileOpener(string fileName, string arrayName, int q){
	ifstream theFile;
	theFile.open(fileName.c_str());
	if (theFile.fail()){
		cout << "File Read: ERROR";
	}
	else
		cout << "File Read: Success";

	for (int i = 0; i < q; i++){
		theFile >> arrayName[i];
	}

	theFile.close();
}


class countersgb{
public:
	string bad[6], good[6];
};

class champStats{
public:
	int aarange, hp, hppl, hr, hrpl, ad, adpl, armor, armorpl, as, aspl, mr, mrpl, ms, mana, manapl, manareg, manaregpl;
};

class itemStats{
public:
	int hp, hppl, hpreg, hpregpl, ad, adpl, armor, armorpl, as, aspl, mr, mrpl, ms, mana, manapl, manareg, manaregpl;
};
class items{
public:
	string name, desc;
	itemStats stats;
};
class skills{
public:
	string name, button, dmgType, scaleType, desc;
	int range, dmgBase, dmgScale, cd, cost;
};

class champ{
public:
	string name, role, passive, q, w, e, r, guide, passiveDesc, qDesc, wDesc, eDesc, rDesc;
	countersgb counters;
	champStats stats;
	int passiveCost, qCost, wCost, eCost, rCost;
	int passiveDmgBase, qDmgBase, wDmgBase, eDmgBase, rDmgBase;
	int passiveDmgScale, qDmgScale, wDmgScale, eDmgScale, rDmgScale;
	int passiveCD, qCD, wCD, eCD, rCD;
	int passiveRange, qRange, wRange, eRange, rRange;
	int ipCost, rpCost;
	string lastChanged;
	skills skill[800];
};

champ champion[120];

void classFiller(){
	for (int i = 0; i < 120; i++){
		int k = i * 6;
		champion[i].name = championName[i];
		champion[i].skill[k].name = skillName[(i + (5 * i))];
		champion[i].skill[k+1].name = skillName[(i + 1 + (5 * i))];
		champion[i].skill[k+2].name = skillName[(i + 2 + (5 * i))];
		champion[i].skill[k+3].name = skillName[(i + 3 + (5 * i))];
		champion[i].skill[k+4].name = skillName[(i + 4 + (5 * i))];
		champion[i].role = role[i];
		for (int j = 0; j < 6; j++){
			champion[i].counters.good[j] = countergName[(6*i)+j];
		}
		for (int k = 0; k < 6; k++){
			champion[i].counters.good[k] = countergName[(6*i)+k];
		}
	}
}

int main(){
	fileOpener("champions", "championName", 120);

	fileOpener("counterb", "counterbName", 800);

	fileOpener("counterg", "countergName", 800);

	fileOpener("skills", "skillName", 600);

	fileOpener("roles", "role", 120);

	for (int i = 0; i < 120; i++){
		for (int j = 0; j < 5; j++){
			string buttons[5] = { "Passive", "Q", "W", "E", "R" };
			champion[i].skill[i*6+j].button = buttons[j];
		}
	}

	int k = 0;

	classFiller();

	cout << "\n\nChampion: ";
	cin >> champName;

	for (int j = 0; j < 120; j++){
		if (champName == championName[j]){
			k = j;
		}
	}
	int r = k * 6;

	cout << "\nName: " << champion[k].name << "\n\nRole: " << champion[k].role;
	for (int p = 0; p < 5; p++){
		cout << "\n\n" << champion[k].skill[r + p].button << " :" << champion[k].skill[r + p].name << "- " << champion[k].skill[r + p].desc << "\n    " << "Range: " << champion[k].skill[r + p].range << "\n    " << "Cost: " << champion[k].skill[r + p].cost << "\n    " << "Cooldown: " << champion[k].skill[r + p].cd << "\n    " << "Damage: " << champion[k].skill[r + p].dmgBase << "+(" << champion[k].skill[r + p].dmgScale << ")";

	}
	cout << "\n\nGood Against: ";
	for (int i = 0; i < 6; i++){
		cout << champion[k].counters.good[i] << " ";
	}
	cout << "\n\nBad Against: ";
	for (int i = 0; i < 6; i++){
		cout << champion[k].counters.good[i] << " ";
	}

	cout << "\n\n";
	system("pause");
}
