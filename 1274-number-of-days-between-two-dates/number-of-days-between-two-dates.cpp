class Solution {
public:
    bool isLeapYear(int year) {

        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    int f(string date) {
        vector<int> days(12);
        days[0] = 31;
        days[1] = 28;
        days[2] = 31;
        days[3] = 30;
        days[4] = 31;
        days[5] = 30;
        days[6] = 31;
        days[7] = 31;
        days[8] = 30;
        days[9] = 31;
        days[10] = 30;
        days[11] = 31;

        int t = 0;
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        if (isLeapYear(y))
            days[1]++;

        for (int i = 1971; i < y; i++) {
            t += 365;
            if (isLeapYear(i))
                t++;
        }

        for (int i = 0; i < m - 1; i++) {
            t += days[i];
        }

        return t + d;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(f(date1) - f(date2));
    }
};