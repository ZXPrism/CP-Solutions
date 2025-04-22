from datetime import date, timedelta


def date_range(start: date, end: date):
    current = start
    while current < end:
        yield current
        current += timedelta(days=1)


ans = 0
for d in date_range(date(1901, 1, 1), date(2001, 1, 1)):
    if d.day == 1 and d.weekday() == 6:
        ans += 1

print(ans)
