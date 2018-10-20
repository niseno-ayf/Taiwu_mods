// MakeSheet.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ofstream fout;
	fout.open("Read.csv");
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j <= 30 - i && j <= (i + 1) / 2; j++) {
			fout << (((i - 2 * j - 1) < 0) ? 0 : (1 << (i - 2 * j - 1))) + 1 - 2 * (30 - i - j) << ',';
			//需求耐心下限
			fout << i << ',';
			fout << j << ',';
			//i - 温的次数，j - 补充耐心的独的个数
			fout << 10 * (30 - i - j) - 20 * ((30 - i - j+2) / 3) +10 << ',';
			//初始可用悟性=悟性/2
			int income = 0;
			for (int k = 0; k < 10; k++) {
				income += 2 * (1 + (i < (27 - 3 * k) ? i : (27 - 3 * k)));
			}
			//无加成部分收益
			income += (30 - i - j)*(i + 1);
			//开场加成部分
			for (int k = 0; k < j; k++) {
				income += 2 * k + 3;
			}
			//补充加成部分
			fout << income << ',' << '\n';
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
