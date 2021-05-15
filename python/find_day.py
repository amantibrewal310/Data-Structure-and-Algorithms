import calendar
import datetime


def findDay(date):
    born = datetime.datetime.strptime(date, "%d %m %Y").weekday()
    return calendar.day_name[born]


date = "15 07 1947"
print(findDay(date))

