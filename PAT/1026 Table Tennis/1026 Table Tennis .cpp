#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
const int K = 111;
const int INF = 1 >> 30;
struct player {
	int arriveTime, startTime, trainTime;
	bool isVip;
}newPlayer;
struct Table {
	int endTime, numServe;
	bool isVip;
}table[K];
int convertTime(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
vector<player> Player;
bool cmpArrive(player a, player b) {
	return a.arriveTime < b.arriveTime;
}
bool cmpStart(player a, player b) {
	return a.startTime < b.startTime;
}
int nextVIPPlayer(int VIPi) {
	VIPi++;
	while (VIPi < Player.size() && Player[VIPi].isVip == 0) {
		VIPi++;//找到下一个VIP客户
	}
	return VIPi;
}
void allotTable(int pID, int tID) {
	if (Player[pID].arriveTime <= table[tID].endTime) {//需要等桌子结束
		Player[pID].startTime = table[pID].endTime;
	}
	else {
		Player[pID].startTime = Player[pID].arriveTime;//来了就开始
	}
	table[tID].endTime = Player[pID].startTime + Player[pID].trainTime;//桌子结束时间等于开始时间加上服务时间
	table[tID].numServe++;
}
int main() {
	int n, m, k, VIPtable;
	scanf("%d", &n);
	int stTime = convertTime(8, 0, 0);
	int edTime = convertTime(21, 0, 0);
	for (int i = 0; i < n; i++) {
		int h, m, s, trainTime, isVip;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVip);
		newPlayer.arriveTime = convertTime(h, m, s);
		newPlayer.startTime = edTime;
		if (newPlayer.arriveTime >= edTime)	continue;
		if (trainTime > 120)	trainTime = 120;
		newPlayer.trainTime = trainTime * 60;
		newPlayer.isVip = isVip;
		Player.push_back(newPlayer);
	}
	scanf("%d%d", &k, &m);
	for (int i = 1; i <= k; i++) {
		table[i].endTime = stTime;
		table[i].numServe = table[i].isVip = 0;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &VIPtable);
		table[VIPtable].isVip = 1;
	}
	sort(Player.begin(), Player.end(), cmpArrive);
	int i = 0, VIPi = -1;
	VIPi = nextVIPPlayer(VIPi);//找到第一个VIP编号
	while (i < Player.size()) {
		int idx = -1, minEndTime = INF;//寻找最早能空闲的球桌
		for (int j = 1; j <= k; j++) {
			if (table[j].endTime < minEndTime) {
				idx = j;
				minEndTime = table[j].endTime;
			}
		}
		if (table[idx].endTime >= edTime)	break;//已经关门，直接break
		if (Player[i].isVip == 1 && i < VIPi) {//如果i号球员是VIP但是VIP>i 说明i号球员已经在训练
			i++;
			continue;
		}
		if (table[idx].isVip == 1) {//球员是VIP，球桌是VIP
			if (Player[i].isVip == 1) {
				allotTable(i, idx);//将idx分配给球员i
				if (VIPi == i)	VIPi = nextVIPPlayer(VIPi);//找到下一个VIP球员
				i++;
			}
			else {
				//球桌是VIP 球员不是VIp
				//r如果当前队首的VIP球员比该VIp球桌早 就把球桌idx(非VIp球桌)分配给他
				if (VIPi < Player.size() && Player[VIPi].arriveTime <= table[idx].endTime) {
					allotTable(VIPi, idx);
					VIPi = nextVIPPlayer(VIPi);
				}
				else {
					allotTable(i, idx);
					i++;
				}
			}
		}
		else {
			//球桌不是vip
			if (Player[i].isVip == 0) {//球桌不是vip 球员不是vip
				allotTable(i, idx);
				i++;
			}
			else {
				//球员是VIP，则找到最早的空闲的VIP球桌
				int VIPidx = 1, minVIPEndTime = INF;
				for (int j = 1; j <= k; j++) {
					if (table[j].isVip == 1 && table[j].endTime < minVIPEndTime) {
						minVIPEndTime = table[j].endTime;//最早结束时间
						VIPidx = j;
					}
				}
				//最早空闲的VIP球桌编号 VIPidx
				if (VIPidx != -1 && Player[i].arriveTime >= table[VIPidx].endTime) {
					//球员来了已经空闲
					//就把他分配给球员i
					allotTable(i, VIPidx);
					if (VIPi == i)	VIPi = nextVIPPlayer(VIPi);
					i++;
				}
				else {
					//如果球员来时 VIP球桌还未空闲 就把球桌idx分配给他
					allotTable(i, idx);
					if (VIPi == i)	VIPi = nextVIPPlayer(VIPi);//找到下一个VIp球员
					i++;//i号球员开始训练 因此继续队列的下一个人
				}
			}
		}
	}
	sort(Player.begin(), Player.end(), cmpStart);
	for (i = 0; i < Player.size()&&Player[i].startTime < edTime; i++) {
		int t1 = Player[i].arriveTime;
		int t2 = Player[i].startTime;
		printf("1%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round((t2 - t1) / 60.0));
	}
	for (i = 1; i <= k; i++) {
		printf("%d", table[i].numServe);
		if (i < k)	printf(" ");
	}
	return 0;
}