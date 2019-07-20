#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct DateTime {
  int month, day, hour, minute;

  int total_minute() const { return day * 24 * 60 + hour * 60 + minute; };

  int operator-(const DateTime& other) const {
    return total_minute() - other.total_minute();
  }

  bool operator<(const DateTime& other) const {
    return (month != other.month
                ? month < other.month
                : (day != other.day
                       ? day < other.day
                       : (hour != other.hour ? hour < other.hour
                                             : minute < other.minute)));
  }
};

ostream& operator<<(ostream& out, const DateTime& dt) {
  out << setfill('0') << setw(2) << dt.day << ":";
  out << setfill('0') << setw(2) << dt.hour << ":";
  out << setfill('0') << setw(2) << dt.minute;
  return out;
}

istream& operator>>(istream& in, DateTime& dt) {
  char _;
  return in >> dt.month >> _ >> dt.day >> _ >> dt.hour >> _ >> dt.minute;
}

struct Record {
  string username;
  DateTime timestamp;
  string status;
};

int costs[25];

int main() {
  for (int i = 0; i < 24; i++) cin >> costs[i];

  int n;
  cin >> n;

  vector<Record> records;
  for (Record r; n-- && cin >> r.username >> r.timestamp >> r.status;) {
    records.push_back(r);
  }

  std::sort(records.begin(), records.end(), [](Record& a, Record& b) {
    return (a.username != b.username ? a.username < b.username
                                     : a.timestamp < b.timestamp);
  });

  int on = 0, off, next;
  for (; on < records.size();) {
    int should_print = 0;
    next = on;
    while (next < records.size() &&
           records[on].username == records[next].username) {
      if (!should_print && records[next].status == "on-line") {
        should_print = 1;
      } else if (should_print == 1 && records[next].status != "on-line") {
        should_print = 2;
      }
      next++;
    }
    if (should_print < 2) {
      on = next;
      continue;
    }
    int total_money = 0;
    printf("%s %02d\n", records[on].username.c_str(),
           records[on].timestamp.month);
    while (on < next) {
      while (on < next - 1 && !(records[on].status == "on-line" &&
                                records[on + 1].status == "off-line")) {
        on++;
      }

      off = on + 1;
      if (off == next) {
        on = next;
        break;
      }
      cout << records[on].timestamp << " ";
      cout << records[off].timestamp << " ";

      int minutes = 0, money = 0;
      for (auto t = records[on];
           t.timestamp.day < records[off].timestamp.day ||
           t.timestamp.hour < records[off].timestamp.hour ||
           t.timestamp.minute < records[off].timestamp.minute;) {
        minutes++;
        money += costs[t.timestamp.hour];
        t.timestamp.minute++;
        if (t.timestamp.minute >= 60) {
          t.timestamp.minute = 0;
          t.timestamp.hour++;
        }
        if (t.timestamp.hour >= 24) {
          t.timestamp.hour = 0;
          t.timestamp.day++;
        }
      }

      total_money += money;
      printf("%d $%.2f\n", minutes, money / 100.0);
      on = off + 1;
    }
    printf("Total amount: $%.2f\n", total_money / 100.0);
  }
  return 0;
}