TARGET = ToyRobotApp

CXX = g++
CFLAGS = -g -Wall -std=c++17 -I${HEADERS}

HEADERS := include/

SOURCES := app/ToyRobotApp.cpp \
		   Command.cpp \
		   Coordinate.cpp \
		   Direction.cpp \
		   Position.cpp \
		   Table.cpp \
		   ToyRobot.cpp \

${TARGET}: ${SOURCES}
	${CXX} ${CFLAGS} -o ${TARGET} ${SOURCES}

all: clean ${TARGET}

clean:
	rm -rf ${TARGET}