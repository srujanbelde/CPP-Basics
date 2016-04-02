/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int days(int yr1, int yr2, int mon1, int mon2, int day1, int day2);
int month(int mon, int yr);
int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int between_days(struct node *date1head, struct node *date2head){
	if ((date1head == NULL) || (date2head == NULL))
		return -1;
	else
	{
		int day1 = 0, day2 = 0, mon1 = 0, mon2 = 0, yr1 = 0, yr2 = 0;
		struct node *temp1 = date1head;
		struct node *temp2 = date2head;
		day1 = ((temp1->data) * 10) + (temp1->next->data);
		day2 = ((temp2->data) * 10) + (temp2->next->data);
		temp1 = temp1->next;
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp2 = temp2->next;
		mon1 = ((temp1->data) * 10) + (temp1->next->data);
		mon2 = ((temp2->data) * 10) + (temp2->next->data);
		temp1 = temp1->next;
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp2 = temp2->next;
		yr1 = ((temp1->data) * 1000) + ((temp1->next->data) * 100) + ((temp1->next->next->data) * 10) + (temp1->next->next->next->data);
		yr2 = ((temp2->data) * 1000) + ((temp2->next->data) * 100) + ((temp2->next->next->data) * 10) + (temp2->next->next->next->data);
		printf("%d%d%d%d%d%d", day1, mon1, yr1, day2, mon2, yr2);
		if ((yr1 == yr2) && (mon1 == mon2) && ((day1 == day2)))
			return 0;
		return days(yr1, yr2, mon1, mon2, day1, day2);
	}
}
int days(int yr1, int yr2, int mon1, int mon2, int day1, int day2)
{
	int count = 0, i;
	for (i = yr1; i<yr2; i++)
	{
		if (i % 4 == 0)
			count += 366;
		else
			count += 365;
	}
	count -= month(mon1, yr1);
	count -= day1;
	count += month(mon2, yr2);
	count += day2;
	if (count<0)
		count = count*-1;
	return count - 1;
}
int month(int mon, int yr)
{
	int days = 0, i;
	for (i = 0; i<mon - 1; i++)
	{
		if (i == 1)
		{
			if (yr % 4 == 0)
				days += 29;
			else
				days += 28;
		}
		else
			days += months[i];
	}
	return(days);
}