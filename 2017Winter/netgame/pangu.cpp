#include <bits/stdc++.h>
using namespace std;
int max_hp,b,d;
int table[100][100][100][100];

int battle(int deep,int ap, int hp, int am, int hm)
{
	if(table[ap][hp][am][hm])
		return table[ap][hp][am][hm];
	if(hm <= ap)
		return table[ap][hp][am][hm] = 1;
	if(hp <= am)
		return table[ap][hp][am][hm] = battle(deep+1, ap, max_hp-am, am, hm)+1;

	if(am-d >= 0)
		return table[ap][hp][am][hm] = min(min(battle(deep+1, ap, hp-am, am, hm-ap),battle(deep+1, ap+b, hp-am, am, hm)),battle(deep+1, ap, hp-am+d,am-d, hm))+1;
	else if(am == 0)
		return table[ap][hp][am][hm] = min(battle(deep+1, ap+b, hp-am, am, hm),battle(deep+1, ap, hp-am,am, hm-ap))+1;
	else
		return table[ap][hp][am][hm] = min(min(battle(deep+1, ap+b, hp-am, am, hm),battle(deep+1, ap, hp-am,am, hm-ap)), battle(deep+1, ap, hp-am, 0, hm))+1;

}
int main()
{
	int ap,hm,am;
	cin >> max_hp >> ap >> hm >> am >> b >> d;
	int hp = max_hp;
	if(am >= hp/2.0 + d)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << battle(0, ap, hp, am, hm) << endl;
	return 0;
}