from datetime import datetime, timedelta

weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

def get_previous_byday(dayname, start_date=None):
    if start_date is None:
        start_date = datetime.today()
    day_num = start_date.weekday()
    day_num_target = weekdays.index(dayname)
    days_ago = (7 + day_num - day_num_target) % 7 
    if days_ago == 0:
        days_ago = 7
    #print("{} {} {}".format(day_num, day_num_target, days_ago))
    target_date = start_date - timedelta(days=days_ago)
    return target_date

print(get_previous_byday('Monday', datetime(2017, 11, 11).now().date()))
print(get_previous_byday('Friday', datetime(2017, 11, 11).now().date()))
print(get_previous_byday('Saturday', datetime(2017, 11, 11).now().date()))
print(get_previous_byday('Sunday', datetime(2017, 11, 11).now().date()))
