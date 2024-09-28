OBJS = wordEntry.o Rai_Aditi_assn4.o
CC = g++
DEBUGS = -g
CFLAGS = -Wall -c $(DEBUGS)
LFLAGS = -Wall $(DEBUGS)


execute: hw.o
	$(CC) $(LFLAGS) $(OBJS) -o hw

hw.o:
	$(CC) $(CFLAGS) wordEntry.cpp
	$(CC) $(CFLAGS) Rai_Aditi_assn4.cpp

clean:
	\rm *.o *~hw

tar:
	tar cfv execute.tar calendar.h Rai_Aditi_appointment.cpp Rai_Aditi_assn3.cpp Rai_Aditi_calendar.cpp Rai_Aditi_day.cpp Rai_Aditi_reminder.cpp
 