#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<double, double> point;
bool flag;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
    long long s = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y;
    s -= (p2.X * p1.Y + p3.X * p2.Y + p1.X * p3.Y);
    if(s > 0) return 1;
    else if(s == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pair<long long, long long>, pair<long long, long long>> l1,
                 pair<pair<long long, long long>, pair<long long, long long>> l2) {
    auto p1 = l1.first, p2 = l1.second;
    auto p3 = l2.first, p4 = l2.second;
    
    if(p1 > p2) swap(p1, p2);
    if(p3 > p4) swap(p3, p4);

    int c1 = ccw(p1, p2, p3);
    int c2 = ccw(p1, p2, p4);
    int c3 = ccw(p3, p4, p1);
    int c4 = ccw(p3, p4, p2);
    
    bool isLine = (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0);
    
    if(isLine) {
        // 일직선 상에서 겹치는지
        if(max(p1, p3) <= min(p2, p4)) {
            // 한 점에서 만나면
            pair<long long, long long> s = max(p1, p3);
            pair<long long, long long> e = min(p2, p4);
            if(s == e) {
                flag = true;
                point = { (double)s.X, (double)s.Y };
            }
            else {
                flag = false;
            }
            return true;
        }
        return false;
    }
    else {
        if(c1 * c2 <= 0 && c3 * c4 <= 0) {
            flag = true;
            // 연립방정식 행렬계산
            long double A1 = p2.Y - p1.Y;
            long double B1 = p1.X - p2.X;
            long double C1 = A1 * p1.X + B1 * p1.Y;
            
            long double A2 = p4.Y - p3.Y;
            long double B2 = p3.X - p4.X;
            long double C2 = A2 * p3.X + B2 * p3.Y;
            
            long double det = A1 * B2 - A2 * B1;
            long double x = (B2 * C1 - B1 * C2) / det;
            long double y = (A1 * C2 - A2 * C1) / det;
            
            point = { (double)x, (double)y };
            return true;
        }
        return false;
    }
}

void printVal(long double val) {
    // 정수면 정수 그대로, 실수면 소수점 아래 10자리까지 출력
    if(val == (long long)val) cout << (long long)val;
    else cout << fixed << setprecision(10) << (double)val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    bool intersect = isIntersect({{x1,y1},{x2,y2}}, {{x3,y3},{x4,y4}});
    cout << intersect << "\n";
    if(flag) {
        printVal(point.X);
        cout << ' ';
        printVal(point.Y);
    }
    return 0;
}
