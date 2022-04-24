#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef struct {
	double x, y;
} Point;

Point readPoint () {
	Point p;
	cin >> p.x >> p.y;
	if (cin.fail()) { throw	0; }
	return p;
}

int main () {
	double X=0, Y=0, A=0;
	Point prev;
	vector<Point> v(0);
	puts("Enter one pair of coordinates per line, Press Ctrl+D to signal the end of input");
	while (true) {
		try {
			v.push_back(readPoint());
		}  catch (int) {
			break;
		}
	}

	if (v.size() < 2) { cout << "Invalid input \n"; return 10; }
	v.push_back(v[0]);
	prev = v[0];
	for (size_t i = 1; i<v.size(); i++) {
		auto x1 = prev.x, x2 = v[i].x, y1=prev.y, y2=v[i].y;
		auto area_total = ((x2-x1)*y1) + ((x2-x1)*(y2-y1)*0.5);
		if (area_total == 0) {
			prev = v[i];
			continue;
		}
		auto xd_temp = ((x1+x2)/2)*(y1*(x2-x1));
		xd_temp += (x1+2*(x2-x1)/3)*((x2-x1)*(y2-y1)*0.5);
		xd_temp /= area_total;
		auto yd_temp = (y1/2)*((x2-x1)*y1);
		yd_temp += (y1 + (y2-y1)/3) * ((x2-x1)*(y2-y1)*0.5);
		yd_temp /= area_total;

		X = ((X*A)+ (xd_temp*area_total))/(A+area_total);
		Y = ((Y*A)+ (yd_temp*area_total))/(A+area_total);
		A = A + area_total;
		prev = v[i];
	}
	puts("--------------------------------------------------------");
	printf("X = %lg\n", X);
	printf("Y = %lg\n", Y);
	puts("---------------------------------------------------------");
	return 0;
}
